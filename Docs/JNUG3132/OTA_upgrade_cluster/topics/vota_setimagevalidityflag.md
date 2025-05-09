# vOTA\_SetImageValidityFlag

```
void vOTA_SetImageValidityFlag(
    uint8 u8Location,
    tsOTA_Common *psCustomData,
    bool bSet,
    tsZCL_EndPointDefinition *psEndPointDefinition);

```

## Description 

This function can be used to set an image validity flag once a downloaded upgrade image has been received and verified by the client.

## Parameters 

-   *u8Location*: Number of sector where image starts in Flash memory
-   *psCustomData*: Pointer to custom data for image \(see [Section 49.11.2](tsota_common.md#id_ac62aed1-0c00-401a-90bd-023da953e84e)\)
-   *bSet*: Flag state to be set:
-   TRUE - Reset
-   FALSE - No reset
-   *psEndPointDefinition*: Pointer to endpoint definition \(see [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\)

## Returns 

-   None

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

