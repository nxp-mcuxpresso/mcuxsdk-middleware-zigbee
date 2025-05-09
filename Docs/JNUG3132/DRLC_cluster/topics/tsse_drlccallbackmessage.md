# tsSE\_DRLCCallBackMessage

The structure of type `tsSE_DRLCCallBackMessage` contains a DRLC callback event. It is shown below but described in [Section 41.7](drlc_events.md#id_085ec6fa-526f-4152-b804-4552a0c0e99e).

```
typedef struct
{
  teSE_DRLCCallBackEventType  eEventType;
  uint8 u8CommandId;
  teSE_DRLCStatus  eDRLCStatus;
  uint32     u32CurrentTime;
  union {
   tsSE_DRLCLoadControlEvent      sLoadControlEvent;
   tsSE_DRLCCancelLoadControlEvent     sCancelLoadControlEvent;
   tsSE_DRLCCancelLoadControlAllEvent  sCancelLoadControlAllEvent;
   tsSE_DRLCReportEvent    sReportEvent;
   tsSE_DRLCGetScheduledEvents    sGetScheduledEvents;
    } uMessage;
} tsSE_DRLCCallBackMessage;

```

**Parent topic:**[Structures](../../DRLC_cluster/topics/structures.md)

