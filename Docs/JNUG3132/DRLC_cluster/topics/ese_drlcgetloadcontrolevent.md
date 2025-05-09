# eSE\_DRLCGetLoadControlEvent

```
teSE_DRLCStatus eDRLCGetLoadControlEvent(
    uint8 u8SourceEndPointId,
    uint8 u8TableIndex,
    teSE_DRLCEventList eEventList,
    tsSE_DRLCLoadControlEvent **ppsLoadControlEvent);

```

## Description 

This function can be used to obtain an LCE from a local LCE list.

The required list must be specified as one of ‘Scheduled’, ‘Active’, ‘Cancelled’ and ‘Deallocated’. The index of the required LCE in the list must also be specified. The index of zero is used to indicate that the LCE with the oldest start-time should be retrieved. To retrieve all the LCEs in a list, repeatedly call this function with index zero until the function indicates that there are no further LCEs in the list \(returns E\_SE\_DRLC\_EVENT\_NOT\_FOUND\).

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint from which the LCE is to be retrieved \(endpoint corresponding to the DRLC cluster\)
-   *u8TableIndex*: Index of required LCE in the specified LCE list \(see below\)
-   *eEventList*: LCE list from which the LCE is to be retrieved, one of:
    -   E\_SE\_DRLC\_EVENT\_LIST\_SCHEDULED
    -   E\_SE\_DRLC\_EVENT\_LIST\_ACTIVE
    -   E\_SE\_DRLC\_EVENT\_LIST\_CANCELLED
    -   E\_SE\_DRLC\_EVENT\_LIST\_DEALLOCATED
-   *ppsLoadControlEvent*Pointer to a pointer to a `tsSE_DRLCLoadControlEvent` structure to receive the obtained LCE \(see [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1)\)

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

