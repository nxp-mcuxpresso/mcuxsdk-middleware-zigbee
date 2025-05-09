# eOTA\_SpecificFileUpgradeEndRequest

```
eOTA_SpecificFileUpgradeEndRequest(
    uint8 u8SourceEndPointId,
    uint8 u8Status);

```

## Description 

This function can be used to issue an Upgrade End Request for the device-specific file download that is in progress in order to indicate to the server that the download has completed. This request can be issued by the client optionally after the downloaded image has been verified and found to be valid.

## Parameters 

-   *u8SourceEndPointId*: Number of endpoint \(on client\) from which the request is sent
-   *u8Status*: Download status of device-specific file - if the file has been completely and successfully received, this parameter must be set to OTA\_STATUS\_SUCCESS

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

