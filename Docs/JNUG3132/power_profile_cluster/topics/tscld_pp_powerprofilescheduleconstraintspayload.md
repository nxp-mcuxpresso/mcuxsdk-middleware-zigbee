# tsCLD\_PP\_PowerProfileScheduleConstraintsPayload

This structure contains the payload of a Power Profile Schedule Constraints Response or of a Power Profile Schedule Constraints Notification, which reports the schedule restrictions on a particular power profile.

```
typedef struct
{
  zuint8  u8PowerProfileId;
  zuint16  u16StartAfter;
  zuint16  u16StopBefore;
} tsCLD_PP_PowerProfileScheduleConstraintsPayload;

```

where:

-   `u8PowerProfileId` is the identifier of the power profile being reported

-   `u16StartAfter` is the minimum time-delay, in minutes, to be implemented between an instruction to start the power profile schedule and actually starting the schedule

-   `u16StopBefore` is the maximum time-delay, in minutes, to be implemented between an instruction to stop the power profile schedule and actually stopping the schedule


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

