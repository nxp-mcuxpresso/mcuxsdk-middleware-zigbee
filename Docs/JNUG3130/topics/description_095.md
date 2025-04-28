# Description

This function requests a ‘many-to-one’ route discovery and should be called on a node that will act as a ‘concentrator’ in the network \(that is, a node with which many other nodes will need to communicate\).

As a result of this function call, a route discovery message is broadcast across the network and Routing table entries \(for routes back to the concentrator\) are stored in the Router nodes.

The maximum number of hops to be taken by a route discovery message in this broadcast must be specified. There is also an option to store the discovered routes in a Route Record Table on the concentrator \(for return communications\).

**Parent topic:**[ZPS\_eAplZdoManyToOneRouteRequest](../topics/zps_eaplzdomanytoonerouterequest.md)

