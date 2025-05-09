# eSE\_DRLCFindLoadControlEvent

```
teSE_DRLCStatus eSE_DRLCFindLoadControlEvent(
uint8 u8SourceEndPointId,
uint32 u32IssuerId,
bool_t bIsServer,
tsSE_DRLCLoadControlEvent **ppsLoadControlEvent,
teSE_DRLCEventList *peEventList);

```

## Description 

This function can be used to obtain the specified LCE from the local LCE lists.

The required LCE must be specified in terms of its identifier issued by the utility company. The function will search all the local LCE lists, identify the list \(if any\) in which the LCE was found and return the found LCE.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint from which the LCE is to be retrieved \(endpoint corresponding to the DRLC cluster\)
-   *u32IssuerId*: Identifier of the LCE to be found \(as issued by the utility company\)
-   *bIsServer*: Cluster server or client:
    -   TRUE - server
    -   FALSE - client
-   *ppsLoadControlEvent*Pointer to a pointer to a `tsSE_DRLCLoadControlEvent` structure to receive the obtained LCE \(see [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1)\)
-   *peEventList*: Pointer to variable to receive enumerated value of the list in which the LCE was found \(see [Section 41.10.7](lce_list_enumerations.md#id_0c1344e3-386f-4c7d-8a39-80c52b077f6b)\)

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

