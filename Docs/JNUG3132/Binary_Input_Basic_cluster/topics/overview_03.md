# Overview

The Binary Output \(Basic\) cluster provides an interface for setting the state of a binary output and its associated characteristics. It is typically used to implement a controller that produces a two-state output signal.

To use the functionality of this cluster, you must include the file **BinaryOutputBasic.h** in your application and enable the cluster by defining CLD\_BINARY\_OUTPUT\_BASIC in the **zcl\_options.h** file.

A Binary Output \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Binary Output \(Basic\) cluster are fully detailed in [Section 19.4.6](compile-time_options_03.md#id_2c3f26e2-50c5-440f-9616-e48d8af94b08).

**Parent topic:**[Binary Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/binary_output_basic.md)

