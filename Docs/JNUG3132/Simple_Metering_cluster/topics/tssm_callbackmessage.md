# tsSM\_CallBackMessage

For a Simple Metering event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsSM_CallBackMessage` structure which contains the Simple Metering parameters:

```
typedef struct
{
     teSM_CallBackEventType eEventType;
      uint8 u8CommandId;
  union
    {
     tsSM_GetProfileResponseCommand    sGetProfileResponseCommand;
     tsSM_RequestFastPollResponseCommand  sRequestFastPollResponseCommand;
     tsSM_GetProfileRequestCommand    sGetProfileCommand;
     tsSM_RequestMirrorResponseCommand   sRequestMirrorResponseCommand;
     tsSM_MirrorRemovedResponseCommand   sMirrorRemovedResponseCommand;
     tsSM_RequestFastPollCommand     sRequestFastPollCommand;
     tsSM_Error           sError;
 }uMessage;
}tsSM_CallBackMessage; 

```

where:

-   `eEventType` is the Simple Metering event type from those listed in [Section](simple_metering_event_enumerations_.md#id_c38fcd65-7a51-4d1b-ad41-7b52704a7414)42.10.7

-   `u8CommandId` is the identifier of the type of Simple Metering command received. This field is only valid for the following Simple Metering event types:

    -   E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND - enumerated commands are provided, as described in [Section 42.10.8](server_command_enumerations.md#id_6a86db53-1248-418f-b2e4-040a87fb251e)

    -   E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND - enumerated commands are provided, as described in [Section 42.10.9](client_command_enumerations.md#id_7dc00443-efc3-4144-afec-0cc8486a5b23)

-   `uMessage` is a union containing the command payload in one of the following forms \(depending on the command specified in the field `u8CommandId`\):

    -   `s``GetProfileResponseCommand` is a structure containing the payload of a ‘Get Profile’ response - see [Section 42.11.9](tssm_getprofileresponsecommand.md#id_76cac5c2-b5e4-4ffb-8a53-6454675922be)

    -   `sRequestFastPollResponseCommand` is a structure containing the payload of a ‘Fast Polling’ response \(*for future use*\)

    -   `sGetProfileCommand` is a structure containing the payload of a ‘Get Profile’ request - see [Section 42.11.8](tssm_getprofilerequestcommand.md#id_fdfdc3c8-933b-4e97-a9cc-334ccc4ed745)

    -   `sRequestMirrorResponseCommand` is a structure containing the payload of an ‘Add Mirror’ response - see [Section 42.11.6](tssm_requestmirrorresponsecommand.md#id_f0a8bde1-a77f-4d19-81d9-dd153d2af499)

    -   `sMirrorRemovedResponseCommand` is a structure containing the payload of an ‘Remove Mirror’ response - see [Section 42.11.7](tssm_mirrorremovedresponsecommand.md#id_afda06de-379c-47e5-a279-92227bc99fb4)

    -   `sRequestFastPollCommand` is a structure containing the payload of an ‘Fast Polling’ request \(*for future use*\)

    -   `sError` is a structure containing the details of an error condition - see [Section 42.11.10](tssm_error.md#id_a4d1e778-b82c-4196-abf0-d71b369c0afe)


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

