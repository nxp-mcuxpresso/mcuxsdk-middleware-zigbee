# tsNvmDefs

The following structure contains information used to configure access to Flash memory:

```
typedef struct
{
    tsOTA_HwFncTable sOtaFnTable;
    uint32           u32SectorSize;
    uint8            u8FlashDeviceType;
}tsNvmDefs;

```

where:

-   `sOtaFnTable` is a structure specifying the callback functions to be used by the cluster to perform initialization, erase, write and read operations on the Flash memory device \(see [Section 49.11.3](tsota_hwfnctable.md#id_26018f7c-44f4-481c-9899-599139b1b154)\) - if user-defined callback functions are not specified, standard NXP functions will be used

-   `u32SectorSize` is the size of a sector of the Flash memory device, in bytes

-   `u8FlashDeviceType` is a value indicating the type of Flash memory device, one of:

    -   E\_FL\_CHIP\_INTERNAL \(Device internal Flash- default\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

