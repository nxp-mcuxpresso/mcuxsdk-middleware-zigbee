# eOTA\_GetCurrentOtaHeader

```
teZCL_Status eOTA_GetCurrentOtaHeader(
    uint8 u8Endpoint,
    bool_t bIsServer,
    tsOTA_ImageHeader *psOTAHeader);

```

## Description 

This function can be used to obtain the OTA header of the application image which is currently running on the local node.

The obtained parameter values are received in a `tsOTA_ImageHeader` structure.

## Parameters 

-   *u8Endpoint*        Number of endpoint on which cluster operates
-   *bIsServer*        Side of the cluster implemented on this device:
-                                   TRUE - Server
-                   FALSE - Client
-   *psOTAHeader*        Pointer         to structure to receive the current OTA header \(see [Section 49.11.1](tsota_imageheader.md#id_15e13c2c-b2e4-405c-9806-306a1fc6d4bd)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[General Functions](../../OTA_upgrade_cluster/topics/general_functions.md)

