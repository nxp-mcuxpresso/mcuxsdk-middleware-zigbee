# tsOTA\_QuerySpecificFileRequestPayload

The following structure contains the payload for a Query Specific File Request which is issued by an OTA Upgrade client to request a device-specific file from the server.

```
typedef struct
{
    uint64 u64RequestNodeAddress;
    uint16 u16ManufacturerCode;
    uint16 u16ImageType;
    uint32 u32FileVersion;
    uint16 u16CurrentZibgeeStackVersion;
}tsOTA_QuerySpecificFileRequestPayload;

```

where:

-   `u64RequestNodeAddress` is the IEEE/MAC address of the node requesting the device-specific file from the server

-   `u16ManufactuerCode` is the ZigBee-assigned manufacturer code of the requesting node \(0xFFFF is used to indicate any manufacturer\)

-   `u16ImageType` indicates the requested file type - one of the reserved values that are assigned to the device-specific file types \(the value should be in the range 0xFFC0 to 0xFFFE, but only 0xFFC0 to 0xFFC2 are currently in use\)

-   `32FileVersion` contains the release and build numbers of the application and stack that correspond to the device-specific file - for details of the format, refer to the *ZigBee Over-the-Air Upgrading Cluster Specification \(095264\)*

-   `u16CurrentZ``ig``beeStackVersion` contains the version of ZigBee stack that is currently running on the client


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

