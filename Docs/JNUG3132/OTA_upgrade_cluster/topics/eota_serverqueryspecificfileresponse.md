# eOTA\_ServerQuerySpecificFileResponse

```
teZCL_Status eOTA_ServerQuerySpecificFileResponse(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_QuerySpecificFileResponsePayload
    *psQuerySpecificFileResponsePayload,
    uint8 u8TransactionSequenceNumber);
```

## Description 

This function can be used to issue a Query Specific File Response to a client which has sent a Query Specific File Request \(the arrival of this request triggers the event E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_REQUEST on the server\). The Query Specific File Response contains information on the latest device-specific file available for download to the client, including the file size and file version.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on server\) from which the response is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on client\) to which the response is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target client
-   *psQuerySpecificFileResponsePayload*:
-   Pointer to structure containing payload for Query Specific File Response \(see [Section 49.11.20](tsota_queryspecificfileresponsepayload.md#id_ec076d34-ffb9-48b4-a22b-f64615a28b85)\)
-   *u8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

