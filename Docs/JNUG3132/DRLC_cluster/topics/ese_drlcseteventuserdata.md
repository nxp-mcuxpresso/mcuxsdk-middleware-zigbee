# eSE\_DRLCSetEventUserData

```
teSE_DRLCStatus eSE_DRLCSetEventUserData(
    uint32 u32IssuerId,
    uint8 u8SourceEndPointId,
    teSE_DRLCUserEventSet eUserEventSetID,
    uint16 u16EventData);

```

## Description 

This function can be used on a DRLC cluster client to locally modify the load control data of an LCE. Any one of the following data values can be changed:

-   Criticality level

-   Cooling temperature set-point

-   Heating temperature set-point

-   Load adjustment percentage

-   Duty cycle


The function can be called multiple times to modify more than one of the above values. The data values are fully described in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1).

## Parameters 

-   *u32IssuerId*: Identifier of the LCE \(as issued by the utility company\)
-   *u8SourceEndPointId*: Number of the local endpoint where the LCE is located \(endpoint corresponding to the DRLC cluster\)
-   *eUserEventSetID*: Identifier of the load control data item to be modified, one of:
    -   E\_SE\_DRLC\_CRITICALITY\_LEVEL\_APPLIED
    -   E\_SE\_DRLC\_COOLING\_TEMPERATURE\_SET\_POINT\_APPLIED
    -   E\_SE\_DRLC\_HEATING\_TEMPERATURE\_SET\_POINT\_APPLIED
    -   E\_SE\_DRLC\_AVERAGE\_LOAD\_ADJUSTMENT\_PERCENTAGE\_APPLIED
    -   E\_SE\_DRLC\_DUTY\_CYCLE\_APPLIED
-   *u16EventData*: Value to which the specified data item is to be set \(for formats of data values, refer to descriptions in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1)\)

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

