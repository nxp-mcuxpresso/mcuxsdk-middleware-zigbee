# eOTA\_ServerUpgradeEndResponse

```
teZCL_Status eOTA_ServerUpgradeEndResponse(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    tsOTA_UpgradeEndResponsePayload
    *psUpgradeResponsePayload,
    uint8 u8TransactionSequenceNumber);

```

## Description 

This function issues an Upgrade End Response to a client to which the server has been downloading an application image. The function is called after receiving an Upgrade End Request from the client, indicating that the client has received the entire application image and verified it \(the arrival of this request triggers the event E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_REQUEST on the server\).

The Upgrade End Response includes the upgrade time for the downloaded image as well as the current time \(the client will use this information to implement a delay before upgrading the running application image\).

**Note:** The cluster server responds automatically to an Upgrade End Request, so it is not normally necessary for the application to call this function.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndpoint*: Number of endpoint \(on server\) from which the response is sent
-   *u8DestinationEndpoint*: Number of endpoint \(on client\) to which the response is sent
-   *psDestinationAddress*: Pointer to structure containing the address of the target client for the response \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\)
-   *psUpgradeResponsePayload*: Pointer to structure containing payload for response \(see [Section 49.11.12](tsota_upgradeendresponsepayload.md#id_cdb28372-e8be-4682-af73-94e5114f985e)\)
-   *u8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

