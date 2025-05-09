# eZCL\_SendWriteAttributesRequest

```
teZCL_Status eZCL_SendWriteAttributesRequest(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    uint16 u16ClusterId,
    bool_t bDirectionIsServerToClient,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    uint8 u8NumberOfAttributesInRequest,
    bool_t bIsManufacturerSpecific,
    uint16 u16ManufacturerCode,
    tsZCL_WriteAttributeRecord *pu16AttributeRequestList);

```

## Description 

This function can be used to send a ‘write attributes’ request to a cluster on a remote endpoint. The function also demands a ‘write attributes’ response from the remote endpoint, listing any attributes that could not be updated \(see below\). Note that write access to cluster attributes on the remote node must be enabled at compile-time as described in [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987).

You must specify the endpoint on the local node from which the request is to be sent.

You must also specify the address of the destination node, the destination endpoint number and the cluster to which attributes are to be written. It is possible to use this function to send a request to bound endpoints or to a group of endpoints on remote nodes - in the latter case, a group address must be specified. Note that when sending requests to multiple endpoints through a single call to this function, multiple responses will subsequently be received from the remote endpoints.

The function allows you to write selected attributes to the remote cluster. You are required to specify the number of attributes to be written and to identify the required attributes by means of an array of identifiers - this array must be created by the application \(the memory space for the array only needs to be valid for the duration of this function call\). The attributes can be from the relevant ZigBee cluster specification or manufacturer-specific

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

Following a ‘write attributes’ response from the remote endpoint, the event E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE is generated for each attribute that was not successfully updated on the remote endpoint. Finally, the event E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE is generated when processing of the response is complete. If required, these events can be handled in the user-defined callback function which is specified when the \(requesting\) endpoint is registered using the endpoint registration function for the device type.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent. This parameter is ignored while sending to address types, eZCL\_AMBOUND and eZCL\_AMGROUP.
-   *u16ClusterId*: Identifier of the cluster to be written to \(see the macros section in the cluster header file\)
-   *bDirectionIsServerToClient*: Direction of request:
    -   TRUE: Cluster server to client
    -   FALSE: Cluster client to server
-   *psDestinationAddress*: Pointer to a structure \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\) containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u8NumberOfAttributesInRequest*: Number of attributes to be written
-   *bIsManufacturerSpecific*: Indicates whether attributes are manufacturer-specific or as defined in relevant ZigBee cluster:
    -   TRUE: Attributes are manufacturer-specific
    -   FALSE: Attributes are from ZigBee cluster
-   *u16ManufacturerCode*: ZigBee Alliance code for the manufacturer that defined proprietary attributes \(set to zero if attributes are from the ZigBee cluster - that is, if *bIsManufacturerSpecific* is set to FALSE\)**
-   *pu16AttributeRequestList*: Pointer to an array of structures containing the attribute data to be written \(see [Section 6.1.21](../../ZCL_structures/topics/tszcl_writeattributerecord.md#id_04d6e2e2-5b63-4954-b862-7738964318bd)\)

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

