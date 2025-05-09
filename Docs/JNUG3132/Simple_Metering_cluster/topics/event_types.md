# Event Types

The `eEventType` field of the `tsSM_CallBackMessage` structure specifies the type of Simple Metering event that has been generated. These event types are enumerated in the `teSM_CallBackEventType` structure \(see [Section 42.10.7](simple_metering_event_enumerations_.md#id_c38fcd65-7a51-4d1b-ad41-7b52704a7414)\) and are listed in the table below.

|**Event Type Enumeration**|**Description**|
|--------------------------|---------------|
|E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND|Generated when a command has been received on a cluster client|
|E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND|Generated when a command has been received on the cluster server|
|E\_CLD\_SM\_FAST\_POLLING\_TIMER\_EXPIRED|Generated on the cluster server at the end of a fast polling episode \(*for future use*\)|

The possible command types for the above event types are listed in [Section 42.7.2](command_types.md#id_ba2b8b47-ae5c-40e3-9925-6ca6c2697d97).

**Parent topic:**[Simple Metering Events](../../Simple_Metering_cluster/topics/simple_metering_events.md)

