# Node descriptor

The Node descriptor contains basic information about the node, such as its ZigBee node type and the radio frequency bands supported. The following functions can be used to obtain a Node descriptor:

-   **zps\_eAplAfGetNodeDescriptor\(\)** obtains the Node descriptor of the local node. The result is stored in a structure of type `zps_tsAplAfNodeDescriptor`.
-   **zps\_eAplZdpNodeDescRequest\(\)** requests the Node descriptor of a remote node. The result is stored in a structure of type `zps_tsAplZdpNodeDescriptor`.

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

