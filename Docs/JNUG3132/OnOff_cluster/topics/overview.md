# Overview

The On/Off cluster allows a device to be put into the ‘on’ and ‘off’ states, or toggled between the two states. The cluster also provides the following enhanced functionality for lighting:

-   When switching off lights with an effect, saves the last light \(attribute\) settings to a global scene, ready to be reused for the next switch-on from the global scene - see [Section 14.5.2](switching_off_lights_with_effect.md#id_a0cd3e78-4439-46f7-bdbf-7c66caa499bc) and [Section 14.6](saving_light_settings.md#id_3cd235e7-bcd7-411a-8914-56f7163653a0)

-   Allows lights to be switched on for a timed period \(and then automatically switched off\) - see [Section 14.5.3](switching_on_timed_lights.md#id_efd0f5a1-6497-4ff2-b8bc-2ceae4b71cda)


To use the functionality of this cluster, you must include the file **OnOff.h** in your application and enable the cluster by defining CLD\_ONOFF in the **zcl\_options.h** file.

It is also necessary to enable the cluster as a server or client, or as both:

-   The cluster server is able to receive commands to change the on/off state of the local device.

-   The cluster client is able to send commands to the server to request a change to the on/off state of the remote device.


The inclusion of the client or server software must be pre-defined in the compile-time options of the application. In addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance.

The compile-time options for the On/Off cluster are fully detailed in [Section 14.10](compile-time_options.md#id_bfec7b3c-d152-4003-ac21-999c7d5ad203).

**Parent topic:**[On/Off Cluster](../../OnOff_cluster/topics/onoff_cluster.md)

