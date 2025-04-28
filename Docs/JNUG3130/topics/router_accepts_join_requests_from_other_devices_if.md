# Router accepts join requests from other devices \(if enabled\)

A Router may now allow other devices \(Routers and End Devices\) to join it as its children. The number of \(direct\) children of the Router is limited by the maximum number of neighbors for the node, which is pre-set via the advanced network parameter *Active Neighbor Table Size*and *Child Table Size*in the ZPS Configuration Editor \(see [Section 13.4.4](setting_advanced_device_parameters.md)\).

**Note:** The initial ‘permit joining’ status is pre-set via the Router parameter Permit Joining Time in the ZPS Configuration Editor. If this is initially disabled, the Router may not accept children until joining has been enabled using zps\_eAplZdoPermitJoining\(\). However, the ‘permit joining’ status is ignored during a join in which the pre-set EPID on the joining device is non-zero and during any rejoin \(see [Section 6.6.2](rejoining_the_network.md)\). The above function can be used at any time to allow joinings for a limited time-period or indefinitely, and can also be used to disable joinings.

Once a node has joined the network, each endpoint application on the node is next likely to search for compatible endpoints on remote nodes with which it can communicate, as described in [Section 6.2.2](finding_compatible_endpoints.md).

**Note:** A network can be set up such that an End Device or Router joins a particular parent node. The required configuration and function calls to employ predetermined parents are described in [Section 6.1.3](pre-determined_parents.md).

**Parent topic:**[Starting Routers and End Devices](../topics/starting_routers_and_end_devices.md)

