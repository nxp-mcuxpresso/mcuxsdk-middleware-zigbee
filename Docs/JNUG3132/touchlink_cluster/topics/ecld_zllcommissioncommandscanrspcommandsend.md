# eCLD\_ZllCommissionCommandScanRspCommandSend

```
PUBLIC teZCL_Status eCLD_ZllCommissionCommandScanRspCommandSend(
    ZPS_tsInterPanAddress *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_ScanRspCommandPayload
*psPayload);

```

## Description 

This function is used to send a Scan Response command containing information about the local node in reply to a received Scan Request from a remote node. The command is sent as an inter-PAN message.

A pointer must be provided to a structure containing the data to be returned.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*        Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *psPayload*        Pointer to structure containing payload data for the Scan Response command \(see [Section 44.8.6](tscld_zllcommission_scanrspcommandpayload.md#id_57e83317-665c-41ad-b83e-6e8bb1102bcc)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

