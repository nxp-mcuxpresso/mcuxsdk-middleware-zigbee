# Message addressing and propagation

If a message sent from one node to another needs to pass through one or more intermediate nodes to reach its final destination \(up to 30 such hops are allowed\), the message carries two destination addresses:

-   Address of the final destination.
-   Address of the node which is the next "hop".

ZigBee PRO is designed for Mesh networks \(see [Section 3.2.2](network_topology.md)\) in which the message propagation path \(the route\) depends on whether the target node is in radio range:

-   If the target node is in range, only the "final destination" address is used.
-   If the target node is not in range, the "next hop" address is that of the first node in the route to the final destination.

The “next hop” address is determined using information stored in a Routing table on the routing node \(Router or Coordinator\). An entry of this table contains information for a remote node, including the network addresses of the remote node and of the next routing node in the route to the remote node. Thus, when a message is received by a routing node, it looks for the destination address in its Routing table and extracts “next hop” address from this table to insert into the message. The message is then passed on and propagation continues in this way until the target node is reached.

**Note:** If the message originates from an End Device, the message is always first passed to the source node’s parent before being passed on.

**Parent topic:**[Network routing](../topics/network_routing.md)

