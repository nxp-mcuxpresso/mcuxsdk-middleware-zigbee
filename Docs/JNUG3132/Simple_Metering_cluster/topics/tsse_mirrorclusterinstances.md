# tsSE\_MirrorClusterInstances

This structure contains information on the Basic and Simple Metering cluster instances that are associated with a mirror endpoint.

**Note:** This structure is only for use by the ZCL and should not be modified by the application.

```
typedef struct
{
   /*Basic Cluster Instance*/
           tsZCL_ClusterInstance sBasicCluster;
           /* SM Cluster Instance */
           tsZCL_ClusterInstance sSM_Cluster;
}tsSE_MirrorClusterInstances;

```

where:

-   `sBasicCluster` is a `tsZCL_ClusterInstance` structure which contains information on the Basic cluster instance associated with a mirror endpoint \(for details of this structure, refer to [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\)

-   `sSM_Cluster` is a `tsZCL_ClusterInstance` structure which contains information on the Simple Metering cluster instance associated with a mirror endpoint \(for details of this structure, refer to [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\)


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

