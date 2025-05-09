# eCLD\_IASACEGetPanelParameter

```
teZCL_Status eCLD_IASACEGetPanelParameter(
    uint8 u8SourceEndPointId,
    teCLD_IASACE_PanelParameterID eParameterId,
    uint8 *pu8ParameterValue);

```

## Description 

This function can be used on an IAS ACE cluster server to obtain the value of a Panel parameter. The Panel parameters are held on the server in a `tsCLD_IASACE_PanelParameter` structure \(see [Section 38.7.4](panel_parameters.md#id_404b2665-5072-489a-a49d-24efc8eca54a)\) and this function can be used to read the value of one parameter in the structure. The function verifies that the specified parameter identifier is valid before attempting the read.

## Parameters

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *eParameterId* : Enumeration identifying the Panel parameter to be read, one of:
-   E\_CLD\_IASACE\_PANEL\_PARAMETER\_PANEL\_STATUS
-   E\_CLD\_IASACE\_PANEL\_PARAMETER\_SECONDS\_REMAINING
-   E\_CLD\_IASACE\_PANEL\_PARAMETER\_AUDIBLE\_NOTIFICATION
-   E\_CLD\_IASACE\_PANEL\_PARAMETER\_ALARM\_STATUS
-   *pu8ParameterValue*: Pointer to location to receive read parameter value

## Returns 

-   E\_ZCL\_SUCCESS \(Panel parameter successfully read\)
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND \(cluster instance not found\)
-   E\_ZCL\_ERR\_PARAMETER\_NULL \(specfied pointer is NULL\)
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND \(Panel parameter identifier invalid\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

