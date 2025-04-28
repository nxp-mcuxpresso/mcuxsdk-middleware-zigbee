# Group multicast

A group multicast is a data transmission which is intended for a selection of network nodes or, more specifically, a selection of endpoints on these nodes. The set of destination endpoints must be pre-assembled into a group with an associated ‘group address’, as described in [Section 5.3](managing_group_addresses.md).

The function **zps\_eAplAfGroupDataReq\(\)** is used to send a data packet to the group of endpoints with a given group address. In practice, the data packet is broadcast to all nodes in the network and it is the responsibility of each recipient node to determine whether it has endpoints in the target group \(and therefore whether the packet is of interest\).

**Parent topic:**[Sending data](../topics/sending_data.md)

