# ‘Command ID’ Enumerations

The following enumerations are used in commands received on a cluster server or client.

```
typedef enum PACK
{
   E_CLD_APPLIANCE_EVENTS_AND_ALERTS_CMD_GET_ALERTS = 0x00,
   E_CLD_APPLIANCE_EVENTS_AND_ALERTS_CMD_ALERTS_NOTIFICATION,
   E_CLD_APPLIANCE_EVENTS_AND_ALERTS_CMD_EVENT_NOTIFICATION 
} teCLD_ApplianceEventsAndAlerts_CommandId;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS|‘Get Alerts’ request \(on server\) or response \(on client\)|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION|Alerts notification \(on client\)|
|E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_EVENT\_NOTIFICATION|Events notification \(on server\)|

**Parent topic:**[Enumerations](../../appliance_events_alerts_cluster/topics/enumerations.md)

