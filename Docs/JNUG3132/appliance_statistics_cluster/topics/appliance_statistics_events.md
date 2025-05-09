# Appliance statistics events

The Appliance Statistics cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). The cluster contains its own event handler. If a device uses this cluster then application-specific Appliance Statistics event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function will then be invoked when an Appliance Statistics event occurs and needs the attention of the application.

For an Appliance Statistics event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceStatisticsCallBackMessage` structure:

```
typedef struct
{
    uint8    u8CommandId;
    union
    {
        tsCLD_ASC_LogNotificationORLogResponsePayload                       
                                      *psLogNotificationORLogResponsePayload;
        tsCLD_ASC_LogQueueResponseORStatisticsAvailablePayload               
                                      *psLogQueueResponseORStatisticsAvailabePayload;
        tsCLD_ASC_LogRequestPayload   *psLogRequestPayload;
    } uMessage;
} tsCLD_ApplianceStatisticsCallBackMessage;

```

When an Appliance Statistics event occurs, one of four command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command types are detailed the tables below for events generated on a server and a client.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_LOG\_REQUEST

|A ‘Log Request’ message has been received by the server \(appliance\)|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_LOG\_QUEUE\_REQUEST

|A ‘Log Queue Request’ message has been received by the server \(appliance\)|

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_LOG\_NOTIFICATION

|A ‘Log Notification’ message has been received by the client|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_LOG\_RESPONSE

|A ‘Log Response’ message has been received by the client|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_LOG\_QUEUE\_RESPONSE

|A ‘Log Queue Response’ message has been received by the client|
|E\_CLD\_APPLIANCE\_STATISTICS\_

 CMD\_STATISTICS\_AVAILABLE

|A ‘Statistics Available’ message has been received by the client|

**Parent topic:**[Appliance Statistics Cluster](../../appliance_statistics_cluster/topics/appliance_statistics_cluster.md)

