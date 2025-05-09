# eCLD\_PollControlSetAttribute

```
teZCL_Status eCLD_PollControlSetAttribute(
    uint8 u8SourceEndPointId,
    uint8 u8AttributeId,
    uint32 u32AttributeValue);*

```

## Description 

This function can be used on a cluster server to write to an attribute of the Poll Control cluster. The function writes to the relevant field of the `tsCLD_PollControl`structure \(detailed in [Section 20.2](cluster_structure_and_attributes.md#id_0088cff5-1178-477d-9e66-701a47ef6f9c)\). The attribute to be accessed is specified using its attribute identifier - enumerations are provided \(see [Section 20.8.1](attribute_id_enumerations.md#id_2520f676-ad17-4135-9754-a2cddc92f405)\).

Therefore, this function can be used to change the configuration of the Poll Control cluster. The change takes effect immediately. So, for example, if the End Device is in normal poll mode when the ‘long poll interval’ is modified, the polling period is immediately re-timed to the new value. If the modified attribute is not related to the currently operating poll mode, the change is implemented the next time the relevant poll mode is started.

The specified value of the attribute is validated by the function. If this value is out-of-range for the attribute, the status `E_ZCL_ERR_INVALID_VALUE` is returned.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster resides
-   *u8AttributeId* : Identifier of attribute to be written to \(see [Section 20.8.1](attribute_id_enumerations.md#id_2520f676-ad17-4135-9754-a2cddc92f405)\)
-   *u32AttributeValue*: Value to be written to attribute

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS

**Parent topic:**[Server Functions](../../poll_control_cluster/topics/server_functions.md)

