# tsCLD\_ZllCommission\_ScanReqCommandPayload

This structure is used to hold the payload data for a Touchlink Scan Request command.

```
typedef struct
{
    uint32 u32TransactionId;
    uint8  u8ZigbeeInfo;
    uint8  u8ZllInfo;
} tsCLD_ZllCommission_ScanReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u8ZigbeeInfo` is a bitmap of ZigBee information which indicates the ZigBee device type of the sending node and whether the radio receiver remains on when the node is idle. This information is inserted by the ZigBee stack.

-   `u8ZllInfo` is a bitmap indicating properties of the sending node, including whether the node is factory new, whether the node is able to assign addresses to other nodes and whether the node is able to initiate a link operation \(supports Touchlink Commissioning cluster on the client side\). This information is inserted automatically.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

