# Unicasts from sleepy nodes

To allow a unicast acknowledgment to be received as described above, the source node must remain awake for a time equal to the timeout period. On a battery-powered node which sleeps, the use of acknowledgments and retries may not be desirable from a power-saving point of view. In this case, acknowledgments should not be used, but it is good practice for the application to monitor the route to a remote node by periodically attempting to read an attribute on the node and wait for a response. If the response is not observed within a pre-defined time then the application should take one of the actions listed below, depending on whether the source node is an End Device or Router.

-   If an End Device, the application should notify the parent node about the routing problem by sending it a unicast network status command using the function **zps\_vNwkSendNwkStatusCommand\(\)**, with the status as “No Route Available \(0x00\)”
-   If a Router, the application should initiate an explicit route discovery to the destination node by calling the function **zps\_eAplZdoRouteRequest\(\)**

**Parent topic:**[Unicast](../topics/unicast.md)

