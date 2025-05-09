# tsOTA\_BlockRequest

The following structure contains payload data for an Image Block Request issued by a client to request an image data block from the server:

```
typedef struct
{
    uint64 u64RequestNodeAddress;
    uint32 u32FileOffset;
    uint32 u32FileVersion;
    uint16 u16ImageType;
    uint16 u16ManufactureCode;
    uint16 u16BlockRequestDelay;
    uint8 u8MaxDataSize;
    uint8 u8FieldControl;
}tsOTA_BlockRequest;

```

where:

-   `u64RequestNodeAddress` is the IEEE/MAC address of the client device from which the request originates \(this information is optional - see `u8FieldControl` below\)

-   `u32FileOffset` specifies the offset from the beginning of the upgrade image, in bytes, of the requested data block \(this value is therefore determined by the amount of image data previously received\)

-   `u32FileVersion` is the file version of the upgrade image for which a data block is being requested

-   `u16ImageType` is a value in the range 0x0000-0xFFBF which identifies the type of image for which a data block is being requested

-   `u16ManufactureCode` is the ZigBee-assigned number identifying the manufacturer of the client device from which the request originates

-   `u16BlockRequestDelay` is used in ‘rate limiting’ to specify the value of the ‘block request delay’ attribute for the client - this is minimum time, in milliseconds, that the client must wait between consecutive block requests \(the client will update the local attribute with this value\). If the server does not support rate limiting or does not need to limit the download rate to the client, this field will be set to 0

-   `u8MaxDataSize` specifies the maximum size, in bytes, of the data block that the client can receive in one transfer \(the server must therefore not send a data block that is larger than indicated by this value\)

-   `u8FieldControl` is a bitmap indicating whether certain optional information about the client is included in this Image Block Request message. Currently, this optional information consists only of the IEEE/MAC address of the client \(contained in `64RequestNodeAddress` above\) - bit 0 is set to ‘1’ if this address is included or to ‘0’ otherwise \(all other bits are reserved\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

