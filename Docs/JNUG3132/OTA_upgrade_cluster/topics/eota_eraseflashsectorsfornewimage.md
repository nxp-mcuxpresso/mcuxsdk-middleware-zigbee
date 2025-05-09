# eOTA\_EraseFlashSectorsForNewImage

```
teZCL_Status eOTA_EraseFlashSectorsForNewImage(
    uint8 u8Endpoint,
    uint8 u8ImageIndex);

```

## Description 

This function can be used to erase certain sectors of the Flash memory of the device in the OTA server node. The sectors allocated to the specified image index number will be erased so that the sectors \(and index number\) can be re-used. The function is normally called before writing a new upgrade image to Flash memory.

The specified image index number must be in the range 0 to \(OTA\_MAX\_IMAGES\_PER\_ENDPOINT - 1\).

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *u8ImageIndex*: Index number of image

## Returns

-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_SUCCESS

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

