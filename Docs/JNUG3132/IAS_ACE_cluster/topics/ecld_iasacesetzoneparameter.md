# eCLD\_IASACESetZoneParameter

```
teZCL_Status eCLD_IASACESetZoneParameter(
    uint8 u8SourceEndPointId,
    teCLD_IASACE_ZoneParameterID eParameterId,
    uint8 u8ZoneID,
    uint8 u8ParameterLength,
    uint8 *pu8ParameterValue);
 ```

## Description 

This function can be used on an IAS ACE cluster server to set the value of a Zone parameter. The Zone parameters for a particular Zone ID are held on the server in a `tsCLD_IASACE_ZoneParameter` structure \(see [Section 38.7.3](zone_parameters.md#id_555011fc-2e63-4ba8-8f3a-98f719b35b31)\) and this function can be used to write a value to one parameter in the structure. The specified zone must have been enrolled in the local Zone table. Before attempting the write, the function verifies that the specified Zone ID is present in the Zone table and that the specified parameter identifier is valid.

If this function is used to set the Zone parameter `eZoneStatus`, an IAS ACE Zone Status Changed command is automatically sent to all bound clients.

The function requires the parameter value to be provided as a **uint8** array. This is to allow one of the array parameters, `au8ZoneLabel[]` or `au8ArmDisarmCode[]`, to be set - the corresponding string parameter, `sZoneLabel` or `sArmDisarmCode`, will be set automatically. The function **eCLD\_IASACESetZoneParameterValue\(\)** provides an easier way of setting one of the non-array/non-string parameters.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *eParameterId* : Enumeration identifying the Zone parameter to be set, one of:
-   : E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_CONFIG\_FLAG
-   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS\_FLAG
-   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS
-   E\_CLD\_IASACE\_ZONE\_PARAMETER\_AUDIBLE\_NOTIFICATION
-   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_LABEL
-   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ARM\_DISARM\_CODE
-   *u8ZoneID*: Zone ID of zone information to be updated
-   *u8ParameterLength*: Number of *uint8* elements in the array containing the parameter value to be set
-   *pu8ParameterValue*: Pointer to a location containing the first element of the array containing the parameter value to be set

## Returns 

-   E\_ZCL\_SUCCESS \(Zone parameter successfully set\)
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND \(cluster instance not found\)
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND \(Zone parameter identifier invalid\)
-   E\_ZCL\_ERR\_NO\_REPORT\_ENTRIES \(Zone ID not found in Zone table\)
-   E\_ZCL\_ERR\_PARAMETER\_NULL \(Pointer to location containing value is NULL\)
-   E\_ZCL\_ERR\_PARAMETER\_RANGE \(specified array length too long to be stored\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

