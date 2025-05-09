# Overview

The Analogue Input \(Basic\) cluster provides an interface for accessing an analogue measurement and its associated characteristics. It is typically used in a sensor that measures an analogue physical quantity.

To use the functionality of this cluster, you must include the file **AnalogInputBasic.h** in your application and enable the cluster by defining CLD\_ANALOG\_INPUT\_BASIC in the **zcl\_options.h** file.

An Analogue Input \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Analogue Input \(Basic\) cluster are fully detailed in [Section 19.1.6](compile-time_options.md#id_246ef431-1483-4e12-82b3-c7054db56683).

**Parent topic:**[Analogue Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/analogue_input_basic.md)

