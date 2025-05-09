# eSE\_DRLCGetScheduledEventsSend

```
teSE_DRLCStatus eSE_DRLCGetScheduledEventsSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address psDestinationAddress,
    tsSE_DRLCGetScheduledEvents *psGetScheduledEvents,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on a DRLC cluster client to send a Get Scheduled Events message to the cluster server in order to request a list of scheduled \(and active\) LCEs. The function can be used to obtain the initial schedule of LCEs and to update the local LCE lists during operation \(for example, if an End Device has been sleeping and has missed unsolicited LCE updates\) - refer to [Section 41.5.2.2](getting_scheduled_events.md#id_f2887a5e-7cc6-46e8-bb28-92b73262e8a0) for more information on the use of this function.

As part of this function call, a `tsSE_DRLCGetScheduledEvents` structure must be provided which specifies the earliest start-time of the LCEs of interest and the maximum number of LCEs to be reported.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the request is sent \(this must be the DRLC cluster server endpoint\)
-   *psDestinationAddress*: Pointer to a ZCL structure containing the address of the remote node to which the request is sent \(this must be the address of the ESP\)
-   *psGetScheduledEvents*: Pointer to a structure which contains the LCE requirements of the request \(see [Section 41.11.2](tsse_drlcgetscheduledevents.md#id_d289e426-5f42-4e70-b88e-1eb09b5e24d0)\)
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

