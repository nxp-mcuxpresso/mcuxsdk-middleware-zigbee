# eZCL\_SendConfigureReportingCommand

```
teZCL_Status eZCL_SendConfigureReportingCommand(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    uint16 u16ClusterId,
    bool_t bDirectionIsServerToClient,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    uint8 u8NumberOfAttributesInRequest,
    bool_t bIsManufacturerSpecific,
    uint16 u16ManufacturerCode,
    tsZCL_AttributeReportingConfigurationRecord
    *psAttributeReportingConfigurationRecord);

```

## Description 

This function can be used on a cluster client to send a ‘configure reporting’ command to a cluster server, in order to request automatic reporting to be configured for a set of attributes. The configuration information is provided to the function in an array of structures, where each structure contains the configuration data for a single attribute. The function will return immediately and the results of the request will later be received in a ‘configure reporting’ response.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

On receiving the ‘configure reporting’ response, the event

E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE\_RESPONSE

is generated for each attribute in the response. Therefore, multiple events will normally result from a single function call \(‘configure reporting’ command\). Following the event for the final attribute, the event

E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE\_RESPONSE

is generated to indicate that the configuration outcomes for all the attributes from the ‘configure reporting’ command have been reported.

**Note:** In order for automatic reporting to be successfully configured for an attribute using this function, the ‘reportable flag’ for the attribute must have been set on the cluster server using the function **eZCL\_SetReportableFlag\(\)**.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent
-   *u16ClusterId*: Identifier of the cluster to be configured \(see the macros section in the cluster header file\) 
-   *bDirectionIsServerToClient*: Direction of request:
    -   TRUE: Cluster server to client
    -   FALSE: Cluster client to server
-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the request would be sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u8NumberOfAttributesInRequest*: Number of attributes for which reporting is to be configured as a result of the request
-   *bIsManufacturerSpecific*: Indicates whether attributes are manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attributes are manufacturer-specific
    -   FALSE: Attributes are from ZigBee cluster
-   *u16ManufacturerCode*: ZigBee Alliance code for the manufacturer that defined proprietary attributes. This code is set to zero if attributes are from the ZigBee cluster - that is, if *bIsManufacturerSpecific* is set to FALSE
-   *psAttributeReportingConfigurationRecord*: Pointer to array of structures, where each structure contains the attributing reporting configuration data for a single attribute \(see [Section 6.1.5](../../ZCL_structures/topics/tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTES\_0
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_FAIL

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

