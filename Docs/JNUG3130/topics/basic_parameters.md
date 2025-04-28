# Basic parameters

The basic parameters are listed and described in the table below.

**ZigBee Wireless Network parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|----|----|----|----|
|*Default Extended Pan ID*|The default Extended PAN ID \(EPID\) when add- ing new devices to the wireless network. The extended PAN ID is the globally unique 64-bit identifier for the network. This identifier is used to avoid PAN ID conflicts between distinct networks and must be unique among the networks overlap- ping in a given area. If the value is zero on the Coordinator, the device will use its own IEEE/ MAC address as the EPID. A zero value on a Router/End Device means that the device will not look for a particular EPID when joining a network. Note that this value is the default EPID used when adding devices in the ZPS Configuration Editor. The actual EPID used for an individual device can be set via the parameter *APS Use Extended PAN ID*– see [Section 12.7](advanced_device_parameters.md).|0|64 bits|
|*Default Security Enabled*|The default setting for Security Enabled when adding new devices to the wireless network.|true|true / false|
|*Maximum Number of Nodes*|The maximum number of nodes for the wireless network. This setting controls the size of tables when adding new devices to the network to ensure adequate resources are available for correct operation a network of the specified size.|20| |

The rest of the network parameters are detailed in the sections that follow, according to their area of application.

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

