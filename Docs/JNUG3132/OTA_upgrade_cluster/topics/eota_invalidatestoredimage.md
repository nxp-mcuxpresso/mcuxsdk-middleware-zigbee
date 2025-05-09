# eOTA\_InvalidateStoredImage

```
teZCL_Status eOTA_InvalidateStoredImage(
    uint8 u8Endpoint,
    uint8 u8ImageIndex);

```

## Description 

This function can be used to invalidate an application image that is held in the Flash memory of the device. Once the image has been invalidated, it will no longer to available for OTA upgrade.

The image to be invalidated is identified by its index number. The specified image index number must be in the range 0 to \(OTA\_MAX\_IMAGES\_PER\_ENDPOINT - 1\).

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *u8ImageIndex*: Index number of image to be invalidated

## Returns 

-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_SUCCESS

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

