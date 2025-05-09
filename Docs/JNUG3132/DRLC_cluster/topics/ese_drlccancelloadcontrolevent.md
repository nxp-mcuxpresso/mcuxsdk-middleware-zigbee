# eSE\_DRLCCancelLoadControlEvent

```
teSE_DRLCStatus eSE_DRLCCancelLoadControlEvent(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address psDestinationAddress,
    tsSE_DRLCCancelLoadControlEvent
    *psCancelLoadControlEvent,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on the DRLC cluster server to cancel an LCE. The LCE is cancelled locally and the cancellation is also sent to the specified DRLC cluster client endpoints. The LCE is ultimately moved to the ‘Deallocated’ list.

The cancellation request should normally be sent to client endpoints that have been previously bound to the cluster server. This is done by specifying an address type of E\_ZCL\_AM\_BOUND in the `tsZCL_Address` structure - in this case, the address field of this structure and the destination endpoint in the function call are both ignored.

The LCE cancellation requirements are specified in the structure `tsSE_DRLCCancelLoadControlEvent`, including the applicable device class\(es\) and enrolment group\(s\), as well as an immediate or randomized end \(for a full description of the end-time options, refer to [Section 41.5.3](cancelling_lces.md#id_6109a002-620c-4d6b-82fe-d7316ac1d9e6)\).

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent. Note that this parameter is ignored when sending to address types E\_ZCL\_AM\_BOUND and E\_ZCL\_AM\_GROUP
-   *psDestinationAddress*: Pointer to a ZCL structure containing the address of the remote node to which the request is sent
-   *psCancelLoadControlEvent*: Pointer to a structure which contains the LCE cancellation requirements \(see [Section 41.11.3](tsse_drlccancelloadcontrolevent.md#id_6964c905-bd16-4f56-a1e3-bbeb4fb213c5)\)
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

