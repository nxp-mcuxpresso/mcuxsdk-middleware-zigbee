# eCLD\_PPPowerProfileNotificationSend

```
teZCL_Status eCLD_PPPowerProfileNotificationSend(
     uint8 u8SourceEndPointId,
     uint8 u8DestinationEndPointId,
     tsZCL_Address *psDestinationAddress,
     uint8 *pu8TransactionSequenceNumber,
     tsCLD_PP_PowerProfilePayload *psPayload);

```

## Description 

This function can be used on the cluster server to send a Power Profile Notification to a cluster client, in order to inform the client about one power profile supported by the server. The notification contains essential information about the power profile, including the energy phases supported by the profile \(and certain details about them\). If the server supports multiple power profiles, the function must be called for each profile separately.

On receiving the notification on the client, the event E\_CLD\_PP\_CMD\_POWER\_PROFILE\_NOTIFICATION is generated, containing the sent power profile information in a `tsCLD_PP_PowerProfilePayload` structure \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\), including essential information about the power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

