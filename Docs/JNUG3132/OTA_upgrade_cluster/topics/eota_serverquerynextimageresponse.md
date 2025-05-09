# eOTA\_ServerQueryNextImageResponse

```
teZCL_Status eOTA_ServerQueryNextImageResponse(
        uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_QueryImageResponse
    *psQueryImageResponsePayload,
    uint8 u8TransactionSequenceNumber);

```

## Description 

This function issues a Query Next Image Response to a client which has sent a Query Next Image Request \(the arrival of this request triggers the event E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_REQUEST on the server\).

The Query Next Image Response contains information on the latest application image available for download to the client, including the image size and file version.

**Note:** The cluster server responds automatically to a Query Next Image Request, so it is not normally necessary for the application to call this function.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on server\) from which the response is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on client\) to which the response is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target client for the response \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psQueryImageResponsePayload*: Pointer to structure containing payload for response \(see [Section 49.11.7](tsota_queryimageresponse.md#id_885caab8-04e8-48e0-98f5-fd53019ed05f)\)
-   *u8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

