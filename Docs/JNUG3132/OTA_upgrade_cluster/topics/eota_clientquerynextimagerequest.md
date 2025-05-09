# eOTA\_ClientQueryNextImageRequest

```
teZCL_Status eOTA_ClientQueryNextImageRequest(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_QueryImageRequest
*psQueryImageRequest);

```

## Description 

This function issues a Query Next Image Request to the server and should be called in either of the following situations:

-   to poll for a new application image \(typically used in this way by an End Device\) - in this case, the function should normally be called periodically

-   to respond to an Image Notify message from the server, which indicated that a new application image is available for download - in this case, the function call should be prompted by the event E\_CLD\_OTA\_COMMAND\_IMAGE\_NOTIFY


The payload of the request includes the relevant image type, current file version, hardware version and manufacturer code.

As a result of this function call, a Query Next Image Response will \(eventually\) be received from the server. The arrival of this response will trigger an E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE event.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on client\) from which the request is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on server\) to which the request is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target server \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psQueryImageRequest*: Pointer to structure containing payload for request \(see [Section 49.11.6](tsota_queryimagerequest.md#id_4166007c-a9a5-45d9-83ab-4a203fb98374)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

