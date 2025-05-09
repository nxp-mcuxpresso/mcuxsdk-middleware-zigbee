# tsCLD\_ZllCommission\_NetworkJoinRouterRspCommandPayload

This structure is used to hold the payload data for a Touchlink Network Join Router Response command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8Status;
} tsCLD_ZllCommission_NetworkJoinRouterRspCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the response, which must take the same value as the identifier in the corresponding request.

-   `u8Status` indicates the outcome of the corresponding Network Join Router Request: 0x00 for success, 0x01 for failure.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

