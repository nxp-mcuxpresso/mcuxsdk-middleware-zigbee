# OTA Upgrade Cluster structure and attributes

The attributes of the OTA Upgrade cluster are contained in the following structure, which is located only on cluster clients:

```
typedef struct
{
#ifdef OTA_CLIENT    
    uint64 u64UgradeServerID;
    uint32 u32FileOffset;
    uint32 u32CurrentFileVersion;
    uint16 u16CurrentStackVersion;
    uint32 u32DownloadedFileVersion;
    uint16 u16DownloadedStackVersion;
    uint8  u8ImageUpgradeStatus;
    uint16 u16ManfId;
    uint16 u16ImageType;
    uint16 u16MinBlockRequestDelay;
#endif    
    uint16 u16ClusterRevision;
} tsCLD_AS_Ota;

```

where:

-   `u64UgradeServerID` contains the 64-bit IEEE/MAC address of the OTA Upgrade server for the client. This address can be fixed during manufacture or discovered during network formation/operation. If not pre-set, the default value is 0xFFFFFFFFFFFFFFFF. This attribute is mandatory.

-   `u32FileOffset` contains the start address in local Flash memory of the upgrade image \(that may be currently in transfer from server to client\). This attribute is optional.

-   `u32CurrentFileVersion` contains the file version of the firmware currently running on the client. This attribute is optional.

-   `u16CurrentStackVersion` contains the version of the ZigBee stack currently running on the client. This attribute is optional.

-   `u32DownloadedFileVersion` contains the file version of the downloaded upgrade image on the client. This attribute is optional.

-   `u16DownloadedStackVersion` contains the version of the ZigBee stack for which the downloaded upgrade image was built. This attribute is optional.

-   `u8ImageUpgradeStatus` contains the status of the client device in relation to image downloads and upgrades. This attribute is mandatory and the possible values are shown in the table below.


|**u8ImageUpgradeStatus**|**Status**|**Notes**|
|------------------------|----------|---------|
|0x00|Normal|Has not participated in a download/upgrade or the previous download/upgrade was unsuccessful|
|0x01|Download in progress|Client is requesting and successfully receiving blocks of image data from server|
|0x02|Download complete|All image data received and image saved to memory|
|0x03|Waiting to upgrade|Waiting for instruction from server to upgrade from the saved image|
|0x04|Count down|Server instructs the Client to count down to start of upgrade|
|0x05|Wait for more|Client is waiting for further upgrade image\(s\) from server - relevant to multi-processor devices, where each processor requires a different image|
|0x06 - 0xFF|Reserved|-|

-   `u16ManfId` contains the device’s manufacturer code, assigned by the ZigBee Alliance. This attribute is optional.

-   `u16ImageType` contains an image type identifier for the upgrade image that is currently being downloaded to the client or waiting on the client for the upgrade process to begin. When neither of these cases apply, the attribute is set to 0xFFFF. This attribute is optional.

-   `u16MinBlockRequestDelay` is the minimum time, in seconds, that the local client must wait between submitting consecutive block requests to the server during an image download. It is used by the ‘rate limiting’ feature to control the average download rate to the client. The attribute can take values in the range 0 to OTA\_BLOCK\_REQUEST\_DELAY\_MAX\_VALUE seconds, where this upper limit can be defined in the **zcl\_options.h** file \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\) - if undefined, its default value is 5 seconds. The value 0x0000 \(default\) indicates that the download can be performed at the full rate with no minimum delay between block requests. This attribute is optional.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


Thus, the OTA Upgrade cluster structure contains only two mandatory elements, `u64UgradeServerID` and `u8ImageUpgradeStatus`. The remaining elements are optional, each being enabled/disabled through a corresponding macro defined in the **zcl\_options.h** file \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\).

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

