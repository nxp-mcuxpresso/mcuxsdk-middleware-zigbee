# tsCLD\_ZllCommission\_FactoryResetReqCommandPayload

This structure is used to hold the payload data for a Touchlink Reset to Factory New Request command.

```
typedef struct
{
    uint32 u32TransactionId;
} tsCLD_ZllCommission_FactoryResetReqCommandPayload;

```

where `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

