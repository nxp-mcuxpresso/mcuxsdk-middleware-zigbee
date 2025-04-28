# Router parameters

**Router Node Type Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|**Miscellaneous Router Parameters**|
|*Name*|Textual name for the node. Used as a pre- fix when generating macro definitions in **zps\_gen.h**.| |Valid C identifier|
|*Permit Joining Time*|Default number of seconds for which permit joining is enabled.<br>-   255 means permanently on<br>-   0 means permanently off|255|0-255|
|*Scan Duration Time*|The length of time to scan the selected RF channels when searching for a network to join.<br>The time spent scanning each channel is:<br>\[aBaseSuperframeDuration x \(2n + 1\)\] symbols<br>where n is the value of the Scan Duration Time parameter.|3|0 – 14|
|*Security Enabled*|Specifies whether the Router will secure communication with other devices in the network.|true|true / false|
|*Initial Security Key*|The initial key that will be used when security is enabled. These are selected from the keys available on the Trust Centre.|None| |

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

