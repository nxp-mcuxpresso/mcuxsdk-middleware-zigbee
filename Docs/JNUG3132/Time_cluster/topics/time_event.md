# Time Event

The Time cluster does not have any events of its own, but the ZCL includes one time-related event: E\_ZCL\_CBET\_TIMER. For this event, the `eEventType` field of the `tsZCL_CallBackEvent` structure \(see [Section 3.1](../../ZCL_event_handling/topics/event_structure.md#id_b693aa7f-8a8b-424a-87a8-1799a7c87f1e)\) is set to E\_ZCL\_CBET\_TIMER.

The application may need to generate this event, as indicated in [Section 3.2](../../ZCL_event_handling/topics/processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38).

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

