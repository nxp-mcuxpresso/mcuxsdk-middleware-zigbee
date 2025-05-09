# eCLD\_ZllCommissionCommandDeviceInfoReqCommandSend

```
teZCL_Status eCLD_ZllCommissionCommandDeviceInfoReqCommandSend(
ZPS_tsInterPanAddress *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber, tsCLD_ZllCommission_DeviceInfoReqCommandPayload *psPayload);

```

## Description 

This function is used to send a Device Information Request command to obtain information about the devices on a remote node. The command is sent as an inter-PAN message.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*        Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to structure containing payload data for the Device Information Request command \(see [Section 44.8.7](tscld_zllcommission_deviceinforeqcommandpayload.md#id_fe1d261e-265e-4b34-918e-f6359bb4a6a6)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

