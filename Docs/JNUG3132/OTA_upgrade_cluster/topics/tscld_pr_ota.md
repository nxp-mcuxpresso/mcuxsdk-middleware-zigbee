# tsCLD\_PR\_Ota

The following structure contains server parameter data that can be pre-set using the function **eOTA\_SetServerParams\(\)** and obtained using **eOTA\_GetServerData\(\)**:

```
typedef struct
{
    uint8* pu8Data;
    uint32 u32CurrentTime;
    uint32 u32RequestOrUpgradeTime;
    uint8  u8QueryJitter;
    uint8  u8DataSize;
} tsCLD_PR_Ota;

```

where:

-   `pu8Data` is a pointer to the start of a block of data

-   `u32CurrentTime` is the current UTC time, in seconds, on the server. If UTC time is not supported by the server, this value should be set to zero

-   `u32RequestOrUpgradeTime` is used by the server as the ‘request time’ and the ‘upgrade time’ when sending responses to clients:

    -   As a ‘request time’, the value may be included in an Image Block Response \(see [Section 49.11.10](tsota_imageblockresponsepayload.md#id_51ded850-0671-42aa-aeef-4ee5317fba37) and [Section 49.11.15](tsota_waitfordata.md#id_d698b23b-cb16-4ed2-80a0-e56aa8c1061a)\)

    -   As an ‘upgrade time’, the value will be included in an Upgrade End Response \(see [Section 49.11.12](tsota_upgradeendresponsepayload.md#id_cdb28372-e8be-4682-af73-94e5114f985e)\)

-   `u8QueryJitter`is a value between 1 and 100 \(inclusive\) which is used by a receiving client to decide whether to reply to an Image Notify message - for information on ‘[Query Jitter](implementing_ota_upgrade_mechanism_.md#id_bf54ba54-0ee3-40b4-a922-40a306cef54c)’, refer to [Section 49.7](implementing_ota_upgrade_mechanism_.md#id_dd5d3237-7c2e-4a47-ad47-9815f483cd62)

-   `u8DataSize` is the length, in bytes, of the data block pointed to by `pu8Data`


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

