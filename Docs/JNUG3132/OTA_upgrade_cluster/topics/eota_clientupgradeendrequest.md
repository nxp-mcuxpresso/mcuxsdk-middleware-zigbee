# eOTA\_ClientUpgradeEndRequest

```
teZCL_Status eOTA_ClientUpgradeEndRequest(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_UpgradeEndRequestPayload
    *psUpgradeEndRequestPayload);

```

## Description 

This function can be used during an image download to send an Upgrade End Request to the server. This is normally used to indicate that all the image data has been received and that the image has been successfully verified - it is the responsibility of the client to determine when all the image data has been received \(using the image size quoted in the original Query Next Image Response\) and then to verify the image.

In addition to the status OTA\_STATUS\_SUCCESS described above, the function can be used by the client to report other conditions to the server:

-   OTA\_REQUIRE\_MORE\_IMAGE: The downloaded image was successfully received and verified, but the client requires multiple images before performing an upgrade

-   OTA\_STATUS\_INVALID\_IMAGE: The downloaded image failed the verification checks and will be discarded

-   OTA\_STATUS\_ABORT The image download that is currently in progress should be cancelled


In all three of the above cases, the client may then request another download.

When the function is called to report success, an Upgrade End Response will \(eventually\) be received from the server, indicating when the image upgrade should be implemented \(a time delay may be indicated in the response\). The arrival of this response will trigger an E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_RESPONSE event.

**Note:** The cluster client automatically sends an Upgrade End Request to the server on completion of a download, so it is not normally necessary for the application to call this function.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on client\) from which the request is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on server\) to which the request is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target server \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psUpgradeEndRequestPayload*: Pointer to structure containing payload for request, including reported status \(see [Section](tsota_upgradeendrequestpayload.md#id_8c1f4ce0-1781-4405-b7d5-ae566167a983)49.11.11\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

