# Simple Metering Events

The Simple Metering cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the Simple Metering cluster then Simple Metering event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eSE\_RegisterMeterEndPoint\(\)** for a standalone Metering Device\). The relevant callback function will then be invoked when a Simple Metering event occurs.

For a Simple Metering event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to a `tsSM_CallBackMessage` structure which contains the Simple Metering parameters:

```
typedef struct
{
  teSM_CallBackEventType eEventType;
  uint8 u8CommandId;
    union
    {
       tsSM_GetProfileResponseCommand     sGetProfileResponseCommand;
       tsSM_RequestFastPollResponseCommand    sRequestFastPollResponseCommand;
       tsSM_GetProfileRequestCommand     sGetProfileCommand;
       tsSM_RequestMirrorResponseCommand    sRequestMirrorResponseCommand;
       tsSM_MirrorRemovedResponseCommand    sMirrorRemovedResponseCommand;
       tsSM_RequestFastPollCommand      sRequestFastPollCommand;
       tsSM_Error            sError;
    }uMessage;
}tsSM_CallBackMessage;

```

Information on the elements of the above structure is provided below.


```{include} ../../Simple_Metering_cluster/topics/event_types.md
:heading-offset: 2
```

```{include} ../../Simple_Metering_cluster/topics/command_types.md
:heading-offset: 2
```

**Parent topic:**[Simple Metering Cluster](../../Simple_Metering_cluster/topics/simple_metering_cluster.md)

