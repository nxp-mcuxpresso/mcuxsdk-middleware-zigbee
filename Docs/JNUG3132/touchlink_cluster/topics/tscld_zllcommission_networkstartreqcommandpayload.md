# tsCLD\_ZllCommission\_NetworkStartReqCommandPayload

This structure is used to hold the payload data for a Touchlink Network Start Request command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint64  u64ExtPanId;
    uint8   u8KeyIndex;
    uint8   au8NwkKey[16];
    uint8   u8LogicalChannel;
    uint16  u16PanId;
    uint16  u16NwkAddr;
    uint16  u16GroupIdBegin;
    uint16  u16GroupIdEnd;
    uint16  u16FreeNwkAddrBegin;
    uint16  u16FreeNwkAddrEnd;
    uint16  u16FreeGroupIdBegin;
    uint16  u16FreeGroupIdEnd;
    uint64  u64InitiatorIEEEAddr;
    uint16  u16InitiatorNwkAddr;
} tsCLD_ZllCommission_NetworkStartReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u64ExtPanId` is the Extended PAN ID \(EPID\) of the new network \(if set to zero, the target node will choose the EPID\).

-   `u8KeyIndex` is a value indicating the type of security key used to encrypt the randomly generated network key in `au8NwkKey`. The valid values are as follows \(all other values are reserved for future use\):

    -   0: Development key, used during development before ZigBee certification

    -   4: Master key, used after successful ZigBee certification

    -   15: Certification key, used during ZigBee certification testing

-   `au8NwkKey[16]` is the 128-bit randomly generated network key encrypted using the key specified in `u8KeyIndex`.

-   `u8LogicalChannel` is the number of the IEEE 802.15.4 radio channel to be used by the network \(if set to zero, the target node will choose the channel\).

-   `u16PanId` is the PAN ID of the new network \(if set to zero, the target node will choose the PAN ID\).

-   `u16NwkAddr` is the 16-bit network \(short\) address assigned to the target node

-   `u16GroupIdBegin` is the start value of the range of group identifiers that the target node can use for its own endpoints \(if set to zero, no range of group identifiers has been allocated\).

-   `u16GroupIdEnd` is the end value of the range of group identifiers that the target node can use for its own endpoints \(if set to zero, no range of group identifiers has been allocated\).

-   `u16FreeNwkAddrBegin` is the start address of the range of network addresses that the target node can assign to other nodes \(if set to zero, no range of network addresses has been allocated\).

-   `u16FreeNwkAddrEnd` is the end address of the range of network addresses that the target node can assign to other nodes \(if set to zero, no range of network addresses has been allocated\).

-   `u16FreeGroupIdBegin` is the start value of the range of free group identifiers that the target node can assign to other nodes \(if set to zero, no range of free group identifiers has been allocated\).

-   `u16FreeGroupIdEnd` is the end value of the range of free group identifiers that the target node can assign to other nodes \(if set to zero, no range of free group identifiers has been allocated\).

-   `u64InitiatorIEEEAddr` is the IEEE \(MAC\) address of the local node \(network initiator\)

-   `u16InitiatorNwkAddr` is the network \(short\) address of the local node \(network initiator\)


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

