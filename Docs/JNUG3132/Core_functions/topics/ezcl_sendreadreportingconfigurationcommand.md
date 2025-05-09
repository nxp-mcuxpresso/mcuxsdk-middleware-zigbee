# eZCL\_SendReadReportingConfigurationCommand

```
teZCL_Status eZCL_SendReadReportingConfigurationCommand(
uint8 u8SourceEndPointId,
uint8 u8DestinationEndPointId,
uint16 u16ClusterId,
bool_t bDirectionIsServerToClient,
tsZCL_Address *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
uint8 u8NumberOfAttributesInRequest,
bool_t bIsManufacturerSpecific,
uint16 u16ManufacturerCode,
tsZCL_AttributeReadReportingConfigurationRecord
*psAttributeReadReportingConfigurationRecord);

```

## Description 

This function can be used on a cluster client to send a ‘read reporting configuration’ command to a cluster server, in order to request the attribute reporting configuration data for a set of attributes. For each attribute, configuration data can be requested relating to either sending or receiving an attribute report. The required configuration data is specified to the function in an array of structures, where each structure contains the requirements for a single attribute. The function will return immediately and the results of the request will later be received in a ‘read reporting configuration’ response.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

On receiving the ‘read reporting configuration’ response, the event

E\_ZCL\_CBET\_REPORT\_READ\_INDIVIDUAL\_ATTRIBUTE\_CONFIGURATION\_RESPONSE

is generated for each attribute in the response. Therefore, multiple events will normally result from a single function call \(‘read reporting configuration’ command\). Following the event for the final attribute reported, the event

E\_ZCL\_CBET\_REPORT\_READ\_ATTRIBUTE\_CONFIGURATION\_RESPONSE

is generated to indicate that the configuration outcomes for all the attributes from the ‘configure reporting’ command have been reported.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent.
-   *u16ClusterId*: containing the attributes \(see the macros section in the cluster header file\)   
-   *bDirectionIsServerToClient*:  Direction of request:
    -   TRUE: Cluster server to client
    -   FALSE: Cluster client to server
-   *psDestinationAddress*Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u8NumberOfAttributesInRequest*: Number of attributes for which reporting is to be configured as a result of the request
-   *bIsManufacturerSpecific*: Indicates whether attributes are manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attributes are manufacturer-specific
    -   FALSE: Attributes are from ZigBee cluster
-   *u16ManufacturerCode*: ZigBee Alliance code for the manufacturer that defined proprietary attributes \(set to zero if attributes are from the ZigBee cluster - that is, if *bIsManufacturerSpecific* is set to FALSE\)
-   *psAttributeReportingConfigurationRecord*: Pointer to an array of structures, where each structure indicates the required configuration data for a single attribute \(see [Section 6.1.7](../../ZCL_structures/topics/tszcl_attributereadreportingconfigurationrecord.md#id_56f15456-6c97-48b3-a90b-1f697c28b53a)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTES\_0
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_FAIL

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

