# eZCL\_SetReportableFlag

```
teZCL_Status eZCL_SetReportableFlag(
    uint8 u8SrcEndPoint,
    uint16 u16ClusterID,
    bool bIsServerClusterInstance,
    bool bIsManufacturerSpecific,
    uint16 u16AttributeId);

```

## Description 

This function can be used on a cluster server to set \(to ‘1’\) the ‘reportable flag’ E\_ZCL\_AF\_RP for an attribute. Setting this flag configures the attribute to be potentially reportable, allowing automatic reporting to be configured and implemented for the attribute. It will also allow the attribute to be reported as a result of a call to **eZCL\_ReportAllAttributes\(\)**.

The cluster on which the attribute resides must be specified. The flag will be set for the specified attribute on all endpoints, but a single endpoint must be nominated which will be used to search for the attribute definition and to check that the specified cluster has been registered with the ZCL.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *u8SourceEndPointId*: Number of endpoint to be used to search for the attribute definition and to check the cluster
-   *u16ClusterId*: Identifier of the cluster containing the attribute for which the flag is to be set: \(see the macros section in the cluster header file\)
-   *bIsServerClusterInstance*: Type of cluster instance to be set:
    -   TRUE: Cluster Server
    -   FALSE: Cluster Client
-   *bIsManufacturerSpecific*: Indicates whether attribute is manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attribute is manufacturer-specific
    -   FALSE: Attribute is from ZigBee cluster:
-   *u16AttributeId*: Identifier of attribute for which the flag is to be set

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_EP\_RANGE

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

