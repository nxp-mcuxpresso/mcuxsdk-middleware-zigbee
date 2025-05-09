# Overview

The Multistate Input \(Basic\) cluster provides an interface for accessing a multistate measurement and its associated characteristics. It is typically used in a sensor that measures a physical quantity that can take one of a discrete number of states.

To use the functionality of this cluster, you must include the file **MultistateInputBasic.h** in your application and enable the cluster by defining CLD\_MULTISTATE\_INPUT\_BASIC in the **zcl\_options.h** file.

A Multistate Input \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Multistate Input \(Basic\) cluster are fully detailed in [Section 19.5.6](compile-time_options_04.md#id_d0c4d235-067f-49d2-9c53-1390d1e54f89).

**Parent topic:**[Multistate Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/multistate_input_basic.md)

