# eOTA\_ClientImagePageRequest

```
teZCL_Status eOTA_ClientImagePageRequest(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_ImagePageRequest *psOtaPageRequest);

```

## Description 

This function can be used during an image download to send an Image Page Request to the server, in order to request the next page of image data. In this function call, a structure must be supplied which contains the payload data for the request. This data includes the page size, in bytes.

**Note 1:** Image Page Requests can be used instead of Image Block Requests if page requests have been enabled in the **zcl\_options.h** file for the client and server \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)).

**Note 2:** The cluster client automatically sends Image Page Requests \(if enabled\) to the server during a download, so it is not normally necessary for the application to call this function.

As a result of this function call, a sequence of Image Block Responses containing the requested data will \(eventually\) be received from the server. The arrival of each response will trigger an E\_CLD\_OTA\_COMMAND\_BLOCK\_RESPONSE event on the client. If this function is used \(rather than the stack\) to issue Image Page Requests, it is the responsibility of the application to keep a count of the number of data bytes received since the Image Page Request was issued - when all the requested page data has been received, this count will equal the specified page size.

Page requests are described in more detail in [Section 49.8.4](page_requests.md#id_a01735d1-0ceb-4b41-a26b-9b9050f56309).

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on client\) from which the request is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on server\) to which the request is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target server \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psOtaPageRequest*: Pointer to structure containing payload for request \(see [Section 49.11.9](tsota_imagepagerequest.md#id_70400234-ce69-45a1-b422-a7464d5aa3f0)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

