# tsZLL\_CommissionEndpointClusterInstances

This structure holds information about the Touchlink Commissioning cluster instance on an endpoint.

```
typedef struct PACK
{
#if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_SERVER)
    tsZCL_ClusterInstance sZllCommissionServer;
#endif
#if (defined CLD_ZLL_COMMISSION) && (defined ZLL_COMMISSION_CLIENT)
    tsZCL_ClusterInstance sZllCommissionClient;
#endif
} tsZLL_CommissionEndpointClusterInstances;

```

where:

-   `s``ZllCommissionServer` is a ZCL structure containing information about the Touchlink Commissioning cluster server instance \(refer to [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\).

-   `s``ZllCommissionClient` is a ZCL structure containing information about the Touchlink Commissioning cluster client instance \(refer to [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\).


**Parent topic:**[Structures](../../touchlink_cluster/topics/structures.md)

