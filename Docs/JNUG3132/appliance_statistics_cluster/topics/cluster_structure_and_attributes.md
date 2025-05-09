# Cluster structure and attributes

The structure definition for the Appliance Statistics cluster \(server\) is:

```
typedef struct
{
#ifdef APPLIANCE_STATISTICS_SERVER    
    zuint32                         u32LogMaxSize;
    zuint8                          u8LogQueueMaxSize;
#endif    
    zuint16                         u16ClusterRevision;
} tsCLD_ApplianceStatistics;

```

where:

-   `u32LogMaxSize` is a mandatory attribute which specifies the maximum size, in bytes, of the payload of a log notification and log response. This value should not be greater than 70 bytes \(otherwise the Partition cluster is needed\)

-   `u8LogQueueMaxSize` is a mandatory attribute which specifies the maximum number of logs in the queue on the cluster server that are available to be requested by the client

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Appliance Statistics Cluster](../../appliance_statistics_cluster/topics/appliance_statistics_cluster.md)

