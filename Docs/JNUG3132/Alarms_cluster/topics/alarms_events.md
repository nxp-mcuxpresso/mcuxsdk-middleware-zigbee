# Alarms Events

The Alarms cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the Alarms cluster, then Alarms event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterThermostatEndPoint\(\)** for a Thermostat device\). The relevant callback function is then invoked when an Alarms event occurs.

For an Alarms event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_AlarmsCallBackMessage` structure:

```
typedef struct
{
 uint8  u8CommandId;
 union
  {
 tsCLD_AlarmsResetAlarmCommandPayload  *psResetAlarmCommandPayload;
  tsCLD_AlarmsAlarmCommandPayload  *psAlarmCommandPayload;
  tsCLD_AlarmsGetAlarmResponsePayload   *psGetAlarmResponse;
  } uMessage;
} tsCLD_AlarmsCallBackMessage;

```

When an Alarms event occurs, one of a number of command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsCLD_AlarmsCallBackMessage` structure. The possible command types are detailed below.

The table below lists and describes the command types that can be received by the cluster server.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_ALARMS\_CMD\_RESET\_ALARM|A Reset Alarm command has been received|
|E\_CLD\_ALARMS\_CMD\_RESET\_ALL\_ALARMS|A Reset All Alarms command has been received|
|E\_CLD\_ALARMS\_CMD\_GET\_ALARM|A Get Alarm command has been received|
|E\_CLD\_ALARMS\_CMD\_RESET\_ALARM\_LOG|A Reset Alarm Log command has been received|

The table below lists and describes the command types that can be received by the cluster client.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_ALARMS\_CMD\_ALARM|An Alarm notification has been received|
|E\_CLD\_ALARMS\_CMD\_GET\_ALARM\_RESPONSE|A Get Alarm response has been received|

**Parent topic:**[Alarms Cluster](../../Alarms_cluster/topics/alarms_cluster.md)

