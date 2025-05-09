# eCLD\_DiagnosticsUpdate

```
teZCL_Status eCLD_DiagnosticsUpdate(
    uint8 u8SourceEndPointId);

```

## Description 

This function updates the \(three\) Stack/Network Information attributes \(see [Section](diagnostics_structure_and_attributes.md#id_5b200dd1-8849-4e3d-8900-703b924bb425)22.2\). It should be called periodically by the application \(on the cluster server\) at the highest rate possible or when an appropriate stack event occurs.

The attributes can otherwise be accessed \(for example, read\) using the Attribute Access functions detailed in [Section 5.2](../../Core_functions/topics/attribute_access_functions.md#id_4affd45c-30c4-4380-b0e4-54535096b0ee).

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint on which cluster server resides

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Functions](../../Diagnostics_cluster/topics/functions.md)

