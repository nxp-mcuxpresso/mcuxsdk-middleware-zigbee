# Overview

The IAS Zone cluster provides an interface to an IAS Zone device, which provides security alarm triggers for a zone or region of a building \(e.g. fire detection\). The cluster allows an IAS Zone device to be configured/controlled from a CIE \(Control and Indicating Equipment\) device. The server side of the cluster is implemented on the IAS Zone device and the client side is implemented on the CIE device. The IAS Zone device is detailed in the *ZigBee Devices User Guide \(JNUG3131\)*.

The cluster supports the following functionality:

-   Up to two alarm types per zone, Alarm1 and Alarm2

-   ‘Low battery’ reports

-   Supervision of the IAS network


To use the functionality of this cluster, you must include the file **IASZone.h** in your application and enable the cluster by defining CLD\_IASZONE in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the IAS Zone cluster are fully detailed in [Section 37.7](compile-time_options.md#id_ad95ceff-e1ed-403a-bd1d-4c75db460c10).

The information that can potentially be stored in this cluster is organised into the following attribute sets:

-   Zone information

-   Zone settings


**Parent topic:**[IAS Zone Cluster](../../IAS_Zone_cluster/topics/ias_zone_cluster.md)

