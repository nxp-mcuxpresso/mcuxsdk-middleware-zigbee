# vZCL\_SetDefaultReporting

```
void vZCL_SetDefaultReporting(
    tsZCL_ClusterInstance *psClusterInstance);

```

## Description 

This function can be used on a cluster server to enable ‘default reporting’ for those attributes that are reportable. It should be called immediately after the cluster instance has been created.

The function checks which attributes are potentially reportable - that is, which attributes have the ‘reportable flag’ E\_ZCL\_AF\_RP set. It then sets the ‘default reporting flag’ E\_ZCL\_ACF\_RP for these attributes.

**Note:** The flag E\_ZCL\_AF\_RP can be set for an attribute in the attribute definition or through a call to the function **eZCL\_SetReportableFlag\(\)**.

Attribute reporting is fully described in [Appendix B.](../../appendix/topics/attribute_reporting.md#id_aa644443-d8c4-48c6-aeb2-7d1c62cd5c77)

## Parameters 

-   *psClusterInstance*        Pointer to structure containing information about the cluster instance for which default reporting is to be enabled \(see [Section 6.1.16](../../ZCL_structures/topics/tszcl_clusterinstance.md#id_4962ba0f-19ed-4eab-acb5-a1111fb84478)\).

## Returns 

-   None

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

