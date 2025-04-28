# ZPS\_tuAfEventData

This structure is a union of the data structures for the individual events described in [Section 8.2.2.3](zps_tsafdataindevent.md) through to [Section 8.2.2.25](zps_tsafzdpevent.md).

The `ZPS_tuAfEventData`structure is detailed below.

```
typedef union
{
ZPS_tsAfDataIndEvent                sApsDataIndEvent;
ZPS_tsAfDataConfEvent               sApsDataConfirmEvent;
ZPS_tsAfDataAckEvent                sApsDataAckEvent;
ZPS_tsAfNwkFormationEvent           sNwkFormationEvent;
ZPS_tsAfNwkJoinedEvent              sNwkJoinedEvent;
ZPS_tsAfNwkJoinFailedEvent          sNwkJoinFailedEvent;
ZPS_tsAfNwkDiscoveryEvent           sNwkDiscoveryEvent;
ZPS_tsAfNwkJoinIndEvent             sNwkJoinIndicationEvent;
ZPS_tsAfNwkLeaveIndEvent            sNwkLeaveIndicationEvent;
ZPS_tsAfNwkLeaveConfEvent           sNwkLeaveConfirmEvent;
ZPS_tsAfNwkStatusIndEvent           sNwkStatusIndicationEvent;
ZPS_tsAfNwkRouteDiscoveryConfEvent  sNwkRouteDiscoveryConfirmEvent;
ZPS_tsAfPollConfEvent               sNwkPollConfirmEvent;
ZPS_tsAfNwkEdScanConfEvent          sNwkEdScanConfirmEvent;
ZPS_tsAfErrorEvent                  sAfErrorEvent;
ZPS_tsAfZdoBindEvent                sZdoBindEvent;
ZPS_tsAfZdoUnbindEvent              sZdoUnbindEvent;
ZPS_tsAfZdoLinkKeyEvent             sZdoLinkKeyEvent;
ZPS_tsAfBindRequestServerEvent      sBindRequestServerEvent;
ZPS_tsAfInterPanDataIndEvent        sApsInterPanDataIndEvent;
ZPS_tsAfInterPanDataConfEvent       sApsInterPanDataConfirmEvent;
ZPS_tsAfZdpEvent                    sApsZdpEvent;
} ZPS_tuAfEventData;
```

**Parent topic:**[Event structures](../topics/event_structures.md)

