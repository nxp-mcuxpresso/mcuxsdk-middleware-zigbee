# Overview

The Diagnostics cluster allows the operation of the ZigBee PRO stack to be followed over time. It provides a tool for monitoring the performance of individual network nodes, including the routing of packets through these nodes.

**Note:** It is strongly recommended that Diagnostics cluster server attributes are stored in persistent memory to allow performance data to be preserved through a device reset or power interruption.

To use the functionality of this cluster, you must include the file **Diagnostics.h** in your application and enable the cluster by defining CLD\_DIAGNOSTICS in the **zcl\_options.h** file.

A Diagnostics cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Diagnostics cluster are fully detailed in [Section 22.5](compile-time_options.md#id_03bf6ea8-2c35-4e83-933a-7933b252153f).

The information that can potentially be stored in this cluster is organized into the following attribute sets:

-   Hardware information

-   Stack/Network information


Currently, only three attributes from the Stack/Network Information attribute set are supported \(see [Section 22.2](diagnostics_structure_and_attributes.md#id_5b200dd1-8849-4e3d-8900-703b924bb425)\).

This cluster has no associated events. However, reads and writes of the cluster attributes may give rise to ZCL events \(the application is responsible for checking that a written value is within the valid range for the target attribute\).

**Parent topic:**[Diagnostics Cluster](../../Diagnostics_cluster/topics/diagnostics_cluster.md)

