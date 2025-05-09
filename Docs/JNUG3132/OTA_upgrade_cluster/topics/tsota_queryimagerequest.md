# tsOTA\_QueryImageRequest

The following structure contains payload data for a Query Next Image Request issued by a client to poll the server for an upgrade image or to respond to an Image Notify message from the server:

```
typedef struct
{
    uint32 u32CurrentFileVersion;
    uint16 u16HardwareVersion;
    uint16 u16ImageType;
    uint16 u16ManufacturerCode;
    uint8  u8FieldControl;
}tsOTA_QueryImageRequest;

```

where:

-   `u32CurrentFileVersion` is the file version of the application image that is currently running on the client that sent the request

-   `u16HardwareVersion` is the hardware version of the client device \(this information is optional - see `u8FieldControl` below\)

-   `u16ImageType` is a value in the range 0x0000-0xFFBF which identifies the type of image currently running on the client

-   `u16ManufacturerCode` is the ZigBee-assigned number identifying the manufacturer of the client device

-   `u8FieldControl` is a bitmap indicating whether certain optional information about the client is included in this Query Next Image Request message. Currently, this optional information consists only of the hardware version \(contained in `u16HardwareVersion` above\) - bit 0 is set to ‘1’ if the hardware version is included or to ‘0’ otherwise \(all other bits are reserved\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

