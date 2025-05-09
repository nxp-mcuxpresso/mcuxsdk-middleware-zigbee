# Overview

The Occupancy Sensing cluster provides an interface to an occupany sensor, allowing the configuration of sensing and the reporting of status.

To use the functionality of this cluster, you must include the file **OccupancySensing.h** in your application and enable the cluster by defining CLD\_OCCUPANCY\_SENSING in the **zcl\_options.h** file.

An Occupancy Sensing cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Occupancy Sensing cluster are fully detailed in [Section 29.6](compile-time_options.md#id_514eb097-c632-4f67-b674-c15b2e469e49).

The information that can potentially be stored in this cluster is organised into the following attribute sets:

-   Occupancy sensor information

-   PIR configuration

-   Ultrasonic configuration


This cluster has no associated events. The status of an occupancy sensor can be obtained by reading the ‘occupancy’ attribute \(see [Section 29.2](occupancy_sensing_structure_and_attributes.md#id_92bbe49c-e6f9-4fd5-8de5-f8e2e59efb11)\) which is automatically maintained by the cluster server. The cluster attributes can be accessed using the general attribute read/write functions, as described in [Section 2.3](../../ZCL_fundamentals/topics/accessing_attributes.md#id_9f17ffc2-9472-40fa-9365-07ad9a0f505b).

**Parent topic:**[Occupancy Sensing Cluster](../../Occupancy_Sensing_cluster/topics/occupancy_sensing_cluster.md)

