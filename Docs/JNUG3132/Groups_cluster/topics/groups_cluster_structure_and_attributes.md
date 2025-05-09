# Groups Cluster structure and attributes

The structure definition for the Groups cluster is:

```
typedef struct
{
    zbmap8                  u8NameSupport;
    zuint16                 u16ClusterRevision;
} tsCLD_Groups;

```

where:

-   `u8NameSupport` indicates whether group names are supported by the cluster:

    -   A most significant bit of 1 indicates that group names are supported.

    -   A most significant bit of 0 indicates that group names are not supported.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md).

**Parent topic:**[Groups Cluster](../../Groups_cluster/topics/groups_cluster.md)

