# eCLD\_IASACESetZoneParameterValue

```
teZCL_Status eCLD_IASACESetZoneParameterValue(
    uint8 u8SourceEndPointId,
    teCLD_IASACE_ZoneParameterID eParameterId,
    uint8 u8ZoneID,
    uint16 u16ParameterValue);

```

## Description 

This function can be used on an IAS ACE cluster server to set the value of a Zone parameter. The Zone parameters for a particular Zone ID are held on the server in a `tsCLD_IASACE_ZoneParameter` structure \(see [Section 38.7.3](zone_parameters.md#id_555011fc-2e63-4ba8-8f3a-98f719b35b31)\) and this function can be used to write a value to one of the non-string/non-array parameters in the structure. The specified zone must have been enrolled in the local Zone table. Before attempting the write, the function verifies that the specified Zone ID is present in the Zone table and that the specified parameter identifier is valid.

If this function is used to set the Zone parameter `eZoneStatus`, an IAS ACE Zone Status Changed command is automatically sent to all bound clients.

This function cannot be used to set the string parameters `sZoneLabel` and `sArmDisarmCode` or the array parameters `au8ZoneLabel[]` and `au8ArmDisarmCode[]`. The function **eCLD\_IASACESetZoneParameter\(\)** must be used to set the string and array parameters.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS ACE cluster resides
-   *eParameterId* : Enumeration identifying the Zone parameter to be set, one of:
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_CONFIG\_FLAG
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS\_FLAG
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_ZONE\_STATUS
    -   E\_CLD\_IASACE\_ZONE\_PARAMETER\_AUDIBLE\_NOTIFICATION
-   *u8ZoneID*: Zone ID of zone information to be updated
-   *u16ParameterValue*: Value to be written to the parameter

## Returns 

-   E\_ZCL\_SUCCESS \(Zone parameter successfully set\)
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND \(cluster instance not found\)
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND \(Zone parameter identifier invalid\)
-   E\_ZCL\_ERR\_NO\_REPORT\_ENTRIES \(Zone ID not found in Zone table\)

**Parent topic:**[Functions](../../IAS_ACE_cluster/topics/functions.md)

