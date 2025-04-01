# Copyright 2016-2025 NXP
# SPDX-License-Identifier: BSD-3-Clause

import re
from collections import OrderedDict

class MapFileGCC(object):
    def __init__(self, path):
        self.path = path
        self.DIS = []
        self.MC = []
        self.LSMM = OrderedDict()
        self.CREF = OrderedDict()
        _mapfile_parts = { # Format: {header -> offset}
            'Discarded input sections': -1,
            'Memory Configuration': -1,
            'Linker script and memory map': -1,
            'Cross Reference Table': -1
        }
        # Process the Mapfile
        with open(self.path, 'rb') as f:
            _lines = f.read().decode('utf-8').splitlines()
        # Find where the different parts start
        for i in range(0, len(_lines)):
            if _lines[i] in _mapfile_parts:
                _mapfile_parts[_lines[i]] = i
        # Parse the parts (-1 means doesn't exist)
        for part in _mapfile_parts:
            if _mapfile_parts[part] != -1:
                self._parse_mapfile_part(part, _lines[_mapfile_parts[part]:])

    def get_DIS_section_by_name(self, name):
        """Returns a list of sections of that name."""
        return [i for i in self.DIS if i['Name'] == name]

    def get_DIS_lto_section_by_name(self, name):
        """Returns a list of sections of that name."""
        cond = lambda x, y: x[:x.rfind('.')] == ('.gnu.lto_' + y)
        return [i for i in self.DIS if cond(i['Name'], name)]

    def iter_DIS_sections(self):
        """Yield all DIS."""
        for sec in self.DIS:
            yield sec

    def get_MC_region_by_address(self, addr):
        """Returns the name of the region that this address falls into."""
        for reg in self.MC:
            if reg['Origin'] <= addr < (reg['Origin'] + reg['Length']):
                return reg['Name']

    def iter_MC_regions(self):
        """Yield all MC regions."""
        for reg in self.MC:
            yield reg

    def get_LSMM_symbol_by_name(self, name):
        """Returns a list."""
        syms = []
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                for sym in subsec['Symbols']:
                    if sym == name:
                        syms.append({
                            'Name': sym,
                            'Section': sec,
                            'Address': subsec['Symbols'][sym]['Address'],
                            'Size': subsec['Symbols'][sym]['Size'],
                            'Archive': subsec['Archive'],
                            'Object': subsec['Object']
                        })
        return syms

    def get_LSMM_symbol_starting_with(self, names):
        """Returns a list of symbols (empty list if no matches)."""
        syms = []
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                for sym in subsec['Symbols']:
                    if sym.startswith(names):
                        syms.append({
                            'Name': sym,
                            'Section': sec,
                            'Address': subsec['Symbols'][sym]['Address'],
                            'Size': subsec['Symbols'][sym]['Size'],
                            'Archive': subsec['Archive'],
                            'Object': subsec['Object']
                        })
        return syms

    def get_LSMM_section_by_name(self, name):
        """Returns a section or None if no matches."""
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                if subsec['Name'] == name:
                    return subsec

    def get_LSMM_section_starting_with(self, names):
        """Returns a list of sections (empty list if no matches)."""
        secs = []
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                if subsec['Name'].startswith(names):
                    secs.append(subsec)
        return secs

    def get_LSMM_section_ending_with(self, name):
        """Returns a list of sections (empty list if no matches)."""
        secs = []
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                if subsec['Name'].endswith(name):
                    secs.append(subsec)
        return secs

    def iter_LSMM_symbols(self):
        """Yield all LSMM symbols."""
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                for sym in subsec['Symbols']:
                    yield {
                        'Name': sym,
                        'Section': sec,
                        'Address': subsec['Symbols'][sym]['Address'],
                        'Size': subsec['Symbols'][sym]['Size'],
                        'Archive': subsec['Archive'],
                        'Object': subsec['Object']
                    }

    def iter_LSMM_sections(self):
        """Yield all subsections from the LSMM."""
        for sec in self.LSMM:
            for subsec in self.LSMM[sec]['Children']:
                yield subsec

    def get_CREF_symbol_by_name(self, name):
        """Returns a dict or None if no matches."""
        if name in self.CREF:
            return self.CREF[name]
        else:
            return None

    def _parse_mapfile_part(self, header, lines):
        if header == 'Discarded input sections':
            self._parse_DIS(lines)
        elif header == 'Memory Configuration':
            self._parse_MC(lines)
        elif header == 'Linker script and memory map':
            self._parse_LSMM(lines)
        elif header == 'Cross Reference Table':
            self._parse_CREF(lines)
        else:
            raise ValueError("Unrecognized header: {:s}".format(header))

    def _parse_DIS(self, lines):
        # Assumed:
        # -- no whitespace character in the section names
        i = 2
        while lines[i]:
            line = lines[i]
            if ' ' not in line[1:]:
                # Line is split => concatenate with next one
                i += 1
                line += lines[i]
            pat = re.compile(
                r"^ (\.[^ ]+) +"
                r"0x([0-9a-f]+) +"
                r"0x([0-9a-f]+) "
                r"(.+)$"
            )
            matches = re.match(pat, line)
            if matches:
                # Further parse the last match
                if matches.group(4)[-1] == ')':
                    if matches.group(4).endswith(" (symbol from plugin)"):
                        # Regular case
                        obj = matches.group(4)[:-21]
                        ar = None
                    else:
                        # Archive case
                        sep = matches.group(4).rfind('(')
                        ar = matches.group(4)[:sep]
                        obj = matches.group(4)[sep+1:-1]
                else:
                    # Regular case
                    obj = matches.group(4)
                    ar = None
                # Add new entry in the DIS table
                self.DIS.append({
                    'Name': matches.group(1).strip(),
                    'Address': int(matches.group(2), 16),
                    'Size': int(matches.group(3), 16),
                    'Object': obj,
                    'Archive': ar
                })
            # Increment the line counter
            i += 1

    def _parse_MC(self, lines):
        i = 3
        while lines[i]:
            pat = re.compile(
                r"^([^\s]+)\s+"
                r"0x([0-9a-f]+)\s+"
                r"0x([0-9a-f]+)\s*"
                r"([rxw]*)$"
            )
            matches = re.match(pat, lines[i])
            if matches:
                # Add new entry to MC dict
                self.MC.append({
                    'Name': matches.group(1),
                    'Origin': int(matches.group(2), 16),
                    'Length': int(matches.group(3), 16),
                    'Attributes': matches.group(4) if matches.group(4) else ""
                })
            # Increment the line counter
            i += 1

    def _parse_LSMM(self, lines):
        i = 2
        # Skip to the first section
        while lines[i]:
            i += 1
        i += 1
        # Process the rest of the LSMM
        while True:
            _sec = None # current section name
            _sym = None # last symbol name
            while lines[i]:
            	# Debug line to help when having issue: IndexError: list index out of range
                # print("i:{}".format(i))
                line = lines[i]
                if line[0] == '.':
                    # Section
                    if ' ' not in line:
                        # Line is split => concatenate with next one
                        if ".ARM.extab" in line or ".ARM.exidx" in line:
                            # These sections does not comply with other sections
                            # These sections should be ignored
                            break
                        i += 1
                        line += lines[i]
                    pat = re.compile(
                        r"^([^\s]+)\s+"
                        r"0x([0-9a-f]+)\s+"
                        r"0x([0-9a-f]+)(?: .*)?$"
                    )
                    matches = re.match(pat, line)
                    if not matches:
                        print(
                            "!! WARNING: Couldn't parse section from the "
                            "\"Linker script and memory map\" part of "
                            "the mapfile. Line ({:d}): <<{:s}>>".format(
                                i, line
                            )
                        )
                        break
                    # Add a new entry to the LSMM dict
                    if matches.group(1) in self.LSMM:
                        raise Exception(
                            "It's assumed that section (not "
                            "subsections) have unique names."
                        )
                    self.LSMM[matches.group(1)] = {
                        'Address': int(matches.group(2), 16),
                        'Size': int(matches.group(3), 16),
                        'Children': []
                    }
                    # Store the name for later referencing
                    _sec = matches.group(1)
                elif line[0:2] == ' .':
                    # Subsection
                    if ' ' not in line[1:]:
                        # Line is split => concatenate with next one
                        i += 1
                        line += lines[i]
                    pat = re.compile(
                        r"^ ([^\s]+)\s+"
                        r"0x([0-9a-f]+)\s+"
                        r"0x([0-9a-f]+) "
                        r"(.+)$"
                    )
                    matches = re.match(pat, line)
                    if not matches:
                        raise ValueError(
                            "Couldn't parse subsection from the "
                            "\"Linker script and memory map\" "
                            "part of the mapfile. Line "
                            "({:d}): <<{:s}>>".format(i, line)
                        )
                    # Further process the source
                    if matches.group(4)[-1] == ')':
                        sep = matches.group(4).rfind('(')
                        ar = matches.group(4)[:sep]
                        obj = matches.group(4)[sep+1:-1]
                    else:
                        ar = None
                        obj = matches.group(4)
                    # Add a new child to section
                    self.LSMM[_sec]['Children'].append({
                        'Name': matches.group(1),
                        'Address': int(matches.group(2), 16),
                        'Size': int(matches.group(3), 16),
                        'Archive': ar,
                        'Object': obj,
                        'Symbols': {}
                    })
                elif line[0:2] == '  ':
                    # Potentially a symbol
                    pat = re.compile(
                        r"^\s+0x([0-9a-f]+)\s+"
                        r"([^\s]+)$"
                    )
                    matches = re.match(pat, line)
                    try:
                        if matches:
                            _addr = int(matches.group(1), 16)
                            _size = 0
                            _subsec = self.LSMM[_sec]['Children'][-1]
                            if self.LSMM[_sec]['Children'][-1]['Symbols']:
                                # Not first symbol => set previous' size
                                _prev_addr = _subsec['Symbols'][_sym]['Address']
                                _subsec['Symbols'][_sym]['Size'] = (
                                    _addr - _prev_addr
                                )
                            else:
                                # First symbol => calculate the current size
                                _subsec_addr = _subsec['Address']
                                _size = _addr - _subsec_addr
                            if (i+1) >= len(lines) or lines[i+1][0:2] != '  ':
                                # This is the last symbol =>
                                # calculate the current size
                                _subsec_addr = _subsec['Address']
                                _subsec_size = _subsec['Size']
                                _size = _subsec_size - (_addr - _subsec_addr)
                            # Add symbol to section's last child
                            _subsec['Symbols'][matches.group(2)] = {
                                'Address': _addr,
                                'Size': _size
                            }
                            # Store the name for later referencing
                            _sym = matches.group(2)
                    except:
                      print("!! DEBUG: Skipping accounting for symbol " + matches.group(2))
                      pass
                else:
                    # Not interested => ignore
                    pass
                # Increment the line counter
                i += 1
            # Increment the line counter (move on to next section) or break
            if lines[i-1].startswith('OUTPUT(') or lines[i-2].startswith('OUTPUT('):
                break
            else:
                i += 1

    def _parse_CREF(self, lines):
        for line in lines[3:]:
            if line[0] != ' ':
                # Symbol definition (as opposed to reference)
                pat = re.compile(
                    r"^([^ ]+) +"
                    r"(.+)$"
                )
                matches = re.match(pat, line)
                # Further parse the source
                if matches.group(2)[-1] == ')':
                    ar = matches.group(2)[:matches.group(2).rfind('(')]
                    obj = matches.group(2)[matches.group(2).rfind('(')+1:-1]
                else:
                    ar = None
                    obj = matches.group(2)
                # Store the symbol
                self.CREF[matches.group(1)] = {
                    'Archive': ar,
                    'Object': obj
                }

class MapFileIAR(object):
    def __init__(self, path):
        self.path = path
        self.EL = OrderedDict()
        # Process the Mapfile
        with open(self.path, 'rb') as f:
            _lines = f.read().decode('utf-8').splitlines()
        # Find where the entry list begins
        _el_start = 0
        for i in range(0, len(_lines)):
            if _lines[i] == '*** ENTRY LIST':
                _el_start = i + 5 # first entry in the table
                break
        # Find where the entry list endswith
        _el_end = 0
        for i in range(_el_start, len(_lines)):
            if not _lines[i]:
                _el_end = i
                break
        # Parse the reference table below the entry list
        ref_dict = {}
        for line in _lines[_el_end + 2:]:
            if not line:
                break
            else:
                key, _eq, val = line.split(' ', 2)
                ref_dict[key] = val
        self._parse_entry_list(_lines[_el_start:_el_end], ref_dict)

    def get_EL_symbol_by_name(self, name):
        """Returns the symbols of that name, None otherwise."""
        if name in self.EL:
            return self.EL[name]

    def get_EL_symbol_by_address(self, addr):
        """Returns the symbol at that address, None otherwise."""
        if addr in self.EL:
            return self.EL[addr]

    def _parse_entry_list(self, elist, refs):
        # Regex pattern compilation
        pat = re.compile(
            r"^([^ ]+) +"
            r"0x([0-9a-f]+) +"
            r"0x([0-9a-f]+) +"
            r"(?:Data|Code) +"
            r"(?:Lc|Gb) +"
            r"(.+) "
            r"(\[[0-9]+\])$"
        )
        for i in range(0, len(elist)):
            line = elist[i]
            # Ignore symbols ending on {ABS} (configs)
            if line.endswith('{ABS}'):
                i += 1
                continue
            # Check if line is split
            if ' ' not in elist[i]:
                i += 1
                line += elist[i]
            # Ignore linker script entries
            if line.endswith('- Linker created -'):
                continue
            # Try matching
            matches = re.match(pat, line)
            if matches:
                if refs[matches.group(5)].endswith('.a'):
                    ar = refs[matches.group(5)]
                    obj = matches.group(4)
                else:
                    ar = None
                    obj = matches.group(4)
                self.EL[int(matches.group(2), 16)] = {
                    'Name': matches.group(1),
                    'Size': int(matches.group(3), 16),
                    'Archive': ar,
                    'Object': obj
                }
