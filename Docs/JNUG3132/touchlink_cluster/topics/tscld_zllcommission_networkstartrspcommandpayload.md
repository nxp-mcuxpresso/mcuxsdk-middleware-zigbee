# tsCLD\_ZllCommission\_NetworkStartRspCommandPayload

This structure is used to hold the payload data for a Touchlink Network Start Response command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8Status;
    uint64  u64ExtPanId;
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
} tsCLD_ZllCommission_NetworkStartRspCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the response, which must take the same value as the identifier in the corresponding request.

-   `u8Status` indicates the outcome of the corresponding Network Start Request: 0x00 for success, 0x01 for failure.

-   `u64ExtPanId` is the Extended PAN ID \(EPID\) of the new network \(this will be the value specified in the corresponding request or a value chosen by the local node\).

-   `u8NwkUpdateId` is the current value of the Network Update Identifier, which will be set to zero for a new network \(see [Section 44.4.3](updating_network_settings.md#id_e5dc05bb-5560-4583-b109-fde47217dfe7)\).

-   `u8LogicalChannel` is the number of the IEEE 802.15.4 radio channel to be used by the network \(this will be the value specified in the corresponding request or a value chosen by the local node\).

-   `u16PanId` is the PAN ID of the new network \(this will be the value specified in the corresponding request or a value chosen by the local node\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

