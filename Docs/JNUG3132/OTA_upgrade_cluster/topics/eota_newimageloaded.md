# eOTA\_NewImageLoaded

```
teZCL_Status eOTA_NewImageLoaded(
        uint8 u8Endpoint,
        bool bIsImageOnCoProcessorMedia,
        tsOTA_CoProcessorOTAHeader
    *psOTA_CoProcessorOTAHeader);

```

## Description 

This function can be used for two purposes which relate to a new application image and which depend on whether the image has been stored in the internal Flash memory of the device or in the external storage device of a co-processor \(if any\) within the server node:

-   For an image stored in internal Flash memory, the function can be used to notify the OTA Upgrade cluster server on the specified endpoint that a new application image has been loaded into Flash memory and is available for download to clients. The server then validates the new image.

-   For one or more images stored in the co-processor’s external storage device, the function can be used to provide OTA header information for the image\(s\) to the cluster server. In the case of more than one image stored in co-processor storage, this function may replicate OTA header information for older images already registered with the server.


**Note:** The co-processor option is currently not supported for JN518x, K32W041, or K32W061.

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *bIsImageOnCoProcessorMedia*: Flag indicating whether image is stored in co-processor external storage device:
-   TRUE - Stored in co-processor
-   FALSE - Stored in internal Flash memory
-   *psOTA\_CoProcessorOTAHeader*: Pointer to OTA headers of images which are held in co-processor storage device

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

