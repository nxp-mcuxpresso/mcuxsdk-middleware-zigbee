# eZCL\_CreateLocalReport

```
teZCL_Status eZCL_CreateLocalReport(
    uint8 u8SourceEndPointId,
    uint16 u16ClusterId,
    bool_t bManufacturerSpecific,
    bool_t bIsServerAttribute,
    tsZCL_AttributeReportingConfigurationRecord
*psAttributeReportingConfigurationRecord);

```

## Description 

This function can be used on a cluster server during a ‘cold start’ to register attribute reporting configuration data \(with the ZCL\) that has been retrieved from Non-Volatile Memory \(NVM\) using the Non-Volatile Memory Manager \(NVM\). Each call of the function registers the Attribute Reporting Configuration Record for a single attribute. This configuration record is supplied to the function in a structure that has been populated using the NVM. The function should only be called after the ZCL has been initialized. Following this function call, automatic attribute reporting can resume for the relevant attribute \(for example, following a power loss or device reset\).

The function must not be called for attributes that have not been configured for automatic attribute reporting. For example, it must not be used for attributes for which the maximum reporting interval is set to REPORTING\_MAXIMUM\_TURNED\_OFF\).

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *u8SourceEndPointId*: Number of endpoint on which the relevant cluster is located
-   *u16ClusterId*: Identifier of the cluster containing the attribute for which retrieved attribute reporting configuration data is to be registered \(see the macros section in the cluster header file\)
-   *bManufacturerSpecific*: Indicates whether attribute is manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attribute is manufacturer-specific
    -   FALSE: Attribute is from ZigBee cluster
-   *bIsServerAttribute*: Indicates whether the attribute is located on the cluster server \(or client\):
    -   TRUE: Attribute is on cluster server
    -   FALSE: Attribute is on cluster client
-   *psAttributeReportingConfigurationRecord*: Pointer to structure \(see [Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\) containing the reporting configuration data for the attribute

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

