# Overview

The Analogue Input \(Basic\) cluster provides an interface for setting the value of an analogue output and accessing its associated characteristics. It is typically used in a a controller that outputs an analogue control signal.

To use the functionality of this cluster, you must include the file **AnalogOutputBasic.h** in your application and enable the cluster by defining CLD\_ANALOG\_OUTPUT\_BASIC in the **zcl\_options.h** file.

An Analogue Output \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Analogue Output \(Basic\) cluster are fully detailed in [Section 19.2.6](compile-time_options_01.md#id_b1b50c0e-c482-45d7-82ff-d4586aa02923).

**Parent topic:**[Analogue Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/analogue_output_basic.md)

