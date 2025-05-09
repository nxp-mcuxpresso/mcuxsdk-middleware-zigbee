# ZCL Event Enumerations

The ZCL event types are enumerated in the `teZCL_CallBackEventType` structure below and described in [Table 22](#id_d1593504-3db9-46e3-ad86-00d5c2a02ac3). An event must be wrapped in a structure of type `tsZCL_CallBackEvent`, detailed in [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), with the `eEventType` field set to one of the enumerations in the table. The event must be passed into the ZCL using the function **vZCL\_EventHandler\(\)**, detailed in [Section 5.1](../../Core_functions/topics/general_functions_.md#id_1f0df55c-1a42-4a30-9031-deb3d5393ead). Event handling is fully described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee).

```
typedef enum 
{
   E_ZCL_CBET_LOCK_MUTEX = 0x0,
   E_ZCL_CBET_UNLOCK_MUTEX,
   E_ZCL_CBET_UNHANDLED_EVENT,
   E_ZCL_CBET_READ_INDIVIDUAL_ATTRIBUTE_RESPONSE,
   E_ZCL_CBET_READ_ATTRIBUTES_RESPONSE,
   E_ZCL_CBET_READ_REQUEST,
   E_ZCL_CBET_REPORT_REQUEST,
   E_ZCL_CBET_DEFAULT_RESPONSE,
   E_ZCL_CBET_ERROR,
   E_ZCL_CBET_TIMER,
   E_ZCL_CBET_ZIGBEE_EVENT,
   E_ZCL_CBET_CLUSTER_CUSTOM,
   E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE,
   E_ZCL_CBET_WRITE_ATTRIBUTES,
   E_ZCL_CBET_WRITE_INDIVIDUAL_ATTRIBUTE_RESPONSE,
   E_ZCL_CBET_WRITE_ATTRIBUTES_RESPONSE,
   E_ZCL_CBET_CHECK_ATTRIBUTE_RANGE,
   E_ZCL_CBET_REPORT_TIMEOUT,
   E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTE,
   E_ZCL_CBET_REPORT_ATTRIBUTES,
   E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE_RESPONSE,
   E_ZCL_CBET_REPORT_ATTRIBUTES_CONFIGURE,
   E_ZCL_CBET_REPORT_INDIVIDUAL_ATTRIBUTES_CONFIGURE,
   E_ZCL_CBET_REPORT_ATTRIBUTES_CONFIGURE_RESPONSE,
   E_ZCL_CBET_REPORT_READ_INDIVIDUAL_ATTRIBUTE_CONFIGURATION_RESPONSE,
   E_ZCL_CBET_REPORT_READ_ATTRIBUTE_CONFIGURATION_RESPONSE,
   E_ZCL_CBET_DISCOVER_INDIVIDUAL_ATTRIBUTE_RESPONSE,
   E_ZCL_CBET_DISCOVER_ATTRIBUTES_RESPONSE,
   E_ZCL_CBET_CLUSTER_UPDATE,
   E_ZCL_CBET_ATTRIBUTE_REPORT_MIRROR,
   E_ZCL_CBET_REPORT_REQUEST,
   E_ZCL_CBET_ENABLE_MS_TIMER,
   E_ZCL_CBET_DISABLE_MS_TIMER,
   E_ZCL_CBET_TIMER_MS,
   E_ZCL_CBET_ZGP_DATA_IND_ERROR,
   E_ZCL_CBET_DISCOVER_INDIVIDUAL_COMMAND_RECEIVED_RESPONSE,
   E_ZCL_CBET_DISCOVER_COMMAND_RECEIVED_RESPONSE,
   E_ZCL_CBET_DISCOVER_INDIVIDUAL_COMMAND_GENERATED_RESPONSE,
   E_ZCL_CBET_DISCOVER_COMMAND_GENERATED_RESPONSE,  
   E_ZCL_CBET_DISCOVER_INDIVIDUAL_ATTRIBUTE_EXTENDED_RESPONSE,
   E_ZCL_CBET_DISCOVER_ATTRIBUTES_EXTENDED_RESPONSE,
   E_ZCL_CBET_ENUM_END
} teZCL_CallBackEventType;

```

The above enumerations are described in the table below.

|**Event Type Enumeration**|**Description**|
|--------------------------|---------------|
|E\_ZCL\_CBET\_LOCK\_MUTEX|Indicates that a mutex needs to be locked by the application. This event can be generated only when cooperative tasks are disabled in the compile-time options

 \(see [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987)\)

|
|E\_ZCL\_CBET\_UNLOCK\_MUTEX|Indicates that a mutex needs to be unlocked by the application. This event can be generated only when cooperative tasks are disabled in the compile-time options \(see [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987)\)|
|E\_ZCL\_CBET\_UNHANDLED\_EVENT|Indicates that a stack event has been received that cannot be handled by the ZCL \(for example, a Data Confirm\)|
|E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|Generated for each attribute included in a ‘read attributes’ response|
|E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE|Indicates that a ‘read attributes’ response has been received|
|E\_ZCL\_CBET\_READ\_REQUEST|Indicates that a ‘read attributes’ request has been received \(giving an opportunity for the local application to update the shared structure before it is read\)|
|E\_ZCL\_CBET\_DEFAULT\_RESPONSE|Indicates that a ZCL default response message has been received \(which indicates an error or that a command has been processed\)|
|E\_ZCL\_CBET\_ERROR|Indicates that a stack event has been received that can-not be handled by the ZCL|
|E\_ZCL\_CBET\_TIMER|Indicates that a one-second tick of the real-time clock has occurred or that the ZCL timer has expired|
|E\_ZCL\_CBET\_ZIGBEE\_EVENT|Indicates that a ZigBee PRO stack event has occurred|
|E\_ZCL\_CBET\_CLUSTER\_CUSTOM|Indicates that a custom event which is specific to a cluster has occurred|
|E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE|Indicates that an attempt has been made to write an attribute in the shared structure, following a ‘write attributes’ request, and indicates success or failure|
|E\_ZCL\_CBET\_WRITE\_ATTRIBUTES|Indicates that all the relevant attributes have been written in the shared structure, following a ‘write attributes’ request|
|E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|Generated for each attribute included in a ‘write attributes’ response \(this event contains only those attributes for which the writes have failed\)|
|E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE|Indicates that a ‘write attributes’ response has been received and has been parsed|
|E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE|Generated for each attribute included in a received ‘write attributes’ request, and prompts the application to perform a range check on the new attribute value and to decide whether a write access to the relevant attribute in the shared structure are allowed or disallowed|
|E\_ZCL\_CBET\_REPORT\_TIMEOUT|Indicates that an attribute report is overdue|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE|Generated for each attribute included in a received attribute report|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES|Indicates that all attributes included in a received attribute report have been parsed|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE\_RESPONSE|Generated for each attribute included in a ‘configure attributes’ response|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE|Indicates that all attributes included in a ‘configure reporting’ request have been parsed|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE|Generated for each attribute included in a ‘configure reporting’ request|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE\_RESPONSE|Indicates that all attributes included in a ‘configure reporting’ response have been reported|
|E\_ZCL\_CBET\_REPORT\_READ\_INDIVIDUAL

 \_ATTRIBUTE\_CONFIGURATION\_RESPONSE

|Generated for each attribute included in a ‘read reporting configuration’ response|
|E\_ZCL\_CBET\_REPORT\_READ\_ATTRIBUTE\_CONFIGURATION\_RESPONSE|Indicates that all attributes included in a ‘read reporting configuration’ response have been reported|
|E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|Generated for each attribute included in a ‘discover attributes’ response|
|E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES

 \_RESPONSE

|Indicates that all attributes included in a ‘discover attributes’ response have been reported|
|E\_ZCL\_CBET\_CLUSTER\_UPDATE|Indicates that a cluster attribute value may have been changed on the local device|
|E\_ZCL\_CBET\_ENABLE\_MS\_TIMER|Indicates that a millisecond timer needs to be started|
|E\_ZCL\_CBET\_DISABLE\_MS\_TIMER|Indicates that a millisecond timer needs to be stopped|
|E\_ZCL\_CBET\_TIMER\_MS|Indicates that a millisecond timer has expired|
|E\_ZCL\_CBET\_ZGP\_DATA\_IND\_ERROR|Indicates that a ZigBee Green Power data indication error has occurred|
|E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_COMMAND\_RECEIVED\_RESPONSE|Generated for each command \(that can be received\) included in a ‘command discovery‘ response|
|E\_ZCL\_CBET\_DISCOVER\_COMMAND\_RECEIVED\_RESPONSE|Indicates that all commands \(that can be received\) included in a ‘command discovery’ response have been reported|
|E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_COMMAND\_GENERATED\_RESPONSE|Generated for each command \(that can be generated\) included in a ‘command discovery‘ response|
|E\_ZCL\_CBET\_DISCOVER\_COMMAND\_GENERATED\_RESPONSE|Indicates that all commands \(that can be generated\) included in a ‘command discovery’ response have been reported|
|E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_EXTENDED\_RESPONSE|Generated for each attribute included in a ‘discover attributes extended’ response|
|E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES\_EXTENDED\_RESPONSE|Indicates that all attributes included in a ‘discover attributes extended’ response have been reported|
|E\_ZCL\_CBET\_REPORT\_TIMEOUT|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE\_RESPONSE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTES\_CONFIGURE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_ATTRIBUTES\_CONFIGURE\_RESPONSE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_READ\_INDIVIDUAL\_ATTRIBUTE\_CONFIGURATION\_RESPONSE|Reserved for future use|
|E\_ZCL\_CBET\_REPORT\_READ\_ATTRIBUTE\_CONFIGURATION\_RESPONSE|Reserved for future use|
|E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|Reserved for future use|
|E\_ZCL\_CBET\_DISCOVER\_ATTRIBUTES\_RESPONSE|Reserved for future use|

**Note:** The structure `teZCL_CallBackEventType` is extended by the EZ-mode Commissioning module with the events listed and described in [Section 40.5](#xref). These events are only included if this module is used, in which case they are added after E\_ZCL\_CBET\_ENUM\_END.

**Parent topic:**[Enumerations and Status Codes](../../ZCL_enums_codes/topics/enumerations_and_status_codes.md)

