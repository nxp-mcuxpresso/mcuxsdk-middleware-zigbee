# eCLD\_PPEnergyPhasesScheduleReqSend

```
teZCL_Status eCLD_PPEnergyPhasesScheduleReqSend(
uint8 u8SourceEndPointId,
uint8 u8DestinationEndPointId,
tsZCL_Address *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
tsCLD_PP_PowerProfileReqPayload *psPayload);

```

## Description 

This function can be used on the cluster server to send an Energy Phases Schedule Request to a cluster client, in order to obtain the schedule of energy phases for a particular power profile.

The function is non-blocking and will return immediately. On successfully receiving an Energy Phases Schedule Response from the client, an `E_CLD_PP_CMD_ENERGY_PHASE_SCHEDULE_RSP` event is generated on the server, containing the requested schedule information in a `tsCLD_PP_EnergyPhasesSchedulePayload` structure \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\). For full details of handling an Energy Phases Schedule Request, refer to [Section](requesting_a_schedule_by_server.md#id_cd6274b7-0366-4883-9612-b48405b2c9e6)21.5.4.1.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides:
-   *u8DestinationEndPointId*: Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.3](tscld_pp_powerprofilereqpayload.md#id_cdfb37de-bac6-43f9-9ae4-561a0fb4c48a)\), including the identifier of the relevant power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

