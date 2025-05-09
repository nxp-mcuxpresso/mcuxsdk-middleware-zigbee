# eCLD\_PPPowerProfileRequestSend

```
teZCL_Status eCLD_PPPowerProfileRequestSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_PP_PowerProfileReqPayload *psPayload);

```

## Description 

This function can be used on a cluster client to send a Power Profile Request to the cluster server, in order to obtain one or more power profiles from the server. The function can be used to request a specific power profile \(specified using its identifier\) or all the power profiles supported by the server \(specified using an identifier of zero\).

The function is non-blocking and will return immediately. On receiving the server’s response, an E\_CLD\_PP\_CMD\_POWER\_PROFILE\_RSP event is generated on the client, containing a power profile in a `tsCLD_PP_PowerProfilePayload` structure \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\).

When a particular Power Profile ID is specified but:

-   The Power Profile ID is not in the valid range, the server will send a default response of INVALID\_VALUE.

-   The Power Profile ID is in the valid range but no data corresponding to this ID is available, the server will respond with a default response of NOT\_FOUND.


When all power profiles on the server are requested, a response is received for each profile separately and, therefore, the above event is generated for each profile reported.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster client resides:
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster server resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the server node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message
-   *psPayload*: Pointer to structure containing the payload for the request \(see [Section 21.10.3](tscld_pp_powerprofilereqpayload.md#id_cdfb37de-bac6-43f9-9ae4-561a0fb4c48a)\), including the identifier of the required power profile

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Client Functions](../../power_profile_cluster/topics/client_functions.md)

