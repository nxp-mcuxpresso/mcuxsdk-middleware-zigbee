# eOTA\_HandleImageVerification

```
teZCL_Status eOTA_HandleImageVerification(
    uint8 u8SourceEndPointId,
    uint8 u8DstEndpoint,
    teZCL_Status eImageVerificationStatus);

```

## Description 

This function transmits an upgrade end request with the specified status.

## Parameters 

-   *u8SourceEndPointId*: Identifier of endpoint on which the cluster client operates
-   *u8DstEndpoint*: Identifier of endpoint \(on the server\) to which the upgrade end request is sent
-   *eImageVerificationStatus*: Image status code

## Returns 

-   E\_ZCL\_FAIL
-   E\_ZCL\_SUCCESS

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

