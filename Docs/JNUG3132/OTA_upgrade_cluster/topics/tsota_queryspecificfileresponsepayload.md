# tsOTA\_QuerySpecificFileResponsePayload

The following structure contains the payload for a Query Specific File Response which is issued by an OTA Upgrade server in response to a request for a device-specific file.

```
typedef struct
{
    uint32 u32FileVersion;
    uint32 u32ImageSize;
    uint16 u16ImageType;
    uint16 u16ManufacturerCode;
    uint8 u8Status;
}tsOTA_QuerySpecificFileResponsePayload;

```

where:

-   `32FileVersion` contains the release and build numbers of the application and stack that correspond to the device-specific file - this field will take the same value as the equivalent field in the corresponding Query Specific File Request \(see [Section 49.11.19](tsota_queryspecificfilerequestpayload.md#id_bf04a6cc-72de-495c-be36-77a5cf93fe16)\)

-   `u32ImageSize` is the size of the requested file, in bytes

-   `u16ImageType` indicates the requested file type - this field will take the same value as the equivalent field in the corresponding Query Specific File Request \(see [Section 49.11.19](tsota_queryspecificfilerequestpayload.md#id_bf04a6cc-72de-495c-be36-77a5cf93fe16)\)

-   `u16ManufactuerCode` is the ZigBee-assigned manufacturer code of the requesting node - this field will take the same value as the equivalent field in the corresponding Query Specific File Request \(see [Section 49.11.19](tsota_queryspecificfilerequestpayload.md#id_bf04a6cc-72de-495c-be36-77a5cf93fe16)\)

-   `u8Status` indicates whether a suitable file is available for download:

    -   OTA\_STATUS\_SUCCESS: A suitable file is available

    -   OTA\_STATUS\_NO\_IMAGE\_AVAILABLE: No suitable file is available

        -   The other elements of the structure are only included in the case of success.

**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

