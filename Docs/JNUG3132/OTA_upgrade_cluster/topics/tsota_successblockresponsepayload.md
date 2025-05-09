# tsOTA\_SuccessBlockResponsePayload

The following structure contains payload data for an Image Block Response which reports ‘success’ and therefore contains a block of image data \(see [Section 49.11.10](tsota_imageblockresponsepayload.md#id_51ded850-0671-42aa-aeef-4ee5317fba37)\):

```
typedef struct
{
    uint8* pu8Data;
            uint32 u32FileOffset;
            uint32 u32FileVersion;
            uint16 u16ImageType;
            uint16 u16ManufacturerCode;
    uint8  u8DataSize;
}tsOTA_SuccessBlockResponsePayload;

```

where:

-   `pu8Data` is a pointer to the start of the data block being transferred

-   `u32FileOffset` is the offset, in bytes, of the start of the data block from the start of the image \(normally, the same offset as specified in the Image Block Request\)

-   `u32FileVersion` is the file version of the upgrade image to which the included data block belongs

-   `u16ImageType` is the type of the upgrade image to which the included data block belongs

-   `u16ManufacturerCode` is the manufacturer code that was received from the client in the Image Block Request

-   `u8DataSize` is the length, in bytes, of the included data block \(this must be less than or equal to the maximum data block length for the client, specified in the Image Block Request\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

