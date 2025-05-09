# Overview

The IAS ACE cluster provides a control interface to a CIE \(Control and Indicating Equipment\) device in an IAS \(Intruder Alarm System\). For example, it allows a remote control unit to be used to configure the IAS via a CIE device. The server side of the cluster is implemented on the CIE device and the client side is implemented on the remote device.

To use the functionality of this cluster, you must include the file **IASACE.h** in your application and enable the cluster by defining CLD\_IASACE in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the IAS ACE cluster are fully detailed in [Section 38.9](compile-time_options.md#id_ff437f8c-3021-4c45-ad35-493db4a27d6b).

**Parent topic:**[IAS Ancillary Control Equipment Cluster](../../IAS_ACE_cluster/topics/ias_ancillary_control_equipment_cluster.md)

