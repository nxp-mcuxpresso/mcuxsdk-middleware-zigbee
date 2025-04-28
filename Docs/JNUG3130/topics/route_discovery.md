# Route discovery

The ZigBee stack network layer supports a ‘route discovery’ facility which finds the best available route to the destination, when sending a message. A message is normally routed along an already discovered mesh route, if one exists. Otherwise, the routing node \(Router or the Coordinator\) involved in sending the message initiates a route discovery. Once complete, the message is sent along the calculated route.

The mechanism for route discovery between two End Devices has the following steps:

1.  A route discovery broadcast is sent by the parent of the source End Device, and contains the destination End Device’s network address.
2.  All routing nodes eventually receive the broadcast, one of which is the parent of the destination End Device.
3.  The parent of the destination node sends back a reply addressed to the parent of the source node.
4.  As the reply travels back through the network, the hop count and a signal quality measure for each hop are recorded. Each routing node in the path can build a Routing table entry containing the best path to the destination End Device.

The best path is usually the one with the least number of hops. However, if a hop on the most direct route has a poor signal quality, a greater chance that retries would be needed. In such cases, a route with more hops might be chosen.

1.  Eventually each routing node in the path has a Routing table entry and the route from source to destination End Device is established. Note that the corresponding route from destination to source is not known - the route discovered is unidirectional.

A source Router implements route discovery in a similar way to the above except the Router broadcasts its own route discovery message \(without needing its parent to do this\). Similarly, the Coordinator broadcasts its own route discovery messages.

**Note:**

Message routing is performed automatically by the ZigBee stack and is transparent to the user application. If required, route discovery is also automatic and transparent to the application.

**Parent topic:**[Network routing](../topics/network_routing.md)

