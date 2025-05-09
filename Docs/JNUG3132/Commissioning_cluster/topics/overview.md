# Overview

The Commissioning cluster is used for commissioning the ZigBee stack on a device during network installation and defining the device behaviour with respect to the ZigBee network \(it does not affect applications operating on the devices\).

-   The Commissioning cluster server must be implemented on a device that is to be commissioned into a network.

-   The Commissioning cluster client must be implemented on a device that can initiate the commissioning of another device into a network - for example, on a commissioning tool.


This optional cluster is enabled by defining CLD\_COMMISSIONING in the **zcl\_options.h** file. The inclusion of the client or server software must also be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\). The compile-time options for the Commissioning cluster are fully detailed in [Section 43.10](compile-time_options.md#id_ff1e5475-70c7-41e3-8ab8-1188b0c7ab78).

Only server attributes are supported and all are optional - the required attributes must be enabled in the compile-time options. The information that can potentially be stored in the Commissioning cluster is organised into the following attribute sets: Start-up Parameters, Join Parameters, End Device Parameters, Concentrator Parameters.

**Note:** The attribute values are set by the application but the application must ensure that these values are synchronized with the settings and NIB values for the ZigBee PRO stack.

The Commissioning cluster also provides optional commands, which can be enabled in the compile-time options.

**Parent topic:**[Commissioning Cluster](../../Commissioning_cluster/topics/commissioning_cluster.md)

