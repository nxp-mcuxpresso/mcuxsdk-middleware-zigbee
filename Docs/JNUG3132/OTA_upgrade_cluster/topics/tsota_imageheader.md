# tsOTA\_ImageHeader

The following structure contains information for the OTA header:

```
typedef struct
{
            uint32 u32FileIdentifier;
    uint16 u16HeaderVersion;
    uint16 u16HeaderLength;
    uint16 u16HeaderControlField;
    uint16 u16ManufacturerCode;
    uint16 u16ImageType;
    uint32 u32FileVersion;
    uint16 u16StackVersion;
    uint8  stHeaderString[OTA_HEADER_STRING_SIZE];
            uint32 u32TotalImage;
    uint8  u8SecurityCredVersion;
    uint64 u64UpgradeFileDest;
    uint16 u16MinimumHwVersion;
    uint16 u16MaxHwVersion;
}tsOTA_ImageHeader;

```

where:

-   `u32FileIdentifier` is a 4-byte value equal to 0x0BEEF11E which indicates that the file contains an OTA upgrade image

-   `u16HeaderVersion` is the version of the OTA header expressed as a 2-byte value in which the most significant byte contains the major version number and the least significant byte contains the minor version number

-   `u16HeaderLength` is the full length of the OTA header, in bytes

-   `u16HeaderControlField` is a bitmap indicating certain information about the file, as detailed in table below.


|**Bit**|**Information**|
|-------|---------------|
|0|Security credential version \(in OTA header\):

 1: Field present in header

 0: Field not present in header

|
|1|Device-specific file \(also see `u64UpgradeFileDest`\):

 1: File is device-specific

 0: File is not device-specific

|
|2|Maximum and minimum hardware version \(in OTA header\):

 1: Field present in header

 0: Field not present in header

|
|3-15|Reserved|

-   `u16ManufacturerCode` is the ZigBee-assigned manufacturer code \(0xFFFF is a wildcard value, representing any manufacturer\)

-   `u16ImageType` is a unique value representing the image type, where this value is normally manufacturer-specific but certain values have been reserved for specific file types, as indicated below \(the wildcard value of 0xFFFF represents any file type\):


|**Value**|**File Type**|
|---------|-------------|
|0x0000 – 0xFFBF|Manufacturer-specific|
|0xFFC0|Security credential|
|0xFFC1|Configuration|
|0xFFC2|Log|
|0xFFC3 – 0xFFFE|Reserved|
|0xFFFF|Wildcard|

-   `u32FileVersion` contains the release and build numbers of the application and stack used to produce the application image - for details of the file version format, refer to         the *ZigBee Over-the-Air Upgrading Cluster Specification \(095264\)*

-   `u16StackVersion` contains ZigBee stack version that is used by the application \(this is 0x0002 for ZigBee PRO\)

-   `stHeaderString[]` is a manufacturer-specific string that can be used to store any useful human-readable information

-   `u32TotalImage` is the total size, in bytes, of the image that will be transferred over-the air \(including the OTA header and any optional data\)

-   `u8SecurityCredVersion` indicates the security credential version type that is required by the client in order to install the image - the possibilities are SE1.0 \(0x0\), SE1.1 \(0x1\) and SE2.0 \(0x2\)

-   `u64UpgradeFileDest` contains the IEEE/MAC address of the destination device for the file, in the case when the file is device-specific \(as indicated by bit 1 of `u16HeaderControlField`\)

-   `u16MinimumHwVersion` indicates the earliest hardware platform on which the image should be used, expressed as a 2-byte value in which the most significant byte contains the hardware version number and the least significant byte contains the revision number

-   `u16MaxHwVersion` indicates the latest hardware platform on which the image should be used, expressed as a 2-byte value in which the most significant byte contains the hardware version number and the least significant byte contains the revision number


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

