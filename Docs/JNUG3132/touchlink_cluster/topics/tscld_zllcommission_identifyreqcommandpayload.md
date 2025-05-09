# tsCLD\_ZllCommission\_IdentifyReqCommandPayload

This structure is used to hold the payload data for a Touchlink Identify Request command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint16  u16Duration;
} tsCLD_ZllCommission_IdentifyReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u16Duration` specifies the length of time \(in seconds\) that the target node is to remain in identify mode. The possible values are:

    -   0x0000: Exit identify mode immediately

    -   0x0001–0xFFFE: Number of seconds to remain in identify mode

    -   0xFFFF: Remain in identify mode for the default time for the target node

        -   If the target node is unable to provide accurate timings, it will attempt to remain in identify mode for as close to the requested time as possible

**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

