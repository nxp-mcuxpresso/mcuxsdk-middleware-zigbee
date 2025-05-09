# tsCLD\_ZllCommission\_DeviceInfoRspCommandPayload

This structure is used to hold the payload data for a Touchlink Device Information Response command.

```
typedef struct
{
    uint32  u32TransactionId;
    uint8   u8NumberSubDevices;
    uint8   u8StartIndex;
    uint8   u8DeviceInfoRecordCount;
    tsCLD_ZllDeviceRecord asDeviceRecords[ZLL_MAX_DEVICE_RECORDS];
} tsCLD_ZllCommission_DeviceInfoRspCommandPayload;

```

where:

-   `u32TransactionId` is the 32-bit Inter-PAN Transaction Identifier of the response, which must take the same value as the identifier in the corresponding request.

-   `u8NumberSubDevices` is the number of ZigBee devices on the node \(as reported in the Scan Response\).

-   `u8StartIndex` is the index \(starting from 0\) of the first entry in the device table from which device information has been obtained \(this value should be as specified in the corresponding request\).

-   `u8DeviceInfoRecordCount` indicates the number of device information records included in the response \(in the range 0 to 5\).

-   `asDeviceRecords[]` is an array, where each array element is a `tsCLD_ZllDeviceRecord` structure containing a device information record for one ZigBee device on the node.


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

