# Broadcast

A broadcast is a data transmission to all network nodes, although it is possible to select a subset of nodes. The following destinations are possible:

-   All nodes
-   All nodes for which ‘receiver on when idle’ - these include the Coordinator, Routers and non-sleeping End Devices
-   All Routers and the Coordinator

The function **zps\_eAplAfBroadcastDataReq\(\)** is used to broadcast a data packet. It is possible to specify a particular destination endpoint on the nodes \(the same endpoint number for all recipient nodes\) or all endpoints. Following this function call, the packet may be broadcast up to four times \(in addition, the packet may be subsequently re-broadcast up to four times by each intermediate routing node\).

**Parent topic:**[Sending data](../topics/sending_data.md)

