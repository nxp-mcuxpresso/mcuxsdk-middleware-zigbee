# Maintaining ZCL Time

The simplest case of keeping time on a ZigBee PRO device is to maintain ‘ZCL time’ only \(without using the Time cluster\). In this case, the ZCL time on a device can be initialized by the application using the function **vZCL\_SetUTCTime\(\)**.

The ZCL time is subsequently incremented from a local one-second timer, as follows. On expiration of the timer, an event is generated \(from the hardware/software timer that drives the one-second timer\), which causes a ZCL user task to be activated. The event is initially handled by this task as described in [Section 3.2](../../ZCL_event_handling/topics/processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38), resulting in an E\_ZCL\_CBET\_TIMER event being passed to the ZCL via the function **vZCL\_EventHandler\(\)**. The following actions should then be performed:

1. The ZCL automatically increments the ZCL time and may run cluster-specific schedulers.

2. The user task resumes the one-second timer.


```{include} ../../Time_cluster/topics/updating_zcl_time_following_sleep.md
:heading-offset: 2
```

```{include} ../../Time_cluster/topics/zcl_time_synchronisation.md
:heading-offset: 2
```

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

