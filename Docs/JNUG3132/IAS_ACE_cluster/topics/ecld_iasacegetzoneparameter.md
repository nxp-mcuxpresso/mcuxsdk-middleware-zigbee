# eCLD\_IASACEGetZoneParameter

```
teZCL_Status eCLD_IASACEGetZoneParameter(
    uint8 u8SourceEndPointId,
    teCLD_IASACE_ZoneParameterID eParameterId,
    uint8 u8ZoneID,
    uint8 *pu8ParameterLength,
    uint8 *pu8ParameterValue);

```

## Description

This function can be used on an IAS ACE cluster server to obtain the value of a Zone parameter. The Zone parameters for a particular Zone ID are held on the server in a `tsCLD_IASACE_ZoneParameter` structure \(see [Section 38.7.3](zone_parameters.md#id_555011fc-2e63-4ba8-8f3a-98f719b35b31)\) and this function can be used to read the value of one parameter in the structure. Before attempting the read, the function verifies that the specified Zone ID is present in the Zone table and that the specified parameter identifier is valid.

The function expects the read parameter value to be returned as a **uint8** array.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *eParameterId*: Enumeration identifying the Zone parameter to be read, one of:
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_CONFIG\_FLAG
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS\_FLAG
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_AUDIBLE\_NOTIFICATION
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_LABEL
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ARM\_DISARM\_CODE
-   *u8ZoneID*: Zone ID of zone information to be accessed
-   **pu8ParameterLength*: Pointer to location to receive the number of *uint8* elements in the array containing the parameter value obtained
-    **pu8ParameterValue*: Pointer to location to receive the first element of the array containing the parameter value obtained

## Returns 

-   E\_ZCL\_SUCCESS \(Zone parameter successfully read\)
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND \(cluster instance not found\)
-   E\_ZCL\_ERR\_PARAMETER\_NULL \(a specified pointer is NULL\)
-   E\_ZCL\_ERR\_NO\_REPORT\_ENTRIES \(Zone ID not found in Zone table\)
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND \(Zone parameter identifier invalid\)
-   E\_ZCL\_ERR\_PARAMETER\_RANGE \(returned array too long to be stored\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

