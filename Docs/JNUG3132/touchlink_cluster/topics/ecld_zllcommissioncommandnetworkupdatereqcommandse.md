# eCLD\_ZllCommissionCommandNetworkUpdateReqCommandSend

```
teZCL_Status eCLD_ZllCommissionCommandNetworkUpdateReqCommandSend(
        ZPS_tsInterPanAddress *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_ZllCommission_NetworkUpdateReqCommandPayload
        *psPayload);

```

## Description 

This function is used to send a Network Update Request command to bring a node that has missed a network update back into the network. The command is sent as an inter-PAN message.

The command payload contains information about the network, including the current value of the Network Update Identifier. This identifier takes a value in the range 0x00 to 0xFF and is incremented when a network update has occurred \(the value wraps around at 0xFF\). Thus, if this value in the payload is more recent than the value of this identifier held by the target node, the node should update its network settings using the values in the rest of the payload. The payload information is detailed in [Section 44.8.17](tscld_zllcommission_networkupdatereqcommandpayload.md#id_2f60b1a7-5129-41f0-9525-b2a79e7388f2).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress* Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload* Pointer to structure containing payload data for the Network Update Request command \(see [Section 44.8.17](tscld_zllcommission_networkupdatereqcommandpayload.md#id_2f60b1a7-5129-41f0-9525-b2a79e7388f2)\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

