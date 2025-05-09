# ‘LCE Status’ Enumerations

LCE status is enumerated in the `teSE_DRLCEventStatus` structure below:

```
typedef enum PACK
{
    E_SE_DRLC_LOAD_CONTROL_EVENT_COMMAND_RECIEVED =0x01,
    E_SE_DRLC_EVENT_STARTED,
    E_SE_DRLC_EVENT_COMPLETED,
    E_SE_DRLC_USER_CHOSEN_OPT_OUT,
    E_SE_DRLC_USER_CHOSEN_OPT_IN,
    E_SE_DRLC_EVENT_HAS_BEEN_CANCELLED,
    E_SE_DRLC_EVENT_HAS_BEEN_SUPERSEDED,
    E_SE_DRLC_EVENT_PARTIALLY_COMPLETED_WITH_USER_OPT_OUT,
    E_SE_DRLC_EVENT_PARTIALLY_COMPLETED_WITH_USER_OPT_IN,
    E_SE_DRLC_EVENT_COMPLETED_NO_USER_PARTICIPATION,
    E_SE_DRLC_REJECTED_INVALID_CANCEL_COMMAND_DEFAULT =0xF8,
    E_SE_DRLC_REJECTED_INVALID_CANCEL_COMMAND_INVALID_EFFECTIVE_TIME,
    E_SE_DRLC_REJECTED_EVENT_RECEIVED_AFTER_IT_HAD_EXPIRED =0xFB,
    E_SE_DRLC_REJECTED_INVALID_CANCEL_COMMAND_UNDEFINED_EVENT=0xFD,
    E_SE_DRLC_LOAD_CONTROL_EVENT_COMMAND_REJECTED,
    E_SE_DRLC_EVENT_STATUS_ENUM_END
} teSE_DRLCEventStatus;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_SE\_DRLC\_LOAD\_CONTROL\_EVENT\_COM-MAND\_RECEIVED|LCE command received \(to add new LCE to local lists\)|
|E\_SE\_DRLC\_EVENT\_STARTED|LCE has started|
|E\_SE\_DRLC\_EVENT\_COMPLETED|LCE has completed|
|E\_SE\_DRLC\_USER\_CHOSEN\_OPT\_OUT|Client has opted out of the LCE|
|E\_SE\_DRLC\_USER\_CHOSEN\_OPT\_IN|Client has opted into the LCE|
|E\_SE\_DRLC\_EVENT\_HAS\_BEEN\_CANCELLED|LCE has been cancelled|
|E\_SE\_DRLC\_EVENT\_HAS\_BEEN\_SUPERSEDED|LCE has been replaced with another LCE|
|E\_SE\_DRLC\_EVENT\_PARTIALLY\_COMPLETED\_WITH\_USER\_OPT\_OUT|LCE has prematurely completed due to a client opt-out during the LCE|
|E\_SE\_DRLC\_EVENT\_PARTIALLY\_COMPLETED\_WITH\_USER\_OPT\_IN|LCE has completed but was only partially executed due to a client opt-in during the LCE|
|E\_SE\_DRLC\_EVENT\_COMPLETED\_NO\_USER\_PARTICIPATION|LCE has completed but there was no client participation \(due to a client opt-out from the start\)|
|E\_SE\_DRLC\_REJECTED\_INVALID\_CANCEL\_COMMAND\_DEFAULT|Received ‘cancel command’ invalid and rejected \(default\)|
|E\_SE\_DRLC\_REJECTED\_INVALID\_CANCEL\_COMMAND\_INVALID\_EFFECTIVE\_TIME|Received ‘cancel command’ rejected due to invalid effective time \(start-time of cancellation\)|
|E\_SE\_DRLC\_REJECTED\_EVENT\_RECEIVED\_AFTER\_IT\_HAD\_EXPIRED|LCE was received after it had expired \(current time is greater than start-time + duration\)|
|E\_SE\_DRLC\_REJECTED\_INVALID\_CANCEL\_COMMAND\_UNDEFINED\_EVENT|Received ‘cancel command’ due to undefined LCE|
|E\_SE\_DRLC\_LOAD\_CONTROL\_EVENT\_COM-MAND\_REJECTED|LCE command rejected|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

