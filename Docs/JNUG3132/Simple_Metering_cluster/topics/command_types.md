# Command Types

For each event type listed in [Section 42.7.1](event_types.md#id_5df90559-6acf-47ec-9ba8-7895ef94f94d), one of a number of command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command types for each event type are detailed below.

## E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND 

The E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND event is generated when a command has been received on a cluster client. The possible command types for this event type are listed in the table below, which gives the enumerations and the associated `uMessage` union elements in the `tsSM_CallBackMessage` structure:

|**u8CommandId Enumeration**|**uMessage Union Element**|
|---------------------------|--------------------------|
|E\_CLD\_SM\_GET\_PROFILE\_RESPONSE|sGetProfileResponseCommand|
|E\_CLD\_SM\_REQUEST\_MIRROR|sRequestMirrorAdd|
|E\_CLD\_SM\_REMOVE\_MIRROR|sRequestMirrorRemove|
|E\_CLD\_SM\_REQUEST\_FAST\_POLL\_MODE\_

 RESPONSE

|sRequestFastPollResponseCommand

 \(*for future use*\)

|
|E\_CLD\_SM\_CLIENT\_ERROR|sError|

The above command enumerations are fully described in [Section 42.10.8](server_command_enumerations.md#id_6a86db53-1248-418f-b2e4-040a87fb251e).

## E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND 

The E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND event is generated when a command has been received on the cluster server. The possible command types for this event type are listed in the table below, which gives the enumerations and the associated `uMessage` union elements in the `tsSM_CallBackMessage` structure:

|**u8CommandId Enumeration**|**uMessage Union Element**|
|---------------------------|--------------------------|
|E\_CLD\_SM\_GET\_PROFILE|sGetProfileCommand|
|E\_CLD\_SM\_REQUEST\_MIRROR\_RESPONSE|sRequestMirrorResponseCommand|
|E\_CLD\_SM\_MIRROR\_REMOVED|sMirrorRemovedResponseCommand|
|E\_CLD\_SM\_REQUEST\_FAST\_POLL\_MODE|sRequestFastPollCommand \(*for future use*\)|
|E\_CLD\_SM\_SERVER\_ERROR|sError|

The above command enumerations are fully described in [Section 42.10.9](client_command_enumerations.md#id_7dc00443-efc3-4144-afec-0cc8486a5b23).

## E\_CLD\_SM\_FAST\_POLLING\_TIMER\_EXPIRED 

The E\_CLD\_SM\_FAST\_POLLING\_TIMER\_EXPIRED event is generated on the cluster server at the end of a fast polling episode. It has no associated data structure. *Fast polling is not certifiable in SE 1.1.1 or earlier and this event is reserved for future use*.

**Parent topic:**[Simple Metering Events](../../Simple_Metering_cluster/topics/simple_metering_events.md)

