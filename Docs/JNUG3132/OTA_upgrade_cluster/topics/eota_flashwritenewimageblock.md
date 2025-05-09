# eOTA\_FlashWriteNewImageBlock

```
teZCL_Status eOTA_FlashWriteNewImageBlock(
    uint8 u8Endpoint,
    uint8 u8ImageIndex,
    bool bIsServerImage,
    uint8 *pu8UpgradeBlockData,
    uint8 u8UpgradeBlockDataLength,
    uint32 u32FileOffSet);

```

## Description 
This function can be used to write a block of an upgrade image to the devices internal Flash memory in the OTA server node. The image may be either of the following:

-   An upgrade image for the server itself \(the server will later be rebooted from this image\)

-   An upgrade image for one or more clients, which will later be made available for OTA distribution through the wireless network


The image in Flash memory to which the block belongs is identified by its index number. The specified image index number must be in the range 0 to \(OTA\_MAX\_IMAGES\_PER\_ENDPOINT - 1\).

Note that for JN518x, K32W041, and K32W061, internal Flash memory, writes must be 512-byte aligned.

## Parameters

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *u8ImageIndex*: Index number of image
-   *bIsServerImage*: Indicates whether new image is for the server or a client:
-   TRUE - Server image
-   FALSE - Client image
-   *pu8UpgradeBlockData*: Pointer to image block to be written
-   *u8UpgradeBlockDataLength*: Size, in bytes, of image block to be written
-   *u32FileOffSet*: Offset of block from start of image file \(in terms of number of bytes\)

## Returns 

-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_FAIL
-   E\_ZCL\_SUCCESS

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

