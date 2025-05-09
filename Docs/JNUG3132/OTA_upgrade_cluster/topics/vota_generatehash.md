# vOTA\_GenerateHash

```
void vOTA_GenerateHash(
    tsZCL_EndPointDefinition *psEndPointDefinition,
    tsOTA_Common *psCustomData,
    bool bIsServer,
    bool bHeaderPresent,
    AESSW_Block_u *puHash,
    uint8 u8ImageLocation);

```

## Description 

This function can be used to generate a hash checksum for an application image in Flash memory, using the Matyas-Meyer-Oseas cryptographic hash.

## Parameters 

-   *psEndPointDefinition*        Pointer to structure which defines endpoint corresponding to the application \(see [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\)
-   *psCustomData*        Pointer to data structure connected with event associated with the checksum \(see [Section 49.11.2](tsota_common.md#id_ac62aed1-0c00-401a-90bd-023da953e84e)\)
-   *bIsServer*        Side of cluster implemented on this device:
-                                   TRUE - Server
-                   FALSE - Client
-   *bHeaderPresent*        Presence of image header:
-                                   TRUE - Present
-                   FALSE - Absent
-   *puHash*        Pointer                 to structure to receive calculated hash checksum
-   *u8ImageLocation*        Number of sector where image starts in Flash memory

## Returns

-   None

**Parent topic:**[General Functions](../../OTA_upgrade_cluster/topics/general_functions.md)

