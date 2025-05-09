# Overview

The Multistate Input \(Basic\) cluster provides an interface for setting the value of a multistate output and its associated characteristics. It is typically used in a controller which outputs a control signal that can be set to one of a discrete number of states.

To use the functionality of this cluster, you must include the file **MultistateOutputBasic.h** in your application and enable the cluster by defining CLD\_MULTISTATE\_OUTPUT\_BASIC in the **zcl\_options.h** file.

An Multistate Output \(Basic\) cluster instance can act as either a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Multistate Output \(Basic\) cluster are fully detailed in [Section 19.6.6](compile-time_options_05.md#id_126ba61f-da2e-466a-bad1-71e85befc3e4).

**Parent topic:**[Multistate Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/multistate_output_basic.md)

