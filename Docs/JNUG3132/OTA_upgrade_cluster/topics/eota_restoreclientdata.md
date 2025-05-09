# eOTA\_RestoreClientData

```
teZCL_Status eOTA_RestoreClientData(
    uint8 u8Endpoint,
    tsOTA_PersistedData *psOTAData,
    bool_t bReset);

```

## Description 

This function can be used to restore OTA Upgrade context data that has been previously saved to Flash memory \(using the NVM\) on the local client - for example, it restores the OTA Upgrade attribute values. The function can be used to restore the data in RAM following a device reset or simply to refresh the data in RAM.

## Parameters 

-   *8Endpoint*: Number of endpoint corresponding to context data
-   *psOTAData*: Pointer to structure containing the context data to be restored \(see [Section 49.11.13](tsota_successblockresponsepayload.md#id_695eaf9c-84f6-4191-9f6d-50413e62a4de)\)
-   *bReset*: Indicates whether the data restoration follows a reset:
-   TRUE - Follows a reset
-   FALSE - Does not follow a reset

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

