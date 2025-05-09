# Overview

The Door Lock cluster is required in ZigBee devices as indicated in the table below.

||**Server-side**|**Client-side**|
|---|---------------|---------------|
|**Mandatory in...**|Door Lock|Door Lock Controller|
|**Optional in...**||Remote Control|

The Door Lock cluster is enabled by defining CLD\_DOOR\_LOCK in the **zcl\_options.h** file.

The inclusion of the client or server software must be pre-defined in the application’s compile-time options \(in addition, if the cluster is to reside on a custom endpoint then the role of client or server must also be specified when creating the cluster instance\).

The compile-time options for the Door Lock cluster are fully detailed in [Section 36.9](compile-time_options.md#id_5bdb64ed-506e-4959-b0a6-b803868b285b).

**Parent topic:**[Door Lock Cluster](../../door_lock_cluster/topics/door_lock_cluster.md)

