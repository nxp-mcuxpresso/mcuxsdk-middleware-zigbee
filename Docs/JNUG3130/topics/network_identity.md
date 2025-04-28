# Network identity

A ZigBee network must be uniquely identifiable. This allows more than one ZigBee network to operate in close proximity - nodes operating in the same space must be able to identify which network they belong to.

For this purpose, ZigBee uses two identifiers, as follows:

-   **PAN ID:** A 16-bit value called the PAN ID \(Personal Area Network Identifier\) is used in inter-node communications \(implemented at the IEEE 802.15.4 level of the stack\) to identify the relevant network. A value for the PAN ID is selected at random by the Coordinator when the network is started. When other nodes join the network, they learn the network’s PAN ID and use it in all subsequent communications with the network.

It is possible that the PAN ID generated for a newly installed network clashes with the PAN ID of another network already operating on the same radio channel, in the same neighborhood. In this case, ZigBee PRO automatically resolves such a conflict by generating another random PAN ID for the new network. This continues until a value is obtained that does not clash with the PAN ID of any other detectable network.

-   **Extended PAN ID:** A 64-bit value called the Extended PAN ID \(EPID\) is used in forming the network and subsequently modifying the network, if necessary. This identifier can be pre-set to a random value in the user application that runs on the Coordinator. Alternatively, the identifier can be pre-set to zero. In this case, the Coordinator adopts its own 64-bit IEEE/MAC address as the Extended PAN ID when the network starts. This is a sure way of obtaining a globally unique value \(see [Section 3.2.4](network_addressing.md)\).

When a Router or End Device first tries to find a network to join, it uses the Extended PAN ID in either of following ways:

-   If an Extended PAN ID has been pre-set in the user application for the Router or End Device, the node joins the network that has this Extended PAN ID \(provided this network is detected\).
-   If there is no pre-set Extended PAN ID for the Router or End Device, the node joins the first network detected, irrespective of the Extended PAN ID. The joining node then learns the Extended PAN ID of its network. It later uses this identifier to rejoin the network if, for some reason, it loses contact with the network \(the node is orphaned\).

For more information on joining a network, refer to [Section 3.3.2](joining_a_network_routers_and_end_devices.md).

**Note:** At the Application level, you only need to be concerned with the Extended PAN ID, as the allocation and use of the PAN ID is transparent to the application.

**Parent topic:**[Network level concepts](../topics/network_level_concepts.md)

