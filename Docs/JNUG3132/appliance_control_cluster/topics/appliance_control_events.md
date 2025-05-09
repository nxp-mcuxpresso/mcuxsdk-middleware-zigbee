# Appliance control events

The Appliance Control cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). The cluster contains its own event handler. If a device uses this cluster then application-specific Appliance Control event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function will then be invoked when an Appliance Control event occurs and needs the attention of the application.

For an Appliance Control event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceControlCallBackMessage` structure:

```
typedef struct
{
    uint8   u8CommandId;
    bool   *pbApplianceStatusTwoPresent;
    union
    {
        tsCLD_AC_ExecutionOfCommandPayload *psExecutionOfCommandPayload;
        tsCLD_AC_SignalStateResponseORSignalStateNotificationPayload
                                      *psSignalStateResponseAndNotificationPayload;
    } uMessage;
} tsCLD_ApplianceControlCallBackMessage;

```

When an Appliance Control event occurs, one of four command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsSM_CallBackMessage` structure. The possible command types are detailed the tables below for events generated on a server and a client.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_CONTROL\_

 CMD\_EXECUTION\_OF\_COMMAND

|An ‘Execution of Command’ message has been received by the server \(appliance\), requesting an opera-tion on the appliance|
|E\_CLD\_APPLIANCE\_CONTROL\_

 CMD\_SIGNAL\_STATE

|A ‘Signal State’ message has been received by the server \(appliance\), requesting the status of the appli-ance|

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_APPLIANCE\_CONTROL\_CM-D\_SIGNAL\_STATE\_RESPONSE|A response to a ‘Signal State’ message has been received by the client, containing the requested appli-ance status|
|E\_CLD\_APPLIANCE\_CONTROL\_CM-D\_SIGNAL\_STATE\_NOTIFICATION|A ‘Signal State’ notification message has been received by the client, containing unsolicited status information|

**Parent topic:**[Appliance Control Cluster](../../appliance_control_cluster/topics/appliance_control_cluster.md)

