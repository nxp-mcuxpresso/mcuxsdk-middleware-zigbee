# eCLD\_IASZoneUpdateZoneStatus

```
teZCL_Status eCLD_IASZoneUpdateZoneStatus(
    uint8 u8SourceEndPoint,
    uint16 u16StatusBitMask,
    bool_t bStatusState);
```

## Description 

This function can be used on an IAS Zone cluster server to update the zone status bitmap stored in the `b16ZoneStatus` attribute, described in [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1).

In one call to this function, one or more selected bits in the `b16ZoneStatus` attribute bitmap can be to set to ‘1’ or ‘0’. The affected bits must themselves be specified in a bitmap and the value to be set must also be specified.

If the server is enrolled with a client on a CIE device, the function sends a notification of this update to the client, in a Zone Status Change Notification. Before sending the notification and returning, the function invokes a user-defined callback function to allow the application to validate the status change.

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the IAS Zone cluster resides
-   *u16StatusBitMask*: 16-bit bitmap indicating the bits of the `zb16ZoneStatus` bitmap to be updated. There is a one-to-one correspondence between the bits of the two bitmaps and a bit should be set to ‘1’ if the corresponding attribute bit is to be updated. Enumerations are provided \(which can be logical-ORed\):

|**Bits**|**Enumeration**|
|--------|---------------|
|0|CLD\_IASZONE\_STATUS\_MASK\_ALARM1|
|1|CLD\_IASZONE\_STATUS\_MASK\_ALARM2|
|2|CLD\_IASZONE\_STATUS\_MASK\_TAMPER|
|3|CLD\_IASZONE\_STATUS\_MASK\_BATTERY|
|4|CLD\_IASZONE\_STATUS\_MASK\_SUPERVISION\_REPORTS|
|5|CLD\_IASZONE\_STATUS\_MASK\_RESTORE\_REPORTS|
|6|CLD\_IASZONE\_STATUS\_MASK\_TROUBLE|
|7|CLD\_IASZONE\_STATUS\_MASK\_AC\_MAINS|
|8|CLD\_IASZONE\_STATUS\_MASK\_TEST|
|9|CLD\_IASZONE\_STATUS\_MASK\_BATTERY\_DEFECT|
|10-15|Reserved|

-   *bStatusState*: Boolean indicating the value to which the attribute bits to be updated must be set - enumerations are provided:
    -   `CLD_IASZONE_STATUS_MASK_SET (1)`
    -   `CLD_IASZONE_STATUS_MASK_RESET (0)`

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../IAS_Zone_cluster/topics/functions.md)

