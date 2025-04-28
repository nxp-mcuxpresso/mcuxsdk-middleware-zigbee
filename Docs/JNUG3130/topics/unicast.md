# Unicast

A unicast is a data transmission to a single destination - in this case, a single endpoint. The destination node for a unicast can be specified using the network address or the IEEE/MAC address of the node:

-   **zps\_eAplAfUnicastDataReq\(\)** is used to send a data packet to an endpoint on a node with a given network address.
-   **zps\_eAplAfUnicastIeeeDataReq\(\)** is used to send a data packet to an endpoint on a node with a given IEEE/MAC address.

Neither of these functions provide any indication that the data packet has been successfully delivered to its destination. It is possible that a unicast packet will not reach its destination because the packet is lost - for example, it becomes caught in a circular route. However, equivalent functions are available which request the destination node to provide an acknowledgment of data received - these ‘with acknowledgment’ functions are **zps\_eAplAfUnicastAckDataReq\(\)** and **zps\_eAplAfUnicastIeeeAckDataReq\(\)**, requiring network and IEEE/MAC addresses respectively. These functions request end-to-end acknowledgments which, when received, generate zps\_EVENT\_APS\_DATA\_ACK events \(note that the ‘next hop’ zps\_EVENT\_APS\_DATA\_CONFIRM events will also be generated\). A timeout of approximately 1600 ms is applied to the acknowledgments. If an acknowledgment has not been received within the timeout period, the data is re-sent, and up to 3 more re-tries can subsequently be performed before the data transfer is abandoned completely \(which occurs approximately 3 seconds after the initial send\).

**Note:** If a message is unicast to a destination for which a route has not already been established, the message will not be sent and a route discovery will be performed instead. If this is the case, the unicast function will return `zps_NWK_ENUM_ROUTE_ERROR`. The application must then wait for the stack event `zps_EVENT_NWK_ROUTE_DISCOVERY_CONFIRM`\(success or failure\) before attempting to re-send the message by calling the same unicast function again.


```{include} ../topics/unicasts_from_sleepy_nodes.md
:heading-offset: 4
```

```{include} ../topics/fragmenting_large_unicast_packets.md
:heading-offset: 4
```

**Parent topic:**[Sending data](../topics/sending_data.md)

