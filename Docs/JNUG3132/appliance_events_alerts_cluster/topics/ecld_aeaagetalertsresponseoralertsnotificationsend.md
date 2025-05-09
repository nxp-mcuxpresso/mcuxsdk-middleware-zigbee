# eCLD\_AEAAGetAlertsResponseORAlertsNotificationSend

```
teZCL_Status eCLD_AEAAGetAlertsResponseORAlertsNotificationSend(
uint8 u8SourceEndPointId,
uint8 u8DestinationEndPointId,
tsZCL_Address *psDestinationAddress,
uint8 *pu8TransactionSequenceNumber,
teCLD_ApplianceEventsAndAlerts_CommandId eCommandId,
tsCLD_AEAA_GetAlertsResponseORAlertsNotificationPayload
*psPayload);

```

## Description 

This function can be used on an Appliance Events and Alerts cluster server to send a ‘Get Alerts Response’ message \(in reply to a ‘Get Alerts’ message\) or an unsolicited ‘Alerts Notification’ message to a cluster client.

The command to be sent must be specified as one of:

-   E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_GET\_ALERTS

-   E\_CLD\_APPLIANCE\_EVENTS\_AND\_ALERTS\_CMD\_ALERTS\_NOTIFICATION


You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 


## Returns 


**Parent topic:**[Functions](../../appliance_events_alerts_cluster/topics/functions.md)

