# Get Alarm Response Payload

```
typedef struct
{
   uint8   u8Status;
   uint8   u8AlarmCode;
   uint16  u16ClusterId;
   uint32  u32TimeStamp;
} tsCLD_AlarmsGetAlarmResponsePayload;

```

where:

-   `u8Status` indicates the result of the Get Alarm operation as follows:

    -   SUCCESS \(0x01\): An alarm entry is successfully retrieved from the Alarms table and its details are reported in the remaining fields \(below\)

    -   NOT\_FOUND \(0x00\): There were no alarm entries to be retrieved from the Alarms table and the remaining fields \(below\) are empty

-   `u8AlarmCode` is the code which identifies the type of alarm reported - these codes are cluster-specific

-   `u16ClusterId` is the Cluster ID of the cluster which generated the alarm

-   `u32TimeStamp` is a timestamp representing the time \(UTC\) at which the alarm was generated \(a value of 0XFFFFFFFF indicates that no timestamp is available for the alarm\)


**Parent topic:**[Custom Response Payloads](../../Alarms_cluster/topics/custom_response_payloads.md)

