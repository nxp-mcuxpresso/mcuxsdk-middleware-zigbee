# Alarms Table Entry

The following structure contains the data for an entry of an Alarms table.

```
typedef struct
{
    DNODE    dllAlarmsNode;
    uint8    u8AlarmCode;
    uint16   u16ClusterId;
    uint32   u32TimeStamp;
} tsCLD_AlarmsTableEntry;

```

where:

-   `dllAlarmsNode` is for internal use and no knowledge of it is required

-   `u8AlarmCode` is the code which identifies the type of alarm - these codes are cluster-specific

-   `u16ClusterId` is the Cluster ID of the cluster which generated the alarm

-   `u32TimeStamp` is a timestamp representing the time \(UTC\) at which the alarm was generated \(a value of 0XFFFFFFFF indicates that no timestamp is available for the alarm\)


**Parent topic:**[Structures](../../Alarms_cluster/topics/structures.md)

