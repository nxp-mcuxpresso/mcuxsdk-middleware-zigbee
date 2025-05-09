# eOTA\_Create

```
teZCL_Status eOTA_Create(
    tsZCL_ClusterInstance *psClusterInstance,
    bool_t bIsServer,
    tsZCL_ClusterDefinition *psClusterDefinition,
    void *pvEndPointSharedStructPtr,
    uint8 u8Endpoint,
    uint8 *pu8AttributeControlBits,
    tsOTA_Common *psCustomDataStruct);

```

## Description 

This function creates an instance of the OTA Upgrade cluster on the specified endpoint. The cluster instance can act as a server or a client, as specified. The shared structure of the device associated with cluster must also be specified.

The function must be the first OTA function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

## Parameters 

-   *psClusterInstance*: Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\)
-   *bIsServer*: Side of cluster to be implemented on this device:
    -   TRUE - Server
    -   FALSE - Client
-   *psClusterDefinition*: Pointer to structure indicating the type of cluster \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\) - this structure must contain the details of the OTA Upgrade cluster
-   *pvEndPointSharedStructPtr*: Pointer to shared device structure for relevant endpoint \(depends on device type, e.g. Door Lock\)
-   *u8Endpoint*: Number of endpoint with which cluster will be associated
-   *pu8AttributeControlBits*: Pointer to an array of bitmaps, one for each attribute in the relevant cluster - for internal cluster definition use only, array should be initialised to 0
-   *tpsCustomDataStruct*: Pointer to structure containing custom data for OTA Upgrade cluster \(see [Section 49.11.2](tsota_common.md#id_ac62aed1-0c00-401a-90bd-023da953e84e)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[General Functions](../../OTA_upgrade_cluster/topics/general_functions.md)

