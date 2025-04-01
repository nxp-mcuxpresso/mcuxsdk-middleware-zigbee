# Copyright 2016-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

from __future__ import division
from __future__ import print_function
import re
import os.path
import argparse
import json
from collections import OrderedDict
import jsonschema
import openpyxl
from elftools.elf.elffile import ELFFile
from map_parser import MapFileGCC, MapFileIAR
from itertools import groupby
import pprint

# ----------------------------------------------------------------------
#
# UTILITY FUNCTIONS
#
# ----------------------------------------------------------------------
def get_sections(filename):
    """Returns an OrderedDict of sections (dicts)."""
    secs = OrderedDict()
    with open(filename, 'rb') as f:
        ef = ELFFile(f)
        for sec in ef.iter_sections():
            if sec.header['sh_flags'] & 0x2:
                # Section is allocatable
                secs[sec.name] = {
                    'Size': sec.header['sh_size'],
                    'Address': sec.header['sh_addr'],
                    'Offset': sec.header['sh_offset'],
                    'Type': sec.header['sh_type'],
                    'Flags': sec.header['sh_flags']
                }
    return secs

def get_symbols(filename):
    """Returns a list of symbols (dicts)."""
    syms = []
    itypes = ['STT_NOTYPE', 'STT_FILE', 'STT_SECTION']
    isecs = ['SHN_ABS', 'SHN_UNDEF']
    with open(filename, 'rb') as f:
        ef = ELFFile(f)
        symtab = ef.get_section_by_name('.symtab')
        for sym in symtab.iter_symbols():
            sym_type = sym['st_info']['type']
            sym_secind = sym['st_shndx']
            if sym_type not in itypes and sym_secind not in isecs:
                syms.append({
                    'Name': sym.name,
                    'Address': int(sym['st_value']),
                    'Size': int(sym['st_size']),
                    'Section': ef.get_section(int(sym_secind)).name,
                    'Type': sym_type,
                    'Archive' : None,
                    'Object': None,
                    'Component': None
                })
    return syms

def check_LTO(filename):
    """Returns true if the ELF file was compiled with -flto flag."""
    with open(filename, 'rb') as f:
        ef = ELFFile(f)
        symtab = ef.get_section_by_name('.symtab')
        for i in range(0, 50): # Should get a match within the first 50 syms
            sym = symtab.get_symbol(i)
            if sym['st_info']['type'] == 'STT_FILE' and 'ltrans' in sym.name:
                return True
    return False

def _progress_message(caller, amount, fraction):
    """Prints a generic progress message, used in the lookup functions."""
    print(
        "{:s}: matched {:d} out of {:d} ({:F}%) symbols".format(
            caller,
            fraction,
            amount,
            (fraction * 100.0) / amount
        )
    )

def cref_lookup(symbol_table, gcc_mapfile):
    """Tries to match symbols with entries from the CREF table.

    Accepts a list of symbols (dicts) and a MapFileGCC object.

    The CREF table includes all non-static (PRIVATE in the case of
    jendefs.h) symbols. Therefore, usually majority of the symbols, e.g.
    70% or more, will be matched by this function.
    """
    for sym in symbol_table:
        match = gcc_mapfile.get_CREF_symbol_by_name(sym['Name'])
        if match:
            sym['Archive'] = match['Archive']
            sym['Object'] = match['Object']
    # Print progress
    sym_cntr = 0
    for sym in symbol_table:
        if sym['Object']:
            sym_cntr += 1
    #_progress_message('cref_lookup()', len(symbol_table), sym_cntr)

def lsmm_lookup(symbol_table, gcc_mapfile):
    """Tries to match symbols with the contents of the LSMM table.

    Accepts a list of symbols (dicts) and a MapFileGCC object.

    The LSMM table includes a detailed breakdown of how the memory is
    mapped. It includes all sections that are allocatable, as well as
    their respective symbols. There is no guarantee, however, that all
    symbols can be found in the LSMM table. This function does two
    iterations: first looking for a section and then -- for a symbol.
    """
    for sym in symbol_table:
        if sym['Object']:
            continue
        # Look for section match first, then for symbol
        match = gcc_mapfile.get_LSMM_section_by_name(
            sym['Section'] + '.' + sym['Name']
        )
        if match:
            sym['Archive'] = match['Archive']
            sym['Object'] = match['Object']
        else:
            # Look for a symbol match
            matches = gcc_mapfile.get_LSMM_symbol_by_name(sym['Name'])
            if len(matches) > 1:
                print(
                    '!! WARNING: Lookup for symbol <<{:s}>> returned '
                    'multiple matches: {!s}'.format(sym['Name'], matches)
                )
            if matches:
                sym['Archive'] = matches[0]['Archive']
                sym['Object'] = matches[0]['Object']
    # Print progress
    sym_cntr = 0
    for sym in symbol_table:
        if sym['Object']:
            sym_cntr += 1
    #_progress_message('lsmm_lookup()', len(symbol_table), sym_cntr)

def dis_lookup(symbol_table, gcc_mapfile, LTO=False):
    """Tries to match symbols with the entries of the DIS table.

    Accepts a list of symbols (dicts) and a MapFileGCC object. The
    LTO argument is a flag that toggles the lookup for LTO sections.

    The DIS table consists of input sections which did not end up in
    the final binary. This would usually be stuff like optimized-out
    sections, non-allocatable sections, etc. This is also where all
    LTO section end up if you compile your source with LTO but link
    it without.
    """
    for sym in symbol_table:
        if sym['Object']:
            continue
        # Look for a section match
        if LTO:
            matches = gcc_mapfile.get_DIS_lto_section_by_name(sym['Name'])
        else:
            matches = gcc_mapfile.get_DIS_section_by_name(
                sym['Section'] + '.' + sym['Name']
            )
        if matches:
            if len(matches) > 1:
                print(
                    '!! WARNING: Found more than one matches during '
                    'dis_lookup() with symbol name {:s}'.format(
                        sym['Name']
                    )
                )
            sym['Archive'] = matches[0]['Archive']
            sym['Object'] = matches[0]['Object']
    # Print progress
    sym_cntr = 0
    for sym in symbol_table:
        if sym['Object']:
            sym_cntr += 1
    #_progress_message('dis_lookup()', len(symbol_table), sym_cntr)

def lsmm_stripped_lookup(symbol_table, gcc_mapfile):
    """Tries to match demangled symbols with the contents of the LSMM table.

    Accepts a list of symbols (dicts) and a MapFileGCC object.

    The function does three iterations:
    -- sections starting with the symbols' (including a lookup for
        .text.unlikely if the symbol belongs to .text) section and
        name, which is useful if the symbol has suffixes like '.part.0'
        or '.constprop.23', etc. Mostly useful for when not using a
        different map file (e.g. non-LTO map).
    -- sections ending with symbols' names, which is only useful when
        using a different map file, as sometimes symbols end up in a
        different section and this accounts for that.
    -- symbols starting with the symbols' names, which is pretty much
        the symbol alternative of the first iteration.
    """
    for sym in symbol_table:
        if sym['Object']:
            continue
        # Look for section match (starting)
        if sym['Section'] == '.text':
            matches = gcc_mapfile.get_LSMM_section_starting_with((
                '.text.' + sym['Name'],
                '.text.unlikely.' + sym['Name']
            ))
        else:
            matches = gcc_mapfile.get_LSMM_section_starting_with(
                sym['Section'] + '.' + sym['Name']
            )
        if matches:
            if len(matches) > 1:
                print(
                    '!! WARNING: Found more than one matches during '
                    'lsmm_stripped_lookup(), section starting with '
                    '{:s}'.format(sym['Section'] + '.' + sym['Name'])
                )
            sym['Archive'] = matches[0]['Archive']
            sym['Object'] = matches[0]['Object']
            continue
        # Look for section match (ending)
        matches = gcc_mapfile.get_LSMM_section_ending_with(sym['Name'])
        if matches:
            if len(matches) > 1:
                print(
                    '!! WARNING: Found more than one matches during '
                    'lsmm_stripped_lookup(), section ending with '
                    '{:s}'.format(sym['Name'])
                )
            sym['Archive'] = matches[0]['Archive']
            sym['Object'] = matches[0]['Object']
            continue
        # Look for symbol match
        matches = gcc_mapfile.get_LSMM_symbol_starting_with(sym['Name'])
        if matches:
            if len(matches) > 1:
                print(
                    '!! WARNING: Found more than one matches during '
                    'lsmm_stripped_lookup(), symbol starting with '
                    '{:s}'.format(sym['Name'])
                )
            sym['Archive'] = matches[0]['Archive']
            sym['Object'] = matches[0]['Object']
    # Print progress
    sym_cntr = 0
    for sym in symbol_table:
        if sym['Object']:
            sym_cntr += 1
    #_progress_message('lsmm_stripped_lookup()', len(symbol_table), sym_cntr)

def excel_write_table(worksheet, data, position=(0, 0)):
    """Write a data structure as a table to the given worksheet.

    The data structure is a matrix of the following format:

        matrix = (row_1, ..., row_n)      could be a list too
        row_n = (cell_1, ..., cell_n)     could be a list too
        cell_n = (contents, style_dict)

    Where contents is a the contents of the cell (usually a string),
    and style_dict is a dictionary whose format is explained in
    the docstring of the excel_apply_style() function.

    The position argument has the format (row_index, column_index),
    where indices start from 0, i.e. (0, 0) translates to cell A1.
    This position denotes the upper left corner (cell) of the table.
    """
    row_cntr, col_cntr = position
    col_widths = {}
    # Write the table
    for row in data:
        col_cntr = position[1]
        for (cell, style_dict) in row:
            # Get the cell position in Excel notation
            row_str = str(row_cntr + 1)
            col_str = get_excel_col_label(col_cntr)
            cell_pos =  col_str + row_str
            # Set the cell
            worksheet[cell_pos] = cell
            # Apply the styles from the style dictionary
            excel_apply_style(worksheet[cell_pos], style_dict)
            # Check if widest cell in the column
            if col_str in col_widths:
                col_widths[col_str] = max(
                    col_widths[col_str],
                    len(str(cell)) + 1
                )
            else:
                col_widths[col_str] = len(str(cell)) + 1
            col_cntr += 1
        row_cntr += 1
    # "Autofit" the columns
    for col in col_widths:
        if worksheet.column_dimensions[col].width == None:
            worksheet.column_dimensions[col].width = col_widths[col]
        else:
            worksheet.column_dimensions[col].width = max(
                worksheet.column_dimensions[col].width,
                col_widths[col]
            )

def excel_apply_style(cell, style_dict):
    """Applies the styles from the style dictionary to the cell.

    The style dictionary can contains an arbitrary number of
    key->value pairs, but the only accepted keys are:
        -- font
        -- fill
        -- border
        -- alignment
        -- number_format
        -- protection
    They correspond to the cell's style attributes, part of the
    openpyxl module. Check it's documentation to see what values
    are expected.
    """
    for style in style_dict:
        if style == 'font':
            cell.font = style_dict['font']
        elif style == 'fill':
            cell.fill = style_dict['fill']
        elif style == 'border':
            cell.border = style_dict['border']
        elif style == 'alignment':
            cell.alignment = style_dict['alignment']
        elif style == 'number_format':
            cell.number_format = style_dict['number_format']
        elif style == 'protection':
            cell.protection = style_dict['protection']
        else:
            raise ValueError(
                "Unrecognized style encountered during "
                "excel_apply_style(): {:s}".format(style)
            )

def get_excel_col_label(index):
    """Converts a column number to a column label, starting from 0."""
    div = index // 26
    mod = index % 26
    if div > 0:
        return get_excel_col_label(div - 1) + chr(ord('A') + mod)
    else:
        return chr(ord('A') + mod)

# ----------------------------------------------------------------------
#
# MAIN APPLICATION
#
# ----------------------------------------------------------------------
if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Explore the memory structure of an ELF binary.'
    )
    parser.add_argument('elffile_path', help='path to the ELF file')
    parser.add_argument('mapfile_path', help='path to the Map file')
    parser.add_argument('config_path', help='path to a configuration file')
    parser.add_argument(
        '--output',
        help='path (without extension) where to save the output'
    )
    parser.add_argument(
        '--toolchain',
        default='gcc',
        choices=['gcc', 'iar'],
        help='the type of the compilation suite that produced the ELF and Map'
    )
    clargs = vars(parser.parse_args())

    # Load config file
    with open(clargs['config_path'], "r") as config_file:
        custom_components = json.load(
            config_file,
            object_pairs_hook=OrderedDict
        )
        # Validate with JSON schema
        schema = {
            "$schema": "http://json-schema.org/draft-04/schema#",
            "type": "object",
            "additionalProperties": {
                "type": "object",
                "properties": {
                    "patterns": {
                        "type": "array",
                        "items": {"type": "string"}
                    },
                    "color": {"type": "string"}
                },
                "required": ["patterns"]
            }
        }
        jsonschema.validate(custom_components, schema)

    # Compile regex patterns from the config file
    for cc in custom_components:
        for i in range(0, len(custom_components[cc]['patterns'])):
            try:
                custom_components[cc]['patterns'][i] = re.compile(
                    custom_components[cc]['patterns'][i]
                )
            except Exception as e:
                raise ValueError(
                    "Could not compile the following regex string: "
                    "\"{:s}\". Reason: {:s}.".format(
                        custom_components[cc]['patterns'][i],
                        e
                    )
                )

    # Get sections and symbols (this step is independent of the toolchain)
    secs = get_sections(clargs['elffile_path'])
    syms = get_symbols(clargs['elffile_path'])

    # If GCC and LTO => strip appended numbers from the symbols
    if clargs['toolchain'] == 'gcc' and check_LTO(clargs['elffile_path']):
        for sym in syms:
            sns = sym['Name'].split('.')
            for i in range(len(sns) - 1, -1, -1):
                if len(sns[i]) >= 4 and sns[i].isdigit():
                    del sns[i]
                elif sns[i] == 'constprop':
                    del sns[i:i+2]
            sym['Name'] = '.'.join(sns)

    # Load the mapfile
    if clargs['toolchain'] == 'gcc':
        mf = MapFileGCC(clargs['mapfile_path'])
    else:
        mf = MapFileIAR(clargs['mapfile_path'])

    # Get sections' regions (i.e. FLASH, RAM, etc.) and do some
    # further processing
    if clargs['toolchain'] == 'gcc':
        for sec in secs:
            secs[sec]['Region'] = mf.get_MC_region_by_address(
                secs[sec]['Address']
            )
        # Discard sections that fall in the *default* region (they
        # don't contribute to the binary's memory layout), as well as
        # all of their symbols. Do the same for the '.test' section.
        for key in list(secs.keys()):
            if secs[key]['Region'] == '*default*' or key == '.test':
                del secs[key]
        for i in range(len(syms) - 1, -1, -1):
            if syms[i]['Section'] not in secs:
                del syms[i]
    else:
        # Remove the 'Fill1' section (it just fills the rest of the
        # binary with 1s).
        for key in list(secs.keys()):
            if key == 'Fill1':
                del secs[key]
        # The IAR map files lack a memory configuration section, so
        # instead inspect and parse the sections' names
        for sec in secs:
            sec_name, sec_type = sec.split(' ', 1)
            if sec_type.startswith(('ro', 'rw')):
                secs[sec]['Region'] = 'FLASH'
            else:
                secs[sec]['Region'] = 'RAM'

    # Try to match symbols to object/archive files
    if clargs['toolchain'] == 'gcc':
        # First iteration
        cref_lookup(syms, mf)
        # Second iteration
        lsmm_lookup(syms, mf)
        # Third iteration
        dis_lookup(syms, mf)
        # Fourth iteration
        lsmm_stripped_lookup(syms, mf)
        if check_LTO(clargs['elffile_path']):
            # Fifth iteration
            dis_lookup(syms, mf, LTO=True)
    else:
        # Match all symbols with the entry list from the map file
        for sym in syms:
            match = mf.get_EL_symbol_by_address(sym['Address'])
            if match:
                sym['Archive'] = match['Archive']
                sym['Object'] = match['Object']

    # Parse components
    for sym in syms:
        if not sym['Object']:
            continue
        found_match = False
        if sym['Archive']:
            sym_src = sym['Archive']
        else:
            sym_src = sym['Object']
        for cc in custom_components:
            for pat in custom_components[cc]['patterns']:
                if re.match(pat, sym_src):
                    sym['Component'] = cc
                    found_match = True
                    break
            if found_match:
                break

    # Final iteration: discard all symbols with an unresolved
    # component and a size of zero
    for i in range(len(syms) - 1, -1, -1):
        if syms[i]['Component']:
            continue
        elif syms[i]['Component'] == None:
            syms[i]['Component'] = 'N/A'
            continue
        elif syms[i]['Size'] == 0:
            del syms[i]

# ----------------------------------------------------------------------
#
# EXCEL WRITING
#
# ----------------------------------------------------------------------

    # Create a workbook
    workbook = openpyxl.Workbook()
    # Clear author field
    workbook.properties.creator = None

    # Create styles
    header_style = {
        'font': openpyxl.styles.Font(
            bold=True,
            color='FFFFFFFF'
        ),
        'border': openpyxl.styles.Border(
            left=openpyxl.styles.Side(style='thin', color='FF000000'),
            right=openpyxl.styles.Side(style='thin', color='FF000000'),
            top=openpyxl.styles.Side(style='thin', color='FF000000'),
            bottom=openpyxl.styles.Side(style='thin', color='FF000000')
        ),
        'fill': openpyxl.styles.PatternFill(
            fill_type='solid',
            start_color='FF000000',
            end_color='FF000000'
        ),
        'alignment': openpyxl.styles.Alignment(
            horizontal='center'
        )
    }
    sec_entry_style = {
        'border': openpyxl.styles.Border(
            left=openpyxl.styles.Side(style='thin', color='FF000000'),
            right=openpyxl.styles.Side(style='thin', color='FF000000'),
            top=openpyxl.styles.Side(style='thin', color='FF000000'),
            bottom=openpyxl.styles.Side(style='thin', color='FF000000')
        )
    }
    comp_entry_style = {
        'border': openpyxl.styles.Border(
            left=openpyxl.styles.Side(style='thin', color='FF000000'),
            right=openpyxl.styles.Side(style='thin', color='FF000000'),
            top=openpyxl.styles.Side(style='thin', color='FF000000'),
            bottom=openpyxl.styles.Side(style='thin', color='FF000000')
        )
    }
    totals_style = {
        'font': openpyxl.styles.Font(
            bold=True
        )
    }
    sym_entry_style = {
        'border': openpyxl.styles.Border(
            left=openpyxl.styles.Side(style='thin', color='FF000000'),
            right=openpyxl.styles.Side(style='thin', color='FF000000'),
            top=openpyxl.styles.Side(style='thin', color='FF000000'),
            bottom=openpyxl.styles.Side(style='thin', color='FF000000')
        )
    }

    # Create a Sections worksheet
    ws_secs = workbook.active
    ws_secs.title = 'Sections'
    secs_table = [
        (
            ('Section name', header_style),
            ('Address', header_style),
            ('Size (bytes)', header_style),
            ('Region', header_style)
        )
    ]
    for sec in secs:
        row = (
            (sec, sec_entry_style),
            ('0x{:08X}'.format(secs[sec]['Address']), sec_entry_style),
            (secs[sec]['Size'], sec_entry_style),
            (secs[sec]['Region'], sec_entry_style)
        )
        secs_table.append(row)
    excel_write_table(ws_secs, secs_table)

    # Create a dictionary of components' region sizes
    regs = sorted(set([secs[sec]['Region'] for sec in secs]))
    comps_regs = {} # {component -> {region -> size}}
    for sym in syms:
        if sym['Component']:
            sym_comp = sym['Component']
        else:
            sym_comp = 'N/A'
        if sym_comp not in comps_regs:
            # Create and initialize the regions dict
            comps_regs[sym_comp] = {}
            for reg in regs:
                comps_regs[sym_comp][reg] = 0
            curr_reg = secs[sym['Section']]['Region']
            comps_regs[sym_comp][curr_reg] += sym['Size']
        else:
            # Increment region size
            curr_reg = secs[sym['Section']]['Region']
            comps_regs[sym_comp][curr_reg] += sym['Size']

    # Create a Components worksheet
    ws_comps = workbook.create_sheet(title="Components")
    comps_table = [
        [('Component name', header_style)] +
        [(reg + ' (bytes)', header_style) for reg in regs]
    ]
    for comp in sorted(comps_regs):
        entry_style = comp_entry_style.copy()
        if comp != 'N/A' and 'color' in custom_components[comp]:
            entry_style['fill'] = openpyxl.styles.PatternFill(
                fill_type='solid',
                start_color=custom_components[comp]['color'],
                end_color=custom_components[comp]['color']
            )
        row = [
            (comp, entry_style)
        ]
        for reg_cell in comps_table[0][1:]:
            reg = reg_cell[0][:-8]
            row.append(
                (comps_regs[comp][reg], entry_style)
            )
        comps_table.append(row)
    excel_write_table(ws_comps, comps_table)
    # Write totals
    totals_table = [[
        ('Totals', totals_style)
    ]]
    col_cntr = 1
    row_cntr = len(comps_table)
    for reg in regs:
        col_label = get_excel_col_label(col_cntr)
        totals_table[0].append(
            ('=SUM({:s}2:{:s}{:d})'.format(
                col_label,
                col_label,
                row_cntr
            ), totals_style)
        )
        col_cntr += 1
    excel_write_table(ws_comps, totals_table, position=(row_cntr, 0))

    # Create a Symbols worksheet
    ws_syms = workbook.create_sheet(title="Symbols")
    syms_table = [
        (
            ('Symbol name', header_style),
            ('Section', header_style),
            ('Size (bytes)', header_style),
            ('Component', header_style),
            ('Object', header_style),
            ('Archive', header_style)
        )
    ]
    # Sort syms in place
    syms.sort(key=lambda x: (x['Component'], x['Name']))
    for sym in syms:
        entry_style = sym_entry_style.copy()
        if (sym['Component'] and 'N/A' not in sym['Component'] and
          'color' in custom_components[sym['Component']]):
            comp_color = custom_components[sym['Component']]['color']
            entry_style['fill'] = openpyxl.styles.PatternFill(
                fill_type='solid',
                start_color=comp_color,
                end_color=comp_color
            )
        syms_table.append(
            (
                (sym['Name'], entry_style),
                (sym['Section'], entry_style),
                (sym['Size'], entry_style),
                (sym['Component'], entry_style),
                (sym['Object'], entry_style),
                (sym['Archive'], entry_style)
            )
        )
    excel_write_table(ws_syms, syms_table)

    # Create a File worksheet
    ws_files = workbook.create_sheet(title="Files")
    files_table = [
        (
            ('Object', header_style),
            ('Text size (bytes)', header_style),
            ('Data size (bytes)', header_style),
            ('BSS size (bytes)', header_style),
            ('Data RAM2 size (bytes)', header_style),
            ('Total flash size (bytes)', header_style),
            ('Total ram size (bytes)', header_style),
            ('Total size (bytes)', header_style),
        )
    ]
    
    syms.sort(key = lambda x: x['Address'])

    misses = {}
    total = 0
    # Calculate the remaining memory that's not included in any symbol
    for sym in syms:
        if not sym['Object']:
            sym['Object'] = 'No object'

        for sec in secs:
            if sym['Section'] == sec:
                if sec not in misses:
                    misses[sec] = {
                        "addr": 0,
                        "size": 0,
                    }

                if misses[sec]['addr'] == 0:
                    misses[sec]['addr'] = sym['Address']

                if misses[sec]['addr'] != sym['Address']:
                    misses[sec]['size'] += sym['Address'] - misses[sec]['addr']

                misses[sec]['addr'] = sym['Address'] + sym['Size']

    for sec in misses:
        syms.append({
            "Name": "No symbol",
            "Object": "No symbols",
            "Section": sec,
            "Size": misses[sec]['size'],
        })

    # Sort syms in place
    syms.sort(key=lambda x: (x['Object']))

    symsGroupedByObjects = [[sym for sym in g] for _, g in groupby(syms, key = lambda x: x['Object'])]

    for group in symsGroupedByObjects:
        sizes = {
            "text": 0,
            "data": 0,
            "bss": 0,
            "dataRam2": 0
        }
        objectName = group[0]['Object']

        for sym in group:
            sizes['text'] += sym['Size'] if sym['Section'] == '.text' else 0
            sizes['data'] += sym['Size'] if sym['Section'] == '.data' else 0
            sizes['bss'] += sym['Size'] if sym['Section'] == '.bss' else 0
            sizes['dataRam2'] += sym['Size'] if sym['Section'] == '.data_RAM2' else 0

        totalSize = sizes['text'] + sizes['data'] + sizes['bss'] + sizes['dataRam2']
        totalFlash = sizes['text'] + sizes['data'] + sizes['dataRam2']
        totalRam = sizes['data'] + sizes['bss'] + sizes['dataRam2']
        files_table.append(
            (
                (objectName, sec_entry_style),
                (sizes['text'], sec_entry_style),
                (sizes['data'], sec_entry_style),
                (sizes['bss'], sec_entry_style),
                (sizes['dataRam2'], sec_entry_style),
                (totalFlash, sec_entry_style),
                (totalRam, sec_entry_style),
                (totalSize, sec_entry_style)
            )
        )

    excel_write_table(ws_files, files_table)

    # Save workbook
    if clargs['output']:
        output_path = clargs['output'] + '.xlsx'
    else:
        output_path = os.path.splitext(clargs['elffile_path'])[0] + '.xlsx'
    workbook.save(output_path)
