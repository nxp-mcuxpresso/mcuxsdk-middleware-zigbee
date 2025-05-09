# eCLD\_ZllUtilityCreateUtility

```
teZCL_Status eCLD_ZllUtilityCreateUtility(
        tsZCL_ClusterInstance *psClusterInstance,
        bool_t bIsServer,
        tsZCL_ClusterDefinition *psClusterDefinition,
        void *pvSharedStructPtr,
        tsZCL_AttributeStatus psAttributeStatus,
        tsCLD_ZllUtilityCustomDataStructure
    *psCustomDataStructure);

```

## Description 

This function creates a Touchlink Commissioning cluster instance for the Commissioning Utility. The cluster instance is created on the endpoint of the calling application, which should be the main application on the node. The type of cluster instance \(server or client\) to be created must be specified.

## Parameters 

-   *psClusterInstance* Pointer to cluster instance structure on local endpoint
-   *bIsServer* Type of cluster instance \(server or client\) to be created:
-   TRUE - server
-   FALSE - client
-   *psClusterDefinition* Pointer to cluster definition structure containing information about the cluster
-   *pvSharedStructPtr* Pointer to structure containing the shared storage for the cluster
-   *psAttributeStatus* Pointer to a structure containing the storage for each attribute's status
-   *psCustomDataStructure* Pointer to custom data to be provided to the cluster \(see [Section 44.8.20](tscld_zllutility_endpointinformationcommandpayload.md#id_6f261fcd-1151-4138-9efb-328ec99b1269)\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

