# eCLD\_PPCreatePowerProfile

```
teZCL_Status eCLD_PPCreatePowerProfile(
        tsZCL_ClusterInstance *psClusterInstance,
        bool_t bIsServer,
        tsZCL_ClusterDefinition *psClusterDefinition,
        void *pvEndPointSharedStructPtr,
        uint8 *pu8AttributeControlBits,
        tsCLD_PPCustomDataStructure *psCustomDataStructure);

```

## Description 

This function creates an instance of the Power Profile cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function should only be called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard Zigbee device\). This function creates a Power Profile cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions. For more details of creating cluster instances on custom endpoints, refer to [Appendix D.](../../appendix/topics/custom_endpoints.md#id_f064c220-73a1-4c15-b83c-9218b85711c5)

**Note:** This function must not be called for an endpoint on which a standard Zigbee device is used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function from those described in the *Zigbee Devices User Guide \(JNUG3131\)*.

When used, this function must be the first Power Profile cluster function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

The function requires an array to be declared for internal use, which contains one element \(of type **uint8**\) for each attribute of the cluster. The array length is automatically adjusted by the compiler using the following declaration:

```
uint8 au8PPAttributeControlBits[(sizeof(asCLD_PPClusterAttrDefs)/ 
        sizeof(tsZCL_AttributeDefinition))];
int8 au8PPAttributeControlBits[(sizeof(asCLD_PPClusterAttrDefs)/ 
        sizeof(tsZCL_AttributeDefinition))];

```

## Parameters 

-   *psClusterInstance*: Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initializing individual structure fields.
-   *bIsServer*: Type of cluster instance \(server or client\) to be created:
-   TRUE - server
-   FALSE - client
-   *psClusterDefinition*: Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the Power Profile cluster. This parameter can refer to a pre-filled structure called `sCLD_PP` which is provided in the **PowerProfile.h** file.
-   *pvEndPointSharedStructPtr*: Pointer to the shared structure used for attribute storage. This parameter should be the address of the structure of type `tsCLD_PP`, which defines the attributes of the Power Profile cluster. The function initializes the attributes with default values.
-   *pu8AttributeControlBits*: Pointer to an array of **uint8** values, with one element for each attribute in the cluster \(see above\). For a cluster client, set this pointer to NULL.
-   *psCustomDataStructure*: Pointer to a structure containing the storage for internal functions of the cluster \(see [Section 21.10.14](tscld_ppcustomdatastructure.md#id_54acf6a2-5580-4608-bc3d-db40149110fb)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Server/Client Function](../../power_profile_cluster/topics/serverclient_function.md)

