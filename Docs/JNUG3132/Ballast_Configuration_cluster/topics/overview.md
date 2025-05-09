# Overview

The Ballast Configuration cluster allows the ballast for a set of lamps to be configured.

To use the functionality of this cluster, you must include the file **BallastConfiguration.h** in your application and enable the cluster by defining CLD\_BALLAST\_CONFIGURATION in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to access ballast configuration data on the local device.

-   The cluster client is able to send commands to access ballast configuration data on the remote device.


The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\). The compile-time options for the Ballast Configuration cluster are fully detailed in [Section 32.5](compile-time_options.md#id_8d244fdc-c504-4880-bcb0-4af383000935).

The information that can potentially be stored in this cluster is organised into the following attribute sets:

-   Ballast Information

-   Ballast Settings

-   Lamp Information

-   Lamp Settings

-   Global


Note that not all of the above attribute sets are currently implemented in the NXP software and not all attributes within a supported attribute set are implemented \(see [Section 32.2](cluster_structure_and_attributes.md#id_b9c4f89c-360b-44be-886c-dbf0f10227c8) for the supported attribute sets and attributes\).

**Parent topic:**[Ballast Configuration Cluster](../../Ballast_Configuration_cluster/topics/ballast_configuration_cluster.md)

