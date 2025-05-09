# Identify Cluster Structure and Attribute

The structure definition for the Identify cluster is:

```
typedef struct
{
#ifdef IDENTIFY_SERVER    
    zuint16                 u16IdentifyTime;
#ifdef CLD_IDENTIFY_ATTR_COMMISSION_STATE
    zbmap8                  u8CommissionState;
#endif  
#endif
    zuint16                 u16ClusterRevision;
} tsCLD_Identify;

```

Where:

-   `u16IdentifyTime` is a mandatory attribute specifying the remaining length of time, in seconds, that the device continues in identification mode. Setting the attribute to a non-zero value puts the device into identification mode and the attribute is then decremented every second.

-   `u8CommissionState` is an optional attribute for use with EZ-mode Commissioning \(see [Chapter 40](#xref)\) to indicate the network status and operational status of the node - this information is contained in a bitmap, as follows:


|**Bits**|**Description**|
|--------|---------------|
|0|Network State

 -   1 if in the correct network \(must be 1 if Operational State bit is 1\)

-   0 if not in a network, or in a temporary network, or network status is unknown


|
|1|Operational State

 -   1 if commissioned for operation \(Network State bit is set to 1\)

-   0 if not commissioned for operation


|
|2 - 7|Reserved|

*u16ClusterRevision* is a mandatory attribute that specifies the revision of the cluster specification on which this instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Identify Cluster](../../Identify_cluster/topics/identify_cluster.md)

