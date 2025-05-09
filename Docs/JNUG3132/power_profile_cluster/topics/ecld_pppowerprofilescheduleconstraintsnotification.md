# eCLD\_PPPowerProfileScheduleConstraintsNotificationSend

```
teZCL_Status eCLD_PPPowerProfileScheduleConstraintsNotificationSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_PP_PowerProfileScheduleConstraintsPayload
    *psPayload);

```

## Description 

This function can be used on the cluster server to send a Power Profile Schedule Constraints Notification to a cluster client, in order to inform the client of the schedule restrictions on a particular power profile. The constraints are specified in a `tsCLD_PP_PowerProfileScheduleConstraintsPayload` structure \(see [Section 21.10.7](tscld_pp_powerprofilescheduleconstraintspayload.md#id_ced83d02-2054-4ebb-9d1a-41f398b565e5)\). They can subsequently be used by the client in calculating the schedule for the energy phases of the power profile. The function is used to send an unsolicited command.

On receiving the notification on the client, the event E\_CLD\_PP\_CMD\_SCHEDULE\_CONSTRAINTS\_NOTIFICATION is generated, containing the sent power profile constraint information in a `tsCLD_PP_PowerProfileScheduleConstraintsPayload` structure.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.7](tscld_pp_powerprofilescheduleconstraintspayload.md#id_ced83d02-2054-4ebb-9d1a-41f398b565e5)\), including the identifier of the relevant power profile and the associated schedule constraints

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

