# Service discovery

Service discovery allows a node to request information from a remote node about the remote node's capabilities. This information is stored in a number of descriptors \(see [Section 3.4.2](descriptors.md)\) on the remote node. It includes the following:

-   The device type and capabilities of the node.
-   The power characteristics of the node.
-   Information about each application running on the node.
-   Optional information such as serial numbers.
-   Other user-defined information - for example, easily understandable names such as ‘*MtgRoomLight*’.

Requests for these descriptors are made by a device during the discovery process that is typically part of the device's configuration and integration into a ZigBee network.

**Parent topic:**[Discovery](../topics/discovery.md)

