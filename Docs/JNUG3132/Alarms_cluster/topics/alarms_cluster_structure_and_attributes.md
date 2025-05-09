# Alarms Cluster structure and attributes

The structure definition for the Alarms cluster is shown below.

```
typedef struct
{
#ifdef ALARMS_SERVER
    #ifdef CLD_ALARMS_ATTR_ALARM_COUNT
        zuint16             u16AlarmCount;
    #endif
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_Alarms;

```

where:

-   `u``16AlarmCount` is an optional attribute which contains the number of entries currently in the Alarms table on the cluster server.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Alarms Cluster](../../Alarms_cluster/topics/alarms_cluster.md)

