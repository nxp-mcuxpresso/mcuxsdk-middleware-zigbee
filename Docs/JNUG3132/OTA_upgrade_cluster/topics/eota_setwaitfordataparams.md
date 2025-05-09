# eOTA\_SetWaitForDataParams

```
teZCL_Status eOTA_SetWaitForDataParams(
    uint8 u8Endpoint,
    uint16 u16ClientAddress,
    tsOTA_WaitForData *sWaitForDataParams);

```

## Description 

This function can be used to send an Image Block Response with a status of OTA\_STATUS\_WAIT\_FOR\_DATA to a client, in response to an Image Block Request from the client.

The payload of this response includes a new value for the ‘block request delay’ attribute on the client. This value can be used by the client for ‘rate limiting’ -that is, to control the rate at which the client requests data blocks from the server and therefore the average OTA download rate from the server to the client.

Rate limiting is described in more detail in [Section 49.8.1](rate_limiting.md#id_42342e5f-63cb-4458-9bad-7f1b68210fd8).

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) from which the response is sent
-   *u16ClientAddress*: Network address of client device to which the response is sent
-   *sWaitForDataParams*: Pointer to structure containing ‘Wait for Data’ parameter values for Image Block Response payload \(see [Section](tsota_waitfordata.md#id_d698b23b-cb16-4ed2-80a0-e56aa8c1061a)49.11.15\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

