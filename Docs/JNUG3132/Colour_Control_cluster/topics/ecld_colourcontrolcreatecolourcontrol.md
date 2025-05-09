# eCLD\_ColourControlCreateColourControl

```
teZCL_Status eCLD_ColourControlCreateColourControl(
    tsZCL_ClusterInstance *psClusterInstance,
    bool_t bIsServer,
    tsZCL_ClusterDefinition *psClusterDefinition,
    void *pvEndPointSharedStructPtr,
    uint8 *pu8AttributeControlBits,
    tsCLD_ColourControlCustomDataStructure
    *psCustomDataStructure);
```

## Description 

This function creates an instance of the Colour Control cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function should only be called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\). This function creates a Colour Control cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions.

**Note:** This function must not be called for an endpoint on which a standard ZigBee device is used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function.

When used, this function must be the first Colour Control cluster function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

The function requires an array to be declared for internal use, which contains one element \(of type **uint8**\) for each attribute of the cluster. The array length should therefore equate to the total number of attributes supported by the Colour Control cluster. The function initializes the array elements to zero.

## Parameters 

-   *psClusterInstance*: Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initializing individual structure fields.
-   *bIsServer* : Type of cluster instance \(server or client\) to be created:
-   TRUE - server
-   FALSE - client
-   *psClusterDefinition*: Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the Colour Control cluster. This parameter can refer to a pre-filled structure called `sCLD_ColourControl` which is provided in the **ColourControl.h** file.
-   *pvEndPointSharedStructPtr*: Pointer to the shared structure used for attribute storage. This parameter should be the address of the structure of type `tsCLD_ColourControl` which defines the attributes of Colour Control cluster. The function initializes the attributes with default values.
-   *pu8AttributeControlBits*: Pointer to an array of **uint8** values, with one element for each attribute in the cluster \(see above\).
-   *psCustomDataStructure*: Pointer to a structure containing the storage for internal functions of the cluster \(see [Section 31.7.1](custom_data_structure.md#id_773ee8b6-e416-43c4-9f84-9fcbb4190476)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Colour_Control_cluster/topics/functions.md)

