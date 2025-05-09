# 
eZCL\_ReadLocalAttributeValue
```
ZPS_teStatus eZCL_ReadLocalAttributeValue(
    uint8 u8SourceEndPointId,
    uint16 u16ClusterId,
    bool bIsServerClusterInstance,
    bool bIsManufacturerSpecific,
    bool_t blsClientAttribute,
    uint16 u16AttributeId,
    void *pvAttributeValue);

```

## Description 

This function can be used to read a local attribute value of the specified cluster on the specified endpoint. Before reading the attribute value, the function checks that the attribute and cluster actually reside on the endpoint.

## Parameters 

-   *u8SourceEndPointId*        Number of the local endpoint on which the read will be performed
-   *u16ClusterId*        Identifier of the cluster to be read \(see the macros section in the cluster header file\)                
-   *bIsServerClusterInstance*        Type of cluster instance to be read:
-   TRUE: Cluster server
-   FALSE: Cluster client
-   *bIsManufacturerSpecific*                Indicates whether attribute is manufacturer-specific or as defined in relevant ZigBee cluster:
-   TRUE: Attribute is manufacturer-specific
-   FALSE: Attribute is from ZigBee cluster
-   *blsClientAttribute*        Type of attribute to be read \(client or server\):
-   TRUE: Client attribute
-   FALSE: Server attribute
-   *u16AttributeId*        Identifier of the attribute to be read
-   *pvAttributeValue*        Pointer                 to location to receive the read attribute value

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTE\_WO
-   E\_ZCL\_ERR\_ATTRIBUTES\_ACCESS
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_PARAMETER\_RANGE

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

