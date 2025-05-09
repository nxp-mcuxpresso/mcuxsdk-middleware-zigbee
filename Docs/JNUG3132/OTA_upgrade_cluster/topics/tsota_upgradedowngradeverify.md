# tsOTA\_UpgradeDowngradeVerify

The following structure contains the data for an event of the type E\_CLD\_OTA\_INTERNAL\_COMMAND\_SWITCH\_TO\_UPGRADE\_DOWNGRADE.

```
typedef struct
{
    uint32 u32DownloadImageVersion;
    uint32 u32CurrentImageVersion;
    teZCL_Status eUpgradeDowngradeStatus;
}tsOTA_UpgradeDowngradeVerify;

```

where:

-           `u32DownloadImageVersion` is the version received in upgrade end response

-                   `u32CurrentImageVersion` is the version of running image

-           `eImageVersionVerifyStatus` is a status field which should be updated to E\_ZCL\_SUCCESS or E\_ZCL\_FAIL by the application after checking the received image version, to indicate whether the upgrade image has a valid image version


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

