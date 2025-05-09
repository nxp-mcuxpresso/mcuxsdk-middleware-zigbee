# Overview

The IAS WD cluster provides an interface to an IAS Warning Device, allowing warning indications triggered by alarm conditions to be sent to it. The server side of the cluster is implemented on the IAS Warning Device and the client side is implemented on the triggering device. The IAS Warning Device is detailed in the *ZigBee Devices User Guide \(JNUG3131\)*.

To use the functionality of this cluster, you must include the file **IASWD.h** in your application and enable the cluster by defining CLD\_IASWD in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the compile-time options of the application. In addition, if the cluster resides on a custom endpoint, then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the IAS WD cluster are fully detailed in [Section 39.7](compile-time_options.md#id_47b8a56c-185d-4643-b5f9-c6fb4991585e).

**Parent topic:**[IAS Warning Device Cluster](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md)

