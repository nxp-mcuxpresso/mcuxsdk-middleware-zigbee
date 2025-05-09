# eCLD\_ZllCommissionCommandNetworkJoinRouterReqCommandSend

```
teZCL_Status eCLD_ZllCommissionCommandNetworkJoinRouterReqCommandSend(
    ZPS_tsInterPanAddress *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload
    *psPayload);

```

## Description 

This function is used to send a Network Join Router Request command to allow a detected Router to join the created network. The command is sent as an inter-PAN message.

The function can be called once a network has been created. The target Router is distinct from the Router that was included when network was created.

The command payload contains information about the network and the local node, as well as certain data for the target node. This payload information is detailed in [Section 44.8.13](tscld_zllcommission_networkjoinrouterreqcommandpay.md#id_136bcd5e-a6b3-43ec-a37e-af42ba0f064f).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psDestinationAddress*                Pointer to stucture containing PAN ID and address information for target node
-   *pu8TransactionSequenceNumber*        Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *psPayload*        Pointer to structure containing payload data for the Network Join Router Request command \(see [Section 44.8.13](tscld_zllcommission_networkjoinrouterreqcommandpay.md#id_136bcd5e-a6b3-43ec-a37e-af42ba0f064f)\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

