# PDU Manager

The Protocol Data Unit Manager \(PDUM\) configuration is mandatory and must always be present.

**PDU Manager parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Number of NPDUs*|The number of NPDUs available to the ZigBee stack. These are internal to the stack.|16|8 or higher|

**APDU**

Specifies a buffer to contain instances of a cluster.

**APDU parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Instances*|The maximum number of instances of this APDU. Note that this value must be greater than the value of the parameter *Maximum Number of Simultaneous Data Requests with Acks* - see [Advanced device parameters](advanced_device_parameters.md#TABLE_A415BCB2-1230-441F-9FDA-EC0B8653A59E).| | |
|*Name*|The name of the APDU. This is the identifier that should be used in the application C code to refer to the APDU.| |Valid C identifier|
|*Size*|The maximum size of the APDU.| | |

**Parent topic:**[Advanced device parameters](../topics/advanced_device_parameters.md)

