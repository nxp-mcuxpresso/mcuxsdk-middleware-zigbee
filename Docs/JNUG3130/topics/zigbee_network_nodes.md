# ZigBee network nodes

A wireless network consists of a set of nodes that can communicate with each other by means of radio transmissions, according to a set of routing rules \(for passing messages between nodes\). A ZigBee wireless network includes three types of node:

-   **Coordinator:** This is the first node to be started and is responsible for forming the network by allowing other nodes to join the network through it. Once the network is established, the Coordinator has a routing role \(is able to relay messages from one node to another\) and is also able to send/receive data. Every network must have one and only one Coordinator.
-   **Router:** This is a node with a routing capability, and is also able to send/receive data. It also allows other nodes to join the network through it, so plays a role in extending the network. A network may have many Routers.
-   **End Device:** This is a node which is only capable of sending and receiving data \(it has no routing capability\). A network may have many End Devices.

The [ZigBee PRO network topology](zigbee_pro_network_topology.md) describes deployment of these node types in a ZigBee PRO network. More detailed information about the node types is provided in [ZigBee nodes](zigbee_nodes.md).

**Parent topic:**[ZigBee overview](../topics/zigbee_overview.md)

