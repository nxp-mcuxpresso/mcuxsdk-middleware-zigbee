# Discovering Routes

The route from one network node to another can be pre-established by implementing a route discovery. As a result, each routing node along the route will contain a Routing table entry for the destination node, where this entry consists of the destination address and the ‘next hop’ address. Routing and route discovery are fully introduced in [Section 3.5](network_routing.md).

Two functions are provided in the ZigBee PRO API to initiate route discoveries:

-   **zps\_eAplZdoRouteRequest\(\)** can be used to establish a route from the local node to a specific destination node. This kind of end-to-end route discovery is outlined in [Section 3.5.2](route_discovery.md).
-   **zps\_eAplZdoManyToOneRouteRequest\(\)** can be used on a ‘concentrator’ node to implement a ‘many-to-one’ route discovery back to itself. The result is that Routing tables in routing nodes within a certain radius of the concentrator will acquire entries with the concentrator as the destination. Many-to-one routing is outlined in [Section 3.5.3](many-to-one_routing.md).

**Parent topic:**[Discovering the network](../topics/discovering_the_network.md)

