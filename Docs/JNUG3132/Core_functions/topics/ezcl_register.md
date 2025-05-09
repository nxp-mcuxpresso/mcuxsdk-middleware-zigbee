# eZCL\_Register

```
teZCL_Status eZCL_Register(
     tsZCL_EndPointDefinition *psEndPointDefinition);

```

## Description 

This function is used to register an endpoint with the ZCL. The function validates the clusters and corresponding attributes supported by the endpoint, and registers the endpoint.

The function should only be called to register a custom endpoint \(which does not contain one of the standard ZigBee device types\). It should be called for each custom endpoint on the local node. The function is not required when using a standard ZigBee device \(for example, On/Off Switch\) on an endpoint - in this case, the appropriate device registration function should be used.

## Parameters 

-   *psEndPointDefinition*: Pointer to `tsZCL_EndPointDefinition` structure for the endpoint to be registered \(see [Section 'tsZCL_EndPointDefinition'](../../ZCL_structures/topics/tszcl_endpointdefinition.md) 

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_PARAMETER\_RANGE
-   E\_ZCL\_ERR\_HEAP\_FAIL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_SECURITY\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_0
-   E\_ZCL\_ERR\_CLUSTER\_NULL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTES\_NULL
-   E\_ZCL\_ERR\_ATTRIBUTE\_TYPE\_UNSUPPORTED,
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND,
-   E\_ZCL\_ERR\_CALLBACK\_NULL

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

