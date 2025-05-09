# Cluster structure and attribute

The structure definition for the Appliance Events and Alerts cluster \(server\) is.

```
typedef struct
{
 zuint16   u16ClusterRevision;
} tsCLD_ApplianceEventsAndAlerts;

```

where `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Appliance Events and Alerts Cluster](../../appliance_events_alerts_cluster/topics/appliance_events_and_alerts_cluster.md)

