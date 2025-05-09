# tsZLL\_CommissionEndpoint

This structure is used to hold endpoint information for a Touchlink application.

```
typedef struct
{
tsZCL_EndPointDefinition sEndPoint;
tsZLL_CommissionEndpointClusterInstances sClusterInstance;
#if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
    tsCLD_ZllCommission sZllCommissionServerCluster;
    tsCLD_ZllCommissionCustomDataStructure      
                sZllCommissionServerCustomDataStructure;
#endif
#if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_CLIENT)
    tsCLD_ZllCommission sZllCommissionClientCluster;
    tsCLD_ZllCommissionCustomDataStructure      
               sZllCommissionClientCustomDataStructure;
#endif
} tsZLL_CommissionEndpoint;

```

where:

-   `sEndPoint` is a ZCL structure containing information about the endpoint \(refer to [Section 6.1.1](../../ZCL_structures/topics/tszcl_endpointdefinition.md#id_7b9b9c13-fc48-4cf5-b3f4-69aacd27ac38)\).

-   `sClusterInstance` is a structure containing information about the Touchlink Commissioning cluster instance on the endpoint \(see [Section 44.8.2](tszll_commissionendpointclusterinstances.md#id_729880ec-c501-41df-9fbb-b874935daf14)\).

-   For a Touchlink server, the following fields are used:

    -   `sZllCommissionServerCluster` is the Touchlink Commissioning cluster structure \(which contains no attributes\).

    -   `sZllCommissionServerCustomDataStructure` is a structure containing custom data for the cluster server \(see [Section 44.8.3](tscld_zllcommissioncustomdatastructure.md#id_e0106865-5ba5-4428-9e8d-0b142aa016a3)\).

-   For a Touchlink client, the following fields are used:

    -   `sZllCommissionClientCluster`is the Touchlink Commissioning cluster structure \(which contains no attributes\).

    -   `sZllCommissionClientCustomDataStructure` is a structure containing custom data for the cluster client \(see [Section 44.8.3](tscld_zllcommissioncustomdatastructure.md#id_e0106865-5ba5-4428-9e8d-0b142aa016a3)\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

