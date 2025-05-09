# tsCLD\_ZllCommission\_NetworkJoinRouterReqCommandPayload

This structure is used to hold the payload data for a Touchlink Network Join Router Request command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8KeyIndex;
    uint8   au8NwkKey[16];
    uint8   u8NwkUpdateId;
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint16  u16GroupIdBegin;
    uint16  u16GroupIdEnd;
    uint16  u16FreeNwkAddrBegin;
    uint16  u16FreeNwkAddrEnd;
    uint16  u16FreeGroupIdBegin;
    uint16  u16FreeGroupIdEnd;
} tsCLD_ZllCommission_NetworkJoinRouterReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u64ExtPanId` is the Extended PAN ID \(EPID\) of the network.

-   `u8KeyIndex` is a value indicating the type of security key used to encrypt the network key in `au8NwkKey`. The valid values are as follows \(all other values are reserved for future use\):

    -   0: Development key, used during development before ZigBee certification

    -   4: Master key, used after successful ZigBee certification

    -   15: Certification key, used during ZigBee certification testing

-   `au8NwkKey[16]` is the 128-bit network key encrypted using the key specified in `u8KeyIndex`.

-   `u8NwkUpdateId` is the current value of the Network Update Identifier. This identifier takes a value in the range 0x00 to 0xFF and is incremented when a network update has occurred which requires the network settings on the nodes to be changed.

-   `u8LogicalChannel` is the number of the IEEE 802.15.4 radio channel used by the network.

-   `u16PanId` is the PAN ID of the network

-   `u16NwkAddr` is the 16-bit network \(short\) address assigned to the target node

-   `u16GroupIdBegin` is the start value of the range of group identifiers that the target node can use for its own endpoints \(if set to zero, no range of group identifiers has been allocated\).

-   `u16GroupIdEnd` is the end value of the range of group identifiers that the target node can use for its own endpoints \(if set to zero, no range of group identifiers has been allocated\).

-   `u16FreeNwkAddrBegin` is the start address of the range of network addresses that the target node can assign to other nodes \(if set to zero, no range of network addresses has been allocated\).

-   `u16FreeNwkAddrEnd` is the end address of the range of network addresses that the target node can assign to other nodes \(if set to zero, no range of network addresses has been allocated\).

-   `u16FreeGroupIdBegin` is the start value of the range of free group identifiers that the target node can assign to other nodes \(if set to zero, no range of free group identifiers has been allocated\).

-   `u16FreeGroupIdEnd` is the end value of the range of free group identifiers that the target node can assign to other nodes \(if set to zero, no range of free group identifiers has been allocated\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

