# Reset Alarm Command Payload

```
typedef struct
{
   uint8   u8AlarmCode;
   uint16  u16ClusterId;
} tsCLD_AlarmsResetAlarmCommandPayload;

```

where:

-   `u8AlarmCode` is the code which identifies the type of alarm to be reset - these codes are cluster-specific

-   `u16ClusterId` is the Cluster ID of the cluster which generates the alarm to be reset


**Parent topic:**[Custom Command Payloads](../../Alarms_cluster/topics/custom_command_payloads.md)

