# eZCL\_SendReadAttributesRequest

```
teZCL_Status eZCL_SendReadAttributesRequest(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    uint16 u16ClusterId,
    bool_t bDirectionIsServerToClient,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    uint8 u8NumberOfAttributesInRequest,
    bool_t bIsManufacturerSpecific,
    uint16 u16ManufacturerCode,
    uint16 *pu16AttributeRequestList);

```

## Description 

This function can be used to send a ‘read attributes’ request to a cluster on a remote endpoint. Read access to cluster attributes on the remote node must be enabled at compile-time as described in [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987).

Specify the endpoint on the local node from which the request is to be sent. Also specify the address of the destination node, the destination endpoint number, and the cluster from which attributes are to be read. It is possible to use this function to send a request to bound endpoints or to a group of endpoints on remote nodes. In the latter case, a group address must be specified.

**Note:** When sending requests to multiple endpoints through a single call to this function, multiple responses would subsequently be received from the remote endpoints.

The function allows you to read selected attributes from the remote cluster. Specify the number of attributes to be read and to identify the required attributes by means of an array of identifiers. This array must be created by the application \(the memory space for the array only needs to persist for the duration of this function call\). The attributes can be from the relevant ZigBee cluster specification or manufacturer-specific.

Also provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This feature is useful while sending more than one request to the same destination endpoint.

On receiving the ‘read attributes’ response, the obtained attribute values are automatically written to the local copy of the shared device structure for the remote device and an E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event is then generated for each attribute updated. The response may not contain values for all requested attributes. Finally, once all received attribute values have been parsed, the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE is generated.

## Parameters 

-   *u8SourceEndPointId*Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*Number of the remote endpoint to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *u16ClusterId*Identifier of the cluster to be read \(see the macros section in the cluster header file\)
-   *bDirectionIsServerToClient*Direction of request:
    -   TRUE: Cluster server to client
    -   FALSE: Cluster client to server
-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u8NumberOfAttributesInRequest*: Number of attributes to be read
-   *bIsManufacturerSpecific*: Indicates whether attributes are manufacturer-specific or defined in the relevant ZigBee cluster:
    -   TRUE: Attributes are manufacturer-specific
    -   FALSE: Attributes are from ZigBee cluster
-   *u16ManufacturerCode*: ZigBee Alliance code for the manufacturer that defined proprietary attributes \(set to zero if attributes are from the ZigBee cluster - that is, if *bIsManufacturerSpecific* is set to FALSE\)
-   *pu16AttributeRequestList*: Pointer to an array which lists the attributes to be read. The attributes are identified by using enumerations \(listed in the ‘Enumerations’ section of each cluster-specific chapter\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTES\_0
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

