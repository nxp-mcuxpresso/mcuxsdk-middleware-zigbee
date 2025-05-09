# eZCL\_SendDiscoverAttributesRequest

```
teZCL_Status eZCL_SendDiscoverAttributesRequest(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    uint16 u16ClusterId,
    bool_t bDirectionIsServerToClient,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    uint16 u16AttributeId,
    bool_t bIsManufacturerSpecific,
    uint16 u16ManufacturerCode,
    uint8 u8MaximumNumberOfIdentifiers);

```

## Description

This function can be used to send a ‘discover attributes’ request to a cluster \(normally a cluster server\) on a remote device. The range of attributes of interest \(within the standard set of cluster attributes\) must be defined by specifying the identifier of the ‘start’ attribute and the number of attributes in the range. The function returns immediately and the results of the request are later received in a ‘discover attributes’ response.

You must provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful while sending more than one request to the same destination endpoint.

On receiving the ‘discover attributes’ response, the event

*E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE*

is generated for each attribute reported in the response. Therefore, multiple events normally result from a single function call \(‘discover attributes’ request\). Following the event for the final attribute reported, the event

*E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES\_RESPONSE*

is generated to indicate that all attributes from the discover attributes response have been reported.

Attribute discovery is fully described in [Section 2.3.4](../../ZCL_fundamentals/topics/attribute_discovery.md#id_ca11ddf2-ae2d-4f1b-9e80-17c2622fded5).

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent
-   *u16ClusterId*: Identifier of the cluster to be queried \(see the macros section in the cluster header file\): :
-   *bDirectionIsServerToClient*: Direction of request:
    -   TRUE: Cluster server to client
    -   FALSE: Cluster client to server
-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u16AttributeId*: Identifier of ‘start’ attribute of interest
-   *bIsManufacturerSpecific*: Indicates whether attributes are manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attributes are manufacturer-specific
    -   FALSE: Attributes are from ZigBee cluster
-   *u16ManufacturerCode*: ZigBee Alliance code for the manufacturer that defined proprietary attributes \(set to zero if attributes are from the ZigBee cluster - that is, if *bIsManufacturerSpecific* is set to FALSE\)
-   *u8MaximumNumberOfIdentifiers*: Number of attributes in attribute range of interest \(maximum number of attributes to report in response\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTES\_0
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

