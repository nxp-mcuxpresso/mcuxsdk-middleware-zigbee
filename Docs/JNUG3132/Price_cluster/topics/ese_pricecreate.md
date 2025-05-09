# eSE\_PriceCreate

```
teSE_PriceStatus eSE_PriceCreate(
        bool_t bIsServer,
        uint8 u8NumberOfRecordEntries,
        uint8 *pu8AttributeControlBits,
        uint8 *pau8RateLabel,
        tsZCL_ClusterInstance *psClusterInstance,
        tsZCL_ClusterDefinition *psClusterDefinition,
        tsSE_PriceCustomDataStructure
        *psCustomDataStructure,
        tsSE_PricePublishPriceRecord
        *psPublishPriceRecord,
        void *pvEndPointSharedStructPtr);

```

## Description 

This function creates an instance of the Price cluster on an endpoint. The cluster instance is created on the endpoint which is associated with the supplied `tsZCL_ClusterInstance` structure and can act as a server or a client, as specified.

The function should only be called when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\). This function will create a Price cluster instance on the endpoint, but instances of other clusters may also be created on the same endpoint by calling their corresponding creation functions. For more details of creating cluster instances on custom endpoints, refer to [Appendix D.](../../appendix/topics/custom_endpoints.md#id_f064c220-73a1-4c15-b83c-9218b85711c5)

**Note:** This function must not be called for an endpoint on which a standard ZigBee device \(e.g. IPD\) will be used. In this case, the device and its supported clusters must be registered on the endpoint using the relevant device registration function from those described in the *ZigBee Devices User Guide (JNUG3131)*

When used, this function must be the first Price cluster function called in the application, and must be called after the stack has been started and after the ZCL has been initialized.

The function requires an array to be declared for internal use, which contains one element \(of type **uint8**\) for each attribute of the cluster. The array length should therefore equate be the total number of attributes supported by the Price cluster, which can be obtained by using the macro PRICE\_NUM\_OF\_ATTRIBUTES.

The array declaration should be as follows:

```
uint8 au8AppPriceClusterAttributeControlBits[PRICE_NUM_OF_ATTRIBUTES];

```

The function initializes the array elements to zero.

The function also requires an array of price labels to be declared, in which each array element is a label \(string\) for each price in the price list. The required declarations are different for a cluster server and client, as follows:

```
uint8 au8RateLabel[SE_PRICE_NUMBER_OF_CLIENT_PRICE_RECORD_ENTRIES][SE_PRICE_CLIENT_MAX_STRING_LENGTH];
uint8 au8RateLabel[SE_PRICE_NUMBER_OF_CLIENT_PRICE_RECORD_ENTRIES][SE_PRICE_CLIENT_MAX_STRING_LENGTH];

```

## Parameters 

-   *bIsServer* Type of cluster instance \(server or client\) to be created:
-   TRUE - server
-   FALSE - client
-   *u8NumberOfRecordEntries* Number of prices that can be stored in the price list, one of:
-   SE\_PRICE\_NUMBER\_OF\_SERVER\_PRICE\_RECORD\_ENTRIES
-   SE\_PRICE\_NUMBER\_OF\_CLIENT\_PRICE\_RECORD\_ENTRIES
-   *pu8AttributeControlBits* Pointer to an array of **uint8** values, with one element for each attribute in the cluster \(see above\).
-   *pau8RateLabel* Pointer to an array of price labels \(strings\), with one element for each price in the price list \(see above\).
-   *psClusterInstance* Pointer to structure containing information about the cluster instance to be created \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\). This structure is updated by the function by initialising individual structure fields.
-   *psClusterDefinition* Pointer to structure indicating the type of cluster to be created \(see [Section 6.1.2](../../ZCL_structures/topics/tszcl_clusterdefinition.md#id_463410b1-fa22-42d5-821c-70353eeb5dc5)\). In this case, this structure must contain the details of the Price cluster. This parameter can refer to a pre-filled structure called `sCLD_Price` which is provided in the **Price.h** file.
-   *psCustomDataStructure* Pointer to structure which contains custom data for the Price cluster. This structure is used for internal data storage. No knowledge of the fields of this structure is required
-   *pvEndPointSharedStructPtr* Pointer to the shared structure used for attribute storage. This parameter should be the address of the structure of type `tsCLD_Price` which defines the attributes of Price cluster. The function initializes the attributes with default values.

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

