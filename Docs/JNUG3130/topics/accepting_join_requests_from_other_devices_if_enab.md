# Accepting join requests from other devices \(if enabled\)

The Coordinator may now allow other devices \(Routers and End Devices\) to join the network as its children, enabling the network to grow. A maximum number of \(direct\) children of the Coordinator is pre-set via the advanced network parameters *Active Neighbor Table Size*and *Child Table Size*in the ZPS Configuration Editor \(see [Section 13.4.4](setting_advanced_device_parameters.md), [Setting advanced device parameters](setting_advanced_device_parameters.md)\), beyond which the Coordinator does not accept any further join requests from prospective children.

**Note:**

The initial ‘permit joining’ status is pre-set via the Coordinator parameter Permit Joining Time in the ZPS Configuration Editor.

If this is initially disabled, the Coordinator may not accept children until joining has been enabled using **zps\_eAplZdoPermitJoining\(\)**.

However, the ‘permit joining’ status is ignored during a join in which the pre-set EPID on the joining device is non-zero and during any rejoin \(see [Section 6.6.2](rejoining_the_network.md)\). The above function can be used at any time to allow joinings for a limited time-period or indefinitely, and can also be used to disable joinings.

Once the Coordinator \(and therefore network\) has started, the stack event `zps_EVENT_NWK_STARTED` is generated on the device. If the Coordinator fails to start, the stack event `zps_EVENT_NWK_FAILED_TO_START` is generated.

When a node joins the Coordinator, the stack event `zps_EVENT_NWK_NEW_NODE_HAS_JOINED` is generated on the Coordinator.

**Parent topic:**[Starting the Coordinator](../topics/starting_the_coordinator.md)

