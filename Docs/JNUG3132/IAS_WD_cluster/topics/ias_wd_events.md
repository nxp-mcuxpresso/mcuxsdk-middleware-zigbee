# IAS WD Events

The IAS WD cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the IAS WD cluster then IAS WD event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterWarningDeviceEndPoint\(\)** for a Warning Device\). The relevant callback function is then invoked when an IAS WD event occurs.

For an IAS WD event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_IASWDCallBackMessage` structure:

```
typedef struct
{
  uint8   u8CommandId;
  union
  {
  tsCLD_IASWD_StartWarningReqPayload  *psWDStartWarningReqPayload;
  tsCLD_IASWD_SquawkReqPayload   *psWDSquawkReqPayload;
  tsCLD_IASWD_StrobeUpdate  *psStrobeUpdate;  /* Internal */
  tsCLD_IASWD_WarningUpdate   *psWarningUpdate; /* Internal */
  } uMessage;
} tsCLD_IASWDCallBackMessage;

```

When an IAS WD event occurs, one of several command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command/event types are detailed in the table below \(not that `psStrobeUpdate` and `psWarningUpdate` are for internal use only\).

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_IASWD\_CMD\_WD\_START\_WARNING|A Start Warning command has been received by the cluster server - this command requests that the alarm is activated for a specified time. The command payload is contained in the event in the `tsCLD_IASWD_StartWarningReqPayload` structure, described in [Section 39.6.2](custom_command_payloads.md#id_32e3eeca-7fb1-44b3-84c4-aab62a0010d2).|
|E\_CLD\_IASWD\_CMD\_WD\_SQUAWK|A Squawk command has been received by the cluster server - this command requests that the alarm is briefly activated to emit a ‘squawk’ to indicate a status change, such as system disarmed. The command payload is contained in the event in the `tsCLD_IASWD_SquawkReqPayload` structure, described in [Section 39.6.2](custom_command_payloads.md#id_32e3eeca-7fb1-44b3-84c4-aab62a0010d2).|

**Parent topic:**[IAS Warning Device Cluster](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md)

