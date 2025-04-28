# Coordinator

All ZigBee networks must have one \(and only one\) Coordinator.

At the network level, the Coordinator is mainly needed at system initialization - it is the first node to be started and performs the following initialization tasks:

-   Selects the frequency channel to be used by the network \(usually the one with the least detected activity\)
-   Starts the network
-   Allows child nodes to join the network through it

The Coordinator can additionally provide other services such as message routing and security management. It may also provide services at the Application level. If any of these additional services are used, the Coordinator must be able to provide them at all times. However, if none of these additional services are used, the network will be able to operate normally even if the Coordinator fails or is switched off.

**Parent topic:**[ZigBee nodes](../topics/zigbee_nodes.md)

