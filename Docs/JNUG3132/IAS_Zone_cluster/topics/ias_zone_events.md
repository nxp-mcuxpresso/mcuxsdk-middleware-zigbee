# IAS Zone Events

The IAS Zone cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the IAS Zone cluster then IAS Zone event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eHA\_RegisterIASZoneEndPoint\(\)** for a Zone device\). The relevant callback function is then invoked when an IAS Zone event occurs.

For an IAS Zone event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_IASZoneCallBackMessage` structure:

```
typedef struct
{
uint8 u8CommandId;
union
    {
     tsCLD_IASZone_TestModeUpdate                   *psTestModeUpdate; /* Internal */
     tsCLD_IASZone_EnrollRequestCallBackPayload     sZoneEnrollRequestCallbackPayload;
     tsCLD_IASZone_EnrollResponsePayload            *psZoneEnrollResponsePayload;
     tsCLD_IASZone_StatusChangeNotificationPayload  *psZoneStatusNotificationPayload;
     tsCLD_IASZone_InitiateTestModeRequestPayload   *psZoneInitiateTestModeRequestPayload;
    } uMessage;
} tsCLD_IASZoneCallBackMessage;
```

When an IAS Zone event occurs, one of several command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command/event types are detailed in the table below \(note that `psTestModeUpdate` is for internal use only\).

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_IASZONE\_CMD\_ZONE\_ENROLL\_RESP|An IAS Zone Enroll Response has been received by the cluster server|
|E\_CLD\_IASZONE\_CMD\_ZONE\_STATUS\_NOTIFICATION|An IAS Zone Status Change Notification has been received by the cluster client|
|E\_CLD\_IASZONE\_CMD\_ZONE\_ENROLL\_REQ|An IAS Zone Enroll Request has been received by the cluster client|
|E\_CLD\_IASZONE\_CMD\_INITIATE\_NORMAL\_OP\_MODE\_REQ|An IAS Zone Normal Operation Mode Initiation Request command has been received by the cluster server|
|E\_CLD\_IASZONE\_CMD\_INITIATE\_TEST\_MODE\_REQ|An IAS Zone Initiate Test Mode Request has been received by the cluster server|

**Parent topic:**[IAS Zone Cluster](../../IAS_Zone_cluster/topics/ias_zone_cluster.md)

