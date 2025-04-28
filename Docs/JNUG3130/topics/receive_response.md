# Receive response

The node now waits for a response from the potential parent, which determines whether the node is a permitted device and whether the parent is currently allowing devices to join. To determine whether the joining node is a permitted device, the parent consults the Trust Centre \(if it is not the Trust Centre itseIf\). If these criteria are satisfied, the parent will then allow the node to join the network as its child. In its acceptance response to its new child, the parent will include the 16-bit network address that it has randomly allocated to the child \(see [Section 3.2.4](network_addressing.md)\).

If the potential parent is unable to accept the node as a child, a rejection response is sent. to the node, which must then try another potential parent \(or another network\).

**Parent topic:**[Joining a network \(Routers and End Devices\)](../topics/joining_a_network_routers_and_end_devices.md)

