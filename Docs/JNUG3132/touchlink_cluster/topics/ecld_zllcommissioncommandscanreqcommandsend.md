# eCLD\_ZllCommissionCommandScanReqCommandSend

```
eCLD_ZllCommissionCommandScanReqCommandSend(
    ZPS_tsInterPanAddress *psDestinationAddress,
     *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_ScanReqCommandPayload
    *psPayload);

```

## Description 

This function is used to send a Scan Request command to initiate a scan for other nodes in the local neighbourhood. The command is sent as an inter-PAN message.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node\(s\)
-   *pu8TransactionSequenceNumber*        Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to structure containing payload data for the Scan Request command \(see [Section](tscld_zllcommission_scanreqcommandpayload.md#id_076c7bc6-7249-4391-ae9b-bf43007e9139)44.8.5\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

