# eCLD\_ZllCommissionCreateCommission

```
teZCL_Status eCLD_ZllCommissionCreateCommission(
    tsZCL_ClusterInstance *psClusterInstance,
    bool_t bIsServer,
    tsZCL_ClusterDefinition *psClusterDefinition,
    void *pvSharedStructPtr,
    tsZCL_AttributeStatus *psAttributeStatus,
    tsCLD_ZllCommissionCustomDataStructure
*psCustomDataStructure);

```

## Description 

This function creates a Touchlink Commissioning cluster instance for Touchlink on the endpoint of the calling application. The type of cluster instance \(server or client\) to be created must be specified.

In practice, this function does not need to be called explicitly by the application, as the function **eZLL\_RegisterCommissionEndPoint\(\)** calls this function to create the cluster instance.

## Parameters 

-   *psClusterInstance*        Pointer to cluster instance structure on local endpoint
-   *bIsServer*        Type of cluster instance \(server or client\) to be created:
-   TRUE - server
-   FALSE - client
-   *psClusterDefinition*        Pointer to cluster definition structure containing information about the cluster
-   *pvSharedStructPtr*        Pointer to structure containing the shared storage for the cluster
-   *psAttributeStatus*        Pointer to a structure containing the storage for each attribute's status
-   *psCustomDataStructure*        Pointer to custom data to be provided to the cluster \(see [Section 44.8.3](tscld_zllcommissioncustomdatastructure.md#id_e0106865-5ba5-4428-9e8d-0b142aa016a3)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

