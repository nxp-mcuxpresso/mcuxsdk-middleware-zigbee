# tsOTA\_BlockResponseEvent

The following structure contains payload data for an Image Block Response containing data other than upgrade image data.

```
typedef struct
{
    uint8    u8Status;
    uint8   *pu8Data;
    uint8    u8DataSize;
}tsOTA_BlockResponseEvent;

```

where:

-   `u8Status` indicates whether a suitable upgrade image is available:

    -   OTA\_STATUS\_SUCCESS: A suitable image is available

    -   OTA\_STATUS\_NO\_IMAGE\_AVAILABLE: No suitable image is available

-   `pu8Data` is a pointer to the start of the data block being transferred

-   `u8DataSize` is the length, in bytes, of the included data block \(this must be less than or equal to the maximum data block length for the client, specified in the Image Block Request\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

