# tsCLD\_ZllCommissionCustomDataStructure

This structure is used to hold the data for a Touchlink command received by a node.

```
typedef struct
{
    tsZCL_ReceiveEventAddressInterPan    sRxInterPanAddr;
    tsZCL_CallBackEvent                  sCustomCallBackEvent;
    tsCLD_ZllCommissionCallBackMessage   sCallBackMessage;
} tsCLD_ZllCommissionCustomDataStructure;

```

where:

-   `RxInterPanAddr` is a ZCL structure containing the Inter-PAN addresses of the source and destination nodes of the command.

-   `sCustomCallBackEvent` is the ZCL event structure for the command.

-   `sCallBackMessage` is a structure containing the command ID and payload \(see [Section 44.8.4](tscld_zllcommissioncallbackmessage.md#id_5f8449b2-d487-4f83-b14c-da89f4cf1231)\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

