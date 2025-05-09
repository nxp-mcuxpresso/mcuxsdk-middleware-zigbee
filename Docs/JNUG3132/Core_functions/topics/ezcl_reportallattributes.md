# eZCL\_ReportAllAttributes

```
teZCL_Status eZCL_ReportAllAttributes(
    tsZCL_Address *psDestinationAddress,
    uint16 u16ClusterID,
    uint8 u8SrcEndPoint,
    uint8 u8DestEndPoint,
    PDUM_thAPduInstance hAPduInst);

```

## Description 

This function can be used on the cluster server to issue an attribute report for all the reportable attributes on the server. Only the standard attributes are reported - this does not include manufacturer-specific attributes.

Use of this function requires no special configuration on the cluster server. However, the target client must be enabled to receive attribute reports \(via the compile-time option ZCL\_ATTRIBUTE\_REPORTING\_CLIENT\_SUPPORTED - see [Appendix B.3.1](../../appendix/topics/compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a)\).

After this function is called and before the attribute report is sent, the event E\_ZCL\_CBET\_REPORT\_REQUEST is generated on the server, allowing the application to update the attribute values in the shared structure, if required.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the attribute report is sent
-   *u16ClusterID*: Identifier of the cluster containing the attributes to be reported \(see the macros section in the cluster header file\)
-   *u8SrcEndPoint*: Number of endpoint on server from which attribute report is sent
-   *u8DestEndPoint*: Number of endpoint on target client to which attribute report is sent
-   *hAPduInst*: Handle of APDU instance that will contain the attribute report

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

