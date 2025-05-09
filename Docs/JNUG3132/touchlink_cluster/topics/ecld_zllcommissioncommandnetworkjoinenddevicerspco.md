# eCLD\_ZllCommissionCommandNetworkJoinEndDeviceRspCommandSend

```
PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinEndDeviceRspCommandSend(
ZPS_tsInterPanAddress *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload
*psPayload);

```

## Description 

This function is used to send a Network Join End Device Response command to confirm that the local \(End Device\) node is ready to join a network in reply to a received Network Join End Device Request from a remote node. The command is sent as an inter-PAN message.

A pointer must be provided to a structure containing the data to be returned.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *psDestinationAddress* Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber* Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *psPayload* Pointer to structure containing payload data for the Network Join End Device Response command \(see [Section 44.8.16](tscld_zllcommission_networkjoinenddevicerspcommand.md#id_83461af7-92ca-4873-b042-782f0af7d3a9)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

