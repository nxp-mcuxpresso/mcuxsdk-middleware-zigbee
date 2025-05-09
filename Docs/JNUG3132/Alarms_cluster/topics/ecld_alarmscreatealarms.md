# eCLD\_AlarmsCreateAlarms

```
teZCL_Status eCLD_AlarmsCreateAlarms(
        tsZCL_ClusterInstance *psClusterInstance, 
        bool_t bIsServer,
        tsZCL_ClusterDefinition *psClusterDefinition,
        void *pvEndPointSharedStructPtr,
        uint8 *pu8AttributeControlBits,
        tsCLD_AlarmsCustomDataStructure
    *psCustomDataStructure);

```

## Description 

This function creates an instance of the Alarms cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function is only called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\). This function creates an Alarms cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions.

**Note:** This function is not called for an endpoint on which a standard ZigBee device is used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function.

When used, this function must be the first Alarms cluster function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

## Parameters 

-   *psClusterInstance*:Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initializing individual structure fields.
-   *bIsServer*: Type of cluster instance \(server or client\) to be created:
    -   TRUE - server

    -   FALSE - client

-   *psClusterDefinition*: Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the Alarms cluster. This parameter can refer to a pre-filled structure called `sCLD_``Alarms` which is provided in the **Alarms.h** file.
-   *pvEndPointSharedStructPtr*: Pointer to the shared structure used for attribute storage. This parameter should be the address of the structure of type `tsCLD_Alarms` which defines the attributes of Alarms cluster. The function initializes the attributes with default values.
-   *pu8AttributeControlBits*: Pointer to an array of **uint8** values, with one element for each attribute in the cluster \(see above\)
-   *psCustomDataStructure*: Pointer to a structure containing the storage for internal functions of the cluster \(see [Section 17.7.2](custom_data_structure.md#id_97f15da2-76ce-4b3d-b62f-a74a73045b84)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[Functions](../../Alarms_cluster/topics/functions.md)

