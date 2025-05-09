# ZCL Time Synchronization

The local ZCL time on a device can be synchronized with the time in a time-related cluster, such as Time, Price, or Messaging. The ZCL time is considered to be synchronized following a call to **vZCL\_SetUTCTime\(\)**. The NXP implementation of the ZCL also provides the following functions relating to ZCL time synchronization:

-   **u32ZCL\_GetUTCTime\(\)** obtains the ZCL time \(held locally\).

-   **bZCL\_GetTimeHasBeenSynchronised\(\)** determines whether the ZCL time on the device has been synchronized - that is, whether **vZCL\_SetUTCTime\(\)** has been called.

-   **vZCL\_ClearTimeHasBeenSynchronised\(\)** can be used to specify that the device can no longer be considered to be synchronized \(for example, if there has been a problem in accessing the Time cluster server over a long period\).


**Parent topic:**[Maintaining ZCL Time](../../Time_cluster/topics/maintaining_zcl_time.md)

