# eCLD\_ZllCommission​​​CommandDeviceIdentify​ReqCommandSend


```
teZCL_Status eCLD_ZllCommissionCommandDeviceIdentifyReqCommandSend(
ZPS_tsInterPanAddress *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
tsCLD_ZllCommission_IdentifyReqCommandPayload
*psPayload);

```

## Description 

This function is used to send an Identify Request command to ask a remote node to identify itself by entering ‘identify mode’ \(this is a visual indication, such as flashing a LED\). The command is sent as an inter-PAN message.

The command payload contains a value indicating the length of time, in seconds, that the target device should remain in identify mode. It is also possible to use this command to instruct the target node to immediately exit identify mode \(if it is already in this mode\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress* Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*  Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*  Pointer to structure containing payload data for the Identify Request command \(see [Section 44.8.9](tscld_zllcommission_identifyreqcommandpayload.md#id_b0078eb1-06a1-4f60-84d2-32ca0e2779d8)\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

