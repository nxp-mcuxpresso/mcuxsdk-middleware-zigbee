# Overview

The Fan Control cluster is used to control the speed of a fan which may be part of a heating or cooling system. It allows the speed or state of the fan to be set, as well as the possible speeds/states that a thermostat can set.

To use the functionality of this cluster, you must include the file **FanControl.h** in your application and enable the cluster by defining CLD\_FAN\_CONTROL in the **zcl\_options.h** file.

A Fan Control cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Fan Control cluster are fully detailed in [Section 34.6](compile-time_options.md#id_183bd3e0-dabc-45c6-ba7a-2e32ee8fabe2).

**Parent topic:**[Fan Control Cluster](../../Fan_Control_cluster/topics/fan_control_cluster.md)

