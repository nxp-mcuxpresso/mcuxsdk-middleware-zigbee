# eOTA\_ServerImageBlockResponse

```
teZCL_Status eOTA_ServerImageBlockResponse(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_ImageBlockResponsePayload
    *psImageBlockResponsePayload,
    uint8 u8BlockSize,
    uint8 u8TransactionSequenceNumber);

```

## Description 

This function issues an Image Block Response, containing a block of image data, to a client to which the server is downloading an application image. The function is called after receiving an Image Block Request from the client, indicating that the client is ready to receive the next block of the application image \(the arrival of this request triggers the event E\_CLD\_OTA\_COMMAND\_BLOCK\_REQUEST on the server\).

The size of the block, in bytes, is specified as part of the function call. This must be less than or equal to the maximum possible block size defined in the **zcl\_options.h** file \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\).

**Note:** The cluster server responds automatically to an Image Block Request, so it is not normally necessary for the application to call this function.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on server\) from which the response is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on client\) to which the response is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target client for the response \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psImageBlockResponsePayload*: Pointer to structure containing payload for response \(see [Section 49.11.10](tsota_imageblockresponsepayload.md#id_51ded850-0671-42aa-aeef-4ee5317fba37)\)
-   *u8BlockSize*: Size, in bytes, of block to be transferred
-   *u8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

