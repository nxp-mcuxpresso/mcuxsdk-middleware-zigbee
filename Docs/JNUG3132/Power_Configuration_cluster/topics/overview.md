# Overview

The Power Configuration cluster allows:

-   information to be obtained about the power source\(s\) of a device

-   voltage alarms to be configured


To use the functionality of this cluster, you must include the file **PowerConfiguration.h** in your application and enable the cluster by defining CLD\_POWER\_CONFIGURATION in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to change the power configuration on the local device.

-   The cluster client is able to send commands to change the power configuration on the remote device.


The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Power Configuration cluster are fully detailed in [Section 9.6](compile-time_options.md#id_f58cfe1a-9698-4c9f-8b16-d45128b6ca04).

**Parent topic:**[Power Configuration Cluster](../../Power_Configuration_cluster/topics/power_configuration_cluster.md)

