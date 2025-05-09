# DRLC Events

The DRLC cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the DRLC cluster then DRLC event handling must be included in the callback function for the associated endpoint - for example:

-   For an ESP \(cluster server\), this callback function is registered through **eSE\_RegisterEspMeterEndPoint\(\)** or **eSE\_RegisterEspEndPoint\(\)**

-   For an IPD \(cluster client\), this callback function is registered through **eSE\_RegisterIPDEndPoint\(\)**


The relevant callback function is then invoked when a DRLC event occurs.

For a DRLC event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to a `tsSE_DRLCCallBackMessage` structure which contains the DRLC parameters:

```
typedef struct
{
 teSE_DRLCCallBackEventType  eEventType;
  uint8   u8CommandId;
  teSE_DRLCStatus  eDRLCStatus;
  uint32  u32CurrentTime;
  union {
  tsSE_DRLCLoadControlEvent     sLoadControlEvent;
  tsSE_DRLCCancelLoadControlEvent  sCancelLoadControlEvent;
  tsSE_DRLCCancelLoadControlAllEvent  sCancelLoadControlAllEvent;
  tsSE_DRLCReportEvent       sReportEvent;
  tsSE_DRLCGetScheduledEvents   sGetScheduledEvents;
   } uMessage;
} tsSE_DRLCCallBackMessage;

```

Information on the elements of the above structure is provided in the sub-sections below.


```{include} ../../DRLC_cluster/topics/event_and_command_types.md
:heading-offset: 2
```

```{include} ../../DRLC_cluster/topics/other_elements_of_tsse_drlccallbackmessage.md
:heading-offset: 2
```

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

