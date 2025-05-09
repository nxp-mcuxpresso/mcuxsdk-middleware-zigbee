# Overview

The Thermostat cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|Thermostat||
|**Optional in...**||Remote Control|

The Thermostat cluster is enabled by defining CLD\_THERMOSTAT in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Thermostat cluster are fully detailed in [Section](compile-time_options.md#id_a6c5caa2-6d08-442f-b081-d58124b2489b)33.10.

The information that can potentially be stored in this cluster is organised into the following attribute sets:

-   Thermostat Information

-   Thermostat Settings


The attributes are listed and described next, in [Section 33.2](thermostat_cluster_structure_and_attributes.md#id_2ef68b17-5921-48db-ba27-b9070b7f39e5).

**Parent topic:**[Thermostat Cluster](../../thermostat_cluster/topics/thermostat_cluster.md)

