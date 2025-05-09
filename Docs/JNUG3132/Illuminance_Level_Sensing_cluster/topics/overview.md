# Overview

The Illuminance Level Sensing cluster provides an interface to a device that can sense the local level of illumination. The cluster can configure notifications that are generated when the light-level is above, within or below a certain illuminance band.

To use the functionality of this cluster, you must include the file **IlluminanceLevelSensing.h** in your application and enable the cluster by defining CLD\_ILLUMINANCE\_LEVEL\_SENSING in the **zcl\_options.h** file.

An Illuminance Level Sensing cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the compile-time options of the application. In addition, if the cluster is designed to reside on a custom endpoint, then the role of client or server must also be specified while creating the cluster instance.

The compile-time options for the Illuminance Level Sensing cluster are fully detailed in [Section 24.6](compile-time_options.md#id_ff40adbf-5bf3-417d-83c0-0e05286f9632).

The information that can potentially be stored in this cluster is organized into the following attribute sets:

-   Illuminance Level Sensing Information

-   Illuminance Level Sensing Settings


**Parent topic:**[Illuminance Level Sensing Cluster](../../Illuminance_Level_Sensing_cluster/topics/illuminance_level_sensing_cluster.md)

