# eCLD\_ZllCommissionCommandDeviceInfoRspCommandSend

```
PUBLIC teZCL_Status eCLD_ZllCommissionCommandDeviceInfoRspCommandSend(
ZPS_tsInterPanAddress *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
tsCLD_ZllCommission_DeviceInfoRspCommandPayload
*psPayload);

```

## Description 

This function is used to send a Device Information Response command containing information about the devices on the local node in reply to a received Device Information Request from a remote node. The command is sent as an inter-PAN message.

A pointer must be provided to a structure containing the data to be returned.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*        Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *psPayload*        Pointer to structure containing payload data for the Device Information Response command \(see [Section 44.8.8](tscld_zllcommission_deviceinforspcommandpayload.md#id_33e1e219-6687-4d0b-8d1f-f9e5256ceb1f)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

