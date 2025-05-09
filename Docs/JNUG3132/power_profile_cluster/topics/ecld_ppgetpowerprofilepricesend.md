# eCLD\_PPGetPowerProfilePriceSend

```
teZCL_Status eCLD_PPGetPowerProfilePriceSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_PP_PowerProfileReqPayload *psPayload);

```

## Description 

This function can be used on the cluster server to send a Get Power Profile Price Request to a cluster client, in order to request the cost of executing the schedule of a particular power profile. Use of this function must be enabled in the cluster compile-time options, as described in [Section 21.11](compile-time_options.md#id_b8a93293-b412-43d1-a3e6-4800989d0691).

The function is non-blocking and will return immediately. On successfully receiving a Get Power Profile Price Response from the client, an E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_RSP event is generated on the server, containing the requested price information in a `tsCLD_PP_GetPowerProfilePriceRspPayload` structure \(see [Section](tscld_pp_getpowerprofilepricersppayload.md#id_e3e14a9b-2497-4cee-aef9-4826500661f3)21.10.9\). For full details of handling a Get Power Profile Price Request, refer to [Section 21.5.6.1](requesting_cost_of_a_power_profile_schedule_by_ser.md#id_fd9cfc3c-67dc-4f3f-891b-a475ce6ed9f1).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*        Number of local endpoint on which cluster server resides        
-   *u8DestinationEndPointId*         Number of remote endpoint on which cluster client resides
-   *psDestinationAddress*        Pointer to a structure containing the destination address of the client node
-   *pu8TransactionSequenceNumber*        Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*        Pointer to structure containing the payload for the request \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\), including the identifier of the relevant power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

