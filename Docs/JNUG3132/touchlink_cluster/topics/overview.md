# Overview

The Touchlink Commissioning cluster is associated with a node as a whole, rather than with individual ZigBee devices on the node. It must be used on nodes that incorporate one or more of the ZigBee devices indicated in [Table 83](#id_b5abfe96-f90a-4496-a88c-c8b49a591d31) below, which shows the supported devices when the Touchlink Commissioning cluster acts as a client, server and combined client/server.

| Client                      | Client/Server               | Server                      |
| --------------------------- | --------------------------- | --------------------------- |
| Colour Controller           | Colour Controller           | Colour Controller           |
| Colour Scene Controller     | Colour Scene Controller     | Colour Scene Controller     |
| Non-Colour Controller       | Non-Colour Controller       | Non-Colour Controller       |
| Non-Colour Scene Controller | Non-Colour Scene Controller | Non-Colour Scene Controller |
| Control Bridge              | Control Bridge              | Control Bridge              |
| On/Off Sensor               | On/Off Sensor               | On/Off Sensor               |
|                             | On/Off Light                | On/Off Light                |
|                             | On/Off Plug-in Unit         | On/Off Plug-in Unit         |
|                             | Dimmable Light              | Dimmable Light              |
|                             | Dimmable Plug-in Unit       | Dimmable Plug-in Unit       |
|                             | Colour Light                | Colour Light                |
|                             | Extended Colour Light       | Extended Colour Light       |
|                             | Colour Temperature Light    | Colour Temperature Light    |

This cluster supports two sets of functionality, corresponding to two distinct commands sets:

-   Touchlink

-   Commissioning Utility


Functions are provided for implementing both sets of commands. These functions are referenced in [Section 44.4](using_touchlink.md#id_f01fd7b4-9690-422c-a1bd-7aeddd320a43) and [Section 44.5](using_the_commissioning_utility.md#id_ba07220a-e60c-4f4b-9c9c-f8ef4fef96f8), and detailed in [Section 44.7](functions.md#id_7b6c276b-ed1c-40a7-9c7e-d3569fd0d947).

The Commissioning Utility functionality is not required on Lighting devices.

For the compile-time options for enabling the Touchlink Commissioning cluster for Touchlink and the Commissioning Utility, refer to [Section 44.10](compile-time_options.md#id_b35eeb86-3074-417e-8aae-7184fa911842).

**Parent topic:**[Touchlink Commissioning Cluster](../../touchlink_cluster/topics/touchlink_commissioning_cluster.md)

