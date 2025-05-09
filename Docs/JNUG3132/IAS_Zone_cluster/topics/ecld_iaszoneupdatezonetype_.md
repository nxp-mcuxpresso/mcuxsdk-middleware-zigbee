# eCLD\_IASZoneUpdateZoneType

```
teZCL_Status eCLD_IASZoneUpdateZoneType(
    uint8 u8SourceEndPoint,
    teCLD_IASZoneType eIASZoneType);

```

## Description 

This function can be used on an IAS Zone cluster server to update the zone type value stored in the `e16ZoneType` attribute. The possible values are listed in [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1) and the function checks that the specified type is one of these values.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS Zone cluster resides *eIASZoneType*: Zone type value to be written to the attribute \(for the possible values, refer to [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

