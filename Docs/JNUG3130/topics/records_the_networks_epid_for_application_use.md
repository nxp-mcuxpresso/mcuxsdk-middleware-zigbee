# Records the network's EPID for application use

The function **zps\_eAplAibSetApsUseExtendedPanId\(\)** may now be used to create a persistent record of the EPID of the network that the node has joined \(it is necessary to first obtain the EPID value using the functions **zps\_pvAplZdoGetNwkHandle\(\)** and **zps\_u64NwkGetEpid\(\)**\). If this EPID record is created, the node automatically continues in the network following a reset without explicitly rejoining.

**Parent topic:**[Starting Routers and End Devices](../topics/starting_routers_and_end_devices.md)

