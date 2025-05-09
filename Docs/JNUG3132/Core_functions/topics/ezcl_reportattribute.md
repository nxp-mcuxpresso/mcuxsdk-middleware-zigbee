# eZCL\_ReportAttribute

```
teZCL_Status eZCL_ReportAttribute(
    tsZCL_Address *psDestinationAddress,
    uint16 u16ClusterID,
    uint16 u16AttributeID,
    uint8 u8SrcEndPoint,
    uint8 u8DestEndPoint,
    PDUM_thAPduInstance hAPduInst);

```

## Description 

This function can be used on the cluster server to issue an attribute report for an individual reportable attribute on the server. Only a standard attribute can be reported - a manufacturer-specific attribute cannot be reported.

Use of this function requires no special configuration on the cluster server but the target client must be enabled to receive attribute reports \(via the compile-time option ZCL\_ATTRIBUTE\_REPORTING\_CLIENT\_SUPPORTED - see [Appendix B.3.1](../../appendix/topics/compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a)\).

After this function has been called and before the attribute report is sent, the event E\_ZCL\_CBET\_REPORT\_REQUEST is generated on the server, allowing the application to update the attribute value in the shared structure, if required.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the attribute report is sent
-   *u16ClusterID*: Identifier of the cluster containing the attribute to be reported \(see the macros section in the cluster header file\)
-   *u16AttributeID*: Identifier of the attribute to be reported
-   *u8SrcEndPoint*: Number of endpoint on server from which attribute report is sent
-   *u8DestEndPoint*: Target client to which attribute report is sent
-   *hAPduInst*: Handle of APDU instance that contains the attribute report

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_REPORTABLE
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

