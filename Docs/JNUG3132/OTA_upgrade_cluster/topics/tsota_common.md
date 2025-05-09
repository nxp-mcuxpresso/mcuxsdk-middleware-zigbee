# tsOTA\_Common

The following structure contains data relating to an OTA message received by the cluster \(server or client\) - this data is used for callback functions and the local OTA state machine:

```
typedef struct
{
    tsZCL_ReceiveEventAddress  sReceiveEventAddress;
    tsZCL_CallBackEvent        sOTACustomCallBackEvent;
    tsOTA_CallBackMessage      sOTACallBackMessage;
} tsOTA_Common;

```

The fields are for internal use and no knowledge of them is required. The `tsOTA_CallBackMessage` structure is described in [Section 49.11.21](tsota_callbackmessage.md#id_312a27a2-f182-4f8b-a4e0-93a3d75ce9b5).

**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

