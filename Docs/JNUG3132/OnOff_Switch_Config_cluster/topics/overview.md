# Overview

The On/Off Switch Configuration cluster allows the switch type on a device to be defined, as well as the commands to be generated when the switch is moved between its two states.

To use the functionality of this cluster, you must include the file **OOSC.h** in your application and enable the cluster by defining CLD\_OOSC in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to define a switch configuration.

-   The cluster client is able to send commands to define a switch configuration.


The inclusion of the client or server software must be pre-defined in the compile-time options of the application. In addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the On/Off Switch Configuration cluster are fully detailed in [Section 15.6](compile-time_options.md#id_6ffa5622-2482-4d29-a59b-dd4175a3f036).

**Parent topic:**[On/Off Switch Configuration Cluster](../../OnOff_Switch_Config_cluster/topics/onoff_switch_configuration_cluster.md)

