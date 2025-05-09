# Alarm Notification Payload

```
typedef struct
{
  uint8   u8AlarmCode;
  uint16   u16ClusterId;
} tsCLD_AlarmsAlarmCommandPayload;

```

where:

-   `u8AlarmCode` is the code which identifies the type of alarm that has been generated - these codes are cluster-specific

-   `u16ClusterId` is the Cluster ID of the cluster which generated the alarm


**Parent topic:**[Custom Command Payloads](../../Alarms_cluster/topics/custom_command_payloads.md)

