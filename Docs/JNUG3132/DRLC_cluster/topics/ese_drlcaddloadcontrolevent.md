# eSE\_DRLCAddLoadControlEvent

```
teSE_DRLCStatus eSE_DRLCAddLoadControlEvent(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address psDestinationAddress,
    tsSE_DRLCLoadControlEvent *psLoadControlEvent,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on the DRLC cluster server to add an LCE \(received from the utility company\) to the ‘Scheduled’ list. The function also sends the LCE to the specified DRLC cluster client endpoints, where it will also be added to the ‘Scheduled’ list. Note that the LCE will be added to the ‘Active’ lists on the relevant devices if a ‘start-time of now’ is specified in the LCE.

The LCE should normally be sent to client endpoints that have been previously bound to the cluster server. This is done by specifying an address type of E\_ZCL\_AM\_BOUND in the `tsZCL_Address` structure - in this case, the address field of this structure and the destination endpoint in the function call are both ignored.

## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which the LCE is sent
-   *u8DestinationEndPointId*: Number of the remote endpoint to which the LCE is sent. Note that this parameter is ignored when sending to address types E\_ZCL\_AM\_BOUND and E\_ZCL\_AM\_GROUP
-   *psDestinationAddress*: Pointer to a ZCL structure containing the address of the remote node to which the LCE is sent
-   *psLoadControlEvent*: Pointer to a structure \(see [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1)\) which contains the LCE to be added and sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the packet sent

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

