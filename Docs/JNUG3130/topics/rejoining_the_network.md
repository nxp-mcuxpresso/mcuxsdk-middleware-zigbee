# Rejoining the network

A node may leave its network - for example, by:

-   losing radio contact with its parent - the stack on the ‘orphaned’ node will detect this loss and automatically attempt to rejoin the network
-   calling **zps\_eAplZdoLeaveNetwork\(\)** - the node will automatically attempt to rejoin the network if an immediate rejoin has been requested in the function call \(although the node can be configured to always rejoin the network following a leave, using the function **zps\_vNwkNibSetLeaveRejoin\(\)**\)

If the node successfully rejoins the network, the stack event zps\_EVENT\_NWK\_NEW\_NODE\_HAS\_JOINED is generated on the parent node and one of the following stack events is generated on the joined node:

-   zps\_EVENT\_NWK\_JOINED\_AS\_ROUTER \(if joined as a Router\)
-   zps\_EVENT\_NWK\_JOINED\_AS\_ENDDEVICE \(if joined as an End Device\)

These events contain the network address that the parent has allocated to the joined node \(this may be different from the network address that the node previously had\).

If the join request is unsuccessful, the zps\_EVENT\_NWK\_FAILED\_TO\_JOIN event is generated on the requesting node.

If an automatic rejoin has failed or has not been requested, the function **zps\_eAplZdoRejoinNetwork\(\)** can be used to request a rejoin \(this function must be called on the node that needs to rejoin\). The application may be designed to call this function when a button is pressed on the node. The result of this function call will be indicated by means of the above events.

The function **zps\_eAplZdpMgmtDirectJoinRequest\(\)** is also provided which submits a request to a remote parent to allow a particular node to join it. In addition, the function **zps\_eAplZdpMgmtPermitJoiningRequest\(\)** is provided which allows joining to be enabled/disabled on a remote node.

**Note:**

1.  When a device rejoins a network, the ‘permit joining’ status on the potential parent is ignored.
2.  When a device joins the network, its application may call zps\_eAplZdpDeviceAnnceRequest\(\) to announce the device’s membership and network address to the rest of the network. The information is sent in a Device\_annce announcement, which must be collected by the recipient nodes using the function ZQ\_bZQueueReceive\(\).

**Note:** \(**Caution\):** If a node rejoins the same secured network but its stack context data was cleared before the rejoin \(by calling NvErase\(\)\), data sent by the node will be rejected by the destination node since the frame counter has been reset on the source node. Therefore, you are not recommended to clear the stack context data before a rejoin. For more information and advice, refer to Appendix B.3.

**Parent topic:**[Leaving and rejoining the network](../topics/leaving_and_rejoining_the_network.md)

