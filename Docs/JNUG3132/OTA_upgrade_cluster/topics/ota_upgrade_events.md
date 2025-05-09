# OTA Upgrade events

The events that can be generated on an OTA Upgrade cluster server or client are defined in the structure `teOTA_UpgradeClusterEvents` \(see [Section 49.12.2](teota_upgradeclusterevents.md#id_09ef20c4-d717-495d-913d-13aa91100504)\). The events are listed in the table below, which also indicates on which side of the cluster \(server or client\) the events can occur:

|**Cluster Side\(s\)**|**Event**|
|---------------------|---------|
|Server|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_REQUEST|
|E\_CLD\_OTA\_COMMAND\_BLOCK\_REQUEST|
|E\_CLD\_OTA\_COMMAND\_PAGE\_REQUEST|
|E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_REQUEST|
|E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_REQUEST|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SEND\_UPGRADE\_END\_RESPONSE|
||E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_IMAGE\_BLOCK\_REQUEST|
|Client|E\_CLD\_OTA\_COMMAND\_IMAGE\_NOTIFY|
|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE|
|E\_CLD\_OTA\_COMMAND\_BLOCK\_RESPONSE|
|E\_CLD\_OTA\_COMMAND\_UPGRADE\_END\_RESPONSE|
|E\_CLD\_OTA\_COMMAND\_QUERY\_SPECIFIC\_FILE\_RESPONSE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_TIMER\_EXPIRED|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_POLL\_REQUIRED|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_RESET\_TO\_UPGRADE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SAVE\_CONTEXT|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_DL\_ABORTED|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_BLOCK\_RESPONSE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_DL\_ABORT|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_IMAGE\_DL\_COMPLETE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_CO\_PROCESSOR\_SWITCH\_TO\_NEW\_IMAGE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_BLOCK\_RESPONSE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_COMPLETE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_DL\_ABORT|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_USE\_NEW\_FILE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SPECIFIC\_FILE\_NO\_UPGRADE\_END\_RESPONSE|
|E\_CLD\_OTA\_COMMAND\_QUERY\_NEXT\_IMAGE\_RESPONSE\_ERROR|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_SIGNER\_ADDRESS|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_RCVD\_DEFAULT\_RESPONSE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_VERIFY\_IMAGE\_VERSION|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_SWITCH\_TO\_UPGRADE\_DOWNGRADE|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_REQUEST\_QUERY\_NEXT\_IMAGES|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_OTA\_START\_IMAGE\_VERIFICATION\_IN\_LOW\_PRIORITY|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_VALIDATING\_UPGRADE\_IMAGE|
||E\_CLD\_OTA\_INTERNAL\_COMMAND\_FAILED\_COPYING\_SERIALIZATION\_DATA|
|E\_CLD\_OTA\_BLOCK\_RESPONSE\_TAG\_OTHER\_THAN\_UPGRADE\_IMAGE|
|Both|E\_CLD\_OTA\_INTERNAL\_COMMAND\_LOCK\_FLASH\_MUTEX|
|E\_CLD\_OTA\_INTERNAL\_COMMAND\_FREE\_FLASH\_MUTEX|

OTA Upgrade events are treated as ZCL events. Thus, an event is received by the application, which wraps the event in a `tsZCL_CallBackEvent`structure and passes it into the ZCL using the function **vZCL\_EventHandler\(\)** - for further details of ZCL event processing, refer to [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee).

The above events are outlined in the sub-sections below.


```{include} ../../OTA_upgrade_cluster/topics/server-side_events.md
:heading-offset: 2
```

```{include} ../../OTA_upgrade_cluster/topics/client-side_events.md
:heading-offset: 2
```

```{include} ../../OTA_upgrade_cluster/topics/server-side_and_client-side_events.md
:heading-offset: 2
```

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

