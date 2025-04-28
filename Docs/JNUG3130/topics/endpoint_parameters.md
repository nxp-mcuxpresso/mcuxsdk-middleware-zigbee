# Endpoint parameters

**Endpoint parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Application Device Id*|Device ID for the endpoint.|||
|*Application Device Version*|Version number for the device.|||
|*Enabled*|Whether the endpoint is enabled or disabled.|true|true / false|
|*End Point Id*|The endpoint number \(must be unique within the network\).||1-240|
|*Name*|Textual name for the endpoint. Used as a prefix when generating macro definitions.| |Valid C identifier|
|*Profile*|The application profile for the endpoint. This as a link to a profile definition.| | |

**Input Cluster**

Specifies that the endpoint will receive for the specified cluster.

**Input cluster parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Cluster*|A link to an input cluster that will receive on the endpoint.| | |
|*Receive APDU*|A link to an APDU that will buffer any incoming messages.| | |
|*Discoverable*|Defines whether the input cluster will be present in the endpoints simple descriptor which is used for service discovery.|true|true / false|

**Output cluster**

Specifies that the endpoint will transmit for the specified cluster.

**Output cluster parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Cluster*|A link to an output cluster that will transmit on the endpoint.|-|-|
|*Transmit APDUs*|List of APDUs that will be used to transmit the cluster.|-|-|
|*Discoverable*|Defines whether the input cluster will be present in the endpoints Simple descriptor which is used for service dis- covery.|true|true / false|

**Parent topic:**[Advanced device parameters](../topics/advanced_device_parameters.md)

