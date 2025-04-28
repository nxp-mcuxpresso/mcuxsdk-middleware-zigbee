# End Device parameters

**End Device Node Type Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|**Miscellaneous End Device Parameters**| | | |
|*Name*|Textual name for the node. Used as a prefix when generating macro definitions in **zps\_- gen.h**.| |Valid C identifier|
|*Scan Duration Time*|The length of time to scan the selected RF channels when searching for a network to join.<br> The time spent scanning each channel is:<br> `(aBaseSuperframeDuration * (2n + 1)) symbols` <br> where `n` is the value of the Scan Duration Time parameter.|3|0 – 14|
|*Security Enabled*|Specifies whether the End Device will secure communication with other devices in the network.|true|true / false|
|*Initial Security Key*|The initial key that will be used when security is enabled. These are selected from the keys available on the Trust Centre.|None| |
|*Sleeping*|Indicates whether the device will turn its receiver off and enter a low-power mode. The End Device’s parent will buffer any incoming data until the device returns to its normal operating state and issues a poll request.|false|true / false|
|*Number of Poll Failures Before Rejoin*|This parameter controls the number of consecutive poll failures from when the device returns to its normal operating state before attempting to find a new parent by initiating a network rejoin.|5|0 will disable this behavior|

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

