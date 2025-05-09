# eCLD\_PPPowerProfileStateReqSend

```
teZCL_Status eCLD_PPPowerProfileStateReqSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on a cluster client to send a Power Profile State Request to the cluster server, in order to obtain the identifier\(s\) of the power profile\(s\) currently supported on the server.

The function is non-blocking and returns immediately. On receiving the server’s response, an E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_RSP event is generated on the client, containing the required identifier\(s\). The response contains the power profile records of all the supported power profiles on the server in a `tsCLD_PP_PowerProfileStatePayload` structure \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster client resides:
-   *u8DestinationEndPointId* : Number of remote endpoint on which cluster server resides
-   *psDestinationAddress*: Pointer to a structure containing the destination address of the server node
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the message

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Client Functions](../../power_profile_cluster/topics/client_functions.md)

