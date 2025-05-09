# tsOTA\_ImageNotifyCommand

The following structure contains the payload data for an Image Notify message issued by the server when a new upgrade image is available for download:

```
typedef struct
{
            teOTA_ImageNotifyPayloadType ePayloadType;
            uint32                       u32NewFileVersion;
            uint16                       u16ImageType;
            uint16                       u16ManufacturerCode;
            uint8                        u8QueryJitter;
}tsOTA_ImageNotifyCommand;

```

where:

-   `ePayloadType` is a value indicating the type of payload of the command \(enumerations are available - see [Section 49.12.4](teota_imagenotifypayloadtype.md#id_1187821d-bc4f-44bf-b183-07dd4992b4c6)\)

-   `u32NewFileVersion` is the file version of the client upgrade image that is currently available for download \(the wild card of 0xFFFFFFFF is used to indicate that all clients should upgrade to this image\)

-   `u16ImageType` is a number indicating the type of image that is available for download \(the wild card of 0xFFFF is used to indicate that all image types are involved\)

-   `u16ManufacturerCode` is a ZigBee-assigned number identifying the manufacturer to which the available image is connected \(if all manufacturers are involved, this value should not be set\)

-   `u8QueryJitter` is a value between 1 and 100 \(inclusive\) which is used by the receiving client to decide whether to reply to this Image Notify message - for information on ‘[Query Jitter](implementing_ota_upgrade_mechanism_.md#id_bf54ba54-0ee3-40b4-a922-40a306cef54c)’, refer to [Section 49.7](implementing_ota_upgrade_mechanism_.md#id_dd5d3237-7c2e-4a47-ad47-9815f483cd62)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

