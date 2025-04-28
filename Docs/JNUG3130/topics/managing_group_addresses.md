# Managing group addresses

A ‘group address’ is a concept that simplifies data transfers \(see [Section 6.5](transferring_data.md)\) to multiple nodes/endpoints. It is a collective 16-bit address which refers to a group of destination endpoints \(that may be located on different nodes\). So, for example, when a group address is specified as the destination address for a data transfer, the data will be delivered to all the nodes/endpoints in the associated group. It is the responsibility of the wireless network application to allocate and manage group addresses on a network-wide basis.

A node which is to receive group-addressed communications must have a Group Address table. This table contains information about all the groups to which endpoints on the node belong - that is, each group address and the associated local endpoint numbers. The table is consulted on receiving a data packet with a group address - if the group address exists in the table, the packet is passed to the corresponding endpoint\(s\).

A Group Address table is created on a node using the ZPS Configuration Editor. The table can then be maintained by the application as follows:

-   An endpoint can be added to a group by calling the function **zps\_eAplZdoGroupEndpointAdd\(\)** on the local node \(which contains the endpoint\).
-   An endpoint can be removed from a group by calling the function **zps\_eAplZdoGroupEndpointRemove\(\)** on the local node \(which contains the endpoint\). Alternatively, **zps\_eAplZdoGroupAllEndpointRemove\(\)** can be used to remove a specified local endpoint from all groups to which it belongs.

The group addresses used in a network are defined by the application developer.

**Parent topic:**[Application coding with ZigBee PRO APIs](../topics/application_coding_with_zigbee_pro_apis.md)

