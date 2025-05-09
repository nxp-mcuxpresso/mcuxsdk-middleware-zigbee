# eCLD\_IASACECreateIASACE

```
teZCL_Status eCLD_IASACECreateIASACE(
tsZCL_ClusterInstance *psClusterInstance,
bool_t bIsServer,
tsZCL_ClusterDefinition *psClusterDefinition,
void *pvEndPointSharedStructPtr,
tsCLD_IASACECustomDataStructure
*psCustomDataStructure);
```

## Description 

This function creates an instance of the IAS ACE cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function should only be called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\). This function will create an IAS ACE cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions.

**Note:** This function must not be called for an endpoint on which a standard ZigBee device is used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function.

When used, this function must be called after the stack has been started and after the ZCL has been initialized.

## Parameters 

-   *psClusterInstance*: Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initializing individual structure fields.
-   *bIsServer*: Type of cluster instance \(server or client\) to be created: *TRUE - server*, *FALSE - client*
-   *psClusterDefinition*: Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the IAS ACE cluster.
-   *pvEndPointSharedStructPtr*: Set this pointer to NULL for this cluster
-   *psCustomDataStructure*: Pointer to a structure containing the storage for internal functions of the cluster \(see [Section 38.7.1](custom_data_structure.md#id_b9b20aaa-bbfc-4c0b-ab63-3b2cea893f06)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

