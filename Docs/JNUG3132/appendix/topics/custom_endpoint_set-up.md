# Appendix D.3: Custom Endpoint Set-up

In order to set up a custom endpoint \(supporting selected clusters\), you must do the following in your application code:

1. Create a structure for the custom endpoint containing details of the cluster instances and attributes supported - see [Custom Endpoint Structure](#id_e81a091a-f0a1-4cb6-ad76-8864bc68c2ac) below.

2. Initialise the fields of the `tsZCL_EndPointDefinition` structure for the endpoint.

3. Call the relevant cluster creation function\(s\) for the cluster\(s\) to be supported on the endpoint - see [Appendix D.2](cluster_creation_functions.md#id_ad8265eb-82d5-4584-9c02-04528cc6573f).

4. Call the ZCL function **eZCL\_Register\(\)** for the endpoint.

## Custom Endpoint Structure 

In your application code, to set up a custom endpoint you must create a structure containing details of the cluster instances and attributes to be supported on the endpoint. This structure must include the following:

-   A definition of the custom endpoint through a `tsZCL_EndPointDefinition` structure - for example:

    -           `tsZCL_EndPointDefinition sEndPoint`
-   A structure containing a set of `tsZCL_ClusterInstance` structures for the supported cluster instances - for example:


```
typedef struct
{
    tsZCL_ClusterInstance sBasicServer;
    tsZCL_ClusterInstance sBasicClient;
    tsZCL_ClusterInstance sIdentifyServer;
    tsZCL_ClusterInstance sOnOffCluster;
    tsZCL_ClusterInstance sDoorLockCluster;
} tsHA_AppCustomDeviceClusterInstances

```

-   For each cluster instance that is not shared with another endpoint, the following should be specified via the relevant `tsZCL_ClusterInstance` structure:
-   Attribute definitions, if any - for example, the `tsCLD_Basic` structure for the Basic cluster
-                   Custom data structures, if any - for example, the `tsIdentify_CustomStruct` structure for the Identify cluster
-           Memory for tables or any other resources, if required by the cluster creation function

**Note:** If a custom endpoint is to co-exist with a device endpoint, the endpoints can share the structures for the clusters that they have in common. Therefore, it is not necessary to define these cluster structures for the custom endpoint, since they already exist for the device endpoint.

**Parent topic:**[Appendix D: Custom endpoints](../../appendix/topics/custom_endpoints.md)

