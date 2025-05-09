# IAS ACE Events

The IAS ACE cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the IAS ACE cluster then IAS ACE event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterIASCIEEndPoint\(\)** for a CIE device\). The relevant callback function will then be invoked when an IAS ACE event occurs.

For an IAS ACE event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_IASACECallBackMessage` structure:

```
typedef struct
{
uint8    u8CommandId;
  union
  {
  tsCLD_IASACE_ArmPayload  *psArmPayload;
  tsCLD_IASACE_BypassPayload     *psBypassPayload;
  tsCLD_IASACE_GetZoneInfoPayload   *psGetZoneInfoPayload;
  tsCLD_IASACE_GetZoneStatusPayload   *psGetZoneStatusPayload;
  tsCLD_IASACE_ArmRespPayload      *psArmRespPayload;
  tsCLD_IASACE_GetZoneIDMapRespPayload   *psGetZoneIDMapRespPayload;
  tsCLD_IASACE_GetZoneInfoRespPayload   *psGetZoneInfoRespPayload;
  tsCLD_IASACE_ZoneStatusChangedPayload  *psZoneStatusChangedPayload;
  tsCLD_IASACE_PanelStatusChangedOrGetPanelStatusRespPayload   
   *psPanelStatusChangedOrGetPanelStatusRespPayload;
  tsCLD_IASACE_SetBypassedZoneListPayload    *psSetBypassedZoneListPayload;
  tsCLD_IASACE_BypassRespPayload    *psBypassRespPayload;
  tsCLD_IASACE_GetZoneStatusRespPayload   *psGetZoneStatusRespPayload;
    } uMessage;
} tsCLD_IASACECallBackMessage;

```

When an IAS ACE event occurs, one of twelve command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsCLD_IASACECallBackMessage` structure. The possible command/event types are detailed in [Table 52](#id_bd3b6605-64a5-48e8-b5e8-26a973ed76f7) below \(for command descriptions, refer to [Section 38.4](command_summary.md#id_73229af1-7c4b-4ebb-8c15-a640325a0272)\).

In the case where an IAS Arm or Bypass command has been received and results in a change to a Zone parameter on the cluster server \(e.g. an update of the zone status `u8ZoneStatusFlag`\), a second event will be generated before any response is sent. This is a ‘cluster update’ event for which the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_UPDATE. This prompts the application to perform any required actions such as saving persistent data and refreshing a display.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|**Server Events**|
|E\_CLD\_IASACE\_CMD\_ARM|An IAS ACE Arm command has been received by the server|
|E\_CLD\_IASACE\_CMD\_BYPASS|An IAS ACE Bypass command has been received by the server|
|E\_CLD\_IASACE\_CMD\_EMERGENCY|An IAS ACE Emergency command has been received by the server|
|E\_CLD\_IASACE\_CMD\_FIRE|An IAS ACE Fire command has been received by the server|
|E\_CLD\_IASACE\_CMD\_PANIC|An IAS ACE Panic command has been received by the server|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_ID\_MAP|An IAS ACE Get Zone ID Map command has been received by the server|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_INFO|An IAS ACE Get Zone Information command has been received by the server|
|E\_CLD\_IASACE\_CMD\_GET\_PANEL\_STATUS|An IAS ACE Get Panel Status command has been received by the server|
|E\_CLD\_IASACE\_CMD\_GET\_BYPASSED\_ZONE\_LIST|An IAS ACE Get Bypassed Zone List command has been received by the server|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_STATUS|An IAS ACE Get Zone Status command has been received by the server|
|**Client Events**|
|E\_CLD\_IASACE\_CMD\_ARM\_RESP|An IAS ACE Arm Response command has been received by the client|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_ID\_MAP\_RESP|An IAS ACE Get Zone ID Map Response command has been received by the client|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_INFO\_RESP|An IAS ACE Get Zone Information Response command has been received by the client|
|E\_CLD\_IASACE\_CMD\_ZONE\_STATUS\_CHANGED|An IAS ACE Zone Status Changed command has been received by the client|
|E\_CLD\_IASACE\_CMD\_PANEL\_STATUS\_CHANGED|An IAS ACE Panel Status Changed command has been received by the client|
|E\_CLD\_IASACE\_CMD\_GET\_PANEL\_STATUS\_RESP|An IAS ACE Get Panel Status Response command has been received by the client|
|E\_CLD\_IASACE\_CMD\_SET\_BY-PASSED\_ZONE\_LIST|An IAS ACE Set Bypassed Zone List command has been received by the client|
|E\_CLD\_IASACE\_CMD\_BYPASS\_RESP|An IAS ACE Bypass Response command has been received by the client|
|E\_CLD\_IASACE\_CMD\_GET\_ZONE\_STATUS\_RESP|An IAS ACE Get Zone Status Response command has been received by the client|

**Parent topic:**[IAS Ancillary Control Equipment Cluster](../../IAS_ACE_cluster/topics/ias_ancillary_control_equipment_cluster.md)

