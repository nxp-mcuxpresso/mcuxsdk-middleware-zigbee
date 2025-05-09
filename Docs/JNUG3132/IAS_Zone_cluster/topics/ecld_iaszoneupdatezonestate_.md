# eCLD\_IASZoneUpdateZoneState

```
teZCL_Status eCLD_IASZoneUpdateZoneState(
    uint8 u8SourceEndPoint,
    teCLD_IASZoneState eZoneState);
```

## Description 

This function can be used on an IAS Zone cluster server to update the zone state value stored in the `e8ZoneState` attribute, described in [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1). This attribute indicates whether or not the server is enrolled with a client on a CIE device. The function checks that the specified state is valid.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS Zone cluster resides
-   *eZoneState*: Zone state value to be written to the attribute, one of:
    -   E\_CLD\_IASZONE\_STATE\_NOT\_ENROLLED \(0x00\)
    -   E\_CLD\_IASZONE\_STATE\_ENROLLED \(0x01\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

