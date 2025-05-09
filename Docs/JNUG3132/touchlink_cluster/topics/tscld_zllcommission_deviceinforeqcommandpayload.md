# tsCLD\_ZllCommission\_DeviceInfoReqCommandPayload

This structure is used to hold the payload data for a Touchlink Device Information Request command.

```
typedef struct
{
    uint32 u32TransactionId;
    uint8  u8StartIndex;
} tsCLD_ZllCommission_DeviceInfoReqCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the request. This is a random number generated and inserted automatically.

-   `u8StartIndex` specifies the index \(starting from 0\) of the first entry in the device table from which device information should be obtained.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

