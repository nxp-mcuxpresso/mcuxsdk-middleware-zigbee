# Other Elements of tsSE\_DRLCCallBackMessage

In addition to the fields `eEventType` and `u8CommandId` described in [Section 41.7.1](event_and_command_types.md#id_280d70e2-14c1-4055-88d1-f61aa0aedd77), the `tsSE_DRLCCallBackMessage` structure contains the following elements.

## eDRLCStatus 

The `eDRLCStatus` field indicates the status returned from the command that has been executed \(the command identified in `u8CommandId`\). The status codes are enumerated in the `teSE_DRLCStatus` structure, shown below and described in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9).

```
typedef enum PACK
{
  E_SE_DRLC_DUPLICATE_EXISTS  = 0x80,
  E_SE_DRLC_EVENT_LATE,
  E_SE_DRLC_EVENT_NOT_YET_ACTIVE,
  E_SE_DRLC_EVENT_OLD,
  E_SE_DRLC_NOT_FOUND,
  E_SE_DRLC_EVENT_NOT_FOUND,
  E_SE_DRLC_EVENT_IGNORED,
  E_SE_DRLC_CANCEL_DEFERRED,
  E_SE_DRLC_BAD_DEVICE_CLASS,
  E_SE_DRLC_BAD_CRITICALITY_LEVEL,
  E_SE_DRLC_DURATION_TOO_LONG,
  E_SE_DRLC_ENUM_END
} teSE_DRLCStatus;

```

## u32CurrentTime 

The u32CurrentTime field contains the time \(UTC\) at which the event was generated.

## uMessage 

This field is a union of structures, containing a structure for each of the DRLC command payloads. The valid structure in the event is defined by the value of `u8CommandId` \(refer to the description of the E\_SE\_DRLC\_EVENT\_COMMAND event in [Section 41.7.1](event_and_command_types.md#id_280d70e2-14c1-4055-88d1-f61aa0aedd77)\).

**Parent topic:**[DRLC Events](../../DRLC_cluster/topics/drlc_events.md)

