# eZCL\_OverrideClusterControlFlags

```
    teZCL_Status eZCL_OverrideClusterControlFlags(
    uint8 u8SrcEndpoint,
    uint16 u16ClusterId,
    bool bIsServerClusterInstance,
    uint8 u8ClusterControlFlags);

```

## Description 

This function can be used to over-ride the control flag setting for the specified cluster \(it can be used for any cluster\). If required, this function can be called immediately after the relevant endpoint registration function \(for example, for a Light Sensor device, **eHA\_RegisterLightSensorEndPoint\(\)**\) or at any subsequent point in the application.

In particular, this function can be used by the application to change the default security level for a cluster.

## Parameters

-   *u8SourceEndPointId*: Number of the local endpoint on which the control flag is to be over-ridden
-   *u16ClusterId*: Identifier of the cluster to have control flag over-ridden \(see the macros section in the cluster header file\):
-   *bIsServerClusterInstance*:  Type of cluster instance:
    -   TRUE: Cluster server
    -   FALSE: Cluster client
-   *u8ClusterControlFlags*:  Value to be written to control flag, one of:
    -   E\_ZCL\_SECURITY\_NETWORK
    -   E\_ZCL\_SECURITY\_APPLINK

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

