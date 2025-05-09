# eOTA\_ClientQuerySpecificFileRequest

```
eOTA_ClientQuerySpecificFileRequest(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_QuerySpecificFileRequestPayload
*psQuerySpecificFileRequestPayload);

```

## Description 

This function can be used to issue a Query Specific File Request to the server. It should be called to request a device-specific file from the server. As a result of this function call, a Query Specific File Response will \(eventually\) be received in reply.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on client\) from which the request is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on server\) to which the request is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target server
-   *psQuerySpecificFileRequestPayload*: Pointer to structure containing payload for Query Specific File Request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

