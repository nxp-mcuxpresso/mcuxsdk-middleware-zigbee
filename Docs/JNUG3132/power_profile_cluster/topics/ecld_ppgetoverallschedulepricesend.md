# eCLD\_PPGetOverallSchedulePriceSend

```
teZCL_Status eCLD_PPGetOverallSchedulePriceSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on the cluster server to send a Get Overall Schedule Price Request to a cluster client, in order to obtain the overall cost of all the power profiles that are executed over the next 24 hours. Use of this function must be enabled in the cluster compile-time options, as described in [Section 21.11](compile-time_options.md#id_b8a93293-b412-43d1-a3e6-4800989d0691).

The function is non-blocking and will return immediately. On successfully receiving a Get Overall Schedule Price Response from the client, an E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE\_RSP event is generated on the server, containing the required price information in a `tsCLD_PP_GetOverallSchedulePriceRspPayload` structure \(see [Section](tscld_pp_getoverallschedulepricersppayload.md#id_0b0f4382-76c2-420d-bb99-d503dec06f43)21.10.10\). For full details of handling a Get Overall Schedule Price Request, refer to [Section 21.5.6.2](requesting_cost_of_power_profile_schedules_over_a_.md#id_3f46759e-a199-4d06-aa04-3ad55f4fbe65).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster server resides
-   *u8DestinationEndPointId*: Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

