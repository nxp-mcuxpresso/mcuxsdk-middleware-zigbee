# eOTA\_UpdateClientAttributes

```
teZCL_Status eOTA_UpdateClientAttributes(
    uint8 u8Endpoint);

```

## Description 

This function can be used on a client to set the OTA Upgrade cluster attributes to their default values. It should be called during application initialization after the cluster instance has been created using **eOTA\_Create\(\)**.

Following subsequent resets, provided that context data has been saved, the application should call **eOTA\_RestoreClientData\(\)** instead of this function.

## Parameters 

-   *u8Endpoint*: Number of endpoint corresponding to context data

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

