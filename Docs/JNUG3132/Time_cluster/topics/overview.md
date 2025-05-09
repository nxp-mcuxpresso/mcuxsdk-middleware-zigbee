# Overview

The Time cluster is required in a ZigBee PRO network in which the constituent devices must be kept time-synchronized - for example, in an HVAC system, it may be necessary for heating to operate only between specific times of the day. In such a case, one device implements the Time cluster as a server and acts as the time-master for the network. While the other devices in the network, implement the Time cluster as a client and time-synchronize with the server.

**Note:** As for all clusters, the Time cluster is stored in a shared device structure \(see [Section 18.3](attribute_settings.md#id_466de93a-a275-47e8-baa5-69915f98bf8b)\) which, for the cluster client, reflects the state of the cluster server. Access to the shared device structure \(on Time cluster server and client\) must be controlled using a mutex - for information on mutexes, refer to [Appendix A](../../appendix/topics/mutex_callbacks.md#id_3604e1a6-d753-4b1f-a7bb-2f6b4334e0d3).

The Time cluster is enabled by defining CLD\_TIME in the **zcl\_options.h** file. The inclusion of the client or server software must also be pre-defined in the application’s compile-time options. In addition, if the cluster is to reside on a custom endpoint then specify the role of client or server, when creating the cluster instance. The compile-time options for the Time cluster are fully detailed in [Section 18.10](compile-time_options.md#id_ebd4cb5b-5723-431c-926b-516d8e9afb88).

In addition to the time in the Time cluster, the ZCL also keeps its own time, ‘ZCL time’. ZCL time may be maintained on a device even when the Time cluster is not used by the device. Both times are described below.

## Time Attribute 

The Time cluster contains an attribute for the current time, as well as associated information such as time-zone and daylight saving - see [Section 18.3](attribute_settings.md#id_466de93a-a275-47e8-baa5-69915f98bf8b). The time attribute is referenced to UTC \(Coordinated Universal Time\) and based on the type **UTCTime**, which is defined in the ZigBee standard as:

*"UTCTime is an unsigned 32-bit value representing the number of seconds since 0 hours, 0 minutes, 0 seconds, on the January 1, 2000 UTC".*

## ZCL Time 

‘ZCL time’ is based on the above **UTCTime** definition. This time is derived from a 1 second timer and is used to drive any ZCL timers that have been registered.

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

