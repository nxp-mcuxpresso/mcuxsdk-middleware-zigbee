# tsOTA\_WaitForDataParams

The following structure is used in the `tsOTA_CallBackMessage` structure \(see [Section 49.11.21](tsota_callbackmessage.md#id_312a27a2-f182-4f8b-a4e0-93a3d75ce9b5)\) on an OTA Upgrade server. It contains the data needed to notify a client that rate limiting is required or the client must wait to receive an upgrade image.

```
typedef struct
{
   bool_t             bInitialized;
   uint16             u16ClientAddress;
   tsOTA_WaitForData  sWaitForDataPyld;
}tsOTA_WaitForDataParams;

```

where:

-   `bInitialized` is a boolean flag indicating the server’s request to the client:

    -   TRUE - Implement rate limiting or wait to receive upgrade image
    -           FALSE - Otherwise
-   `u16ClientAddress` contains the 16-bit network address of the client

-   `sWaitForDataPyld` is a structure containing the payload for an Image Block Response with status OTA\_STATUS\_WAIT\_FOR\_DATA \(see [Section](tsota_waitfordata.md#id_d698b23b-cb16-4ed2-80a0-e56aa8c1061a)49.11.15\)


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

