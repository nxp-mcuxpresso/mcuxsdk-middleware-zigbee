# Node descriptor

This is mandatory and defines the type and capabilities of the node.

**Node descriptor parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|**Descriptor Availability Parameters**|
|*Complex Descriptor Available*|Complex descriptors are not supported. Not editable.|false|false|
|*User Descriptor Available*|Indicates whether a user descriptor is present. Not editable.|false|true / false|
|**Descriptor Capabilities Parameters**|
|*Extended Active Endpoint List Available*|Indicates whether an extended active endpoint list is available. Not editable.|false|false|
|*Extended Simple Descriptor List Available*|Indicates whether an extended simple descriptor list is available. Not editable.|false|false|
|**MAC Capability Flags**|
|*Allocate Address*|Indicates whether the device allocates short \(network\) addresses or not. Not editable.| |true / false|
|*Alternate PAN Coordinator*|Indicates whether the device acts as an alternative PAN Coordinator. Not editable.| |true / false|
|*Device type*|Indicates whether the device is a Full Functionality Device \(FFD\) or Reduced Functionality Device \(RFD\). Not editable.| |true / false|
|*Power source*|Indicates whether the device is mains powered or not. Not editable.| |true / false|
|*Rx On When Idle*|Indicates whether the device has its receiver enabled while the device is idle. Not editable.| |true / false|
|*Security*|Indicates whether the device uses high or standard security. Only standard security is supported. Not editable.|false|true / false|
|**Miscellaneous parameters**|
|*APS flags*|Not editable.|0|0|
|*Frequency Band*|Frequency band of radio. The the JN518x and K32W041/K32W061/K32W1/MCXW71/ MCXW72/RW612 devices only support the 2.4 GHz band. Not editable.|2.4 GHz|2.4 GHz|
|*Logical Type*|The device type: Coordinator, Router, or End Device. Not editable.| |ZC/ZR/ZED|
|*Manufacturer Code*|The manufacturer ID code. The ZigBee Alliance allocates this code.| |0 - 65535|
|*Maximum buffer size*|The maximum buffer size. Not editable.|127| |
|*Maximum incoming transfer size*|The maximum incoming transfer size supported by the device. This is calculated from the APDU sizes for input clusters. Not editable.| | |
|*Maximum outgoing transfer size*|The maximum incoming transfer size supported by the device. This is calculated from the APDU sizes for output clusters. Not editable| | |
|**System Server Capabilities parameters**|
|*Backup binding table cache*|Indicates if the node can act as a back-up binding table cache. Not supported and not editable.|false|true / false|
|*Backup discovery cache*|Indicates if the node can act as a back-up discovery cache. Not supported and not editable.|false|true / false|
|*Backup trust center*|Indicates if the node can act as a back- up trust centre. Not supported and not editable.|false|true / false|
|*Network manager*|Indicates if the node can act as a net- work manager. Not editable.|false|true / false|
|*Primary binding table cache*|Indicates if the node can act as a primary binding table cache. Not supported and not editable.|false|true / false|
|*Primary discovery cache*|Indicates if the node can act as a primary discovery cache. Not supported and not editable.|false|true / false|
|*Primary trust center*|Indicates if the node can act as a trust center. Not editable.|false|true / false|

**Parent topic:**[Advanced device parameters](../topics/advanced_device_parameters.md)

