# eCLD\_PPPowerProfileScheduleConstraintsReqSend

```
teZCL_Status eCLD_PPPowerProfileScheduleConstraintsReqSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_PP_PowerProfileReqPayload *psPayload);

```

## Description 

This function can be used on a cluster client to send a Power Profile Schedule Constraints Request to the cluster server, in order to obtain the schedule restrictions on a particular power profile on the server. The obtained constraints can subsequently be used in calculating a schedule of energy phases for the power profile \(e.g. before calling **eCLD\_PPEnergyPhasesScheduleNotificationSend\(\)**\).

The function is non-blocking and will return immediately. The server will send a response to this request and on receiving this response, an E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_SCHEDULE\_CONSTRAINTS\_RSP event is generated on the client, containing the requested schedule constraints in a `tsCLD_PP_PowerProfileScheduleConstraintsPayload` structure \(see [Section 21.10.7](tscld_pp_powerprofilescheduleconstraintspayload.md#id_ced83d02-2054-4ebb-9d1a-41f398b565e5)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster client resides
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster server resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the server node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.3](tscld_pp_powerprofilereqpayload.md#id_cdfb37de-bac6-43f9-9ae4-561a0fb4c48a)\), including the identifier of the relevant power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Client Functions](../../power_profile_cluster/topics/client_functions.md)

