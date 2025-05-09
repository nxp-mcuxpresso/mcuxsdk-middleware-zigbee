# eOTA\_ServerImageNotify

```
teZCL_Status eOTA_ServerImageNotify(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_ImageNotifyCommand *psImageNotifyCommand);

```

## Description 

This function issues an Image Notify message to one or more clients to indicate that a new application image is available for download.

The message can be unicast to an individual client or multicast to selected clients \(but cannot be broadcast to all clients, for security reasons\).

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on server\) from which the message is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on client\) to which the message is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target client for the message - a multicast to more than one client is also possible \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psImageNotifyCommand*: Pointer to structure containing payload for message \(see [Section 49.11.5](tsota_imagenotifycommand.md#id_5b4b4193-2e77-4385-9d9e-89803ba59926)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

