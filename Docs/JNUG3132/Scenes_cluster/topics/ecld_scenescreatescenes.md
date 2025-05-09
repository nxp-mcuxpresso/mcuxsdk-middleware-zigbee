# eCLD\_ScenesCreateScenes

```
teZCL_Status eCLD_ScenesCreateScenes(
    tsZCL_ClusterInstance *psClusterInstance,
    bool_t bIsServer,
    tsZCL_ClusterDefinition *psClusterDefinition,
    void *pvEndPointSharedStructPtr,
    uint8 *pu8AttributeControlBits,
    tsCLD_ScenesCustomDataStructure
    *psCustomDataStructure,
tsZCL_EndPointDefinition *psEndPointDefinition);

```

## Description 

This function creates an instance of the Scenes cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function should be called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\). This function creates a Scenes cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions.

**Note:** Do not call this function for an endpoint on which a standard ZigBee device is used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function.

When used, this function must be the first Scenes cluster function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

On calling this function for the first time, a ‘global scene’ entry is created/reserved in the Scene table. On subsequent calls \(for example, following a power-cycle or on waking from sleep\), if the scene data is recovered by the application from non-volatile memory before the function is called then there is no reinitialization of the scene data. Note that removing all groups from the device also removes the global scene entry \(along with other scene entries\) from the Scene table.

The function requires an array to be declared for internal use, which contains one element \(of type **uint8\)** for each attribute of the cluster. The array length should therefore equate to the total number of attributes supported by the Scene cluster.

The function initializes the array elements to zero.

## Parameters 

-   *psClusterInstance*: Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initializing individual structure fields.
-   *bIsServer*: Type of cluster instance \(server or client\) to be created:
    -   TRUE - server
    -   FALSE - client
-   *psClusterDefinition*: Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the Scenes cluster. This parameter can refer to a pre-filled structure called `sCLD_Scenes` which is provided in the **Scenes.h** file.
-   *pvEndPointSharedStructPtr*: Pointer to the shared structure used for attribute storage. This parameter should be the address of the structure of type `tsCLD_Scenes` which defines the attributes of Scenes cluster. The function initializes the attributes with default values.
-   *pu8AttributeControlBits*: Pointer to an array of **uint8** values, with one element for each attribute in the cluster \(see above\).
-   *psCustomDataStructure*: Pointer to a structure containing the storage for internal functions of the cluster \(see [Section 13.7.1](custom_data_structure.md#id_bc2ef262-264c-4860-824c-710da652bb26)\)
-   *psEndPointDefinition*: Pointer to the ZCL endpoint definition structure for the application \(see [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\)

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[Functions](../../Scenes_cluster/topics/functions.md)

