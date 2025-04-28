# User Descriptor

The User descriptor is a user-defined character string, normally used to describe the node \(for example, “Thermostat”\). The maximum length of the character string is 16, by default. A node need not have a User descriptor - if it has one, this must be indicated in the Node descriptor. The following functions can be used to access a User descriptor:

-   **zps\_eAplZdpUserDescSetRequest\(\)**sets the User descriptor of a remote node.
-   **zps\_eAplZdpUserDescRequest\(\)**requests the User descriptor of a remote node. The result is stored in a structure of type `zps_tsAplZdpUserDescReq`.

The above functions can only be used to access the User descriptor of a non-NXP device \(which supports this descriptor\), since the storage of a User descriptor on an NXP device is not supported.

**Parent topic:**[Obtaining node properties](../topics/obtaining_node_properties.md)

