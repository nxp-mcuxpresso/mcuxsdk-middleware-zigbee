# eCLD\_ZllCommissionCommandNetworkStartRspCommandSend

```
PUBLIC teZCL_Status     eCLD_ZllCommissionCommandNetworkStartRspCommandSend(
    ZPS_tsInterPanAddress *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_NetworkStartRspCommandPayload
    *psPayload);

```

## Description 

This function is used to send a Network Start Response command to confirm that the local \(Router\) node is ready to be the first node to join a newly created network in reply to a received Network Start Request from a remote node. The command is sent as an inter-PAN message.

A pointer must be provided to a structure containing the data to be returned.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*        Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *psPayload*        Pointer to structure containing payload data for the Network Start Response command \(see [Section 44.8.12](tscld_zllcommission_networkstartrspcommandpayload.md#id_0977fe59-eeac-4002-9070-daf8c2f0cba2)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

