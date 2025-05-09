# tsZCL\_DefaultResponse

This structure is contained in a ZCL event of type E\_ZCL\_CBET\_DEFAULT\_RESPONSE \(see [Section](event_structure_tszcl_callbackevent.md#id_c4305c06-afe0-4b8a-952a-40536e816bab)\):

```
 typedef struct PACK {
     uint8  u8CommandId; 
     uint8  u8StatusCode;
} tsZCL_DefaultResponse;

```

Where:

-   `u8CommandId` is the ZCL identifier of the command that triggered the default response message

-   `u8StatusCode` is the status code from the default response message \(0x00 for OK or an error code defined in the ZCL Specification - see [Section 4.2](../../ZCL_error_handling/topics/errorcommand_status_on_receiving_command.md#id_0f838bb9-eb56-4aea-a490-86160a9d244f)\)


The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_DEFAULT\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

