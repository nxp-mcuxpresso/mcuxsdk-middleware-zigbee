# tsZCL\_ClusterInstance

This structure contains information about an instance of a cluster on a device:

```
struct tsZCL_ClusterInstance
{
    bool_t                      bIsServer;
    tsZCL_ClusterDefinition    *psClusterDefinition;
    void                       *pvEndPointSharedStructPtr;
    uint8                      *pu8AttributeControlBits;
    void                       *pvEndPointCustomStructPtr;
    tfpZCL_ZCLCustomcallCallBackFunction
                                pCustomcallCallBackFunction;
};

```

where:

-   `bIsServer` indicates whether the cluster instance is a server or client:

    -   TRUE - server

    -   FALSE - client

-   `psClusterDefinition` is a pointer to the cluster definition structure - see [Section 6.1.2](tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)

-   `pvEndPointSharedStructPtr` is a pointer to the shared device structure that contains the cluster’s attributes

-   `pu8AttributeControlBits` is a pointer to an array of bitmaps, one for each attribute in the relevant cluster - for internal cluster definition use only, array should be initialized to 0

-   `pvEndPointCustomStructPtr` is a pointer to any custom data \(only relevant to a user-defined cluster\)

-   `pCustomcallCallBackFunction` is a pointer to a custom callback function \(only relevant to a user-defined cluster\)


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

