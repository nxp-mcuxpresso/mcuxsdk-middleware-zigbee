# IAS WD Structure and Attribute

The structure definition for the IAS WD cluster is:

```
typedef struct
{
#ifdef IASWD_SERVER   
  zuint16   u16MaxDuration;
#endif    
  zuint16   u16ClusterRevision;    
} tsCLD_IASWD;

```

where:

-   `u``16MaxDuration` is the maximum duration, in seconds, for which the alarm can be continuously active \(for example, a siren sounded\). The range of possible values is 0 to 65534 seconds and the default value is 240 seconds.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[IAS Warning Device Cluster](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md)

