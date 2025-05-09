# tsOTA\_UpgradeEndResponsePayload

The following structure contains payload data for an Upgrade End Response issued by the server \(as the result of an Upgrade End Request from a client\):

```
typedef struct
{
    uint32 u32UpgradeTime;
    uint32 u32CurrentTime;
    uint32 u32FileVersion;
    uint16 u16ImageType;
    uint16 u16ManufacturerCode;
}tsOTA_UpgradeEndResponsePayload;

```

where:

-   `u32UpgradeTime` is the UTC time, in seconds, at which the client should upgrade the running image with the downloaded image. If the server does not support UTC time \(indicated by a zero value for `u32CurrentTime`\), the client should interpret this value as a time delay before performing the image upgrade

-   `u32CurrentTime` is the current UTC time, in seconds, on the server. If UTC time is not supported by the server, this value should be set to zero. If this value is set to 0xFFFFFFFF, this indicates that the client should wait for an upgrade command from the server before performing the image upgrade


**Note:** If the client does not support UTC time but both of the above time values are non-zero, the client will take the difference between the two times as a time delay before performing the image upgrade.

-   `u32FileVersion` is the file version of the downloaded application image \(a wild card value of 0xFFFFFFFF can be used when the same response is sent to client devices from different manufacturers\)

-   `u16ImageType` is the type of the downloaded application image \(a wild card value of 0xFFFF can be used when the same response is sent to client devices from different manufacturers\)

-   `u16ManufacturerCode` is the manufacturer code that was received from the client in the Upgrade End Request message \(a wild card value of 0xFFFF can be used when the same response is sent to client devices from different manufacturers\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

