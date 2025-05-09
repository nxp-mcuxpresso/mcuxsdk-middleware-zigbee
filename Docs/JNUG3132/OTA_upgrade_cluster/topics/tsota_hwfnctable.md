# tsOTA\_HwFncTable

The following structure contains pointers to callback functions to be used by the OTA Upgrade cluster to perform initialization, erase, write and read operations on Flash memory \(if these functions are not specified, standard NXP functions will be used\):

```
typedef struct
{
     void (*prInitHwCb)(uint8, void*);
     void (*prEraseCb) (uint8 u8Sector);
     void (*prWriteCb) (uint32 u32FlashByteLocation,
                        uint16 u16Len,
                        uint8 *pu8Data);
     void (*prReadCb)  (uint32 u32FlashByteLocation,
                        uint16 u16Len,
                        uint8 *pu8Data);
} tsOTA_HwFncTable;

```

where:

-   `prInitHwCb` is a pointer to a callback function that is called after a cold or warm start to perform any initialization required for the Flash memory device

-   `prEraseCb` is a pointer to a callback function that is called to erase a specified sector of Flash memory

-   `prWriteCb` is a pointer to a callback function that is called to write a block of data to a sector, starting the write at a specified byte location in the sector \(address zero is the start of the sector\)

-   `prReadCb` is a pointer to a callback function that is called to read a block of data from a sector, starting the read at a specified byte location in the sector \(address zero is the start of the sector\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

