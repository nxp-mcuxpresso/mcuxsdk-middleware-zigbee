# eCLD\_IASZoneUpdateZoneID

```
teZCL_Status eCLD_IASZoneUpdateZoneID(
    uint8 u8SourceEndPoint,
    uint8 u8IASZoneId);

```

## Description 

This function can be used on an IAS Zone cluster server to update the zone ID value stored in the `u8ZoneId` attribute. This is an 8-bit user-defined identifier.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS Zone cluster resides
-   *u8IASZoneId*: Zone ID value to be written to the attribute

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

