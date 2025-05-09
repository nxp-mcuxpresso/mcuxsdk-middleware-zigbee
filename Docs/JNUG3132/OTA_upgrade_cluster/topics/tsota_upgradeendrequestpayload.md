# tsOTA\_UpgradeEndRequestPayload

The following structure contains payload data for an Upgrade End Request issued by a client to terminate/close an image download from the server:

```
typedef struct
{
    uint32 u32FileVersion;
    uint16 u16ImageType;
    uint16 u16ManufacturerCode;
            uint8  u8Status;
}tsOTA_UpgradeEndRequestPayload;

```

where:

-   `u32FileVersion` is the file version of the upgrade image which has been downloaded

-   `u16ImageType` is the type of the upgrade image which has been downloaded

-   `u16ManufacturerCode` is the ZigBee-assigned number identifying the manufacturer of the client device from which the request originates

-   `u8Status` is the reported status of the image download, one of:

    -   OTA\_STATUS\_SUCCESS \(successfully downloaded and verified\)

    -   OTA\_STATUS\_INVALID\_IMAGE \(downloaded but failed verification\)

    -   OTA\_REQUIRE\_MORE\_IMAGE \(other images needed\)

    -   OTA\_STATUS\_ABORT \(download in progress is to be aborted\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

