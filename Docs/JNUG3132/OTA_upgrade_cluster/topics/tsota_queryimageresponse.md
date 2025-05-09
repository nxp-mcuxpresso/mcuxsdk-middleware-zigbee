# tsOTA\_QueryImageResponse

The following structure contains payload data for a Query Next Image Response issued by the server \(as the result of a Query Next Image Request from a client\):

```
typedef struct
{
    uint32 u32ImageSize;
    uint32 u32FileVersion;
    uint16 u16ManufacturerCode;
    uint16 u16ImageType;
    uint8  u8Status;
}tsOTA_QueryImageResponse;

```

where:

-   `u32ImageSize` is the total size of the available image, in bytes

-   `u32FileVersion` is the file version of the available image

-   `u16ManufacturerCode` is the manufacturer code that was received from the client in the Query Next Image Request message

-   `u16ImageType` is the image type that was received from the client in the Query Next Image Request message

-   `u8Status` indicates whether a suitable image is available for download:

    -   OTA\_STATUS\_SUCCESS: A suitable image is available

    -   OTA\_STATUS\_NO\_IMAGE\_AVAILABLE: No suitable image is available

        -   The other elements of the structure are only included in the case of success.

**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

