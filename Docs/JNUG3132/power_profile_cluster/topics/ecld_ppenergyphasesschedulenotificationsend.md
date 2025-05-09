# eCLD\_PPEnergyPhasesScheduleNotificationSend

```
teZCL_Status eCLD_PPEnergyPhasesScheduleNotificationSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_PP_EnergyPhasesSchedulePayload
*psPayload);

```

## Description 

This function can be used on a cluster client to send an Energy Phases Schedule Notification to the cluster server, in order to start the schedule of energy phases of a power profile on the server. The function is used to send an unsolicited command and should only be called if the server allows itself to be remotely controlled. The command payload specifies the identifiers of the required energy phases and includes the relative start-times of the phases \(see [Section 21.10.12](tscld_pp_energyphasedelay.md#id_f35a9742-8103-4549-ac3c-8e862fb0a6eb)\).

On receiving the notification on the server, the event E\_CLD\_PP\_CMD\_ENERGY\_PHASE\_SCHEDULE\_NOTIFICATION is generated, containing the sent energy phase schedule information in a `tsCLD_PP_EnergyPhasesSchedulePayload` structure \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\). The subsequent handling of this notification is detailed in [Section 21.5.4.2](notification_of_a_schedule_by_client.md#id_b545b6d7-cc27-4a0e-bfca-dd8b143c2a3b).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster client resides:
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster server resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the server node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the command \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\), including the scheduled energy phases and start-times

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Client Functions](../../power_profile_cluster/topics/client_functions.md)

