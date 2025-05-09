# eOTA\_SetServerAuthorisation

```
teZCL_Status eOTA_SetServerAuthorisation(
    uint8 u8Endpoint,
    eOTA_AuthorisationState eState,
    uint64 *pu64WhiteList,
    uint8 u8Size);

```

## Description 

This function can be used to define a set of clients to which the server is authorized to download application images. The function allows all clients to be authorized or a list of selected authorized clients to be provided. Clients are specified in this list by means of their 64-bit IEEE/MAC addresses.

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *eState*: Indicates whether a list of authorized clients is used or all clients are authorized - one of:
    -   E\_CLD\_OTA\_STATE\_USE\_LIST
    -   E\_CLD\_OTA\_STATE\_ALLOW\_ALL
-   *pu64WhiteList*: Pointer to list of IEEE/MAC addresses of authorized clients \(ignored if all clients are authorized through *eState* parameter\)
-   *u8Size* Number of clients in list
-   \(ignored if all clients are authorized through *eState* parameter\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

