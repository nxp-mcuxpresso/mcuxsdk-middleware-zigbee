# Overview

The Colour Control cluster is used to control the colour of a light.

**Note:** **Note 1:** This cluster should normally be used with the Level Control cluster \(see [Chapter 16](../../Level_Control_cluster/topics/level_control_cluster.md#id_492efae6-d88d-4203-be53-0039b6fe8f2d)\) and On/Off cluster \(see [Chapter 14](../../OnOff_cluster/topics/onoff_cluster.md#id_95380f68-4a55-4dd0-814d-ba1e49f7f592)\). This is assumed to be the case in this description.

**Note:** **Note 2:** This cluster only controls the colour balance and not the overall brightness of a light. The brightness is adjusted using the Level Control cluster.

The Colour Control cluster provides the facility to specify the colour of a light in the colour space defined in the *Commission Internationale de l'Éclairage \(CIE\) specification \(1931\)*. Colour control can be performed in terms of any of the following:

-   x and y values, as defined in the CIE specification

-   hue and saturation

-   colour temperature


To use the functionality of this cluster, you must include the file **ColourControl.h** in your application and enable the cluster by defining CLD\_COLOUR\_CONTROL in the **zcl\_options.h** file - see [Section 31.9](compile-time_options.md#id_a8b0fac5-e0c9-4b31-97d5-1255b76f2311).

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to change the colour on the local light device.

-   The cluster client is able to send commands to change the colour on the remote light device.


The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Colour Control cluster are fully detailed in [Section](compile-time_options.md#id_a8b0fac5-e0c9-4b31-97d5-1255b76f2311)31.9.

The information that can potentially be stored in this cluster is organized into the following attribute sets:

-   Colour Information

-   Defined Primaries Information

-   Additional Defined Primaries Information

-   Defined Colour Point Settings

-   Enhanced Colour Mode


**Parent topic:**[Colour Control Cluster](../../Colour_Control_cluster/topics/colour_control_cluster.md)

