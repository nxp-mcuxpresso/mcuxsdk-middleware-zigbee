# Overview

The Binary Input \(Basic\) cluster provides an interface for accessing a binary measurement and its associated characteristics. It is typically used to implement a sensor that measures a two-state physical quantity.

To use the functionality of this cluster, you must include the file **BinaryInputBasic.h** in your application and enable the cluster by defining CLD\_BINARY\_INPUT\_BASIC in the **zcl\_options.h** file.

A Binary Input \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Binary Input \(Basic\) cluster are fully detailed in [Section 19.3.6](compile-time_options_02.md#id_f892b4ca-3821-492e-89a0-f0e77ee25288).

**Parent topic:**[Binary Input \(Basic\) Cluster](../../Binary_Input_Basic_cluster/topics/binary_input_basic_cluster.md)

