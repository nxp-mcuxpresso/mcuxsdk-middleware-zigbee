# eCLD\_ZllUtilityCommandHandler

```
teZCL_Status eCLD_ZllUtilityCommandHandler(
    ZPS_tsAfEvent *pZPSevent,
    tsZCL_EndPointDefinition *psEndPointDefinition,
    tsZCL_ClusterInstance *psClusterInstance);

```

## Description 

This function parses a ZigBee PRO event and invokes the user-defined callback function that has been registered for the device \(using the relevant endpoint registration function\).

The registered user-defined callback function must be designed to handle events associated with the Commissioning Utility.

## Parameters 

-   *pZPSevent*        Pointer to received ZigBee PRO event
-   *psEndPointDefinition*        Pointer to structure which defines endpoint on which the Commissioning Utility resides
-   *psClusterInstance*        Pointer to Touchlink Commissioning cluster instance structure

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

