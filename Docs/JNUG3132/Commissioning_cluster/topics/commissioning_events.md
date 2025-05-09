# Commissioning Events

The Commissioning cluster has its own events that are handled through the callback mechanism outlined in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses this cluster then application-specific Commissioning event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function will then be invoked when a Commissioning event occurs and needs the attention of the application.

For a Commissioning event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_CommissioningCallBackMessage` structure \(fully detailed in [Section](tscld_commissioningcallbackmessage.md#id_aa520f47-70fc-4357-af0f-2f63512087fc)43.9.6\).

```
typedef struct
{
    uint8                      u8CommandId;
    union
    {
        tsCLD_Commissioning_RestartDevicePayload                    
                              *psRestartDevicePayload;
        tsCLD_Commissioning_ModifyStartupParametersPayload          
                              *psModifyStartupParamsPayload; 
    } uReqMessage;
    union
    {
        tsCLD_Commissioning_ResponsePayload                         
                              *psCommissioningResponsePayload; 
    } uRespMessage;
} tsCLD_CommissioningCallBackMessage;

```

When a Commissioning event occurs, one of a number of command types could have been received. The relevant command type is specified through the `u8CommandId` field of the `tsCLD_CommissioningCallBackMessage` structure. The possible command types are detailed below.

The table below details the command types that can be received by the cluster server.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_COMMISSIONING\_CMD\_RESTART\_DEVICE|A Restart Device command has been received|
|E\_CLD\_COMMISSIONING\_CMD\_SAVE\_STARTUP\_PARAMS|A Save Start-up Parameters command has been received|
|E\_CLD\_COMMISSIONING\_CMD\_RESTORE\_STARTUP\_PARAMS|A Restore Start-up Parameters command has been received|
|E\_CLD\_COMMISSIONING\_CMD\_RESET\_STARTUP\_PARAMS|A Reset Start-up Parameters command has been received|

The table below details the command types that can be received by the cluster client.

|**u8CommandId Enumeration**|**Description**|
|---------------------------|---------------|
|E\_CLD\_COMMISSIONING\_CMD\_RESTART\_DEVICE|A Restart Device response has been received|
|E\_CLD\_COMMISSIONING\_CMD\_SAVE\_STARTUP\_PARAMS|A Save Start-up Parameters response has been received|
|E\_CLD\_COMMISSIONING\_CMD\_RESTORE\_STARTUP\_PARAMS|A Restore Start-up Parameters response has been received|
|E\_CLD\_COMMISSIONING\_CMD\_RESET\_STARTUP\_PARAMS|A Reset Start-up Parameters response has been received|

**Parent topic:**[Commissioning Cluster](../../Commissioning_cluster/topics/commissioning_cluster.md)

