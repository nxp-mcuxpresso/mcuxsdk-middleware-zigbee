# eOTA\_ClientImageBlockRequest

```
teZCL_Status eOTA_ClientImageBlockRequest(
        uint8 u8SourceEndpoint,
        uint8 u8DestinationEndpoint,
        tsZCL_Address *psDestinationAddress,
        tsOTA_BlockRequest
    *psOtaBlockRequest);

```

## Description 

This function can be used during an image download to send an Image Block Request to the server, in order to request the next block of image data.

As a result of this function call, an Image Block Response containing the requested data block will \(eventually\) be received from the server. The arrival of this response will trigger an E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE event.

**Note:** The cluster client automatically sends Image Block Requests to the server during a download, so it is not normally necessary for the application to call this function.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on client\) from which the request is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on server\) to which the request is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target server \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psOtaBlockRequest*: Pointer to structure containing payload for request \(see [Section 49.11.8](tsota_blockrequest.md#id_922a2ae2-61cd-403c-a42e-efd4ab2d7aca)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

