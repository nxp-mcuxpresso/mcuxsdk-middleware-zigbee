# eCLD\_CommissioningSetAttribute

```
teZCL_Status eCLD_CommissioningSetAttribute(
    uint8 u8SourceEndPointId,
    teCLD_Commissioning_AttributeSet eAttributeSet,
    void *vptrAttributeSetStructure);

```

## Description {
This function can be used on a Commissioning cluster server to write values to a particular attribute set of the Commissioning cluster.

## Parameters 

-   *u8SourceEndPointId*        Number of the local endpoint through which to issue the request.
-   *eAttributeSet*        Enumeration indicating attribute set to write to, one of:
-   E\_CLD\_COMMISSIONING\_ATTR\_SET\_STARTUP\_PARAMS
-   E\_CLD\_COMMISSIONING\_ATTR\_SET\_JOIN\_PARAMS
-   E\_CLD\_COMMISSIONING\_ATTR\_SET\_ENDDEVICE\_PARAMS
-   E\_CLD\_COMMISSIONING\_ATTR\_SET\_CONCENTRATOR\_PARAMS
-   *vptrAttributeSetStructure*        Pointer to a structure containing the new values for the attribute set - the relevant structures are detailed in [Section 43.2](commissioning_cluster_structure_and_attributes.md#id_d7d1eb5e-31d3-44cf-ab40-60afe26e471e)

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Functions](../../Commissioning_cluster/topics/functions.md)

