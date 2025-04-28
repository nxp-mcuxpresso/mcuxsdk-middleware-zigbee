# Power descriptor

The Node Power descriptor contains information about the node’s supported power sources and present power source. The following functions can be used to obtain a Power descriptor:

-   **zps\_eAplAfGetNodePowerDescriptor\(\)** obtains the Node Power descriptor of the local node. The result is stored in a structure of type `zps_tsAplAfNodePowerDescriptor`.
-   **zps\_eAplZdpPowerDescRequest\(\)** requests the Node Power descriptor of a remote node. The result is stored in a structure of type `zps_tsAplZdpNodePowerDescriptor`.

Note that elements of the Node Power descriptor can be set on the local node using the ZPS Configuration Editor.

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

