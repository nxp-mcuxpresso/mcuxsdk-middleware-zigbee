# -*- coding: utf-8 -*-
###############################################################################
#
# MODULE:      ZPS Configuration Tool
#
# COMPONENT:   ZPSConfig.py
#
# AUTHOR:      MRW
#
# DESCRIPTION: python script to generate configuration files for Zigbee Protocol
#              Stack.
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
# Copyright 2015-2024 NXP
#
###############################################################################

version = "1.5.3.0"
maxr = 0
R23_UPDATES = 0
R23_INPUTCONFIG = 0
WWAH_SUPPORT = 0

import os
import stat
import re
import sys

from lxml import objectify
import datetime
from optparse import OptionParser
import subprocess
import struct
from functools import cmp_to_key

###############################################################################
# Command line options


parser = OptionParser()
parser.add_option('-n', '--node-name', dest='zigbeeNodeName', default='',
                  help="Name of node to generate configuration for.")
parser.add_option('-t', '--target', dest='targetHardware', default='JN5139',
                  help="Target hardware platform for node")
parser.add_option('-o', '--output', dest='outputDir', default=os.path.curdir,
                  help='Path to output the configuration into.')
parser.add_option('-f', '--config-file', dest='configFilename',
                  help='Configuration file')
parser.add_option('-l', '--zigbee-nwk-lib', dest='zigbeeNwkLibFSP', default='libZPSNWK_JN513x.a',
                  help="Zigbee target software library.")
parser.add_option('-e', '--Endian', dest='endian', type="string", default='BIG_ENDIAN',
                  help="Endian of the processor.")
parser.add_option('-a', '--zigbee-apl-lib', dest='zigbeeAplLibFSP', default='libZPSAPL_JN513x.a',
                  help="Zigbee target software library.")
parser.add_option('-y', '--optional_features', action="store_true", dest='OptionalFeatures', default=False,
                  help="gets the optional features in the diagram")
parser.add_option('-c', '--compiler-tools', dest='ToolsDir', default='',
                  help="specifies a path to the compiler tools")
(options, args) = parser.parse_args(sys.argv[1:])

R23_M_ZDOServices = """
    NWK_addr_req
    IEEE_addr_req
    Node_Desc_req
    Power_Desc_req
    Simple_Desc_req
    Active_EP_req
    Match_Desc_req
    Device_annce
    Parent_annce
    System_Server_Discovery_req
    Mgmt_Lqi_req
    Mgmt_Rtg_req
    Mgmt_Bind_req
    Mgmt_Leave_req
    Mgmt_Permit_Joining_req
    Mgmt_NWK_Beacon_Survey_req
    Security_Challenge_req
    """


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
# Calculate the size of library objects.
def getLibObjSize(sObjdump, sLib, sEndian):
    oProc = subprocess.Popen([sObjdump, "-s", "-j.libobjsize", sLib], stdout=subprocess.PIPE)
    sData = oProc.communicate()[0]
    iIdx = sData.find(b'libobjsize')
    iSize = int('0x' + sData[iIdx:iIdx + 100].split()[2].decode('ascii'), 16)
    if sEndian != "BIG_ENDIAN" :
        a = struct.pack('<I',iSize)
        iSize = struct.unpack('>I',a)[0]
    return iSize

###############################################################################
# Get Server Context size
def getAplServerContextSize(sServer, sObjdump, sLib, sEndian):
    try:
        oProc = subprocess.Popen([sObjdump, "-s", "-j"+".zps_apl_Zdo" + sServer + "ContextSize", sLib], stdout=subprocess.PIPE)
        sData = oProc.communicate()[0]
        iIdx = sData.find(b"zps_apl_Zdo" + bytes(sServer, 'ascii') + b"ContextSize")
        iSize = int('0x' + sData[iIdx:iIdx + 100].split()[2].decode('ascii'), 16)
        if sEndian != "BIG_ENDIAN" :
            a = struct.pack('<I',iSize)
            iSize = struct.unpack('>I',a)[0]
        return iSize
    except:
        print("ERROR: Unable to locate '.zps_apl_Zdo%sContextSize' section in library file '%s'\n" % (sServer, sLib))
        sys.exit(10)

###############################################################################
# Calculate a channel mask value
def calculateChannelMask(channelMask):
    channelMaskValue = 0

    if "true" == channelMask.get("Channel11").lower():
        channelMaskValue |= 1<<11
    if "true" == channelMask.get("Channel12").lower():
        channelMaskValue |= 1<<12
    if "true" == channelMask.get("Channel13").lower():
        channelMaskValue |= 1<<13
    if "true" == channelMask.get("Channel14").lower():
        channelMaskValue |= 1<<14
    if "true" == channelMask.get("Channel15").lower():
        channelMaskValue |= 1<<15
    if "true" == channelMask.get("Channel16").lower():
        channelMaskValue |= 1<<16
    if "true" == channelMask.get("Channel17").lower():
        channelMaskValue |= 1<<17
    if "true" == channelMask.get("Channel18").lower():
        channelMaskValue |= 1<<18
    if "true" == channelMask.get("Channel19").lower():
        channelMaskValue |= 1<<19
    if "true" == channelMask.get("Channel20").lower():
        channelMaskValue |= 1<<20
    if "true" == channelMask.get("Channel21").lower():
        channelMaskValue |= 1<<21
    if "true" == channelMask.get("Channel22").lower():
        channelMaskValue |= 1<<22
    if "true" == channelMask.get("Channel23").lower():
        channelMaskValue |= 1<<23
    if "true" == channelMask.get("Channel24").lower():
        channelMaskValue |= 1<<24
    if "true" == channelMask.get("Channel25").lower():
        channelMaskValue |= 1<<25
    if "true" == channelMask.get("Channel26").lower():
        channelMaskValue |= 1<<26

    return channelMaskValue
###############################################################################
# Locate cluster by name
def findProfile(profileName):
    for profile in config.ZigbeeWirelessNetwork.Profiles:
        if profile.get("Name") == profileName:
            return profile

    return None

###############################################################################
# Locate cluster by name
def findCluster(clusterName):
    for profile in config.ZigbeeWirelessNetwork.Profiles:
        for cluster in profile.Clusters:
            if cluster.get("Name") == clusterName:
                return cluster

    return None

###############################################################################
# Locate apdu by node and id
def findNetworkKey(id):

    ref = id.split("->", 2)

    node = findNode(ref[0])
    keyName = "zpscfg:" + ref[1]

    if hasattr(node, "TrustCenter"):
        if hasattr(node.TrustCenter, "Keys"):
            for elem in node.TrustCenter.Keys:
                if keyName == elem.get('{' + elem.nsmap['xsi'] + '}' + 'type'):
                    return elem

    return None

###############################################################################
# Locate apdu by node and id
def networkKeyStr(keyNode):
    key = int(keyNode.Key, 0)
    keyStr = ""
    for i in range(0, 16):
        if (0 != i):
            keyStr += ", "
        keyStr += "0x%02x" % (( key & (0xff << (8 * i) )) >> (8 * i))
    return keyStr

###############################################################################
# Locate apdu by node and id
def findAPdu(node, apduId):

    if hasattr(node, "PDUConfiguration"):
        if hasattr(node.PDUConfiguration, "APDUs"):
            for apdu in node.PDUConfiguration.APDUs:
                if apdu.get("Id") == apduId:
                    return apdu

    return None

###############################################################################
# Locate node by name
def findNode(nodeName):
    node = None
    if nodeName == config.ZigbeeWirelessNetwork.Coordinator.get("Name"):
        node = config.ZigbeeWirelessNetwork.Coordinator
    else:
        # search all child nodes for named node
        if hasattr(config.ZigbeeWirelessNetwork, "ChildNodes"):
            for childNode in config.ZigbeeWirelessNetwork.ChildNodes:
                if nodeName == childNode.get("Name"):
                    node = childNode
                    break

    return node

###############################################################################
# Merge extra over node by name
def mergeNodeXtra(nodeName):
    node = None
    xtra_node = None
    if nodeName == config.ZigbeeWirelessNetwork.Coordinator.get("Name"):
        node = config.ZigbeeWirelessNetwork.Coordinator
        if nodeName == xtra.ZigbeeWirelessNetwork.Coordinator.get("Name"):
            xtra_node = xtra.ZigbeeWirelessNetwork.Coordinator
    else:
        # search all child nodes for named node
        if hasattr(config.ZigbeeWirelessNetwork, "ChildNodes"):
            for childNode in config.ZigbeeWirelessNetwork.ChildNodes:
                if nodeName == childNode.get("Name"):
                    node = childNode
                    break
        if hasattr(xtra.ZigbeeWirelessNetwork, "ChildNodes"):
            for childNode in xtra.ZigbeeWirelessNetwork.ChildNodes:
                if nodeName == childNode.get("Name"):
                    xtra_node = childNode
                    break

    if (xtra_node == None):
        return node

    # Search for node attribute and add it to the config
    for att in xtra_node.attrib:
        if node.get(att):
            if node.get(att) != xtra_node.get(att):
                print("WARNING: Found the same attribute %s with different values in both config and xtra files\n" % att)
        else:
            node.set(att, xtra_node.get(att))
            print("INFO: Added into node %s the attribute %s = %s\n" % (node.get("Name"), att, node.get(att)))

    return node

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
# Check for duplicate Ids
def checkForDuplicateIds(nodes, n1):
    for n2 in nodes:
        if (n2 != n1) and (int(n1.get("Id"), 0) == int(n2.get("Id"), 0)):
            return True
    return False

###############################################################################
# Validate input configuration
def validateConfiguration(nodeName):
    nameCheck = re.compile("[a-zA-Z_][a-zA-Z_0-9]*")

    if not hasattr(config, "ZigbeeWirelessNetwork"):
        print("ERROR: The input configuration file does not have a 'ZigbeeWirelessNetwork' element.\n")
        return False

    if config.ZigbeeWirelessNetwork.get("Version") != None:
        if config.ZigbeeWirelessNetwork.get("Version") != "1.1":
            print("ERROR: Unrecognised input file version '%s'\n" % config.ZigbeeWirelessNetwork.get('Version'))
            return False
    else:
        print("ERROR: The input file does not specify a version\n" )
        return False

    # TODO Why is this is with not, is the message wrong? Should be "file does not"
    if not config.ZigbeeWirelessNetwork.get("DefaultExtendedPANId"):
        print("WARNING: The input configuration file does contain a Default Extended PAN Id for the ZigBee PRO Wireless Network.\n")

    if not config.ZigbeeWirelessNetwork.get("MaxNumberNodes"):
        print("ERROR: The input configuration file does specify a MaxNumberNodes for the ZigBee PRO Wireless Network.\n")
    elif int(config.ZigbeeWirelessNetwork.get("MaxNumberNodes"), 0) < 2:
        print("ERROR: The 'MaxNumberNodes' attribute for a ZigBee PRO Wireless Network must be at least 2 nodes.\n")
        return False

    if not hasattr(config.ZigbeeWirelessNetwork, "Coordinator"):
        print("WARNING: The input configuration file does not contain a 'Coordinator' node.\n")

    if not hasattr(config.ZigbeeWirelessNetwork, "Profiles"):
        print("ERROR: The input configuration file does contain any Profile elements.\n")
        return False

    zdpProfileFound = False
    for p in config.ZigbeeWirelessNetwork.Profiles:
        if not p.get("Id"):
            if p.get("Name"):
                print("ERROR: Profile '%s' does not have an Id attribute." % (p.get("Name")))
            else:
                print("ERROR: A Profile element in the input configuration file does not have an Id or Name attribute.")
            return False

        profileId = int(p.get("Id"), 0)

        if not p.get("Name"):
            print("ERROR: Profile id '%d' does not have a Name attribute.\n" % (profileId))
            return False
        else:
            result = nameCheck.match(p.get("Name"))
            if result.group(0) != p.get("Name"):
                print("ERROR: Profile name '%s' is not a valid C identifier.\n" % (p.get("Name")))
                return False

        if profileId == 0:
            zdpProfileFound = True
        elif profileId > 0xFFFF or profileId < 0:
            print("ERROR: The Id of Profile '%s' must be in the range 1-65535" % (p.get("Name")))


        if checkForDuplicateNames(config.ZigbeeWirelessNetwork.Profiles, p):
            print("ERROR: There are one or more Profiles with the name '%s'. Profiles must have unique names.\n" % (p.get("Name")))
            return False

        if checkForDuplicateIds(config.ZigbeeWirelessNetwork.Profiles, p):
            print("ERROR: There are one or more Profiles with the Id '%s'. Profiles must have unique Ids.\n" % (p.get("Id")))
            return False

        if not hasattr(p, "Clusters"):
            print("ERROR: The Profile '%s' does not contain any Cluster elements.\n" % (p.get("Name")))
            return False
        else:
            for cl in p.Clusters:
                if not cl.get("Id"):
                    if cl.get("Name"):
                        print("ERROR: Cluster '%s' for Profile '%s' does not have an Id attribute." % (cl.get("Name"), p.get("Name")))
                    else:
                        print("ERROR: A Cluster for Profile '%s' does not have an Id or Name attribute." % (p.get("Name")))
                    return False

                clusterId = int(cl.get("Id"), 0)

                if not cl.get("Name"):
                    print("ERROR: Cluster Id '%d' in Profile id '%s' does not have a Name attribute.\n" % (clusterId, p.get("Name")))
                    return False
                else:
                    result = nameCheck.match(p.get("Name"))
                    if result.group(0) != p.get("Name"):
                        print("ERROR: Profile name '%s' is not a valid C identifier.\n" % (p.get("Name")))
                        return False
                if clusterId > 0xFFFF or clusterId < 0:
                    print("ERROR: The Id of Cluster '%s' for Profile '%s' must be in the range 1-65535" % (cl.get("Name"), p.get("Name")))

            if checkForDuplicateNames(p.Clusters, cl):
                print("ERROR: There are one or more Clusters with the name '%s' in Profile '%s'. Clusters must have unique names.\n" % (cl.get("Name"), p.get("Name")))
                return False

            if checkForDuplicateIds(p.Clusters, cl):
                print("ERROR: There are one or more Clusters with the Id '%s' in Profile '%s'. Clusters must have unique Ids.\n" % (cl.get("Id"), p.get("Name")))
                return False

    if not zdpProfileFound:
        print("ERROR: A ZDP Profile is not present in the input configuration file.")
        return False

    # Nodes validation
    allNodes = []
    if hasattr(config.ZigbeeWirelessNetwork, "Coordinator"):
        allNodes += config.ZigbeeWirelessNetwork.Coordinator
    if hasattr(config.ZigbeeWirelessNetwork, "ChildNodes"):
        allNodes += config.ZigbeeWirelessNetwork.ChildNodes

    for node in allNodes:
        if not node.get("Name"):
            print("ERROR: A node in the input configuration file does not have a Name attribute.\n")
            return False
        else:
            result = nameCheck.match(node.get("Name"))
            if result.group(0) != node.get("Name"):
                print("ERROR: The node named '%s' in the input configuration file is not a valid C identifier.\n" % (node.get("Name")))
                return False

        if checkForDuplicateNames(allNodes, node):
            print("ERROR: There are one or more Nodes with the name '%s'. Nodes must have unique names.\n" % (node.get("Name")))
            return False


    # Validate node we are generating configuration for
    foundNode = findNode(nodeName)

    #check if an old .zpscfg is used. Active_EP_req is deprecated in R23
    if R23_UPDATES:
        findDeprecatedCluster = foundNode.find("./Endpoints/InputClusters[@Cluster='Active_EP_req']")
        if findDeprecatedCluster != None:
            print("WARNING: R22 ZPSCONFIG IS RUNNING WITH R23 LIBS")
            print("ENSURE THAT THE NEXT SERVICES ARE ACTIVATED IN ZDO SERVER OR UPDATE THE ZPSCONFIG SCRIPT: %s" % R23_M_ZDOServices)
        else:
            global R23_INPUTCONFIG
            R23_INPUTCONFIG = 1

    if None == foundNode:
        print("ERROR: The input configuration file does not contain a node named '%s'.\n" % (nodeName))
        return False

    if not hasattr(foundNode, "Endpoints"):
        print("ERROR: The input configuration for node '%s' does not contain any 'Endpoint' elements.\n" % (nodeName))
        return False

    zdpEpFound = False
    for ep in foundNode.Endpoints:
        if not ep.get("Id"):
            if ep.get("Name"):
                print("ERROR: Endpoint '%s' for node '%s' does not have an Id attribute.\n" % (ep.get("Name"), nodeName))
            else:
                print("ERROR: An Endpoint for node '%s' does not have either an Id or Name attribute.\n" % (nodeName))
            return False

        if not ep.get("Name"):
            print("ERROR: Endpoint id '%d' for node '%s' does not have a Name attribute.\n" % (ep.get("Id"), nodeName))
            return False
        else:
            result = nameCheck.match(ep.get("Name"))
            if result.group(0) != ep.get("Name"):
                print("ERROR: Endpoint name '%s' for node '%s' is not a valid C identifier.\n" % (ep.get("Name"), nodeName))
                return False

        epId = int(ep.get("Id"), 0)
        if epId == 0:
            zdpEpFound = True
        elif epId > 240:
            if epId != 242:
                print("ERROR: Endpoint '%s' for node '%s' has an invalid id '%d'. Endpoint Ids must be in the range 1-240 or 242.\n" % (ep.get("Name"), nodeName, epId))
                return False

        if checkForDuplicateNames(foundNode.Endpoints, ep):
            print("ERROR: There are one or more Endpoints with the name '%s' for node '%s'. Endpoints must have unique names.\n" % (ep.get("Name"), node.get("Name")))
            return False

        if checkForDuplicateIds(foundNode.Endpoints, ep):
            print("ERROR: There are one or more Endpoints with the Id '%s' for node '%s'. Endpoints must have unique Ids.\n" % (ep.get("Id"), node.get("Name")))
            return False

        if not ep.get("Profile"):
            print("ERROR: Endpoint '%s' on node '%s' does not specify a Profile.\n" % (ep.get("Name"), nodeName))
            return False

        ioClusterFound = False
        if hasattr(ep, "InputClusters"):
            ioClusterFound = True
            for cl in ep.InputClusters:
                if not cl.get("Cluster"):
                    print("ERROR: An Input Cluster for endpoint '%s' on node '%s' does not specify a Cluster.\n" % (ep.get("Name"), nodeName))
                    return False
                if not cl.get("Discoverable"):
                    print("WARNING: Input cluster '%s' for endpoint '%s' on node '%s' does not have a 'Discoverable' attribute. Defaulting to discoverable.\n" % (cl.get("Cluster"), ep.get("Name"), nodeName))
                if not cl.get("RxAPDU"):
                    print("WARNING: Input cluster '%s' for endpoint '%s' on node '%s' does not specify an RxAPDU. No data can be received for this cluster.\n" % (cl.get("Cluster"), ep.get("Name"), nodeName))
                else:
                    # validate that the APDU is present on the node
                    # http://trac/Zigbee-PRO/ticket/438
                    if None == findAPdu(foundNode, cl.get("RxAPDU")):
                        print("ERROR: Unable to find APDU '%s' for input cluster '%s' for endpoint '%s' on node '%s'\n" % (cl.get("RxAPDU"), cl.get("Cluster"), ep.get("Name"), nodeName))
                        return False


        if hasattr(ep, "OutputClusters"):
            ioClusterFound = True
            for cl in ep.OutputClusters:
                if not cl.get("Cluster"):
                    print("WARNING: An Output Cluster for endpoint '%s' on node '%s' does not specify a Cluster.\n" % (ep.get("Name"), nodeName))
                    return False
                if not cl.get("Discoverable"):
                    print("WARNING: Output cluster '%s' for endpoint '%s' on node '%s' does not have a 'Discoverable' attribute. Defaulting to discoverable.\n" % (cl.get("Cluster"), ep.get("Name"), nodeName))
                if not cl.get("TxAPDUs"):
                    print("WARNING: Output cluster '%s' for endpoint '%s' on node '%s' does not specify any TxAPDUs.\n" % (cl.get("Cluster"), ep.get("Name"), nodeName))

        if not ioClusterFound:
            print("WARNING: Endpoint '%s' id %d for node '%s' does not contain any input or output clusters.\n" % (ep.get("Name"), epId, nodeName))

    if not zdpEpFound:
        print("ERROR: The input configuration for node '%s' does not contain a ZDP endpoint.\n" % (nodeName))
        return False

    if hasattr(foundNode, "BindingTable"):
        if foundNode.BindingTable.get("Size"):
            if int(foundNode.BindingTable.get("Size"), 0) < 1:
                print("ERROR: The Binding Table for node '%s' must contain at least 1 entry.\n" % (nodeName))
                return False
        else:
            print("ERROR: The Binding Table for node '%s' must specify a table size.\n" % (nodeName))
            return False

    if not R23_UPDATES and hasattr(foundNode, "UserDescriptor"):
        if foundNode.UserDescriptor.get("UserDescription"):
            if len(foundNode.UserDescriptor.get("UserDescription")) > 16:
                print("WARNING: The User Descriptor '%s' for node '%s' is longer than 16 characters and will be truncated.\n" % (foundNode.UserDescriptor.get("UserDescription"), nodeName))
            elif len(foundNode.UserDescriptor.get("UserDescription")) <= 0:
                print("ERROR: The User Descriptor for node '%s' does not specify a User Description.\n" % (nodeName))
                return False
        else:
            print("ERROR: The User Descriptor for node '%s' must specify a descriptor.\n" % (nodeName))
            return False

    if hasattr(foundNode, "PDUConfiguration"):
        if not foundNode.PDUConfiguration.get("NumNPDUs"):
            print("ERROR: The PDU Manager for node '%s' must have a NumNPDUs attribute.\n" % nodeName)
            return False
        elif int(foundNode.PDUConfiguration.get("NumNPDUs"), 0) < 8:
            print("ERROR: The PDU Manager for node '%s' must have at least 8 NPDUs configured" % nodeName)
            return False
        if not hasattr(foundNode.PDUConfiguration, "APDUs"):
            print("ERROR: The PDU Manager for node '%s' does not have any APDUs.\n" % nodeName)
            return False
    else:
        print("ERROR: The node '%s' must have a PDU Manager element.\n" % nodeName)
        return False


    if hasattr(foundNode, "GroupTable"):
        if foundNode.GroupTable.get("Size"):
            if int(foundNode.GroupTable.get("Size"), 0) < 1:
                print("ERROR: The Group Table for node '%s' must contain at least 1 entry.\n" % (nodeName))
                return False
        else:
            print("ERROR: The Group Table for node '%s' must specify a table size.\n" % (nodeName))
            return False

    if not hasattr(foundNode, "NodeDescriptor"):
        print("ERROR: A Node Descriptor must be specified for node '%s'.\n" % (nodeName))
        return False

    if not hasattr(foundNode, "NodePowerDescriptor"):
        print("ERROR: A Node Descriptor must be specified for node '%s'.\n" % (nodeName))
        return False
    else:
        if foundNode.NodePowerDescriptor.get("DefaultPowerSource"):
            if foundNode.NodePowerDescriptor.get("DefaultPowerSource").lower() == "disposable battery":
                if not foundNode.NodePowerDescriptor.get("DisposableBattery") \
                or ( \
                     foundNode.NodePowerDescriptor.get("DisposableBattery") \
                     and foundNode.NodePowerDescriptor.get("DisposableBattery").lower() == "false" \
                ):
                    print("ERROR: Default power source 'Disposable Battery' is not available in the Node Power Descriptor for node '%s'.\n" % (nodeName))
                    return False

            if foundNode.NodePowerDescriptor.get("DefaultPowerSource").lower() == "rechargeable battery":
                if not foundNode.NodePowerDescriptor.get("RechargeableBattery") \
                or ( \
                     foundNode.NodePowerDescriptor.get("RechargeableBattery") \
                     and foundNode.NodePowerDescriptor.get("RechargeableBattery").lower() == "false" \
                ):
                    print("ERROR: Default power source 'Rechargeable Battery' is not available in the Node Power Descriptor for node '%s'.\n" % (nodeName))
                    return False

            if foundNode.NodePowerDescriptor.get("DefaultPowerSource").lower() == "constant power":
                if not foundNode.NodePowerDescriptor.get("ConstantPower") \
                or ( \
                     foundNode.NodePowerDescriptor.get("ConstantPower") \
                     and foundNode.NodePowerDescriptor.get("ConstantPower").lower() == "false" \
                ):
                    print("ERROR: Default power source 'Constant Power' is not available in the Node Power Descriptor for node '%s'.\n" % (nodeName))
                    return False

    if not hasattr(foundNode, "ZDOServers"):
        print("ERROR: The node '%s' does not contain a ZDO Configuration.\n" % (nodeName))
        return False
    else:
        if not hasattr(foundNode.ZDOServers, "ZdoClient"):
            print("ERROR: The ZDO Configuration for node '%s' must contain a ZDO Client.\n" % (nodeName))
            return False
        if not hasattr(foundNode.ZDOServers, "DeviceAnnceServer"):
            print("ERROR: The ZDO Configuration for node '%s' must contain a Device Annce Server.\n" % (nodeName))
            return False
        if not hasattr(foundNode.ZDOServers, "ActiveEpServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a ActiveEpServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "NwkAddrServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a NwkAddrServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "IeeeAddrServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a IeeeAddrServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "SystemServerDiscoveryServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a SystemServerDiscoveryServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "NodeDescServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a NodeDescServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "PowerDescServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a PowerDescServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "MatchDescServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a MatchDescServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "SimpleDescServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a SimpleDescServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "MgmtLqiServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a MgmtLqiServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "MgmtLeaveServer") and "Coordinator" != foundNode.tag:
            print("WARNING: The ZDO Configuration for node '%s' should contain a MgmtLeaveServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not hasattr(foundNode.ZDOServers, "MgmtNWKUpdateServer"):
            print("WARNING: The ZDO Configuration for node '%s' should contain a MgmtNWKUpdateServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if "Coordinator" == foundNode.tag or ("ChildNodes" == foundNode.tag and "zpscfg:Router" == foundNode.get('{' + foundNode.nsmap["xsi"] + '}' + "type")):
            if not hasattr(foundNode.ZDOServers, "PermitJoiningServer"):
                print("WARNING: The ZDO Configuration for node '%s' should contain a PermitJoiningServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
            if not hasattr(foundNode.ZDOServers, "MgmtRtgServer"):
                print("WARNING: The ZDO Configuration for node '%s' should contain a MgmtRtgServer to meet the requirements for a ZigBee Compliant Platform (ZCP). \n" % (nodeName))
        if not R23_UPDATES and hasattr(foundNode.ZDOServers, "SecurityServer"):
            print("WARNING: The R22 ZDO Configuration for node '%s' ignores the configuration of a SecurityServer from a newer specification.\n" % (nodeName))
            delattr(foundNode.ZDOServers, "SecurityServer")
        elif R23_UPDATES and not hasattr(foundNode.ZDOServers, "SecurityServer"):
            # Inherit the DefaultServer for inserting the missing SecurityServer
            setattr(foundNode.ZDOServers, "SecurityServer", foundNode.ZDOServers.DefaultServer)
            # Add other specific attributes, to be changed as the server is developed
            # E.g. foundNode.ZDOServers.SecurityServer.attrib['TimeoutSecurity'] = '123'
            if R23_INPUTCONFIG:
                print("WARNING: The R23 ZDO Configuration for node '%s' lacks the user specific configuration of a SecurityServer, applying the default.\n" % (nodeName))
            else:
                print("WARNING: The R22 ZDO Configuration for node '%s' lacks the user specific configuration of a SecurityServer, applying the default.\n" % (nodeName))

    # check

    # Node attributes ...
    dns = int(foundNode.get("MacTableSize"), 0)

    if foundNode.get("MaxNumSimultaneousApsdeAckReq") and int(foundNode.get("MaxNumSimultaneousApsdeAckReq"), 0) == 0:
        print("WARNING: No Apsde requests with acknowledgements may be made because MaxNumSimultaneousApsdeAckReq is set to 0.\n")
    if not foundNode.get("MaxNumSimultaneousApsdeReq"):
        print("ERROR: No Apsde requests with acknowledgements may be made because MaxNumSimultaneousApsdeAckReq is set to 0.\n")
        return False
    elif int(foundNode.get("MaxNumSimultaneousApsdeReq"), 0) < 1:
        print("ERROR: MaxNumSimultaneousApsdeReq must be at least 1 or node '%s'.\n" % (nodeName))
        return False

    if not foundNode.get("DefaultCallbackName"):
        print("ERROR: DefaultCallbackName is not set for node '%s'\n" %(nodeName))
        return False
    else:
        result = nameCheck.match(foundNode.get("DefaultCallbackName"))
        if result.group(0) != foundNode.get("DefaultCallbackName"):
            print("ERROR: DefaultCallbackName is not a valid C identifier for node '%s'\n" %(nodeName))
            return False

#    FragmentationMaxNumSimulRx="0"
#    FragmentationMaxNumSimulTx="0"

    if "Coordinator" == foundNode.tag:
        if foundNode.get("apsDesignatedCoordinator").lower() != "true":
            print("ERROR: apsDesignatedCoordinator must be set to true for Coordinator node '%s'\n" % (nodeName))
            return False

    if not foundNode.get("apsMaxWindowSize"):
        print("ERROR: apsMaxWindowSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        val = int(foundNode.get("apsMaxWindowSize"), 0)
        if val < 1 or val > 8:
            print("ERROR: apsMaxWindowSize must be in the range 1-8 for node '%s'\n" %(nodeName))
            return False

    if not foundNode.get("apsInterframeDelay"):
        print("ERROR: apsInterframeDelay is not set for node '%s'\n" %(nodeName))
        return False
    else:
        val = int(foundNode.get("apsInterframeDelay"), 0)
        if val < 10 or val > 255:
            print("ERROR: apsInterframeDelay must be in the range 10-255 for node '%s'\n" %(nodeName))
            return False

    if not foundNode.get("APSDuplicateTableSize"):
        print("ERROR: APSDuplicateTableSize is not set for node '%s'\n" %(nodeName))
        return False
    elif int(foundNode.get("APSDuplicateTableSize"), 0) < 1:
        print("ERROR: APSDuplicateTableSize must be at least 1 for node '%s'\n" %(nodeName))
        return False

    if not foundNode.get("apsSecurityTimeoutPeriod"):
        print("ERROR: apsSecurityTimeoutPeriod is not set for node '%s'\n" %(nodeName))
        return False
    elif int(foundNode.get("apsSecurityTimeoutPeriod"), 0) < 1000:
        print("ERROR: apsSecurityTimeoutPeriod must be at least 1000 ms for node '%s'\n" %(nodeName))
        return False

    if not foundNode.get("apsUseExtPANId"):
        print("ERROR: apsUseExtPANId is not set for node '%s'\n" %(nodeName))
        return False
    else:
        use_epid = int(foundNode.get("apsUseExtPANId"), 0)
        default_epid = int(config.ZigbeeWirelessNetwork.get("DefaultExtendedPANId"), 0)
        if 0 != use_epid and use_epid != default_epid:
            print("WARNING: apsUseExtPANId for node '%s' does not match the DefaultExtenededPANId setting of the ZigBee Wireless Network.\n" %(nodeName))

    if not R23_UPDATES:
        if not foundNode.get("apsNonMemberRadius"):
            print("ERROR: apsNonMemberRadius is not set for node '%s'\n" %(nodeName))
            return False
        else:
            nmr = int(foundNode.get("apsNonMemberRadius"), 0)
            if nmr < 0 or nmr > 7:
                print("ERROR: apsNonMemberRadius for node '%s' must be in the range 0-7.\n" %(nodeName))
                return False

    if "Coordinator" == foundNode.tag or ("ChildNodes" == foundNode.tag and "zpscfg:Router" == foundNode.get('{' + foundNode.nsmap["xsi"] + '}' + "type")):
        if not foundNode.get("PermitJoiningTime"):
            print("ERROR: PermitJoiningTime is not set for node '%s'\n" %(nodeName))
            return False
        else:
            pjt = int(foundNode.get("PermitJoiningTime"), 0)
            if pjt < 0 or pjt > 255:
                print("ERROR: PermitJoiningTime for node '%s' must be in the range 0-255.\n" %(nodeName))
                return False

    if not foundNode.get("SecurityEnabled"):
        print("ERROR: SecurityEnabled is not set for node '%s'\n" %(nodeName))
        return False
    else:
        if foundNode.get("SecurityEnabled").lower() != config.ZigbeeWirelessNetwork.get("DefaultSecurityEnabled").lower():
            print("WARNING: SecurityEnabled for node '%s' does not match the DefaultSecurityEnabled setting for the ZigBeeWirelessNetwork.\n" %(nodeName))

    if not foundNode.get("AddressMapTableSize"):
        print("ERROR: AddressMapTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        amts = int(foundNode.get("AddressMapTableSize"), 0)
        if amts > dns:
            print("ERROR: The AddressMapTableSize for node '%s' is greater then the MacTable setting for the ZigBeeWirelessNetwork.\n" %(nodeName))
            return False

    if not foundNode.get("ActiveNeighbourTableSize"):
        print("ERROR: ActiveNeighbourTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        ants = int(foundNode.get("ActiveNeighbourTableSize"), 0)
        amts = int(foundNode.get("AddressMapTableSize"), 0)
        if ants > dns:
            print("ERROR: The ActiveNeighbourTableSize for node '%s' is greater then the MacTable setting for the ZigBeeWirelessNetwork.\n" %(nodeName))
            return False
        elif ants < 1:
            print("ERROR: The ActiveNeighbourTableSize for node '%s' must be at least 1.\n" %(nodeName))
            return False

    if (foundNode.tag == "Coordinator") or (foundNode.tag == "ChildNodes" and "zpscfg:EndDevice" != foundNode.get('{' + foundNode.nsmap["xsi"] + '}' + "type")):
        if not foundNode.get("ChildTableSize"):
            print("ERROR: ChildTableSize is not set for node '%s'\n" %(nodeName))
            return False
        else:
            cts = int(foundNode.get("ChildTableSize"), 0)
            ants = int(foundNode.get("ActiveNeighbourTableSize"), 0)
            if cts > ants:
                print("ERROR: The ChildTableSize for node '%s' is greater then the ActiveNeighbourTableSize setting for the ZigBeeWirelessNetwork.\n" %(nodeName))
                return False
            elif cts < 1:
                print("ERROR: The ChildTableSize for node '%s' must be at least 1.\n" %(nodeName))
                return False

        global maxr
        if not foundNode.get("MaxRouters"):
            print("INFO: MaxRouters is not set for node '%s' and will be set to ChildTableSize %s\n" %(nodeName, cts))
            maxr = cts
        else:
            maxr = int(foundNode.get("MaxRouters"), 0)
        if maxr < 0:
            print("ERROR: The MaxRouters for node '%s' must be at least 0.\n" %(nodeName))
            return False
        else:
            cts = int(foundNode.get("ChildTableSize"), 0)
            if maxr > cts:
                print("ERROR: The MaxRouters for node '%s' is greater then the ChildTableSize setting for the ZigBeeWirelessNetwork.\n" %(nodeName))
                return False

    if not foundNode.get("DiscoveryNeighbourTableSize"):
        print("ERROR: DiscoveryNeighbourTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        dnts = int(foundNode.get("DiscoveryNeighbourTableSize"), 0)
        if dnts < 1:
            print("ERROR: The DiscoveryNeighbourTableSize for node '%s' must be at least 1.\n" %(nodeName))
            return False

    if not foundNode.get("RouteDiscoveryTableSize"):
        print("ERROR: RouteDiscoveryTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        rdts = int(foundNode.get("RouteDiscoveryTableSize"), 0)
        if rdts < 1:
            print("ERROR: The RouteDiscoveryTableSize for node '%s' must be at least 1.\n" %(nodeName))
            return False

    if not foundNode.get("RoutingTableSize"):
        print("ERROR: RoutingTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        rts = int(foundNode.get("RoutingTableSize"), 0)
        if rts < 1:
            print("ERROR: The RoutingTableSize for node '%s' must be at least 1.\n" %(nodeName))
            return False

    if not foundNode.get("BroadcastTransactionTableSize"):
        print("ERROR: BroadcastTransactionTableSize is not set for node '%s'\n" %(nodeName))
        return False

    if not foundNode.get("RouteRecordTableSize"):
        print("ERROR: RouteRecordTableSize is not set for node '%s'\n" %(nodeName))
        return False
    else:
        rrts = int(foundNode.get("RouteRecordTableSize"), 0)
        if rrts < 1:
            print("ERROR: The RouteRecordTableSize for node '%s' must be at least 1.\n" %(nodeName))
            return False

    if foundNode.get("SecurityEnabled").lower() == "true":
        if not foundNode.get("SecurityMaterialSets"):
            print("ERROR: SecurityMaterialSets is not set for node '%s' with SecurityEnabled set to true.\n" %(nodeName))
            return False
        elif int(foundNode.get("SecurityMaterialSets"), 0) < 1:
            print("ERROR: SecurityMaterialSets must be at least 1 for node '%s' with SecurityEnabled set to true.\n" %(nodeName))
            return False

    return True

    if foundNode.get("Sleeping"):
        if foundNode.get("Sleeping").lower() == "true":
            if not foundNode.get("APSPollPeriod"):
                print("ERROR: APSPollPeriod is not set for node '%s'\n" %(nodeName))
                return False
            else:
                # TODO I think this is wrong is a different name from what is verified
                ftpp = int(foundNode.get("APSAckPollPeriod"), 0)
                if ftpp < 25:
                    print("ERROR: The APSPollPeriod for node '%s' must be at least 25ms.\n" %(nodeName))
                    return False

            if not foundNode.get("NumPollFailuresBeforeRejoin"):
                print("ERROR: NumPollFailuresBeforeRejoin is not set for node '%s'\n" %(nodeName))
                return False
            else:
                npfbr = int(foundNode.get("NumPollFailuresBeforeRejoin"), 0)
                if npfbr == 0:
                    print("WARNING: The NumPollFailuresBeforeRejoin for node '%s' is set to 0. The node will not rejoin if its parent is lost.\n" %(nodeName))

            if foundNode.get("ScanDuration"):
                sd = int(foundNode.get("ScanDuration"), 0)
                if sd < 2 or sd > 5:
                    print("ERROR: The ScanDuration for node '%s' must be in the range 2-5\n" %(nodeName))
                    return False

###############################################################################
# Create html files containing static text
def outputC(dir, configNode, sEndian):
    fsp = os.path.join(dir, "zps_gen.c")
    if (os.path.exists(fsp)):
        mode = os.stat(fsp).st_mode
        mode = mode | stat.S_IWUSR
        os.chmod(fsp, mode)
    Cfile = open(fsp, "w") # [I SP001273_fr 33]

    Cfile.write("""/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         ZPSConfig %s
 *
 * COMPONENT:      zps_gen.c
 *
 * DATE:           %s
 *
 * AUTHOR:         NXP Zigbee Protocol Stack Configuration Tool
 *
 * DESCRIPTION:    ZPS definitions
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
#include <pdum_gen.h>
#include "ZQueue.h"
#include <zps_gen.h>

#include "zps_apl.h"
#include "zps_apl_aib.h"
#include "zps_apl_af.h"

"""  % (version, datetime.datetime.ctime(datetime.datetime.now()), datetime.datetime.today().year))

    Cfile.write("""
/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

#define COMPILE_TIME_ASSERT(pred)    switch(0){case 0:case pred:;}


#define ZPS_APL_ZDO_VSOUI_LENGTH		3
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/*** ZDP Context **************************************************/

typedef struct {
    uint8 u8ZdpSeqNum;
} zps_tsZdpContext;

/*** ZDO Context **************************************************/

typedef bool (*zps_tprAplZdoServer)(void *pvApl, void *pvServerContext, ZPS_tsAfEvent *psZdoServerEvent);

typedef struct {
    zps_tprAplZdoServer prServer;
    void *pvServerContext;
} zps_tsAplZdoServer;

typedef struct
{
    uint8               au8Key[ZPS_NWK_KEY_LENGTH];
    uint8               u8KeySeqNum;
    uint8               u8KeyType;
} zps_tsAplZdoInitSecKey;

typedef struct {
    uint64 u64InitiatorAddr;
    uint64 u64ResponderAddr;
    ZPS_tsTsvTimer sTimer;
""")
    if R23_UPDATES:
        Cfile.write("    CRYPTO_ecdhPublicKey_t  sPublicKey; /* DLK */\n")
        Cfile.write("    CRYPTO_ecdhPrivateKey_t sSecretKey; /* DLK */\n")
        Cfile.write("    uint8 au8Key[ZPS_NWK_KEY_LENGTH];\n")
    else:
        Cfile.write("    uint8 au8Key[ZPS_NWK_KEY_LENGTH];")
    Cfile.write("""
} zps_tsRequestKeyRequests;


typedef struct {
    uint8 au8VsOUIBytes[ZPS_APL_ZDO_VSOUI_LENGTH];
    uint8 eNetworkState; /* ZPS_teZdoNetworkState */
    uint8 eZdoDeviceType; /* ZPS_teZdoDeviceType */
    uint8 eNwkKeyState; /* ZPS_teZdoNwkKeyState */
    uint8 u8PermitJoinTime;
    uint8 u8StackProfile;
    uint8 u8ZigbeeVersion;
    uint8 u8ScanDuration;
    bool_t bLookupTCAddr;
    const zps_tsAplZdoServer *psZdoServers;
    void (*prvZdoServersInit)(void);
    ZPS_tsTsvTimer sAuthenticationTimer;
    ZPS_tsTsvTimer sAuthenticationPollTimer;
    uint8 u8NumPollFailures;
    uint8 u8MaxNumPollFailures;
    bool_t bSecurityDisabled;
    zps_tsAplZdoInitSecKey *psInitSecKey;
    uint8 u8DevicePermissions;
    bool_t (*prvZdoReqFilter)(uint16);
    bool (*pfzps_bAplZdoBindRequestServer)(void *,
            void *,
            ZPS_tsAfEvent *);
    zps_tsRequestKeyRequests *psRequestKeyReqs;
    uint32 u32ReqKeyTimeout;
    uint8 u8MaxNumSimulRequestKeyReqs;
} zps_tsZdoContext;

/**** Context for the ZDO servers data confirms and acks***********/

typedef struct {
    uint8 eState;
    uint8 u8SeqNum;
    uint8 u8ConfAck;
} zps_tsZdoServerConfAckContext;

/*** Trust Center Context *****************************************/

typedef struct
{
    uint16 u16AddrLkup;
    ZPS_teDevicePermissions eDevPermissions;
} zps_tsAplTCDeviceTable;

typedef struct
{
    zps_tsAplTCDeviceTable *asTCDeviceTable;
    uint16  u16SizeOfTCDeviceTable;
} zps_tsAplTCib;


typedef struct
{
    void (*prvTrustCenterInit)(void*);
""")
    if R23_UPDATES:
        Cfile.write("    void (*prvTrustCenterUpdateDevice)(void*, uint64, uint64, uint8, uint16, uint16);")
    else:
        Cfile.write("    void (*prvTrustCenterUpdateDevice)(void*, uint64, uint64, uint8, uint16);")
    Cfile.write("""
    void (*prvTrustCenterRequestKey)(void*, uint64, uint8, uint64);
    zps_tsAplTCib sTCib;
    bool_t bTcOverride;
    bool_t bChangeOverride;
} zps_tsTrustCenterContext;

/*** AF Context ***************************************************/

typedef struct zps_tsAplAfDynamicContext zps_tsAplAfDynamicContext;

typedef struct _zps_tsAplAfSimpleDescCont
{
    ZPS_tsAplAfSimpleDescriptor sSimpleDesc;
    const PDUM_thAPdu *phAPduInClusters;
    bool_t bEnabled;
} zps_tsAplAfSimpleDescCont;

typedef struct {
    zps_tsAplAfDynamicContext *psDynamicContext;
    ZPS_tsAplAfNodeDescriptor *psNodeDescriptor;
    ZPS_tsAplAfNodePowerDescriptor *psNodePowerDescriptor;
    uint32 u32NumSimpleDescriptors;
    zps_tsAplAfSimpleDescCont *psSimpleDescConts;
    """)
    if R23_UPDATES == 0:
        Cfile.write("""
    ZPS_tsAplAfUserDescriptor *psUserDescriptor;
    """)
    Cfile.write("""
    void* hOverrunMsg;   
    uint8 zcp_u8FragApsAckValue;
    uint8 zcp_u8FragBlockControl;
} zps_tsAfContext;

/*** APS Context **************************************************/

typedef struct
{
    uint8 u8Type;
    uint8 u8ParamLength;
} ZPS_tsAplApsmeDcfmIndHdr;

typedef struct
{
    uint8 u8Type;
    uint8 u8ParamLength;
} ZPS_tsAplApsdeDcfmIndHdr;

typedef struct {
    ZPS_tuAddress uDstAddr;
    """)
    if R23_UPDATES:
        Cfile.write("""
    ZPS_tuAddress uTnlDstAddr;
    """)
    Cfile.write("""
    PDUM_thAPduInstance hAPduInst;
    uint8 *pu8SeqCounter;
    uint16 u16ProfileId;
    uint16 u16ClusterId;
    uint8 u8DstEndpoint;
    uint8 u8SrcEndpoint;
    uint8 u8Radius;
    uint8 eDstAddrMode;
    uint8 eTxOptions;
} ZPS_tsAplApsdeReqData;

typedef union
{
    ZPS_tsAplApsdeReqData  sReqData;
} ZPS_tuAplApsdeReqRspParam;

typedef struct
{
    uint8                 u8Type;
    uint8                 u8ParamLength;
    uint16                u16Pad;
    ZPS_tuAplApsdeReqRspParam uParam;
} ZPS_tsAplApsdeReqRsp;

typedef struct
{
    struct {
        uint32 u6Reserved       : 6;
        uint32 u2Fragmentation  : 2;
        uint32 u24Padding       : 24;
    } sEFC;
    uint8 u8BlockNum;
    uint8 u8Ack;
} zps_tsExtendedFrameControlField;

typedef union {
    struct {
        uint8   u8DstEndpoint;
        uint16  u16ClusterId;
        uint16  u16ProfileId;
        uint8   u8SrcEndpoint;
        uint8   u8ApsCounter;
    } sUnicast;

    struct {
            uint16  u16GroupAddr;
            uint16  u16ClusterId;
            uint16  u16ProfileId;
            uint8   u8SrcEndpoint;
            uint8   u8ApsCounter;
        } sGroup;
} zps_tuApsAddressingField;

typedef struct {
    uint16    *psDuplicateTableSrcAddr;
    uint32    *psDuplicateTableHash;
    uint8     *psDuplicateTableApsCnt;
    uint32    *psDuplicateTableIncomingFrameCounter;
    uint8     u8TableIndex;
} zps_tsApsDuplicateTable;

typedef struct zps_tsMsgRecord_tag {
    struct zps_tsMsgRecord_tag *psNext;
    ZPS_tsAplApsdeReqRsp sApsdeReqRsp;
    ZPS_tsTsvTimer sAckTimer;       /* ack timer */
    uint8       u8ReTryCnt;
    uint8       u8ApsCount;
} zps_tsMsgRecord;

typedef struct zps_tsDcfmRecord_tag{
    union {
        uint16 u16DstAddr;
        uint64 u64DstAddr;
    };
    uint8   u8Handle;
    uint8   u8SrcEp;
    uint8   u8DstEp;
    uint8   u8DstAddrMode;
    uint8   u8SeqNum;
} zps_tsDcfmRecord;

typedef struct zps_tsDcfmRecordPool_tag{
    zps_tsDcfmRecord *psDcfmRecords;
    uint8 u8NextHandle;
    uint8 u8NumRecords;
} zps_tsDcfmRecordPool;

typedef struct zps_tsFragmentTransmit_tag {
    enum {
        ZPS_FRAG_TX_STATE_IDLE,
        ZPS_FRAG_TX_STATE_SENDING,
        ZPS_FRAG_TX_STATE_RESENDING,
        ZPS_FRAG_TX_STATE_WAIT_FOR_ACK
    }eState;
    PDUM_thAPduInstance hAPduInst;
    uint16  u16DstAddress;
    uint16  u16ProfileId;
    uint16  u16ClusterId;
    uint8   u8DstEndpoint;
    uint8   u8SrcEndpoint;
    uint8   u8Radius;
    uint8   u8SeqNum;

    ZPS_tsTsvTimer sAckTimer;
    uint8   u8CurrentBlock;
    uint8   u8SentBlocksInWindow;
    uint8   u8MinBlockNumber;
    uint8   u8MaxBlockNumber;
    uint8   u8TotalBlocksToSend;
    uint8   u8RetryCount;
    uint8   u8AckedBlocksInWindow;
    uint8   u8WindowSize;
    uint8   u8BlockSize;
    bool_t  bSecure;
} zps_tsFragmentTransmit;

typedef struct zps_tsfragTxPool_tag {
    zps_tsFragmentTransmit *psFragTxRecords;
    uint8   u8NumRecords;
} zps_tsFragTxPool;

typedef struct zps_tsFragmentReceive_tag {
    enum {
        ZPS_FRAG_RX_STATE_IDLE,
        ZPS_FRAG_RX_STATE_RECEIVING,
        ZPS_FRAG_RX_STATE_PERSISTING
    }eState;
    PDUM_thAPduInstance hAPduInst;
    uint16  u16SrcAddress;
    uint16  u16ProfileId;
    uint16  u16ClusterId;
    uint8   u8DstEndpoint;
    uint8   u8SrcEndpoint;
    uint8   u8SeqNum;

    ZPS_tsTsvTimer  sWindowTimer;
    PDUM_thNPdu     hNPduPrevious;
    uint16  u16ReceivedBytes;
    uint8   u8TotalBlocksToReceive;
    uint8   u8ReceivedBlocksInWindow;
    uint8   u8MinBlockNumber;
    uint8   u8MaxBlockNumber;
    uint8   u8HighestUnAckedBlock;
    uint8   u8WindowSize;
    uint8   u8BlockSize;
    uint8   u8PreviousBlock;
} zps_tsFragmentReceive;

typedef struct zps_tsfragRxPool_tag {
    zps_tsFragmentReceive *psFragRxRecords;
    uint8   u8NumRecords;
    uint8   u8PersistanceTime;
} zps_tsFragRxPool;

typedef struct zps_tsApsPollTimer {
    ZPS_tsTsvTimer sPollTimer;
    uint16 u16PollInterval;
    uint8 u8PollActive;
} zps_tsApsPollTimer;

typedef struct zps_tsApsmeCmdContainer {
    struct zps_tsApsmeCmdContainer *psNext; /* must be first element of struct */
    ZPS_tsNwkNldeReqRsp sNldeReqRsp;
    ZPS_tsTsvTimer sTimer;
    PDUM_thNPdu hNPduCopy;
    uint8 u8Retries;
} zps_tsApsmeCmdContainer;

""")
    if R23_UPDATES:
        Cfile.write("""
typedef struct zps_tsPostponedTxFrag{
    ZPS_tsAplApsdeReqRsp sApsdeReqRsp;
    uint16 u16APduInstSize;
    uint8 u8MaxPayloadSize;
} zps_tsPostponedTxFrag;
""")
    Cfile.write("""

typedef struct {
    zps_tsApsmeCmdContainer *psFreeList;
    zps_tsApsmeCmdContainer *psSubmittedList;
} zps_tsApsmeCmdMgr;

typedef struct {
    void* pvParam;
    ZPS_tsAplApsdeDcfmIndHdr *psApsdeDcfmIndHdr;
}zps_tsLoopbackDataContext;

typedef struct {
    /* APSDE */
    void *pvParam;
    ZPS_tsAplApsdeDcfmIndHdr *(*prpsGetApsdeBuf)(void *);
    void (*prvPostApsdeDcfmInd)(void *, ZPS_tsAplApsdeDcfmIndHdr *);
    /* APSME */
    void *pvApsmeParam;
    ZPS_tsAplApsmeDcfmIndHdr *(*prpsGetApsmeBuf)(void *);
    void (*prvPostApsmeDcfmInd)(void *, ZPS_tsAplApsmeDcfmIndHdr *);

    zps_tsApsDuplicateTable *psApsDuplicateTable;
    zps_tsMsgRecord  *psSyncMsgPool;
    uint8 u8ApsDuplicateTableSize;
    uint8 u8SeqNum;
    uint8 u8SyncMsgPoolSize;
    uint8 u8MaxFragBlockSize;
    zps_tsDcfmRecordPool sDcfmRecordPool;
    ZPS_tsApsCounters *psApsCounters;

    zps_tsFragRxPool sFragRxPool;
    zps_tsFragTxPool sFragTxPool;
    ZPS_teStatus (*preStartFragmentTransmission)(void *, ZPS_tsAplApsdeReqRsp *, uint16, uint8);
    void (*prvHandleExtendedDataAck)(void *, ZPS_tsNwkNldeDcfmInd *, zps_tuApsAddressingField *, zps_tsExtendedFrameControlField *);
    void (*prvHandleDataFragmentReceive)(void *, ZPS_tsAplApsdeDcfmIndHdr *);
""")
    if R23_UPDATES:
        Cfile.write("""
    zps_tsPostponedTxFrag sFragPostponedTx;
    bool bWaitForFragInfo;
""")
    Cfile.write("""
    zps_tsApsmeCmdMgr sApsmeCmdMgr;
    zps_tsApsPollTimer sApsPollTimer;
    zps_tsLoopbackDataContext sLoopbackContext;
    ZPS_tsTsvTimer sLoopbackTimer;
} zps_tsApsContext;

/*** APL Context **************************************************/

typedef struct {
    void *pvNwk;
    const void *pvNwkTableSizes;
    const void *pvNwkTables;
    
    ZPS_tsNwkNib *psNib;
    ZPS_tsAplAib *psAib;
    
    void* hZpsMutex;
    void* hDefaultStackEventMsg;
    void* hMcpsDcfmIndMsg;
    void* hMlmeDcfmIndMsg;
    void* hTimeEventMsg;
    void* hMcpsDcfmMsg;
    /* sub-layer contexts */
    zps_tsZdpContext sZdpContext;
    zps_tsZdoContext sZdoContext;
    zps_tsAfContext  sAfContext;
    zps_tsApsContext sApsContext;

    /* trust center context if present */
    zps_tsTrustCenterContext *psTrustCenterContext;
""")
    if R23_UPDATES:
        Cfile.write("""
    /* TLV context for functions that need it */
    uint8   u8TlvContextSize;
    void   *psTlvContextTlvs;
""")
    Cfile.write("""
} zps_tsApl;

/*** NIB Defaults **************************************************/

typedef struct
{
    uint32 u32VsOldRouteExpiryTime;
    uint8  u8MaxRouters;
    uint8  u8MaxChildren;
    uint8  u8MaxDepth;
    uint8  u8PassiveAckTimeout;
    uint8  u8MaxBroadcastRetries;
    uint8  u8MaxSourceRoute;
    uint8  u8NetworkBroadcastDeliveryTime;
    uint8  u8UniqueAddr;
    uint8  u8AddrAlloc;
    uint8  u8UseTreeRouting;
    uint8  u8SymLink;
""")
    if R23_UPDATES == 0:
        Cfile.write("""
    uint8  u8UseMulticast;
""")
    if R23_UPDATES:
        Cfile.write("""
    uint8  u8GoodParentLqa;
""")
    Cfile.write("""
    uint8  u8LinkStatusPeriod;
    uint8  u8RouterAgeLimit;
    uint8  u8RouteDiscoveryRetriesPermitted;
    uint8  u8VsFormEdThreshold;
    uint8  u8SecurityLevel;
    uint8  u8AllFresh;
    uint8  u8SecureAllFrames;
    uint8  u8VsTxFailThreshold;
    uint8  u8VsMaxOutgoingCost;
    uint8  u8VsLeaveRejoin;
    uint8  u8ZedTimeout;
    uint8  u8ZedTimeoutDefault;""")
    if R23_UPDATES:
        Cfile.write("""
    uint8  u8MaxInitialJoinParentAttempts;
    uint8  u8MaxRejoinParentAttempts;""")
    Cfile.write("""
    uint16 u16VerifyLinkCostTransmitRate;""")
    if R23_UPDATES or WWAH_SUPPORT:
        Cfile.write("""
    uint16 u16NextPanId;""")
    Cfile.write("""
} zps_tsNwkNibInitialValues;


/****************************************************************************/
/***        External Dependencies                                         ***/
/****************************************************************************/

PUBLIC ZPS_teStatus zps_eStartFragmentedTransmission(void *, ZPS_tsAplApsdeReqRsp *, uint16 , uint8);
PUBLIC void zps_vHandleExtendedDataAckFrame(void *, ZPS_tsNwkNldeDcfmInd *, zps_tuApsAddressingField *, zps_tsExtendedFrameControlField * );
PUBLIC void zps_vHandleApsdeDataFragIndNotSupported(void *pvApl, ZPS_tsAplApsdeDcfmIndHdr *);
PUBLIC void zps_vHandleApsdeDataFragInd(void *, ZPS_tsAplApsdeDcfmIndHdr *psApsdeDcfmInd);
bool_t g_pbZpsMutex = FALSE;
PUBLIC void* zps_vGetZpsMutex(void);
extern PUBLIC bool_t APP_bMultimaskJoinCallBack(void *);
""")


    myfoundNode = findNode(options.zigbeeNodeName)

    if None == myfoundNode:
        print("ERROR: The input configuration file does not contain a node named '%s'.\n" % (myfoundNode.get("Name")))
        return False
    if not hasattr(myfoundNode, "Endpoints"):
        print("ERROR: The input configuration for node '%s' does not contain any 'Endpoint' elements.\n" % (myfoundNode.get("Name")))
        return False
    EpTotal = 0 
    for ep in myfoundNode.Endpoints:
        epId = int(ep.get("Id"), 0)
        if epId > 0:
            EpTotal += 1

    # MAC interface table
    MacInterfaceCount = 0
    channelMaskListCount = 0
    ChannelOffset = 0

    if hasattr(configNode, "ChannelMask"):
        channelMask = calculateChannelMask(configNode.ChannelMask)

        if 0 == channelMask:
            channelMask = 0x007fff800
    else:
        channelMask = 0x007fff800

    SetMaskForIndex0 = 0
    if hasattr(configNode, "MacInterfaceList"):
        for interface in configNode.MacInterfaceList.MacInterface:
            if interface.get("RadioType") == "RT2400MHz" :
                SetMaskForIndex0 = 1

    if hasattr(configNode, "MacInterfaceList"):
        for interface in configNode.MacInterfaceList.MacInterface:
            MacInterfaceCount += 1
            channelMaskListCount += int(interface.get("ChannelListSize"))

    if channelMaskListCount > 15:
        print("channelMaskList count in the mac interface should be less than 15")
        return

    if hasattr(configNode, "MacInterfaceList"):
        for interface in configNode.MacInterfaceList.MacInterface:
            indexTocheck = int(interface.get("index"))
            countIndex = 0
            for interface in configNode.MacInterfaceList.MacInterface:
                if indexTocheck == interface.get("index"):
                    countIndex += 1
                if countIndex > 1:
                    print("ERROR: MAC interfaces should have unique index.\n")

    if MacInterfaceCount > 2:
        print("ERROR: Only two interfaces supported. You have set %d\n" %(MacInterfaceCount))

    if MacInterfaceCount > 0 :
        Cfile.write("PRIVATE  bool_t    g_bIgnoreBroadcast [ %d ] =  {" %(MacInterfaceCount))
        for count in range (0,MacInterfaceCount):
            Cfile.write("TRUE,")
        Cfile.write("};\n")
        Cfile.write("PRIVATE  uint32    g_u32MacTxUcastAvgRetry [ %d ] =  {" %(MacInterfaceCount))
        for count in range (0,MacInterfaceCount):
            Cfile.write("1,")
        Cfile.write("};\n")
        Cfile.write("PRIVATE  uint16    g_u16PacketValidateDropCount [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint16    g_u16PacketBufferAllocateFailure [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint16    g_u16PhyToMacQueDrop [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacTxUcastRetry [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacTxUcastFail [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacRxUcast [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacTxUcast [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacRxBcast [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacTxBcast [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32MacCcaFail [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PRIVATE  uint32    g_u32ApsRetry   [ %d ]; \n" %(MacInterfaceCount))
        Cfile.write("PUBLIC   uint32    g_u32ChannelMaskList [ %d ] = " %(channelMaskListCount ) )
        Cfile.write("{ ")
        for count in range (0,channelMaskListCount):
            if SetMaskForIndex0 == 1 and count ==0:
               Cfile.write("    0x%08xUL,\n" % (channelMask))
            else:
               Cfile.write("0xFFFFFFFF,")
        Cfile.write("}; \n")
        Cfile.write("zps_tsAplAfMMServerContext	s_sMultiMaskServer =" )
        Cfile.write("{" )
        Cfile.write("     ZPS_E_MULTIMASK_STATE_IDLE," )
        Cfile.write("     %d,"%(channelMaskListCount) )
        Cfile.write("     0," )
        Cfile.write("     APP_bMultimaskJoinCallBack" )
        Cfile.write("};\n" )
        Cfile.write("    /* ... ZPS_MULTIMASK_SUPPORT */\n" )
        Cfile.write("    /* The MAC Interface Table (default values) */ \n" )
        tempinterface = 0
        Cfile.write("PRIVATE  MAC_tsMacInterface    g_sMacInterface [ %d ]= \n" %(MacInterfaceCount))
        Cfile.write("{\n" )
        if hasattr(configNode, "MacInterfaceList"):
            for interface in configNode.MacInterfaceList.MacInterface:
                Radiotype = "E_MAC_FREQ_NOT_KNOWN"
                macbitmask = 0
                if ((interface.get("Enabled") == "true")):
                    macbitmask |= 1
                else:
                    macbitmask |= 0
                macbitmask |= (int(interface.get("ChannelListSize")) << 2)
                if interface.get("RadioType") == "RT868MHz" :
                    Radiotype = "E_MAC_FREQ_868"
                    tempinterface |= 1
                if interface.get("RadioType") == "RT2400MHz" :
                    Radiotype = "E_MAC_FREQ_2400"
                    tempinterface |= 2
                if int(interface.get("index")) == 0 :
                    if (interface.get("RadioType") != "RT2400MHz"):
                        if MacInterfaceCount > 1:
                            print("ERROR: interface index 0 should always be 2.4G in a multimac\n")
                        MacType =  "E_MAC_TYPE_UART1"
                    else:
                        MacType =  "E_MAC_TYPE_SOC"
                if int(interface.get("index")) > 0 :
                    MacType = "E_MAC_TYPE_UART"+str(interface.get("index"))
                if interface.get("RouterAllowed"):
                    RouterAllowedFlag = 1
                    macbitmask |=  (1 << 1)

                else:
                    RouterAllowedFlag = 0

                Cfile.write("        { %d, 0x%x, %s, %s  } , \n" %( 0, macbitmask, Radiotype, MacType ))

            Cfile.write("};\n")
            Cfile.write("PRIVATE MAC_tsMacInterfaceTable g_asMacInterfaceTable =  \n")
            Cfile.write("{ \n")
            Cfile.write("  &s_sMultiMaskServer,		 /* ZPS_MULTIMASK_SUPPORT ...*/ \n")
            Cfile.write("  g_sMacInterface,\n")
            Cfile.write("  &g_u32ChannelMaskList [0],\n")
            Cfile.write("  g_u32MacTxUcastAvgRetry,\n")
            Cfile.write("  g_u32MacTxUcastRetry,\n")
            Cfile.write("  g_u32MacTxUcastFail,\n")
            Cfile.write("  g_u32MacRxUcast,\n")
            Cfile.write("  g_u32MacTxUcast,\n")
            Cfile.write("  g_u32MacRxBcast,\n")
            Cfile.write("  g_u32MacTxBcast,\n")
            Cfile.write("  g_u32MacCcaFail,\n")
            Cfile.write("  g_u32ApsRetry,\n")
            Cfile.write("  g_u16PacketValidateDropCount,\n")
            Cfile.write("  g_u16PacketBufferAllocateFailure,\n")
            Cfile.write("  g_u16PhyToMacQueDrop,\n")
            Cfile.write("  g_bIgnoreBroadcast,\n")
            Cfile.write("  %d\n" %(MacInterfaceCount))
            Cfile.write("};\n")

    Cfile.write("PUBLIC ZPS_tsApsCounters g_sApsCounters = {0};\n")
    Cfile.write("PUBLIC uint8 u8MaxZpsConfigEp = %d ;\n" %(EpTotal))
    Cfile.write("PUBLIC uint8 au8EpMapPresent[%d] = {" %(EpTotal))
    epLoop = 0
    for ep in myfoundNode.Endpoints:
        epId = int(ep.get("Id"), 0)
        if epId > 0:
            epLoop += 1
            if epLoop < EpTotal:
                Cfile.write("%d ," %(epId) )
            else:
                Cfile.write(" %d " %(epId) )
    Cfile.write(" }; \n")


    if configNode.get("StackProfile"):
        u8ZpsConfigStackProfileId = int(configNode.get("StackProfile"), 0)
        Cfile.write("PUBLIC uint8 u8ZpsConfigStackProfileId = %d;\n" %(u8ZpsConfigStackProfileId))
    else:
        Cfile.write("PUBLIC uint8 u8ZpsConfigStackProfileId = 2;\n")

    # Default save count shifts to 10 = write to PDM once every 1024 increments
    ApsFcSaveCountBitShift = 10
    if configNode.get("ApsFcSaveCountBitShift"):
        ApsFcSaveCountBitShift = int(configNode.get("ApsFcSaveCountBitShift"), 0)
    Cfile.write("PUBLIC const uint32 g_u32ApsFcSaveCountBitShift = %d;\n" %(ApsFcSaveCountBitShift))

    NwkFcSaveCountBitShift = 10
    if configNode.get("NwkFcSaveCountBitShift"):
        NwkFcSaveCountBitShift = int(configNode.get("NwkFcSaveCountBitShift"), 0)
    Cfile.write("PUBLIC const uint32 g_u32NwkFcSaveCountBitShift = %d;\n" %(NwkFcSaveCountBitShift))

    gpSupported="NULL"
    if configNode.get("GreenPowerSupport"):
        if "true" == configNode.get("GreenPowerSupport").lower():
            gpSecTableStruct = "NULL"
            gpTxQueueStruct = "NULL"
            gpAgingTimer = "NULL"
            gpBidirTimer = "NULL"
            sizeSt = 0
            sizeTxQ = 0
            if hasattr(configNode, "GreenPowerTxQueue"):
                sizeTxQ = int(configNode.GreenPowerTxQueue.get("Size"), 0)
                Cfile.write("PRIVATE ZPS_tsAfZgpTxGpQueueEntry aZgpTxGpQueue[%d];\n" % (sizeTxQ))
                Cfile.write("ZPS_tsTsvTimer sTxAgingTimer;\n")
                Cfile.write("TSV_Timer_s sTxBiDirTimer;\n")
                Cfile.write("ZPS_tsAfZgpTxGpQueue sZgpTxGpQueue = { aZgpTxGpQueue, %d };\n" %(sizeTxQ))
                gpAgingTimer = "&sTxAgingTimer"
                gpBidirTimer = "&sTxBiDirTimer"
                gpTxQueueStruct =  "&sZgpTxGpQueue"
            if hasattr(configNode, "GreenPowerSecurityTable"):
                sizeSt = int(configNode.GreenPowerSecurityTable.get("Size"), 0)
                Cfile.write("PRIVATE ZPS_tsAfZgpGpstEntry aZgpGpst[%d];\n" % (sizeSt))
                Cfile.write("ZPS_tsAfZgpGpst sZgpGpst = { aZgpGpst, %d };\n" %(sizeSt))
                gpSecTableStruct = "&sZgpGpst"
            gpSupported="&gsGreenPowerContext"
            Cfile.write("ZPS_tsAfZgpGreenPowerContext gsGreenPowerContext = { %s, %s, %s, %s, 100, 0 };\n" %(gpSecTableStruct,gpTxQueueStruct,gpAgingTimer,gpBidirTimer))

    Cfile.write("ZPS_tsAfZgpGreenPowerContext *g_psGreenPowerContext = %s;\n" %(gpSupported))


    Cfile.write("""
/****************************************************************************/
/***        Local Function Prototypes                                     ***/
/****************************************************************************/

PUBLIC void vZdoServersInit(void);
""")

    deprecatedZdoServers = ['MgmtNWKEnhanceUpdateServer']
    if R23_UPDATES:
        deprecatedZdoServers = ['MgmtNWKEnhanceUpdateServer',
                                'ExtendedSimpleDescServer',
                                'ExtendedActiveEpServer',
                                'EndDeviceBindServer']

    # ZDP servers prototypes
    if hasattr(configNode, "ZDOServers"):
        for server in configNode.ZDOServers.iterchildren():
#                Cfile.write("extern zps_tprAplZdoServer zps_bAplZdo%s;\n" % (server.tag))
            if (server.tag not in deprecatedZdoServers):

                Cfile.write("PUBLIC bool zps_bAplZdo%s(void *, void *, ZPS_tsAfEvent *);\n" % (server.tag))

                (outputParams, outputParamTypes) = zdoServers[server.tag]

                Cfile.write("PUBLIC void zps_vAplZdo%sInit(" % (server.tag))
                outputParamTypes(Cfile)
                Cfile.write(");\n")

    # Trust Centre
    trustCenterPresent = False
    if hasattr(configNode, "TrustCenter"):
        Cfile.write("\n/* Trust Center */\n")
        Cfile.write("PUBLIC void zps_vAplTrustCenterInit(void *);")
        if R23_UPDATES:
            Cfile.write("PUBLIC void zps_vAplTrustCenterUpdateDevice(void *, uint64 , uint64 , uint8 , uint16, uint16);")
        else:
            Cfile.write("PUBLIC void zps_vAplTrustCenterUpdateDevice(void *, uint64 , uint64 , uint8 , uint16);")
        Cfile.write("PUBLIC void zps_vAplTrustCenterRequestKey(void *, uint64 , uint8 , uint64 );")
        trustCenterPresent = True

    Cfile.write("""
/****************************************************************************/
/***        Local Variables                                               ***/
/****************************************************************************/

""")

    # binding table
    bindingTable = "NULL"
    if hasattr(configNode, "BindingTable"):
        size = int(configNode.BindingTable.get("Size"), 0)
        if size > 0:
            Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTableStoreEntry s_bindingTableStorage[%d];\n" % (size))
            Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTable s_bindingTable = { s_bindingTableStorage, %d };\n" % (size))
            bindingTable = "&s_bindingTable"

    # binding table caches - not implemented yet
    bindingCacheCfg = None

    bindingCache = "NULL"
    if None != bindingCacheCfg:
        tableSize = int(bindingCacheCfg.get("TableSize"), 0)
        numTables = int(bindingCacheCfg.get("NumTables"), 0)
        if numTables > 0:
            for i in range(0, numTables):
                Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTableEntry s_bindingCacheStorage_%d[%d];\n" % (i, tableSize))

            Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTable s_bindingCaches[%d] = {\n" % (numTables))
            for i in range(0, numTables):
                Cfile.write("{ 0, &s_bindingCacheStorage_%d, %d },\n" % (i, tableSize))
            Cfile.write("};\n")

            Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTableCache s_bindingCache = { s_bindingCaches, %d, NULL };\n" % (numTables))

            bindingCache = "&s_bindingTable"

    bindingTables = "NULL"
    if "NULL" != bindingCache or "NULL" != bindingTable:
        if R23_UPDATES:
            bindingCache = ""
        Cfile.write("PRIVATE ZPS_tsAplApsmeBindingTableType s_bindingTables = { %s, %s };\n" % (bindingTable, bindingCache))
        bindingTables = "&s_bindingTables"

    # Group table
    groupTable = "NULL"
    groupTableSize = 0
    if hasattr(configNode, "GroupTable"):
        groupTableSize = int(configNode.GroupTable.get("Size"), 0)
        Cfile.write("PRIVATE ZPS_tsAplApsmeGroupTableEntry s_groupTableStorage[%d];\n" % (groupTableSize))
        Cfile.write("PRIVATE ZPS_tsAplApsmeAIBGroupTable s_groupTable = { s_groupTableStorage, %d };\n" % (groupTableSize))
        Cfile.write("PRIVATE ZPS_tsAPdmGroupTableEntry s_groupTablePdmStorage[%d];\n" % (groupTableSize))
        Cfile.write("PUBLIC ZPS_tsPdmGroupTable s_groupPdmTable = { s_groupTablePdmStorage, %d };\n" % (groupTableSize))
        groupTable = "&s_groupTable"
    else:
        Cfile.write("PUBLIC ZPS_tsPdmGroupTable s_groupPdmTable = { NULL, %d };\n" % (groupTableSize))

    # Key Descriptor table
    keyPairTable = "NULL"
    keyPairTableSize = 0
    KeyTypeTable = "NULL"	
    if hasattr(configNode, "KeyDescriptorTable"):
        keyPairTableSize = int(configNode.KeyDescriptorTable.get("Size"), 0)
        Cfile.write("PRIVATE ZPS_tsAplApsKeyDescriptorEntry s_keyPairTableStorage[%d] = {\n" % (keyPairTableSize + 3))
        num_pck = 0
        if hasattr(configNode.KeyDescriptorTable, "PreconfiguredKey"):
            for pck in configNode.KeyDescriptorTable.PreconfiguredKey:

                if num_pck == keyPairTableSize:
                    print("WARNING: There are more PreconfiguredKeys than the KeyDescriptorTable size of %d.\n" % (keyPairTableSize))
                    break

                Cfile.write("    { 0x%016lxULL, { " % (int(pck.get("IEEEAddress"), 0)))
                key = int(pck.get("Key"), 0)
                for i in range(0, 16):
                    if (0 != i):
                        Cfile.write(", ")
                    Cfile.write("0x%02x" % (( key & (0xff << (8 * i) )) >> (8 * i)) )
                Cfile.write(" }, 0 , 0 , 0 },\n")
                num_pck += 1
        # fill in rest of table with blank addresses (all Fs in IEEE addr used to indicate this)
        if num_pck < (keyPairTableSize + 3):
            for pck in range(num_pck, (keyPairTableSize + 3)):
                if R23_UPDATES:
                    Cfile.write("    { 0, 0xFFFF, { }, 0 , 0},\n")
                else:
                    Cfile.write("    { 0, 0xFFFF, { }, 0 },\n")

        Cfile.write("};\n")
        Cfile.write("ZPS_tsAplApsKeyDescriptorEntry  *psAplDefaultDistributedAPSLinkKey = &s_keyPairTableStorage[%d];\n" % (keyPairTableSize+1))
        Cfile.write("ZPS_tsAplApsKeyDescriptorEntry  *psAplDefaultGlobalAPSLinkKey = &s_keyPairTableStorage[%d];\n" % (keyPairTableSize+2))
        Cfile.write("PRIVATE uint32 au32IncomingFrameCounter[%d];\n" % (keyPairTableSize + 3))
        if R23_UPDATES:
            Cfile.write("PRIVATE bool_t abVerifiedFrameCounter[%d];\n" % (keyPairTableSize + 3))
        Cfile.write("PRIVATE ZPS_tsAplApsKeyDescriptorTable s_keyPairTable = { s_keyPairTableStorage, %d };\n\n" % (keyPairTableSize))
        keyPairTable = "&s_keyPairTable"

    if R23_UPDATES:
        challengeReqTable = "NULL"
        challengeReqTableSize = 0
        if hasattr(configNode, "ChallengeReqTable"):
            challengeReqTableSize = int(configNode.ChallengeReqTable.get("Size"), 0)
        if challengeReqTableSize == 0:
            challengeReqTableSize = 10
        Cfile.write("PRIVATE ZPS_tsAplApsChallengeReqEntry s_challengeReqTableStorage[%d] = {\n" % (challengeReqTableSize))
        for pck in range(0, (challengeReqTableSize)):
            Cfile.write("    { 0xFFFFFFFFFFFFFFFF, 0, 0, {} },\n")
        Cfile.write("};\n")
        Cfile.write("PRIVATE ZPS_tsAplApsChallengeReqTable s_challengeReqTable = { s_challengeReqTableStorage, %d };\n\n" % (challengeReqTableSize))
        challengeReqTable = "&s_challengeReqTable"

        fragmentationTable = "NULL"
        fragmentationTableSize = 0
        if hasattr(configNode, "FragmentationTable"):
            fragmentationTableSize = int(configNode.FragmentationTable.get("Size"), 0)
        if fragmentationTableSize < keyPairTableSize:
            fragmentationTableSize = keyPairTableSize
        Cfile.write("PRIVATE ZPS_tsAplApsFragmentationEntry s_fragmentationTableStorage[%d] = {\n" % (fragmentationTableSize))
        for pck in range(0, (keyPairTableSize)):
            Cfile.write("    { 0xFFFF, 0, 0 },\n")
        Cfile.write("};\n")
        Cfile.write("PRIVATE ZPS_tsAplApsFragmentationCacheTable s_fragmentationTable = { s_fragmentationTableStorage, %d };\n\n" % (fragmentationTableSize))
        fragmentationTable = "&s_fragmentationTable"

    # Application layer information base
    Cfile.write("PRIVATE ZPS_tsAplAib s_sAplAib = {\n")

    Cfile.write("    0,\n") # apsTrustCenterAddress

    extPanId = 0
    if configNode.get("apsUseExtPANId"):
        extPanId = int(configNode.get("apsUseExtPANId"), 0)

    Cfile.write("    0x%016lxULL,\n" % (extPanId))
    designatedCoordinator = "FALSE"
    if configNode.tag == "Coordinator":
        designatedCoordinator = "TRUE"

    if configNode.get("apsDesignatedCoordinator"):
        if "true" == configNode.get("apsDesignatedCoordinator").lower():
            designatedCoordinator = "TRUE"
        else:
            designatedCoordinator = "FALSE"
    Cfile.write("    %s,\n" % (designatedCoordinator))

    useInsecureJoin = "TRUE"
    if configNode.get("apsUseInsecureJoin"):
        if "true" == configNode.get("apsUseInsecureJoin").lower():
            useInsecureJoin = "TRUE"
        else:
            useInsecureJoin = "FALSE"
    Cfile.write("    %s,\n" % (useInsecureJoin))
    Cfile.write("    FALSE,\n" )
    if R23_UPDATES:
        Cfile.write("    FALSE,\n" ) # apsZdoRestrictedMode
        Cfile.write("    FALSE,\n" ) # bRequireLinkKeyEncryptionForApsTransportKey
        apsSupportedKeyNegotiationMethods = "ZPS_TLV_G_SUPPKEYNEGMETH_STATKEYREQ"
        if configNode.get("apsSupportedKeyNegotiationMethods"):
            apsSupportedKeyNegotiationMethods = configNode.get("apsSupportedKeyNegotiationMethods")
        Cfile.write("    %s,\n" % (apsSupportedKeyNegotiationMethods))
        Cfile.write("    0,\n" ) # u8SharedSecretsMask
    Cfile.write("    0,\n") # KeyType
    if not R23_UPDATES:
        nonMemberRadius = 2
        if configNode.get("apsNonMemberRadius"):
            nonMemberRadius = int(configNode.get("apsNonMemberRadius"), 0)
        Cfile.write("    0x%02x,\n" % (nonMemberRadius))

    interFrameDelay = 0
    if configNode.get("apsInterframeDelay"):
        interFrameDelay = int(configNode.get("apsInterframeDelay"), 0)
    Cfile.write("    0x%02x,\n" % (interFrameDelay))

    Cfile.write("    0,\n") # apsLastChannelEnergy
    Cfile.write("    0,\n") # apsLastChannelFailureRate
    Cfile.write("    0,\n") # apsChannelTimer

    maxWindowSize = 8
    if configNode.get("apsMaxWindowSize"):
        maxWindowSize = int(configNode.get("apsMaxWindowSize"), 0)
    Cfile.write("    0x%02x,\n" % (maxWindowSize))
    if R23_UPDATES:
        Cfile.write("    128,\n") # u8ApsMaxSizeAsdu

    Cfile.write("    %s,\n" % (bindingTables))
    Cfile.write("    %s,\n" % (groupTable))
    Cfile.write("    %s,\n" % (keyPairTable))
    if R23_UPDATES:
        Cfile.write("   %s,\n" % (fragmentationTable))
    # TODO Default link key setup from config when added to editor
    if keyPairTableSize == 0:
        Cfile.write("    NULL,\n")
    else:
        Cfile.write("    &s_keyPairTableStorage[%d],\n" % (keyPairTableSize))
    Cfile.write("    FALSE,\n")
    Cfile.write("    FALSE,\n")
    apsSecurityTimeoutPeriod = 3000
    if configNode.get("apsSecurityTimeoutPeriod"):
        apsSecurityTimeoutPeriod = int(configNode.get("apsSecurityTimeoutPeriod"), 0)
    Cfile.write("    0x%04x,\n" % (apsSecurityTimeoutPeriod))
    if R23_UPDATES:
        Cfile.write("    %s,\n" % (challengeReqTable))
        Cfile.write("    5,\n") # u8ApsChallengePeriodTimeoutSeconds;
        Cfile.write("    0,\n") # u32ApsChallengeFrameCounter
        Cfile.write("    abVerifiedFrameCounter,\n")
    if keyPairTableSize == 0:
        Cfile.write("    NULL,\n")
    else:
        Cfile.write("    au32IncomingFrameCounter,\n")
    Cfile.write("    g_u32ChannelMaskList\n")
    Cfile.write("};\n")

    # ZDP servers contexts
    numZDOServers = 0
    if hasattr(configNode, "ZDOServers"):
        for server in configNode.ZDOServers.iterchildren():
            if (server.tag not in deprecatedZdoServers):
                (outputParams, outputParamTypes) = zdoServers[server.tag]

                # get context size of server from symbol in library
                contextSize = getAplServerContextSize(server.tag, objdump, options.zigbeeAplLibFSP, options.endian)

                Cfile.write("PRIVATE uint8 s_s%sContext[%d] __attribute__ ((aligned (4)));\n" % (server.tag, contextSize))
                if(server.tag == "BindRequestServer"):
                    if server.get("SimultaneousRequests"):
                        SimultaneousRequests = int(server.get("SimultaneousRequests"),0)
                        Cfile.write("PRIVATE zps_tsZdoServerConfAckContext s_s%sAcksDcfmContext[%d];\n" % (server.tag, SimultaneousRequests))

                numZDOServers += 1

    # ZDP servers
    if hasattr(configNode, "ZDOServers"):
        Cfile.write("\n/* ZDO Servers */\n")
        Cfile.write("PRIVATE const zps_tsAplZdoServer s_asAplZdoServers[%d] = {\n" % (numZDOServers + 1))

        def compare(x, y):
            if (x.tag == "DefaultServer"):
                return 1
            if (x.tag == "ZdoClient"):
                return -1

            if (y.tag == "DefaultServer"):
                return -1
            if (y.tag == "ZdoClient"):
                return 1
            return 0

        temp_arr = list()
        for server in configNode.ZDOServers.iterchildren():
            temp_arr.append(server)

        for server in sorted(temp_arr, key=cmp_to_key(compare)):
            if (server.tag not in deprecatedZdoServers) :
                Cfile.write("    { zps_bAplZdo%s, s_s%sContext },\n" % (server.tag, server.tag))

        Cfile.write("    { NULL, NULL }\n")
        Cfile.write("};\n")

    # Simple descriptors
    Cfile.write("\n/* Simple Descriptors */\n")
    for endpoint in configNode.Endpoints:
        numInputClusters = 0
        numOutputClusters = 0
        endpointId = int(endpoint.get("Id"), 0)
        inDiscFlags = ""
        if hasattr(endpoint, "InputClusters"):
            numInputClusters = len(list(endpoint.InputClusters))

            inClusterList = ""
            inAPduList = ""
            clusterNum = 0
            clusterDiscMask = 0
            for inCluster in endpoint.InputClusters:
                cluster = findCluster(inCluster.get("Cluster"))
                inClusterList += " 0x%04x," % (int(cluster.get("Id"), 0))
                if inCluster.get("RxAPDU"):
                    apdu = findAPdu(configNode, inCluster.get("RxAPDU"))
                    inAPduList += " %s," % (apdu.get("Name"))
                else:
                    inAPduList += " NULL,"

                # update current byte of discoverable flags
                discoverable = 1 << (clusterNum & 7)
                if inCluster.get("Discoverable"):
                    if inCluster.get("Discoverable").lower() == "false":
                        discoverable = 0
                clusterDiscMask |= discoverable

                # add flag byte to list of bytes
                if (clusterNum & 7) == 7:
                    inDiscFlags += "0x%02x, " % (clusterDiscMask)
                    clusterDiscMask = 0
                clusterNum += 1
        # catch any trailing partial byte
        if (clusterNum & 7) != 0:
            inDiscFlags += "0x%02x" % (clusterDiscMask)

        outDiscFlags = ""
        if hasattr(endpoint, "OutputClusters"):
            numOutputClusters = len(list(endpoint.OutputClusters))
            outClusterList = ""
            clusterNum = 0
            clusterDiscMask = 0
            for outCluster in endpoint.OutputClusters:
                cluster = findCluster(outCluster.get("Cluster"))
                outClusterList += " 0x%04x," % (int(cluster.get("Id"), 0))

                # update current byte of discoverable flags
                discoverable = 1 << (clusterNum & 7)
                if outCluster.get("Discoverable"):
                    if outCluster.get("Discoverable").lower() == "false":
                        discoverable = 0
                clusterDiscMask |= discoverable

                # add flag byte to list of bytes
                if (clusterNum & 7) == 7:
                    outDiscFlags += "0x%02x, " % (clusterDiscMask)
                    clusterDiscMask = 0
                clusterNum += 1

        # catch any trailing partial byte
        if (clusterNum & 7) != 0:
            outDiscFlags += "0x%02x" % (clusterDiscMask)


        # Discoverable flags for clusters
        if numInputClusters > 0:
            Cfile.write("PRIVATE const uint16 s_au16Endpoint%dInputClusterList[%d] = {%s };\n" % (endpointId, numInputClusters, inClusterList))
            Cfile.write("PRIVATE const PDUM_thAPdu s_ahEndpoint%dInputClusterAPdus[%d] = {%s };\n" % (endpointId, numInputClusters, inAPduList))
            Cfile.write("PRIVATE uint8 s_au8Endpoint%dInputClusterDiscFlags[%d] = { %s };\n" % (endpointId, (numInputClusters + 7) / 8, inDiscFlags))
            Cfile.write("\n")
        if numOutputClusters > 0:
            Cfile.write("PRIVATE const uint16 s_au16Endpoint%dOutputClusterList[%d] = {%s };\n" % (endpointId, numOutputClusters, outClusterList))
            Cfile.write("PRIVATE uint8 s_au8Endpoint%dOutputClusterDiscFlags[%d] = { %s };\n" % (endpointId, (numOutputClusters + 7) / 8, outDiscFlags))
            Cfile.write("\n")

    if configNode.get("DefaultCallbackName"):
        DefaultCallbackName = configNode.get("DefaultCallbackName")

    Cfile.write("PUBLIC void %s(uint8 u8Endpoint, ZPS_tsAfEvent *psStackEvent);\n"%(DefaultCallbackName))

    Cfile.write("tszQueue zps_msgMlmeDcfmInd;\n")
    Cfile.write("tszQueue zps_msgMcpsDcfmInd;\n")
    Cfile.write("tszQueue zps_TimeEvents;\n")
    Cfile.write("tszQueue zps_msgMcpsDcfm;\n")
    Cfile.write("PRIVATE zps_tsAplAfSimpleDescCont s_asSimpleDescConts[%d] = {\n" % (len(list(configNode.Endpoints))))

    for endpoint in configNode.Endpoints:
        endpointId = int(endpoint.get("Id"), 0)

        numInputClusters = 0
        if hasattr(endpoint, "InputClusters"):
            numInputClusters = len(endpoint.InputClusters)

        numOutputClusters = 0
        if hasattr(endpoint, "OutputClusters"):
            numOutputClusters = len(endpoint.OutputClusters)


        profile = findProfile(endpoint.get("Profile"))

        Cfile.write("    {\n")
        Cfile.write("        {\n")
        Cfile.write("            0x%04x,\n" % (int(profile.get("Id"), 0)))
        Cfile.write("            %s,\n" % (endpoint.get("ApplicationDeviceId")))
        Cfile.write("            %s,\n" % (endpoint.get("ApplicationDeviceVersion")))
        Cfile.write("            %d,\n" % (endpointId))

        Cfile.write("            %d,\n" % (numInputClusters))

        Cfile.write("            %d,\n" % (numOutputClusters))

        if 0 == numInputClusters:
            Cfile.write("            NULL,\n" )
        else:
            Cfile.write("            s_au16Endpoint%dInputClusterList,\n" % (endpointId) )

        if 0 == numOutputClusters:
            Cfile.write("            NULL,\n" )
        else:
            Cfile.write("            s_au16Endpoint%dOutputClusterList,\n" % (endpointId) )

        if 0 == numInputClusters:
            Cfile.write("            NULL,\n" )
        else:
            Cfile.write("            s_au8Endpoint%dInputClusterDiscFlags,\n" % (endpointId) )

        if 0 == numOutputClusters:
            Cfile.write("            NULL,\n" )
        else:
            Cfile.write("            s_au8Endpoint%dOutputClusterDiscFlags,\n" % (endpointId) )

        Cfile.write("        },\n" )
        if 0 == numInputClusters:
            Cfile.write("        NULL,\n" )
        else:
            Cfile.write("        s_ahEndpoint%dInputClusterAPdus,\n" % (endpointId))

        flags = 0
        if "true" == endpoint.get("Enabled").lower():
            flags |= 1
        Cfile.write("        %d\n" % (flags))
        Cfile.write("    },\n")
    Cfile.write("};\n")

    # Node descriptor
    Cfile.write("\n/* Node Descriptor */\n")
    Cfile.write("PRIVATE ZPS_tsAplAfNodeDescriptor s_sNodeDescriptor = {\n")

    if "ZC" == configNode.NodeDescriptor.get("LogicalType"):
        Cfile.write("    0,\n")
    elif "ZR" == configNode.NodeDescriptor.get("LogicalType"):
        Cfile.write("    1,\n")
    elif "ZED" == configNode.NodeDescriptor.get("LogicalType"):
        Cfile.write("    2,\n")

    if not R23_UPDATES:
        Cfile.write("    %s,\n" % (configNode.NodeDescriptor.get("ComplexDescriptorAvailable").upper()))
        Cfile.write("    %s,\n" % (configNode.NodeDescriptor.get("UserDescriptorAvailable").upper()))
        Cfile.write("    0,\n")
    else:
        if hasattr(configNode.NodeDescriptor, "FragmentationSupport"):
            fragmentationSupport = int(configNode.NodeDescriptor.get("FragmentationSupport"), 0)
            if fragmentationSupport == 1:
                Cfile.write("    1,\n")
            else:
                Cfile.write("    0,\n")
        else:
            Cfile.write("    0,\n")
        Cfile.write("    0,\n")
    localFrequencyBand = 0
    if (tempinterface > 0):
        if (tempinterface & 1):
            localFrequencyBand |= 16
        if (tempinterface & 2):
            localFrequencyBand |= 8
        Cfile.write("    0x%02x,\n" % (localFrequencyBand))
    else:
        if ("868MHz" == configNode.NodeDescriptor.get("FrequencyBand") ):
            Cfile.write("    0,\n")
        elif "915MHz" == configNode.NodeDescriptor.get("FrequencyBand"):
            Cfile.write("    4,\n")
        elif ("2.4GHz" == configNode.NodeDescriptor.get("FrequencyBand") ):
            Cfile.write("    8,\n")
    Cfile.write("    %d,\n" % (int(configNode.NodeDescriptor.get("APSFlags"), 0)))

    macFlags = 0
    if "true" == configNode.NodeDescriptor.get("AlternatePANCoordinator").lower():
        macFlags |= 1 << 0
    if "true" == configNode.NodeDescriptor.get("DeviceType").lower():
        macFlags |= 1 << 1
    if "true" == configNode.NodeDescriptor.get("PowerSource").lower():
        macFlags |= 1 << 2
    if "true" == configNode.NodeDescriptor.get("RxOnWhenIdle").lower():
        macFlags |= 1 << 3
    if "true" == configNode.NodeDescriptor.get("Security").lower():
        macFlags |= 1 << 6
    if R23_UPDATES or "true" == configNode.NodeDescriptor.get("AllocateAddress").lower():
        macFlags |= 1 << 7
    Cfile.write("    0x%02x,\n" % (macFlags))

    Cfile.write("    0x%04x,\n" % (int(configNode.NodeDescriptor.get("ManufacturerCode"), 0)))
    Cfile.write("    0x%02x,\n" % (int(configNode.NodeDescriptor.get("MaximumBufferSize"), 0)))
    Cfile.write("    0x%04x,\n" % (int(configNode.NodeDescriptor.get("MaximumIncomingTransferSize"), 0)))

    serverMask = 0
    if "true" == configNode.NodeDescriptor.get("PrimaryTrustCenter").lower():
        serverMask |= 1 << 0
    if "true" == configNode.NodeDescriptor.get("BackupTrustCenter").lower():
        serverMask |= 1 << 1
    if "true" == configNode.NodeDescriptor.get("PrimaryBindingTableCache").lower():
        serverMask |= 1 << 2
    if "true" == configNode.NodeDescriptor.get("BackupBindingTableCache").lower():
        serverMask |= 1 << 3
    if "true" == configNode.NodeDescriptor.get("PrimaryDiscoveryCache").lower():
        serverMask |= 1 << 4
    if "true" == configNode.NodeDescriptor.get("BackupDiscoveryCache").lower():
        serverMask |= 1 << 5
    if "true" == configNode.NodeDescriptor.get("NetworkManager").lower():
        serverMask |= 1 << 6
    # add stack compliance version (R21) into bits 9..15 of server Mask
    if R23_UPDATES:
        serverMask |= 23 << 9
    else:
        serverMask |= 22 << 9
    Cfile.write("    0x%04x,\n" % (serverMask))

    Cfile.write("    0x%04x,\n" % (int(configNode.NodeDescriptor.get("MaximumOutgoingTransferSize"), 0)))

    descriptorCapabilities = 0
    if "true" == configNode.NodeDescriptor.get("ExtendedActiveEndpointListAvailable").lower():
        descriptorCapabilities |= 1 << 0
    if "true" == configNode.NodeDescriptor.get("ExtendedSimpleDescriptorListAvailable").lower():
        descriptorCapabilities |= 1 << 1
    if R23_UPDATES:
        # deprecated
        descriptorCapabilities = 0
    Cfile.write("    0x%02x};\n" % (descriptorCapabilities))

    # Node power descriptor
    if (sEndian == "BIG_ENDIAN"):
        Cfile.write("\n/* Node Power Descriptor */\n")
        Cfile.write("PRIVATE ZPS_tsAplAfNodePowerDescriptor s_sNodePowerDescriptor = {\n")

        currentPowerMode = 0
        if "Synchronised with RxOnWhenIdle" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 0
        elif "Periodic" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 1
        elif "Stimulated" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 2
        Cfile.write("    0x%01x,\n" % (currentPowerMode)) # current power mode

        availablePowerSources = 0
        if "true" == configNode.NodePowerDescriptor.get("ConstantPower").lower():
            availablePowerSources |= 1 << 0
        if "true" == configNode.NodePowerDescriptor.get("RechargeableBattery").lower():
            availablePowerSources |= 1 << 1
        if "true" == configNode.NodePowerDescriptor.get("DisposableBattery").lower():
            availablePowerSources |= 1 << 2
        Cfile.write("    0x%01x,\n" % (availablePowerSources))

        currentPowerSource = 0
        if "Constant Power" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 1
        elif "Rechargeable Battery" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 2
        elif "Disposable Battery" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 4
        Cfile.write("    0x%01x,\n" % (currentPowerSource)) # current power source
        Cfile.write("    0xC};\n") # current power level
    else:
        Cfile.write("\n/* Node Power Descriptor */\n")
        Cfile.write("PRIVATE ZPS_tsAplAfNodePowerDescriptor s_sNodePowerDescriptor = {\n")

        Cfile.write("    0xC,   \n") # current power level
        currentPowerSource = 0
        if "Constant Power" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 1
        elif "Rechargeable Battery" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 2
        elif "Disposable Battery" == configNode.NodePowerDescriptor.get("DefaultPowerSource"):
            currentPowerSource = 4
        Cfile.write("    0x%01x,\n" % (currentPowerSource)) # current power source
        availablePowerSources = 0
        if "true" == configNode.NodePowerDescriptor.get("ConstantPower").lower():
            availablePowerSources |= 1 << 0
        if "true" == configNode.NodePowerDescriptor.get("RechargeableBattery").lower():
            availablePowerSources |= 1 << 1
        if "true" == configNode.NodePowerDescriptor.get("DisposableBattery").lower():
            availablePowerSources |= 1 << 2
        Cfile.write("    0x%01x,\n" % (availablePowerSources))
        currentPowerMode = 0
        if "Synchronised with RxOnWhenIdle" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 0
        elif "Periodic" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 1
        elif "Stimulated" == configNode.NodePowerDescriptor.get("DefaultPowerMode"):
            currentPowerMode = 2
        Cfile.write("    0x%01x};\n" % (currentPowerMode)) # current power mode

    # User descriptor
    if not R23_UPDATES and hasattr(configNode, "UserDescriptor"):
        Cfile.write("\n/* User Descriptor */\n")
        Cfile.write("PRIVATE ZPS_tsAplAfUserDescriptor s_sUserDescriptor = { { ")
        for i in range(0, len(configNode.UserDescriptor.get("UserDescription"))):
            if i < 16:
                Cfile.write("'%c', " % (configNode.UserDescriptor.get("UserDescription")[i]))
        Cfile.write("} };\n")

    # APSDE duplicate table
    Cfile.write("\n/* APSDE duplicate table */\n")
    # duplicate table must respect apscMinDuplicateRejectionTableSize which is 1
    apsDuplicateTableSize = int(configNode.get("APSDuplicateTableSize"), 0)
    if apsDuplicateTableSize < 1:
        apsDuplicateTableSize = 1
    Cfile.write("PRIVATE uint16 s_au16ApsDuplicateTableAddrs[%d];\n" % apsDuplicateTableSize)
    Cfile.write("PRIVATE uint32 s_au32ApsDuplicateTableHash[%d];\n" % int(configNode.get("APSDuplicateTableSize"), 0))
    Cfile.write("PRIVATE uint8 s_au8ApsDuplicateTableSeqCnts[%d];\n" % int(configNode.get("APSDuplicateTableSize"), 0))
    Cfile.write("PRIVATE uint32 s_au32ApsDuplicateTableIncomFC[%d];\n" % int(configNode.get("APSDuplicateTableSize"), 0))
    Cfile.write("PRIVATE zps_tsApsDuplicateTable s_sApsDuplicateTable = { s_au16ApsDuplicateTableAddrs, s_au32ApsDuplicateTableHash, s_au8ApsDuplicateTableSeqCnts, s_au32ApsDuplicateTableIncomFC, 0 };\n")

    # APSDE acked msg containers
    Cfile.write("\n/* APSDE sync msg pool */\n")
    Cfile.write("PRIVATE zps_tsMsgRecord s_asApsSyncMsgPool[%d];\n" % int(configNode.get("MaxNumSimultaneousApsdeAckReq"), 0))

    # APSDE acked msg containers
    Cfile.write("\n/* APSDE dcfm record pool */\n")
    Cfile.write("PRIVATE zps_tsDcfmRecord s_asApsDcfmRecordPool[%d];\n" % int(configNode.get("MaxNumSimultaneousApsdeReq"), 0))

    if int(configNode.get("FragmentationMaxNumSimulRx"), 0) > 0:
        Cfile.write("\n/* APSDE fragmentation rx pool */\n")
        Cfile.write("PRIVATE zps_tsFragmentReceive s_asApsFragRxPool[%d];\n" % int(configNode.get("FragmentationMaxNumSimulRx"), 0))

    if int(configNode.get("FragmentationMaxNumSimulTx"), 0) > 0:
        Cfile.write("\n/* APSDE fragmentation tx pool */\n")
        Cfile.write("PRIVATE zps_tsFragmentTransmit s_asApsFragTxPool[%d];\n" % int(configNode.get("FragmentationMaxNumSimulTx"), 0))

    # apsme command manager

    numApsmeCmdContainers = 4
    if configNode.get("NumAPSMESimulCommands"):
        if int(configNode.get("NumAPSMESimulCommands"), 0) > 0:
            numApsmeCmdContainers = int(configNode.get("NumAPSMESimulCommands"), 0)

    Cfile.write("\n/* APSME Command Manager Command Containers */\n")
    Cfile.write("PRIVATE zps_tsApsmeCmdContainer s_sApsmeCmdContainer_%d = { NULL, {}, {}, NULL, 0 };\n" % numApsmeCmdContainers)
    for i in range(numApsmeCmdContainers - 1, 0, -1):
        Cfile.write("PRIVATE zps_tsApsmeCmdContainer s_sApsmeCmdContainer_%d = { &s_sApsmeCmdContainer_%d, {}, {}, NULL, 0 };\n" % (i, i + 1))

    securityDisabled = False


    # output any initial network key for this node
    securityInitialKey = False
    if not securityDisabled and configNode.get("InitialNetworkKey"):

        initKey = findNetworkKey(configNode.get("InitialNetworkKey"))
        if None != initKey:
            # only need to init preconfigured nwk key
            # default key will be transported from trust center
            # tc link keys will also transport a key from the TC
            if initKey.get('{' + initKey.nsmap['xsi'] + '}' +'type') == "zpscfg:PreConfiguredNwkKey" \
            or (trustCenterPresent and initKey.get('{' + initKey.nsmap['xsi'] + '}' +'type') == "zpscfg:DefaultNwkKey"):
                Cfile.write("\n/* Initial Nwk Key */\n")
                Cfile.write("zps_tsAplZdoInitSecKey s_sInitSecKey = { { %s }, 0x%02x, ZPS_NWK_SEC_NETWORK_KEY };\n" % (networkKeyStr(initKey), int(initKey.KeySequenceNumber, 0) ) )
                securityInitialKey = True

    # Trust Centre Context
    if not securityDisabled and hasattr(configNode, "TrustCenter"):
        Cfile.write("\n/* Trust Center */\n")
        Cfile.write("PRIVATE zps_tsAplTCDeviceTable s_asTrustCenterDeviceTable[%d] = {\n" % (int(configNode.TrustCenter.get("DeviceTableSize"), 0)))
        for i in range(int(configNode.TrustCenter.get("DeviceTableSize"), 0)):
            Cfile.write("                                                            { 0xFFFF, 0 },\n")
        Cfile.write("                                                                };\n")
        Cfile.write("PRIVATE zps_tsTrustCenterContext s_sTrustCenterContext = {\n")
        Cfile.write("    zps_vAplTrustCenterInit,\n")
        Cfile.write("    zps_vAplTrustCenterUpdateDevice,\n")
        Cfile.write("    zps_vAplTrustCenterRequestKey,\n")
        Cfile.write("    { s_asTrustCenterDeviceTable, %d },\n" % (int(configNode.TrustCenter.get("DeviceTableSize"), 0)))
        Cfile.write(" FALSE,\n")
        Cfile.write(" FALSE,\n")
        Cfile.write("};\n\n")

    # Network layer context
    Cfile.write("\n/* Network Layer Context */\n")

    # get the size of the context area directly from the network layer library file.
    # The size is placed in a const variable in the section '.libobjsize'
    nwkContextSize = getLibObjSize(objdump, options.zigbeeNwkLibFSP, options.endian)

    Cfile.write("PRIVATE uint8                   s_sNwkContext[%d] __attribute__ ((aligned (4)));\n" % (nwkContextSize) )
    Cfile.write("PRIVATE ZPS_tsNwkDiscNtEntry    s_asNwkNtDisc[%d];\n" % (int(configNode.get("DiscoveryNeighbourTableSize"), 0)))
    Cfile.write("PRIVATE ZPS_tsNwkActvNtEntry    s_asNwkNtActv[%d];\n" % (int(configNode.get("ActiveNeighbourTableSize"), 0)))
    if ("Coordinator" == configNode.tag) or (configNode.tag == "ChildNodes" and "zpscfg:EndDevice" != configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type")):
        Cfile.write("PRIVATE ZPS_tsNwkRtDiscEntry    s_asNwkRtDisc[%d];\n" % (int(configNode.get("RouteDiscoveryTableSize"), 0)))
        Cfile.write("PRIVATE ZPS_tsNwkRtEntry        s_asNwkRt[%d];\n" % (int(configNode.get("RoutingTableSize"), 0)))
    Cfile.write("PRIVATE ZPS_tsNwkBtr            s_asNwkBtt[%d];\n" % (max((1, int(configNode.get("BroadcastTransactionTableSize"), 0)))))
    if ("Coordinator" == configNode.tag) or (configNode.tag == "ChildNodes" and "zpscfg:EndDevice" != configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type")):
        Cfile.write("PRIVATE ZPS_tsNwkRctEntry       s_asNwkRct[%d];\n" % (int(configNode.get("RouteRecordTableSize"), 0)))
    Cfile.write("PRIVATE ZPS_tsNwkSecMaterialSet s_asNwkSecMatSet[%d];\n" % (int(configNode.get("SecurityMaterialSets"), 0)))
    Cfile.write("PRIVATE uint32                  s_asNwkInFCSet[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
    Cfile.write("PRIVATE uint16                  s_au16NwkAddrMapNwk[%d];\n" % (int(configNode.get("AddressMapTableSize"), 0) +4))          #space for transient entry
    Cfile.write("PRIVATE uint16                  s_au16NwkAddrMapLookup[%d];\n" % (int(configNode.get("AddressMapTableSize"), 0) +4))       #space for transient entry
    Cfile.write("PRIVATE uint64                  s_au64NwkAddrMapExt[%d];\n" % ((int(configNode.get("MacTableSize"), 0))+4)) #space for transient entry
    Cfile.write("#ifdef ZPS_FRQAG\n" )
    Cfile.write("PRIVATE uint32                  s_au32RxPacketCount[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
    Cfile.write("PRIVATE uint32                  s_au32TxPacketCount[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
    Cfile.write("#endif\n" )
    LeaveAllowedDefault = 1
    if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
        LeaveAllowedDefault = 0
    if configNode.get("ChildTableSize"):
        Cfile.write("PRIVATE uint32                  s_au32ZedTimeoutCount[%d];\n" % ( int(configNode.get("ChildTableSize"), 0)))
        Cfile.write("PRIVATE uint8                  s_au8KeepAliveFlags[%d];\n" % ( int(configNode.get("ChildTableSize"), 0)))
    else:
        if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            Cfile.write("PRIVATE uint32                  s_au32ZedTimeoutCount[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
            Cfile.write("PRIVATE uint8                  s_au8KeepAliveFlags[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
        else:
            Cfile.write("PRIVATE uint32                  s_au32ZedTimeoutCount[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
            Cfile.write("PRIVATE uint8                  s_au8KeepAliveFlags[%d];\n" % ( int(configNode.get("ActiveNeighbourTableSize"), 0)))
    Cfile.write("""
PRIVATE const zps_tsNwkNibInitialValues s_sNibInitialValues =
{
    600,""")
    Cfile.write("\n    %d," % (maxr))
    Cfile.write("""
    7,
    15,
    1,
    2,
    11,
    18,
    0,
    2,
    0,
    1,""")
    if R23_UPDATES == 0:  # u8UseMulticast
        Cfile.write("""
    0,""")
    if R23_UPDATES:  # u8GoodParentLqa
        Cfile.write("""
    0,""")
    Cfile.write("""
    15,
    3,
    3,
    255,
    5,
    TRUE,
    TRUE,
    5,
    4,""")
    Cfile.write("\n    %d,"%(LeaveAllowedDefault))
    Cfile.write("""
    6,
    8,""")
    if R23_UPDATES:
        # nwkMaxInitialJoinParentAttempts
        Cfile.write("""
    1,
    3,""") # u8MaxRejoinParentAttempts
    Cfile.write("""
    0,""") #/* u16VerifyLinkCostTransmitRate */
    if R23_UPDATES or WWAH_SUPPORT: # u16NextPanId
        Cfile.write("""
    65535""")
    Cfile.write("""
};

""")

    Cfile.write("\nPRIVATE const ZPS_tsNwkNibTblSize     s_sNwkTblSize = {\n")
    Cfile.write("    %d,\n" % (int(configNode.get("ActiveNeighbourTableSize"), 0)))
    if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):	
        Cfile.write("    0,\n" )
    else:
        Cfile.write("    %d,\n" % (int(configNode.get("RoutingTableSize"), 0)))

    if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
        Cfile.write("    0,\n" )
    else:
        Cfile.write("    %d,\n" % (int(configNode.get("RouteRecordTableSize"), 0)))

    Cfile.write("    %d,\n"  % (int(configNode.get("AddressMapTableSize"), 0)))
    Cfile.write("    %d,\n" % (int(configNode.get("DiscoveryNeighbourTableSize"), 0)))

    if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
        Cfile.write("    0,\n" )
    else:
        Cfile.write("    %d,\n" % (int(configNode.get("RouteDiscoveryTableSize"), 0)))
		
    Cfile.write("    %d,\n" % (int(configNode.get("BroadcastTransactionTableSize"), 0)))
    Cfile.write("    %d,\n" % (int(configNode.get("SecurityMaterialSets"), 0)))
    Cfile.write("    sizeof(s_sNibInitialValues),\n")
    if configNode.get("ChildTableSize"):
        Cfile.write("    %d,\n"  % ((int(configNode.get("ChildTableSize"), 0)))) #child table size
    else:
        if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            Cfile.write("    %d,\n"  % (int(configNode.get("ActiveNeighbourTableSize"), 0))) #child table size
        else:
            Cfile.write("    %d,\n"  % (int(configNode.get("ActiveNeighbourTableSize"), 0) / 6)) #child table size
    Cfile.write("    %d\n" % (int(configNode.get("MacTableSize"), 0)))
    Cfile.write("};\n")
    if configNode.tag == "ChildNodes" and "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
        Cfile.write("""
PRIVATE const ZPS_tsNwkNibTbl s_sNwkTbl = {
    s_asNwkNtDisc,
    s_asNwkNtActv,
    NULL,
    NULL,
    s_asNwkBtt,
    NULL,
    s_asNwkSecMatSet,
    (ZPS_tsNwkNibInitialValues*)&s_sNibInitialValues,
    s_au16NwkAddrMapNwk,
    s_au16NwkAddrMapLookup,
    s_asNwkInFCSet,
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    0,
#endif
    s_au64NwkAddrMapExt,
    s_au32ZedTimeoutCount,
    s_au8KeepAliveFlags,
#ifdef ZPS_FRQAG
    s_au32RxPacketCount,
    s_au32TxPacketCount,
#else
    NULL,
    NULL,
#endif    
};\n""")
    else:
        Cfile.write("""
PRIVATE const ZPS_tsNwkNibTbl s_sNwkTbl = {
    s_asNwkNtDisc,
    s_asNwkNtActv,
    s_asNwkRtDisc,
    s_asNwkRt,
    s_asNwkBtt,
    s_asNwkRct,
    s_asNwkSecMatSet,
    (ZPS_tsNwkNibInitialValues*)&s_sNibInitialValues,
    s_au16NwkAddrMapNwk,
    s_au16NwkAddrMapLookup,
    s_asNwkInFCSet,
#if (defined JENNIC_CHIP_FAMILY_JN516x) || (defined JENNIC_CHIP_FAMILY_JN517x)
    0,
#endif
    s_au64NwkAddrMapExt,
    s_au32ZedTimeoutCount,
    s_au8KeepAliveFlags,
#ifdef ZPS_FRQAG
    s_au32RxPacketCount,
    s_au32TxPacketCount,
#else
    NULL,
    NULL,
#endif    
};\n""")

    # Application layer context
    Cfile.write("\n/* Application Layer Context */\n")

    if not securityDisabled and hasattr(configNode, "TrustCenter"):
        numRequestKeyRequests = 4
    else:
        numRequestKeyRequests = 1
    timeoutRequestKey = 15 #seconds
    Cfile.write("#ifdef WWAH_SUPPORT\n")
    Cfile.write("PRIVATE ZPS_tsAplAibExtensions s_sAibExtension = { \n" )
    Cfile.write("  0  };\n" )
    Cfile.write("\nconst void *zps_g_pvAib_extensions = &s_sAibExtension;\n") 
    Cfile.write("#endif\n" )
	
    Cfile.write("PRIVATE zps_tsRequestKeyRequests s_asRequestKeyRequests[%d];\n" % (numRequestKeyRequests))
    Cfile.write("PRIVATE zps_tsApl s_sApl = {\n")

    Cfile.write("    s_sNwkContext,\n")
    Cfile.write("    &s_sNwkTblSize,\n")
    Cfile.write("    &s_sNwkTbl,\n")

    Cfile.write("    NULL,\n")
    Cfile.write("    &s_sAplAib,\n")

    Cfile.write("    zps_vGetZpsMutex,\n" )

    if configNode.get("DefaultCallbackName"):
        DefaultCallbackName = configNode.get("DefaultCallbackName")
    else:
        return 1
    Cfile.write("    &%s,\n" % (DefaultCallbackName))

    # message handles
    MACMlmeDcfmIndMessage = "zps_msgMlmeDcfmInd"
    MACMcpsDcfmIndMessage = "zps_msgMcpsDcfmInd"
    MACTimeEventMessage = "zps_TimeEvents"
    Cfile.write("    &%s,\n" % MACMcpsDcfmIndMessage)
    Cfile.write("    &%s,\n" % MACMlmeDcfmIndMessage)
    Cfile.write("    &%s,\n" % (MACTimeEventMessage))

    MACMcpsDcfmEventMessage = "zps_msgMcpsDcfm"
    Cfile.write("    &%s,\n" % (MACMcpsDcfmEventMessage))

    Cfile.write("    { 0 },\n")

    if "Coordinator" == configNode.tag:
        nodeType = "ZPS_ZDO_DEVICE_COORD"
    elif "ChildNodes" == configNode.tag:
        if "zpscfg:Router" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            nodeType = "ZPS_ZDO_DEVICE_ROUTER"
        elif "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            nodeType = "ZPS_ZDO_DEVICE_ENDDEVICE"
        else:
            nodeType = "<undefined>"

    permitJoiningTime = 0
    if configNode.get("PermitJoiningTime"):
        permitJoiningTime = int(configNode.get("PermitJoiningTime"), 0)

    # default scan duration to 4 for rejoin etc.
    scanDuration = 4
    if configNode.get("ScanDuration"):
        scanDuration = int(configNode.get("ScanDuration"), 0)

    Cfile.write("    {\n")
    Cfile.write("         { 0x1B, 0x19, 0x4A },\n")
    Cfile.write("        0,\n" )
    Cfile.write("        %s,\n" % (nodeType))

    Cfile.write("        ZPS_ZDO_PRECONFIGURED_LINK_KEY,\n")

    Cfile.write("        0x%02x,\n" % (permitJoiningTime))
    Cfile.write("        2,\n")
    Cfile.write("        2,\n")
    Cfile.write("        %d,\n" %(scanDuration))
    Cfile.write("        FALSE,\n")
    Cfile.write("        s_asAplZdoServers,\n")
    Cfile.write("        vZdoServersInit,\n")
    Cfile.write("        { /* timer struct */},\n")
    Cfile.write("        { /* timer struct */},\n")
    Cfile.write("        0,\n")
    maxNumPollFailures = 3
    if configNode.get("NumPollFailuresBeforeRejoin"):
        maxNumPollFailures = int(configNode.get("NumPollFailuresBeforeRejoin"), 0)
    Cfile.write("        %d,\n" % (maxNumPollFailures))
    Cfile.write("        %d,\n" % (securityDisabled))

    if securityDisabled or not securityInitialKey:
        Cfile.write("        NULL,\n")
    elif securityInitialKey:
        Cfile.write("        &s_sInitSecKey,\n")

    Cfile.write("        0,\n" )
    Cfile.write("        NULL,\n" )
    Cfile.write("        NULL,\n" )
    Cfile.write("        s_asRequestKeyRequests,\n")
    Cfile.write("        %d,\n" % (timeoutRequestKey * 62500))
    Cfile.write("        %d\n" % (numRequestKeyRequests))

    Cfile.write("    },\n")

    Cfile.write("    {\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        &s_sNodeDescriptor,\n")
    Cfile.write("        &s_sNodePowerDescriptor,\n")

    Cfile.write("        %d,\n" % (len(list(configNode.Endpoints))))
    Cfile.write("        s_asSimpleDescConts,\n")

    if not R23_UPDATES:
        if hasattr(configNode, "UserDescriptor"):
            Cfile.write("        &s_sUserDescriptor,\n")
        else:
            Cfile.write("        NULL,\n")

    # TODO - complex descriptor
    #Cfile.write("        NULL,\n")

    Cfile.write("        NULL,\n")

    # zcp_u8FragApsAckValue
    Cfile.write("        0xff,\n")

    # zcp_u8FragBlockControl
    Cfile.write("        0x00\n")

    Cfile.write("    },\n")

    # APS Context
    Cfile.write("    {\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        NULL,\n")
    Cfile.write("        &s_sApsDuplicateTable,\n")
    Cfile.write("        s_asApsSyncMsgPool,\n")

    apsDuplicateTableSize = 1
    if configNode.get("APSDuplicateTableSize"):
        apsDuplicateTableSize = int(configNode.get("APSDuplicateTableSize"), 0)
    Cfile.write("        0x%02x,\n" % (apsDuplicateTableSize))

    Cfile.write("        0,\n")
    Cfile.write("        %d,\n" % (int(configNode.get("MaxNumSimultaneousApsdeAckReq"), 0)) )
    Cfile.write("        0,\n")
    Cfile.write("        { s_asApsDcfmRecordPool, 1, %d },\n" % (int(configNode.get("MaxNumSimultaneousApsdeReq"), 0)) )
    Cfile.write("        &g_sApsCounters,\n")

    fragmentationEnabled = int(configNode.get("FragmentationMaxNumSimulRx"), 0) > 0 or int(configNode.get("FragmentationMaxNumSimulTx"), 0) > 0

    APSPersistenceTime = 100
    if configNode.get("APSPersistenceTime"):
        if int(configNode.get("APSPersistenceTime"), 0) > 25:
            APSPersistenceTime = int(configNode.get("APSPersistenceTime"), 0)

    if int(configNode.get("FragmentationMaxNumSimulRx"), 0) > 0:
        Cfile.write("        { s_asApsFragRxPool, %d, %d },\n" % (int(configNode.get("FragmentationMaxNumSimulRx"), 0), APSPersistenceTime) )
    else:
        Cfile.write("        { NULL, 0, 0 },\n")

    if int(configNode.get("FragmentationMaxNumSimulTx"), 0) > 0:
        Cfile.write("        { s_asApsFragTxPool, %d },\n" % (int(configNode.get("FragmentationMaxNumSimulTx"), 0)) )
    else:
        Cfile.write("        { NULL, 0 },\n")

    if int(configNode.get("FragmentationMaxNumSimulTx"), 0) > 0:
        Cfile.write("        zps_eStartFragmentedTransmission,\n")
        Cfile.write("        zps_vHandleExtendedDataAckFrame,\n")
    else:
        Cfile.write("        NULL,\n")
        Cfile.write("        NULL,\n")

    if int(configNode.get("FragmentationMaxNumSimulRx"), 0) > 0:
        Cfile.write("        zps_vHandleApsdeDataFragInd,\n")
    else:
        Cfile.write("        zps_vHandleApsdeDataFragIndNotSupported,\n")
    if R23_UPDATES:
        Cfile.write("        {},\n")
        Cfile.write("        FALSE,\n")

    # apsme command manager
    Cfile.write("        { &s_sApsmeCmdContainer_1, NULL },\n")

    APSPollPeriod = 100
    if configNode.get("APSPollPeriod"):
        if int(configNode.get("APSPollPeriod"), 0) > 25:
            APSPollPeriod = int(configNode.get("APSPollPeriod"), 0)
    Cfile.write("        { { /* Timer */}, %d, 0 },\n" % APSPollPeriod)
    Cfile.write("        { NULL, NULL },\n")
    Cfile.write("        { /* Timer */}\n")

    Cfile.write("    },\n")

    if not securityDisabled and hasattr(configNode, "TrustCenter"):
        Cfile.write("    &s_sTrustCenterContext\n")
    else:
        Cfile.write("    NULL\n")

    Cfile.write("};\n")
    Cfile.write("\nconst void *zps_g_pvApl = &s_sApl;\n")

    Cfile.write("""
/****************************************************************************/
/***        Exported Variables                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/

/****************************************************************************/
/***        Local Functions                                               ***/
/****************************************************************************/
PUBLIC void *ZPS_pvAplZdoGetAplHandle(void)
{
    return (void*)zps_g_pvApl;
}

PUBLIC uint32 ZPS_u32ApsFcSaveCountBitShift(void)
{
    return g_u32ApsFcSaveCountBitShift;
}

PUBLIC ZPS_tsAplApsKeyDescriptorEntry** ZPS_psAplDefaultDistributedAPSLinkKey(void)
{
    return &psAplDefaultDistributedAPSLinkKey;
}

PUBLIC ZPS_tsAplApsKeyDescriptorEntry** ZPS_psAplDefaultGlobalAPSLinkKey(void)
{
    return &psAplDefaultGlobalAPSLinkKey;
}

PUBLIC ZPS_tsPdmGroupTable* ZPS_ps_groupPdmTable(void)
{
    return &s_groupPdmTable;
}

PUBLIC uint8* ZPS_pu8MaxZpsConfigEp(void) 
{
    return &u8MaxZpsConfigEp;
}

PUBLIC uint8* ZPS_pau8EpMapPresent(void)
{
    return &au8EpMapPresent[0];
}

PUBLIC uint8 ZPS_u8ConfigStackProfileId(void)
{
    return u8ZpsConfigStackProfileId;
}

PUBLIC uint32 ZPS_u32NwkFcSaveCountBitShift(void)
{
    return g_u32NwkFcSaveCountBitShift;
}
""")
    #MAC interface table
    Cfile.write("\n/****************************************************************************\n")
    Cfile.write(" *\n")
    Cfile.write(" * NAME: ZPS_psMacIFTGetTable\n")
    Cfile.write(" *\n")
    Cfile.write(" * DESCRIPTION:\n")
    Cfile.write(" * Obtain the pointer to the Mac inteface table \n")
    Cfile.write(" *\n")
    Cfile.write(" * PARAMETERS 			Name  	   		RW  	Usage \n")
    Cfile.write(" *\n")
    Cfile.write(" * RETURNS:\n")
    Cfile.write(" * Address of Mac interface table if successful, NULL otherwise \n")
    Cfile.write(" *\n")
    Cfile.write(" ****************************************************************************/ \n")
    Cfile.write(" PUBLIC MAC_tsMacInterfaceTable* ZPS_psMacIFTGetTable(void) \n")
    Cfile.write(" {\n")
    Cfile.write("	 return &g_asMacInterfaceTable; \n")
    Cfile.write(" }\n")


    Cfile.write("\n/****************************************************************************\n")
    Cfile.write(" *\n")
    Cfile.write(" * NAME: ZPS_psMacIFTGetInterface \n")
    Cfile.write(" *\n")
    Cfile.write(" * DESCRIPTION:\n")
    Cfile.write(" * Get the Mac interface entry from the MAC interface table for the specified\n")
    Cfile.write(" * Mac ID\n")
    Cfile.write(" *\n")
    Cfile.write(" * PARAMETERS 	Name  		RW  	Usage\n")
    Cfile.write(" *				u8MacID		R		The Mac Id for the interface\n")
    Cfile.write(" * RETURNS:\n")
    Cfile.write(" * Address of Mac interface structure if found, NULL otherwise\n")
    Cfile.write(" *\n")
    Cfile.write(" ****************************************************************************/ \n")
    Cfile.write(" PUBLIC MAC_tsMacInterface* ZPS_psMacIFTGetInterface(uint8 u8MacID)\n")
    Cfile.write(" { \n")
    Cfile.write("	 MAC_tsMacInterface *pRet = NULL;\n")
    Cfile.write(" 	 if(u8MacID < g_asMacInterfaceTable.u8NumInterfaces) \n")
    Cfile.write(" 	 {\n")
    Cfile.write(" 		 pRet = &g_asMacInterfaceTable.psMacInterfaces[u8MacID];\n")
    Cfile.write(" 	 }\n")
    Cfile.write(" 	 return pRet;\n")
    Cfile.write(" }\n")

    # ZDP servers init function
    if hasattr(configNode, "ZDOServers"):
        Cfile.write("\n/* ZDO Server Initialisation */\n")
        Cfile.write("PUBLIC void vZdoServersInit(void)\n{\n")

    for server in configNode.ZDOServers.iterchildren():
        if (server.tag not in deprecatedZdoServers):
            Cfile.write("    zps_vAplZdo%sInit(" % (server.tag))
            (outputParams, outputParamTypes) = zdoServers[server.tag]
            # print(outputParams, outputParamTypes)
            outputParams(Cfile, server)
            Cfile.write(");\n")

    if "Coordinator" == configNode.tag:
        Cfile.write("    zps_vRegisterCallbackForSecondsTick(ZPS_vSecondTimerCallback);\n")
    elif "zpscfg:Router" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
        Cfile.write("    zps_vRegisterCallbackForSecondsTick(ZPS_vSecondTimerCallback);\n")
    Cfile.write("}\n")

    Cfile.write("\nPUBLIC void* ZPS_vGetGpContext(void)\n{\n")
    Cfile.write("\n    return g_psGreenPowerContext;\n}\n")

    Cfile.write("\nPUBLIC void* zps_vGetZpsMutex(void)\n{\n")
    Cfile.write("\n    return &g_pbZpsMutex;\n}\n")

    Cfile.write("\n\nPUBLIC void ZPS_vGetOptionalFeatures(void)\n{\n")
    if configNode.get("InterPAN"):
        if "true" == configNode.get("InterPAN").lower():
            Cfile.write("   ZPS_vAfInterPanInit();\n")

    if configNode.get("GreenPowerSupport"):
        if "true" == configNode.get("GreenPowerSupport").lower():
                Cfile.write("   ZPS_vRegisterGreenPower();\n")
                if hasattr(configNode, "GreenPowerTxQueue"):
                    Cfile.write("   ZPS_vZgpInitGpTxQueue();\n")
                if hasattr(configNode, "GreenPowerSecurityTable"):
                    Cfile.write("   ZPS_vZgpInitGpSecurityTable();\n")

    Cfile.write("}\n")

    Cfile.write("""
/****************************************************************************/
/***        END OF FILE                                                   ***/
/****************************************************************************/
""")

    Cfile.close()
    mode = os.stat(fsp).st_mode
    mode = mode & (~stat.S_IWUSR | stat.S_IRUSR)
    os.chmod(fsp, mode)

###############################################################################
# Create header file
def outputHeader(dir, configNode):
    fsp = os.path.join(dir, "zps_gen.h")
    if (os.path.exists(fsp)):
        mode = os.stat(fsp).st_mode
        mode = mode | stat.S_IWUSR
        os.chmod(fsp, mode)
    Hfile = open(fsp, "w")

    Hfile.write("""/****************************************************************************
 *
 *                 THIS IS A GENERATED FILE. DO NOT EDIT!
 *
 * MODULE:         ZPSConfig
 *
 * COMPONENT:      zps_gen.h
 *
 * DATE:           %s
 *
 * AUTHOR:         NXP Zigbee Protocol Stack Configuration Tool
 *
 * DESCRIPTION:    ZPS definitions
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
"""  % (datetime.datetime.ctime(datetime.datetime.now()), datetime.datetime.today().year))

    Hfile.write("""
#ifndef _ZPS_GEN_H
#define _ZPS_GEN_H

/****************************************************************************/
/***        Macro Definitions                                             ***/
/****************************************************************************/

""")
    Hfile.write("#include <jendefs.h>\n")
    # TODO select nwk layer?
    Hfile.write("#define ZPS_NWK_OPT_ALL\n")

    # Output define for node type
    if "Coordinator" == configNode.tag:
        Hfile.write("#define ZPS_COORDINATOR\n")
    elif "Childnodes" == configNode.tag:
        if "zpscfg:Router" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            Hfile.write("#define ZPS_ROUTER\n")
        elif "zpscfg:EndDevice" == configNode.get('{' + configNode.nsmap["xsi"] + '}' + "type"):
            Hfile.write("#define ZPS_END_DEVICE\n")

    Hfile.write("#define ZPS_NODE_%s\n" % (configNode.get("Name").upper()))

    # Output profile constant definitions
    for profile in config.ZigbeeWirelessNetwork.Profiles:
        Hfile.write("\n/* Profile '%s' */\n" % (profile.get("Name")))
        id = int(profile.get("Id"), 0)
        Hfile.write("#define %s_PROFILE_ID    (0x%04x)\n" % (profile.get("Name").upper(), id))
        for cluster in profile.Clusters:
            id = int(cluster.get("Id"), 0)
            Hfile.write("#define %s_%s_CLUSTER_ID    (0x%04x)\n" % (profile.get("Name").upper(), cluster.get("Name").upper(), id))

    node = config.ZigbeeWirelessNetwork.Coordinator
    Hfile.write("\n/* Node '%s' */\n" % (node.get("Name")))
    Hfile.write("/* Endpoints */\n")
    for endpoint in node.Endpoints:
        id = int(endpoint.get("Id"), 0)
        Hfile.write("#define %s_%s_ENDPOINT    (%d)\n" % (node.get("Name").upper(), endpoint.get("Name").upper(), id))

    if hasattr(config.ZigbeeWirelessNetwork, "ChildNodes"):
        for node in config.ZigbeeWirelessNetwork.ChildNodes:
            Hfile.write("\n/* Node '%s' */\n" % (node.get("Name")))
            Hfile.write("\n/* Endpoints */\n")
            for endpoint in node.Endpoints:
                id = int(endpoint.get("Id"), 0)
                Hfile.write("#define %s_%s_ENDPOINT    (%d)\n" % (node.get("Name").upper(), endpoint.get("Name").upper(), id))

    Hfile.write("/* Table Sizes */\n")
    if hasattr(configNode, "BindingTable"):
        BindTableSize = int(configNode.BindingTable.get("Size"), 0)
    else:
        BindTableSize = 0

    if hasattr(configNode, "GroupTable"):
        groupTableSize = int(configNode.GroupTable.get("Size"), 0)
    else:
        groupTableSize = 0

    if configNode.get("ChildTableSize"):
        childTableSize = int(configNode.get("ChildTableSize"), 0)
    else:
        childTableSize = 0

    channelMaskListCount = 0
    if hasattr(configNode, "MacInterfaceList"):
        for interface in configNode.MacInterfaceList.MacInterface:
            channelMaskListCount += int(interface.get("ChannelListSize"))
    else:
        channelMaskListCount = 0

    Hfile.write("#define ZPS_NEIGHBOUR_TABLE_SIZE      (%d)\n" % (int(configNode.get("ActiveNeighbourTableSize"), 0)))
    Hfile.write("#define ZPS_ADDRESS_MAP_TABLE_SIZE    (%d)\n" % (int(configNode.get("AddressMapTableSize"), 0)))
    Hfile.write("#define ZPS_ROUTING_TABLE_SIZE        (%d)\n" % (int(configNode.get("RoutingTableSize"), 0)))
    Hfile.write("#define ZPS_MAC_ADDRESS_TABLE_SIZE    (%d)\n" % (int(configNode.get("MacTableSize"), 0)))
    Hfile.write("#define ZPS_BINDING_TABLE_SIZE        (%d)\n" % (BindTableSize))
    Hfile.write("#define ZPS_GROUP_TABLE_SIZE          (%d)\n" % (groupTableSize))
    Hfile.write("#define ZPS_CHILD_TABLE_SIZE          (%d)\n" % (childTableSize))
    Hfile.write("#define ZPS_MAX_CHANNEL_LIST_SIZE     (%d)\n" % (channelMaskListCount))
    Hfile.write("""
/****************************************************************************/
/***        Type Definitions                                              ***/
/****************************************************************************/

/****************************************************************************/
/***        External Variables                                            ***/
/****************************************************************************/

extern void *g_pvApl;


/****************************************************************************/
/***        Exported Functions                                            ***/
/****************************************************************************/
PUBLIC void* ZPS_vGetGpContext(void);
/****************************************************************************/
/****************************************************************************/
/****************************************************************************/

#endif
""")
    Hfile.close()
    mode = os.stat(fsp).st_mode
    mode = mode & (~stat.S_IWUSR | stat.S_IRUSR)
    os.chmod(fsp, mode)

###############################################################################
# ZDP servers

def outputDefaultServerInitParams(file, node):
    apdu = findAPdu(node.getparent().getparent(), node.get("OutputAPdu"))
    if None != apdu:
        file.write("&s_s%sContext, %s" % (node.tag, apdu.get("Name") ) )
    else:
        print("WARNING: Server '%s' has no output APDU defined.\n" %(node.tag))

def outputDefaultServerInitParamTypes(file):
    file.write("void *, PDUM_thAPdu ")

def outputEndDeviceBindServerInitParams(file, node):
    apdu = findAPdu(node.getparent().getparent(), node.get("OutputAPdu"))
    if None != apdu:
        file.write("&s_s%sContext, %s, %d, %d" % (node.tag, apdu.get("Name"), int(node.get("Timeout"), 0) * 62500, int(node.get("BindNumRetries"), 0)) )
    else:
        print("WARNING: Server '%s' has no output APDU defined.\n" %(node.tag))

def outputEndDeviceBindServerInitParamTypes(file):
    file.write("void *, PDUM_thAPdu , uint32 , uint8 ")

def outputDeviceAnnceServerInitParams(file, node):
    # only context needed
    file.write("&s_s%sContext" % (node.tag ) )

def outputDeviceAnnceServerInitParamTypes(file):
    file.write("void *")

def outputMgmtNWKUpdateServerInitParams(file, node):
    apdu = findAPdu(node.getparent().getparent(), node.get("OutputAPdu"))
    if None != apdu:
        file.write("&s_s%sContext, %s, &s_sApl" % (node.tag, apdu.get("Name") ) )
    else:
        print("WARNING: Server '%s' has no output APDU defined.\n" %(node.tag))

def outputMgmtNWKUpdateInitParamTypes(file):
    file.write("void *, PDUM_thAPdu , void *")


def outputBindRequestServerInitParams(file, node):
    # only context needed
    TimeInterval = int(node.get("TimeInterval"),0)
    NumOfSimRequests = int(node.get("SimultaneousRequests"),0)
    file.write("&s_s%sContext, %d, %d, %s" % (node.tag , TimeInterval, NumOfSimRequests, "s_sBindRequestServerAcksDcfmContext" ))

def outputBindRequestServerInitParamTypes(file):
    file.write("void *, uint8, uint8, zps_tsZdoServerConfAckContext* ")


zdoServers = {
    'EndDeviceBindServer'         : ( outputEndDeviceBindServerInitParams, outputEndDeviceBindServerInitParamTypes ),
    'DefaultServer'               : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'DeviceAnnceServer'           : ( outputDeviceAnnceServerInitParams, outputDeviceAnnceServerInitParamTypes ),
    'ActiveEpServer'              : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'NwkAddrServer'               : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'IeeeAddrServer'              : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'SystemServerDiscoveryServer' : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'PermitJoiningServer'         : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'NodeDescServer'              : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'PowerDescServer'             : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MatchDescServer'             : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'SimpleDescServer'            : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtLqiServer'               : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtRtgServer'               : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtLeaveServer'             : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtNWKUpdateServer'         : ( outputMgmtNWKUpdateServerInitParams, outputMgmtNWKUpdateInitParamTypes ),
    'MgmtBindServer'              : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'BindUnbindServer'            : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'ExtendedActiveEpServer'      : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'ExtendedSimpleDescServer'    : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'ZdoClient'                   : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'BindRequestServer'           : ( outputBindRequestServerInitParams, outputBindRequestServerInitParamTypes ),
    'ParentAnnceServer'           : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtMibIeeeServer'           : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
    'MgmtNWKEnhanceUpdateServer'  : ( outputMgmtNWKUpdateServerInitParams, outputMgmtNWKUpdateInitParamTypes ),
    'SecurityServer'              : ( outputDefaultServerInitParams, outputDefaultServerInitParamTypes ),
}

patchFunctions = [
    'vHandleEndpointInd',
    'vHandleApsdeDataInd',
    'vHandleApsdeDataDcfm',
    'u32GetScanChannels',
    'eStartNetworkFormation',
    'eStartNetworkDiscovery',
    'eStartRouter',
    'vHandleNetworkFormation',
    'vHandleNetworkDiscovery',
    'vHandleJoin',
    'vHandleJoinInd',
    'vHandleLeaveInd',
    'vHandleLeaveCfm',
    'vHandleNwkStatusInd',
    'vHandleRemoveDeviceIndication',
    'vHandleSwitchKeyIndication',
    'vHandleUpdateDeviceIndication',
    'vHandleTransportKeyIndication'
]

###############################################################################
###############################################################################
###############################################################################

if not options.OptionalFeatures:
    print("ZPSConfig - Zigbee Protocol Stack Configuration Tool v%s\n"  % (version))
    sys.stdout.flush()

# Argument validation
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
    sys.exit(2)

if not os.path.exists(options.configFilename):
    print("ERROR: unable to open configuration file '%s'.\n" % options.configFilename)
    sys.exit(3)

if "" == options.zigbeeNodeName:
    print("ERROR: A node must be specified.\n" )
    sys.exit(9)

OptionalFeatures = 0
if options.OptionalFeatures:
    config = xml_objectify(options.configFilename)
    node = findNode(options.zigbeeNodeName)
    if node.get("InterPAN"):
        if "true" == node.get("InterPAN").lower():
            OptionalFeatures |= 1

    if node.get("GreenPowerSupport"):
        if "true" == node.get("GreenPowerSupport").lower():
                OptionalFeatures |= 2

    print(OptionalFeatures)
    sys.exit(0)

if not os.path.exists(options.zigbeeNwkLibFSP):
    print("ERROR: unable to locate Zigbee target library file '%s'.\n" % options.zigbeeNwkLibFSP)
    sys.exit(4)

if not os.path.exists(options.zigbeeAplLibFSP):
    print("ERROR: unable to locate Zigbee target library file '%s'.\n" % options.zigbeeAplLibFSP)
    sys.exit(5)
if None == re.search('_R23', options.zigbeeAplLibFSP):
    print("R22 mode for APL library file '%s'.\n" % options.zigbeeAplLibFSP)
else:
    print("R23 mode for APL library file '%s'.\n" % options.zigbeeAplLibFSP)
    R23_UPDATES = 1

if None != re.search('_WWAH', options.zigbeeAplLibFSP):
    WWAH_SUPPORT = 1

if None != options.outputDir and (not os.path.exists(options.outputDir)):
    print("ERROR: Output directory '%s' does not exist.\n" % options.outputDir)
    sys.exit(6)

if '' != options.ToolsDir:
    if not os.path.exists(options.ToolsDir):
        print("ERROR: unable to locate Compiler Tools directory '%s'.\n" % options.ToolsDir)
        sys.exit(7)

    # When embedding the python script in the shell, the path was changed from \\
    if options.endian == "BIG_ENDIAN":
        objdump = os.path.normpath(options.ToolsDir + '\\\\bin\\\\ba-elf-objdump')
    else:
        if os.name == 'nt':
            objdump = os.path.normpath(options.ToolsDir + '\\\\bin\\\\arm-none-eabi-objdump')
        else:
            objdump = os.path.normpath(options.ToolsDir + '/bin/arm-none-eabi-objdump')
else:
    if options.endian == "BIG_ENDIAN":
        objdump = 'ba-elf-objdump'
    else:
        objdump = 'arm-none-eabi-objdump'

config = xml_objectify(options.configFilename)
if "" == options.zigbeeNodeName:
    print("ERROR: A node must be specified.\n" )
    sys.exit(9)

if not os.path.exists(options.configFilename + "xtra"):
    print("INFO: Unavalabile extra attributes configuration file '%s'.\n" % (options.configFilename + "xtra"))
    xtra = None
else:
    xtra = xml_objectify(options.configFilename + "xtra")
    mergeNodeXtra(options.zigbeeNodeName)

if validateConfiguration(options.zigbeeNodeName):
    node = findNode(options.zigbeeNodeName)
    outputHeader(options.outputDir, node)
    outputC(options.outputDir, node, options.endian)
    print("Done.\n")
    sys.exit(0)
else:
    # Error found in input file
    sys.exit(1)
