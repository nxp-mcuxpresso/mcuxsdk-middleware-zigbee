# eCLD\_PPEnergyPhaseScheduleStateNotificationSend

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

This function can be used on the cluster server to send an Energy Phases Schedule State Notification to a cluster client, in order to inform the client of the energy phases that are in the schedule of a particular power profile. The function is used to send an unsolicited command.

On receiving the notification on the client, the event E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_NOTIFICATION is generated, containing the sent power profile information in a `tsCLD_PP_EnergyPhasesSchedulePayload` structure \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides 
-   *u8DestinationEndPointId*:  Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *psDestinationAddress*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   **psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\), including the identifier of the relevant power profile and the associated schedule of energy phases

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

