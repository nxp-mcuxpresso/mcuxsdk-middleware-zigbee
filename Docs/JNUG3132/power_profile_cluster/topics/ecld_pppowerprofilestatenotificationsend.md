# eCLD\_PPPowerProfileStateNotificationSend

```
teZCL_Status eCLD_PPEnergyPhasesScheduleStateNotificationSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_PP_EnergyPhasesSchedulePayload
*psPayload);

```

## Description 

This function can be used on the cluster server to send a Power Profile State Notification to a cluster client, in order to inform the client of the state of the power profile that is currently active on the server. The function is used to send an unsolicited command.

On receiving the notification on the client, the event E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_NOTIFICATION is generated, containing the sent power profile state information in a `tsCLD_PP_PowerProfileStatePayload` structure \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides
-   *u8DestinationEndPointId*: Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the command \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\), including the identifier and state of the relevant power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

