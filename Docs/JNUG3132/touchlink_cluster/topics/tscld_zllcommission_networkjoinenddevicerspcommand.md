# tsCLD\_ZllCommission\_NetworkJoinEndDeviceRspCommandPayload

This structure is used to hold the payload data for a Touchlink Network Join End Device Response command.

```
typedef struct
{
    uint32 u32TransactionId;
    uint8   u8Status;
} tsCLD_ZllCommission_NetworkJoinEndDeviceRspCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the response, which must take the same value as the identifier in the corresponding request.

-   `u8Status` indicates the outcome of the corresponding Network Join End Device Request: 0x00 for success, 0x01 for failure.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

