# eOTA\_ServerSwitchToNewImage

```
teZCL_Status eOTA_ServerSwitchToNewImage(
    uint8 u8Endpoint,
    uint8 u8ImageIndex);

```

## Description 

This function can be used to force a reset of the device in the OTA server node and, on reboot, run a new application image that has been saved in the attached Flash memory.

Before forcing the reset of the remove device, the function checks whether the version of the new image is greater than the version of the current image. If this is the case, the function invalidates the currently running image in Flash memory and initiates a software reset - otherwise, it returns an error.

The new application image is identified by its index number. The specified image index number must be in the range 0 to \(OTA\_MAX\_IMAGES\_PER\_ENDPOINT - 1\).

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *u8ImageIndex*: Index number of image

## Returns 

-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_FAIL
-   E\_ZCL\_SUCCESS

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

