# tsOTA\_ImagePageRequest

The following structure contains payload data for an Image Page Request issued by a client to request a page of image data \(multiple blocks\) from the server:

```
typedef struct
{
    uint64 u64RequestNodeAddress;
    uint32 u32FileOffset;
    uint32 u32FileVersion;
    uint16 u16PageSize;
    uint16 u16ResponseSpacing;
    uint16 u16ImageType;
    uint16 u16ManufactureCode;
    uint8 u8MaxDataSize;
    uint8 u8FieldControl;
}tsOTA_ImagePageRequest;

```

where:

-   `u64RequestNodeAddress` is the IEEE/MAC address of the client device from which the request originates \(this information is optional - see `u8FieldControl` below\)

-   `u32FileOffset` specifies the offset from the beginning of the upgrade image, in bytes, of the first data block of the requested page \(this value is therefore determined by the amount of image data previously received\)

-   `u32FileVersion` is the file version of the upgrade image for which data is being requested

-   `u16PageSize` is the total number of data bytes \(in the page\) to be returned by the server before the next Image Page Request can be issued \(this must be larger than the value of `u8MaxDataSize` below\)

-   `u16ResponseSpacing` specifies the time-interval, in milliseconds, that the server should introduce between consecutive transmissions of Image Block Responses \(which is sent in response to the Image Page Request\)

-   `u16ImageType` is a value in the range 0x0000-0xFFBF which identifies the type of image for which data is being requested

-   `u16ManufactureCode` is the ZigBee-assigned number identifying the manufacturer of the client device from which the request originates

-   `u8MaxDataSize` specifies the maximum size, in bytes, of the data block that the client can receive in one transfer \(the server must therefore not send a data block in an Image Block Response that is larger than indicated by this value\)

-   `u8FieldControl` is a bitmap indicating whether certain optional information about the client is included in this Image Page Request message. Currently, this optional information consists only of the IEEE/MAC address of the client \(contained in `64RequestNodeAddress` above\) - bit 0 is set to ‘1’ if this address is included or to ‘0’ otherwise \(all other bits are reserved\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

