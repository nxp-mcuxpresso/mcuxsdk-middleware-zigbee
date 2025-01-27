# -*- coding: utf-8 -*-
###############################################################################
#
# MODULE:      PDUM Configuration Tool
#
# COMPONENT:   PDUMConfig.py
#
# AUTHOR:      MRW
#
# DESCRIPTION: python script to generate configuration file for PDUM component
#
###############################################################################
#
# This software is owned by NXP B.V. and/or its supplier and is protected
# under applicable copyright laws. All rights are reserved. We grant You,
# and any third parties, a license to use this software solely and
# exclusively on NXP products [NXP Microcontrollers such as JN514x, JN516x, JN517x].
# You, and any third parties must reproduce the copyright and warranty notice 
# and any other legend of ownership on each  copy or partial copy of the software.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"  
# AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
# IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
# ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE 
# LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR 
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF 
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN 
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
# POSSIBILITY OF SUCH DAMAGE. 
# 
# Copyright 2015-2023 NXP
#
###############################################################################

import os
import stat
import re
import sys

version = "1.5.2.0"

from lxml import objectify
import datetime
from optparse import OptionParser

###############################################################################
# Command line options

parser = OptionParser()
parser.add_option('-z', '--zigbee', dest='zigbeeNodeName', default='',
                  help="Output configuration for Zigbee Protocol Stack for the specified node.")
parser.add_option('-o', '--output', dest='outputDir', default=os.path.curdir,
                  help='Path to output the configuration into.')
parser.add_option('-f', '--config-file', dest='configFilename',
                  help='Configuration file')
parser.add_option('-e', '--endian', dest='endian',type="string", default='BIG_ENDIAN',
                  help='Endian of the processor BIG_ENDIAN or LITTLE_ENDIAN')

(options, args) = parser.parse_args(sys.argv[1:])

def xml_objectify(fname):
    """This removes namespace prefix from all the things in the xml and creates a fake 'root' element
    """

    tree = objectify.parse(fname)
    root = tree.getroot()
    for elem in root.getiterator():
        if not hasattr(elem.tag, 'find'):
            continue
        i = elem.tag.find('}')
        if i >= 0:
            elem.tag = elem.tag[i + 1:]

    fake_root = objectify.Element('root')
    fake_root[root.tag] = root

    return fake_root

###############################################################################
# Check for duplicate names
def checkForDuplicateNames(nodes, n1):

    if not n1.get("Name"):
        return False

    for n2 in nodes:
        if (n2 != n1) and n2.get("Name") and (n1.get("Name") == n2.get("Name")):
            return True
    return False

###############################################################################
# Validate input configuration
def validateConfiguration(configNode):
    nodeName = configNode.get("Name")
    nameCheck = re.compile("[a-zA-Z_][a-zA-Z_0-9]*")

    if hasattr(configNode, "PDUConfiguration"):
        if not configNode.PDUConfiguration.get("NumNPDUs"):
            print("ERROR: The PDU Manager for node '%s' must have a NumNPDUs attribute.\n" % nodeName)
            return False
        elif int(configNode.PDUConfiguration.get("NumNPDUs"), 0) < 8:
            print("ERROR: The PDU Manager for node '%s' must have at least 8 NPDUs configured" % nodeName)
            return False
        if not hasattr(configNode.PDUConfiguration, "APDUs"):
            print("ERROR: The PDU Manager for node '%s' does not have any APDUs.\n" % nodeName)
            return False
        else:

            for apdu in configNode.PDUConfiguration.APDUs:
                if not apdu.get("Name"):
                    print("ERROR: An APDU for node '%s' does not have a Name specified.\n" % nodeName)
                    return False
                else:
                    result = nameCheck.match(apdu.get("Name"))
                    if result.group(0) != apdu.get("Name"):
                        print("ERROR: The APDU '%s' for node '%s' is not a valid C identifier.\n" % (apdu.get("Name"), nodeName))
                        return False

                if not apdu.get("Id"):
                    print("ERROR: The APDU '%s' for node '%s' does not have an Id specified.\n" % (apdu.get("Name"), nodeName))
                    return False

                if not apdu.get("Size"):
                    print("ERROR: The APDU '%s' for node '%s' does not have a Size specified.\n" % (apdu.get("Name"), nodeName))
                    return False
                elif int(apdu.get("Size"), 0) < 1:
                    print("ERROR: The APDU '%s' for node '%s' must have a Size of at least 1.\n" % (apdu.get("Name"), nodeName))
                    return False

                if not apdu.get("Instances"):
                    print("ERROR: The APDU '%s' for node '%s' does not have a number of Instances specified.\n" % (apdu.get("Name"), nodeName))
                    return False
                elif int(apdu.get("Instances"), 0) < 1:
                    print("ERROR: The APDU '%s' for node '%s' must have a number of Instances of at least 1.\n" % (apdu.get("Name"), nodeName))
                    return False

                if checkForDuplicateNames(configNode.PDUConfiguration.APDUs, apdu):
                    print("ERROR: There are one or more APDUs with the name '%s' for node '%s'. APDUs must have unique names.\n" % (apdu.get("Name"), nodeName))
                    return False

    else:
        print("ERROR: The node '%s' must have a PDU Manager element.\n" % nodeName)
        return False

    return True


###############################################################################
# Create html files containing static text
def outputC(dir, pdumConfig, sEndian):
    fsp = os.path.join(dir, "pdum_gen.c")
    if (os.path.exists(fsp)):
        mode = os.stat(fsp).st_mode
        mode = mode | stat.S_IWUSR
        os.chmod(fsp, mode)
    Cfile = open(fsp, "w") # [I SP001273_fr 33]+

    Cfile.write("""/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         PDUMConfig
 *
 * COMPONENT:      pdum_gen.c
 *
 * DATE:           %s
 *
 * AUTHOR:         NXP PDU Manager Configuration Tool
 *
 * DESCRIPTION:    PDU definitions
 *
 ****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright %s NXP
 ****************************************************************************/

/****************************************************************************/
/***        Include files                                                 ***/
/****************************************************************************/

#include <jendefs.h>
#include <pdum_nwk.h>
#include <pdum_apl.h>

"""  % ( datetime.datetime.ctime(datetime.datetime.now()), datetime.datetime.today().year))

    Cfile.write("""
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

struct pdum_tsAPdu_tag {
    struct pdum_tsAPduInstance_tag *psAPduInstances;
    uint16 u16FreeListHeadIdx;
    uint16 u16Size;
    uint16 u16NumInstances;
};

struct pdum_tsAPduInstance_tag {
    uint8 *au8Storage;
    uint16 u16Size;
    uint16 u16NextAPduInstIdx;
    uint16 u16APduIdx;
};

typedef struct pdum_tsAPduInstance_tag pdum_tsAPduInstance;
typedef struct pdum_tsAPdu_tag pdum_tsAPdu;


/****************************************************************************/
/***        Function Prototypes                                           ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

""")

    Cfile.write("\n/* NPDU Pool */\n")
    npduPoolSize = int(pdumConfig.get("NumNPDUs"));
    Cfile.write("PRIVATE pdum_tsNPdu s_asNPduPool[%d];\n" % (npduPoolSize))

    Cfile.write("\n/* APDU Pool */\n")

    a = 0
    for apdu in pdumConfig.APDUs:
        apduSize = int(apdu.get("Size"));
        apduInstances = int(apdu.get("Instances"));
        for i in range(0, apduInstances):
            storageName = "s_au8%sInstance%dStorage" % (apdu.get("Name"), i)
            Cfile.write("PRIVATE uint8 %s[%d];\n" % (storageName, apduSize))

        Cfile.write("PUBLIC pdum_tsAPduInstance s_as%sInstances[%d] = {\n" % (apdu.get("Name"), apduInstances))
        for i in range(0, apduInstances):
            # Mark the size of the never-allocated APDU instance to illegal value, Zigbee uses up to 0x7fff
            Cfile.write("    { s_au8%sInstance%dStorage, 0xFFFF, 0, %d },\n" % (apdu.get("Name"), i, a))
        Cfile.write("};\n")
        a += 1

    Cfile.write("""
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

""")

    numAPdus = len(list(pdumConfig.APDUs))
    Cfile.write("extern pdum_tsAPdu s_asAPduPool[%d];\n" % (numAPdus))

    Cfile.write("""
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

extern void pdum_vNPduInit(pdum_tsNPdu *psNPduPool, uint16 u16Size);
extern void pdum_vAPduInit(pdum_tsAPdu *asAPduPool, uint16 u16NumAPdus);

#define PDUM_ALLOC_IDX  (0xeeee)    /* indicates APDU instance has been allocated */
PUBLIC uint16 PDUM_u16APduGetCrtUse(PDUM_thAPdu hAPdu)
{
    pdum_tsAPdu *psAPdu = (pdum_tsAPdu *)hAPdu;
    int i, c = 0;

    if (psAPdu->u16NumInstances > 0)
    {
        for (i = 0; i < psAPdu->u16NumInstances; i++)
        {
            if(psAPdu->psAPduInstances[i].u16NextAPduInstIdx == PDUM_ALLOC_IDX)
            {
                c++;
            }
        }
    }

    return c;
}

PUBLIC uint16 PDUM_u16APduGetMaxUse(PDUM_thAPdu hAPdu)
{
    pdum_tsAPdu *psAPdu = (pdum_tsAPdu *)hAPdu;
    int i, c = 0;

    if (psAPdu->u16NumInstances > 0)
    {
        for (i = psAPdu->u16NumInstances - 1; i >= 0; i--)
        {
            if (psAPdu->psAPduInstances[i].u16Size == 0xFFFF)
            {
                c++;
            }
            else
            {
                break;
            }
        }
    }

    return psAPdu->u16NumInstances - c;
}

PUBLIC void PDUM_vInit(void)
{
""")
    Cfile.write("    uint32 i;\n");
    Cfile.write("    for (i =0; i < %d; i++) { \n" %(numAPdus));
    Cfile.write("        s_asAPduPool[i].u16FreeListHeadIdx = 0;\n"  )
    Cfile.write("    }\n"  )
    Cfile.write("    pdum_vNPduInit(s_asNPduPool, %d);\n" % (npduPoolSize) )

    if hasattr(pdumConfig, "PDUMMutexName"):
        #Cfile.write("    pdum_vAPduInit(s_asAPduPool, %d, %s);\n" % (numAPdus, "NULL") )
        Cfile.write("    pdum_vAPduInit(s_asAPduPool, %d);\n" % (numAPdus) )
    else:
        Cfile.write("    pdum_vAPduInit(s_asAPduPool, %d);\n" % (numAPdus) )

    Cfile.write("""}

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/

/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
""")

    Cfile.close()
    mode = os.stat(fsp).st_mode
    mode = mode & (~stat.S_IWUSR | stat.S_IRUSR)
    os.chmod(fsp, mode)

    fsp = os.path.join(dir, "pdum_apdu.S")
    if (os.path.exists(fsp)):
        mode = os.stat(fsp).st_mode
        mode = mode | stat.S_IWUSR
        os.chmod(fsp, mode)
    Cfile = open(fsp, "w") # [I SP001273_fr 33]+

    numAPdus = len(list(pdumConfig.APDUs))

    Cfile.write("    .global s_asAPduPool\n")
    if sEndian != "BIG_ENDIAN":
        Cfile.write("    .section    .data.s_asAPduPool,\"aw\",%progbits\n")
    else:
        Cfile.write("    .section    .data.s_asAPduPool,\"aw\",@progbits\n")
    Cfile.write("    .align 4\n")
    if sEndian != "BIG_ENDIAN":
        Cfile.write("    .type    s_asAPduPool, %object\n")
    else:
        Cfile.write("    .type    s_asAPduPool, @object\n")
    Cfile.write("    .size    s_asAPduPool, %d\n" % (numAPdus * 12))
    Cfile.write("s_asAPduPool:\n")

    for apdu in pdumConfig.APDUs:
        apduSize = int(apdu.get("Size"));
        apduInstances = int(apdu.get("Instances"));

        Cfile.write("    .global pdum_%s\n" % (apdu.get("Name")))
        Cfile.write("pdum_%s:\n" % (apdu.get("Name")))
        Cfile.write("    .long    s_as%sInstances\n" % (apdu.get("Name")))
        Cfile.write("    .short    0\n")
        Cfile.write("    .short    %d\n" % (apduSize))
        Cfile.write("    .short    %d\n" % (apduInstances))
        Cfile.write("    .zero     2\n")

    Cfile.close()
    mode = os.stat(fsp).st_mode
    mode = mode & (~stat.S_IWUSR | stat.S_IRUSR)
    os.chmod(fsp, mode)

###############################################################################
# Create header file
def outputHeader(dir, pdumConfig):
    fsp = os.path.join(dir, "pdum_gen.h")
    if (os.path.exists(fsp)):
        mode = os.stat(fsp).st_mode
        mode = mode | stat.S_IWUSR
        os.chmod(fsp, mode)
    Hfile = open(fsp, "w")

    Hfile.write("""/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         PDUMConfig
 *
 * COMPONENT:      pdum_gen.h
 *
 * DATE:           %s
 *
 * AUTHOR:         NXP PDU Manager Configuration Tool
 *
 * DESCRIPTION:    PDU definitions
 *
 *****************************************************************************
 *
 * This software is owned by NXP B.V. and/or its supplier and is protected
 * under applicable copyright laws. All rights are reserved. We grant You,
 * and any third parties, a license to use this software solely and
 * exclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
 * You, and any third parties must reproduce the copyright and warranty notice
 * and any other legend of ownership on each copy or partial copy of the
 * software.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * Copyright %s NXP
 ****************************************************************************/
"""  % ( datetime.datetime.ctime(datetime.datetime.now()),  datetime.datetime.today().year))

    Hfile.write("""
#ifndef _PDUM_GEN_H
#define _PDUM_GEN_H

#include <pdum_apl.h>

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/
""")
    Hfile.write("/* APDUs */\n")
    a = 0
    for apdu in pdumConfig.APDUs:
        aPduSize = int(apdu.get("Size"));
        Hfile.write("#define %s &pdum_%s\n" % (apdu.get("Name"), apdu.get("Name")))
        a += 1

    Hfile.write("""
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

""")
    Hfile.write("/* APDUs */\n")
    a = 0
    for apdu in pdumConfig.APDUs:
        aPduSize = int(apdu.get("Size"));
        Hfile.write("extern const struct pdum_tsAPdu_tag pdum_%s;\n" % (apdu.get("Name")))
        a += 1

    Hfile.write("""
/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

PUBLIC void PDUM_vInit(void);
PUBLIC uint16 PDUM_u16APduGetMaxUse(PDUM_thAPdu hAPdu);
PUBLIC uint16 PDUM_u16APduGetCrtUse(PDUM_thAPdu hAPdu);

/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif
""")
    # [I SP001273_fr 20] end

    Hfile.close()
    mode = os.stat(fsp).st_mode
    mode = mode & (~stat.S_IWUSR | stat.S_IRUSR)
    os.chmod(fsp, mode)

###############################################################################
###############################################################################
###############################################################################

print("PDUMConfig - PDU Manager Configuration Tool v%s\n"  % (version))

if len(sys.argv) <= 1:
        print("""
\tThis software is owned by NXP B.V. and/or its supplier and is protected
\tunder applicable copyright laws. All rights are reserved. We grant You,
\tand any third parties, a license to use this software solely and
\texclusively on NXP products [NXP Microcontrollers such as JN5168, JN5179].
\tYou, and any third parties must reproduce the copyright and warranty notice
\tand any other legend of ownership on each copy or partial copy of the
\tsoftware.
\t
\tTHIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
\tAND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
\tIMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
\tARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
\tLIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
\tCONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
\tSUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
\tINTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
\tCONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
\tARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
\tPOSSIBILITY OF SUCH DAMAGE.
\t
\tCopyright %s NXP
""" % (datetime.datetime.today().year))
        print("For help: %s --help" % (sys.argv[0]))
        sys.exit(0)

if None == options.configFilename:
    print("ERROR: a configuration file must be specified.\n")
    sys.exit(-1)

if not os.path.exists(options.configFilename):
    print("ERROR: unable to open configuration file '%s'.\n" % options.configFilename)
    sys.exit(-1)

if None != options.outputDir and (not os.path.exists(options.outputDir)):
    print("ERROR: Output directory '%s' does not exist.\n" % options.outputDir)
    sys.exit(-1)

config = xml_objectify(options.configFilename)

if "" == options.zigbeeNodeName:
    print("ERROR: A node must be specified.\n" )
    sys.exit(-1)
else:
    configNode = None
    if hasattr(config.ZigbeeWirelessNetwork, "Coordinator"):
        if options.zigbeeNodeName == config.ZigbeeWirelessNetwork.Coordinator.get("Name"):
            configNode = config.ZigbeeWirelessNetwork.Coordinator

    if None == configNode:
        if hasattr(config.ZigbeeWirelessNetwork, "ChildNodes"):
            for node in config.ZigbeeWirelessNetwork.ChildNodes:
                if options.zigbeeNodeName == node.get("Name"):
                    configNode = node
                    break
            if None == configNode:
                print("ERROR: Unable to find node '%s' in input configuration file.\n" % (options.zigbeeNodeName))
                sys.exit(-1)
        else:
            print("ERROR: Unable to find node '%s' in input configuration file.\n" % (options.zigbeeNodeName))
            sys.exit(-1)

if validateConfiguration(configNode):
    outputHeader(options.outputDir, configNode.PDUConfiguration)
    outputC(options.outputDir, configNode.PDUConfiguration, options.endian)
else:
    sys.exit(1)

print("Done.\n")
