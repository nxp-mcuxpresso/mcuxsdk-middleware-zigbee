# Overview

The Alarms cluster is used to configure alarm functionality on a device and send alarm notifications to other devices.

**Note:** The Alarms cluster is used with other clusters that use alarms. Alarms conditions and codes are cluster-specific and defined in these clusters.

To use the functionality of this cluster, you must include the file **Alarms.h** in your application and enable the cluster by defining CLD\_ALARMS in the **zcl\_options.h** file.

An Alarms cluster instance can act as a client or a server. The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Alarms cluster are fully detailed in [Section 17.9](compile-time_options.md#id_4b6548bb-82a0-43bf-a479-ba9ea1bd1637).

The Alarms cluster server resides on a device on which other clusters may generate alarm conditions \(for example, a cluster attribute value exceeds a certain limit\). When an alarm condition occurs, the Alarms cluster server may send an Alarm notification to a cluster client - for example, the client may be on a device that signals alarms to the user. An Alarms cluster client may also contain a user interface \(for example, a set of buttons\) which allows user instructions to be sent to the server - for example, to reset an alarm.

The Alarms cluster server implements alarm logging by keeping a record of the previously generated alarms in an Alarms table. Thus, historic alarm information can be retrieved from the Alarms table. Each entry of the table contains the following information about one alarm activation:

-   Alarm code which identifies the type of alarm \(this type is cluster-specific\)

-   Cluster ID of the cluster which generated the alarm

-   Time-stamp indicating the time \(UTC\) at which the alarm is generated


A maximum number of Alarms table entries can be set in the compile-time options.

**Note:** Any device which implements time-stamping for alarms must also employ the Time cluster, described in [Chapter 17](alarms_cluster.md#id_709bda96-0108-4916-8d58-eab1f23dd3b0).

**Parent topic:**[Alarms Cluster](../../Alarms_cluster/topics/alarms_cluster.md)

