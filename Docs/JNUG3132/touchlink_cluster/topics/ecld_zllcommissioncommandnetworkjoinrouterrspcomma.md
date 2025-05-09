# eCLD\_ZllCommissionCommandNetworkJoinRouterRspCommandSend

```
PUBLIC teZCL_Status eCLD_ZllCommissionCommandNetworkJoinRouterRspCommandSend(
    ZPS_tsInterPanAddress psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload
    *psPayload);

```

## Description 

This function is used to send a Network Join Router Response command to confirm that the local \(Router\) node is ready to join a network in reply to a received Network Join Router Request from a remote node. The command is sent as an inter-PAN message.

A pointer must be provided to a structure containing the data to be returned.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *psDestinationAddress*        Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   **psPayload*        Pointer to structure containing payload data for the Network Join Router Response command \(see [Section 44.8.14](tscld_zllcommission_networkjoinrouterrspcommandpay.md#id_4af0f069-8ca4-4add-b07a-0445ae8c19f3)\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

