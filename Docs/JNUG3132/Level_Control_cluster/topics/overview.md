# Overview

The Level Control cluster is used to control the level of a physical quantity on a device. The physical quantity is device-dependent - for example, it could be light, sound or heat output.

**Note:** This cluster should be used with the On/Off cluster \(see [Chapter 14](../../OnOff_cluster/topics/onoff_cluster.md#id_95380f68-4a55-4dd0-814d-ba1e49f7f592)\) and this is assumed to be the case in this description.

The Level Control cluster provides the facility to increase to a target level gradually during a ‘switch-on’ and decrease from this level gradually during a ‘switch-off’.

To use the functionality of this cluster, you must include the file **LevelControl.h** in your application and enable the cluster by defining CLD\_LEVEL\_CONTROL in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to change the level on the local device.

-   The cluster client is able to send commands to change the level on the remote device.


The inclusion of the client or server software must be pre-defined in the application’s compile-time options. In addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the Level Control cluster are fully detailed in [Section 16.10](compile-time_options.md#id_d5816170-b45c-4787-ad18-9a2a3f50e8fd).

**Parent topic:**[Level Control Cluster](../../Level_Control_cluster/topics/level_control_cluster.md)

