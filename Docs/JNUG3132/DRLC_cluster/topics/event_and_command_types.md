# Event and Command Types

The `eEventType` field of the `tsSE_DRLCCallBackMessage` structure above specifies the type of DRLC event that has been generated - these event types are enumerated in the `teSE_DRLCCallBackEventType` structure, described below.

**Note:** The `u8CommandId` field of the `tsSE_DRLCCallBackMessage` structure is only required for a DRLC event of type E\_SE\_DRLC\_EVENT\_COMMAND \(see below\).

```
typedef enum PACK
{
   E_SE_DRLC_EVENT_API =0x00,
   E_SE_DRLC_EVENT_COMMAND,
   E_SE_DRLC_EVENT_ACTIVE,
   E_SE_DRLC_EVENT_EXPIRED,
   E_SE_DRLC_EVENT_CANCELLED,
   E_SE_DRLC_EVENT_ENUM_END,
} teSE_DRLCCallBackEventType;

```

## E\_SE\_DRLC\_EVENT\_API 

The E\_SE\_DRLC\_EVENT\_API event is reserved for internal use.

## E\_SE\_DRLC\_EVENT\_COMMAND 

The E\_SE\_DRLC\_EVENT\_COMMAND event is generated when a command has been received on either the server or client. In the `tsSE_DRLCCallBackMessage` structure, the `u8CommandId` field is used to indicate the corresponding command - one of:

|**Command**|**Description**|
|-----------|---------------|
|SE\_DRLC\_LOAD\_CONTROL\_EVENT|Generated on a client when a new LCE has been received from the server and added to the ‘Scheduled’ \(or ‘Active’\) list - the LCE is included in the

 `uMessage.LoadControlEvent` field of the `tsSE_DRLCCallBackMessage` structure

|
|SE\_DRLC\_LOAD\_CONTROL\_EVENT\_CANCEL \*|Generated on a client when a command has been received to cancel an LCE and the LCE has been moved to the ‘Cancelled’ or ‘ Deallocated’ list - which list depends on whether an immediate or randomized end-time is specified in the

 `uMessage.sCancelLoadControlEvent` field of the `tsSE_DRLCCallBackMessage` structure

|
|SE\_DRLC\_LOAD\_CONTROL\_EVENT\_CANCEL\_ALL \*|Generated on a client when a command has been received to cancel all LCEs and the LCEs have been moved to the ‘Cancelled’ or ‘ Deallocated’ list - which list depends on whether an immediate or randomized end-time is specified in the

 `uMessage.sCancelLoadControlAllEvent` field of the `tsSE_DRLCCallBackMessage` structure

|
|SE\_DRLC\_REPORT\_EVENT\_STATUS \*\*|Generated on the server when a Report Event Status message is received from a client - the contents of the report are included in the `uMessage.sReportEvent` field of the `tsSE_DRLCCallBackMessage` structure|
|SE\_DRLC\_GET\_SCHEDULED\_EVENTS \*\*|Generated on the server when a Get Scheduled Events message is received from a client - the contents of the request are included in the

 `uMessage.sGetScheduledEvents` field of the `tsSE_DRLCCallBackMessage` structure

|

\* If an LCE cancellation with a randomized end-time is required, the LCE is first moved to the ‘Cancelled’ list and the event is generated with randomized end-time specified. When the randomized end-time has been reached, the LCE is moved to the ‘Deallocated’ list and the event is generated again but with an immediate end-time specified. The application must then stop the corresponding load control.

\*\* The server can identify which client has sent a Report Event Status or Get Scheduled Events message by examining the `pZPSevent` field of the `tsZCL_CallBackEvent` structure that contains the message.

## E\_SE\_DRLC\_EVENT\_ACTIVE 

The E\_SE\_DRLC\_EVENT\_ACTIVE event is generated when an LCE has been moved from the ‘Scheduled’ list to the ‘Active’ list \(see [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11)\). The activated LCE is included in the `uMessage.LoadControlEvent` field of the `tsSE_DRLCCallBackMessage` structure.

## E\_SE\_DRLC\_EVENT\_EXPIRED 

The E\_SE\_DRLC\_EVENT\_EXPIRED event is generated when an LCE has been moved from the ‘Active’ list \(see [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11)\). The expired LCE is included in the `uMessage.LoadControlEvent` field of the `tsSE_DRLCCallBackMessage` structure.

## E\_SE\_DRLC\_EVENT\_CANCELLED 

The E\_SE\_DRLC\_EVENT\_CANCELLED event is generated when an LCE has been put in the ‘Cancelled’ list \(see [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11)\) as the result of an LCE ‘cancel’ or ‘cancel all’ command. Information on the cancelled LCE\(s\) is included in the `uMessage.sCancelLoadControlEvent` or `uMessage.sCancelLoadControlAllEvent` field of the `tsSE_DRLCCallBackMessage` structure, as appropriate.

**Parent topic:**[DRLC Events](../../DRLC_cluster/topics/drlc_events.md)

