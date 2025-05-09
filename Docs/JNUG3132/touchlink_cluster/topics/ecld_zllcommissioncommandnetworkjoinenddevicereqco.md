# eCLD\_ZllCommissionCommandNetworkJoinEndDeviceReqCommandSend

```
teZCL_Status    eCLD_ZllCommissionCommandNetworkJoinEndDeviceReqCommandSend(
    ZPS_tsInterPanAddress *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_NetworkJoinEndDeviceReqCommandPayload
*psPayload);

```

## Description 

This function is used to send a Network Join End Device Request command to allow a detected End Device to join the created network. The command is sent as an inter-PAN message.

The function can be called once a network has been created.

The command payload contains information about the network and the local node, as well as certain data for the target node. This data includes a range of network addresses and a range of group IDs from which the target End Device can assign values to the other nodes - in this case, the End Device would typically be a remote control unit. This payload information is detailed in [Section 44.8.15](tscld_zllcommission_networkjoinenddevicereqcommand.md#id_b9a6d171-837f-4974-8ad8-473b17a73375).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress*:  Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*:  Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*:  Pointer to structure containing payload data for the Network Join End Device Request command \(see [Section 44.8.15](tscld_zllcommission_networkjoinenddevicereqcommand.md#id_b9a6d171-837f-4974-8ad8-473b17a73375)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

