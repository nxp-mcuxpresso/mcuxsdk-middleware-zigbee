# Pre-determined parents

It is possible to force a parent \(Router or the Coordinator\) to accept certain nodes as its \(direct\) children. The function **zps\_eAplZdoDirectJoinNetwork\(\)** can be used on this parent to register a potential child node \(with specified IEEE/MAC and network addresses\) by adding this node to the Neighbor table - *never write to the Neighbor table directly*. The parent then regards this node as an orphaned child. This function should only be called when the parent node is fully up and running - that is, the node has been started as described in [Section 6.1.1](starting_the_coordinator.md) or [Section 6.1.2](starting_routers_and_end_devices.md).

When one of the designated children is started, its application should call the function **zps\_eAplZdoOrphanRejoinNetwork\(\)** in order to attempt to join the network as if it were a previously orphaned node. This function will start the ZigBee PRO stack and attempt to join the network whose EPID has been pre-configured on the node \(using the ZPS Configuration Editor\). The function will only allow the node to join a parent that already has knowledge of the node \(in the parent’s Neighbor table\).

**Note:**

-   Note 1: When `zps_eAplZdoOrphanRejoinNetwork()` is used, the start-up procedure described in [Section 6.1.2](starting_routers_and_end_devices.md) is not applicable to the joining node and the function `zps_eAplZdoStartStack()` must not be explicitly called on the node.
-   Note 2: When a node joins the network in this way, the ‘permit joining’ status on the parent is ignored.

If the node successfully joins the network \(via the designated parent\), the stack event zps\_EVENT\_NWK\_NEW\_NODE\_HAS\_JOINED is generated on the parent node and one of the following stack events is generated on the joined node:

-   zps\_EVENT\_NWK\_JOINED\_AS\_ROUTER \(if joined as a Router\)
-   zps\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE \(if joined as an End Device\)

These events contain the network address that the parent has allocated to the joined node.

If the join request is unsuccessful, the zps\_EVENT\_NWK\_FAILED\_TO\_JOIN event is generated on the joining node.

Once the node has joined the pre-determined parent, the node is next likely to search for compatible endpoints on remote nodes with which it can communicate, as described in [Section 6.2.2](finding_compatible_endpoints.md).

**Parent topic:**[Forming and joining a network](../topics/forming_and_joining_a_network.md)

