# Overview

The Identify cluster allows the host device to be put into identification mode in which the node highlights itself in some way to an observer \(in order to distinguish itself from other nodes in the network\). It is recommended that identification mode should involve flashing a light with a period of 0.5 seconds.

To use the functionality of this cluster, you must include the file **Identify.h** in your application and enable the cluster by defining CLD\_IDENTIFY in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to start and stop identification mode on the local device.

-   The cluster client is able to send the above commands to the server \(and therefore control identification mode on the remote device\)


The inclusion of the client or server software must be pre-defined in compile-time options of the application. In addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the Identify cluster are fully detailed in [Section 11.9](compile-time_options.md#id_585cc0f6-5292-4da8-bbbe-79babb2e0a4d).

**Note:** The Identify cluster contains optional functionality for the EZ-mode Commissioning module, which is part of the ZigBee Base Device functionality and is described in the *ZigBee Devices User Guide \(JNUG3131\)*.

**Parent topic:**[Identify Cluster](../../Identify_cluster/topics/identify_cluster.md)

