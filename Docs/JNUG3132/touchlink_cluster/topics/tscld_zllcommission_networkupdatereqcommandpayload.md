# tsCLD\_ZllCommission\_NetworkUpdateReqCommandPayload

This structure is used to hold the payload data for a Touchlink Network Update Request command.

```
typedef struct
{
 uint32  u32TransactionId;
 uint64  u64ExtPanId;
 uint8u8NwkUpdateId;
 uint8u8LogicalChannel;
 uint16  u16PanId;
 uint16  u16NwkAddr;
} tsCLD_ZllCommission_NetworkUpdateReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u64ExtPanId` is the Extended PAN ID \(EPID\) of the network.

-   `u8NwkUpdateId` is the current value of the Network Update Identifier \(see [Section 44.4.3](updating_network_settings.md#id_e5dc05bb-5560-4583-b109-fde47217dfe7)\).

-   `u8LogicalChannel` is the number of the IEEE 802.15.4 radio channel used by the network.

-   `u16PanId` is the PAN ID of the network.

-   `u16NwkAddr` is the 16-bit network \(short\) address assigned to the target node.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

