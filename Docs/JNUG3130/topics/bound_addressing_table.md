# Bound addressing table

Specifies that the device should include a Binding table. Binding is optional. If Binding tables are used, they are located on any node which is a source for a binding, but the ZigBee Coordinator handles end device bind requests on behalf of all devices in the network. Nodes that use Binding tables should be allocated enough Binding table entries to handle their own communication needs.

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Size*|The size of the Binding table. Each binding table entry contains:<br>-   The node address and endpoint number of the source of the binding<br>-   The node address and endpoint number of the destination of the binding<br>-   The cluster ID for the binding<br>If a binding is one-to-many, then a table entry is required for each destination.| | |

**Parent topic:**[Advanced device parameters](../topics/advanced_device_parameters.md)

