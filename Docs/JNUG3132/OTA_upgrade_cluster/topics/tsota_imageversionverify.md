# tsOTA\_ImageVersionVerify

The following structure contains the data for an event of the type E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_IMAGE\_VERSION.

```
typedef struct
{
    uint32 u32NotifiedImageVersion;
    uint32 u32CurrentImageVersion;
    teZCL_Status eImageVersionVerifyStatus;
}tsOTA_ImageVersionVerify;

```

where:

-           `u32NotifiedImageVersion` is the version received in the query next image response

-           `u32CurrentImageVersion` is the version of the running image

-           `eImageVersionVerifyStatus` is a status field which should be updated to E\_ZCL\_SUCCESS or E\_ZCL\_FAIL by the application after checking the received image version, to indicate whether the upgrade image has a valid image version


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

