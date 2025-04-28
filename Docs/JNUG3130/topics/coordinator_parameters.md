# Coordinator parameters

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|---|---|---|---|
|**Miscellaneous Coordinator Parameters**| | | | 
|*Name*|Textual name for the node. Used as a prefix when generating macro definitions in **zps\_gen.h**.| |Valid C identifier|
|*Permit Joining Time*|Default number of seconds for which permit joining is enabled.<br>-   '255' means permanently on<br>-   '0' means permanently off|255|0-255|
|*Security Enabled*|Specifies whether the Coordinator will secure communication with other devices in the network.|true|true / false|
|*Initial Security Key*|The initial key that will be used when security is enabled. These are selected from the keys available on the Trust Centre.|None| |

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

