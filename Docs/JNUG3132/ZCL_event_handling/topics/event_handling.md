# Event Handling

This chapter describes the event handling framework which allows the ZCL to deal with stack-related and timer-related events \(including cluster-specific events\).

A message arriving in a message queue triggers a stack event whereas a timer event is triggered when a software timer expires \(for more information on timer events, refer to [Section 5.2](#xref)\).

The event must be wrapped in a `tsZCL_CallBackEvent` structure by the application \(see [Section 3.1](event_structure.md#id_b693aa7f-8a8b-424a-87a8-1799a7c87f1e) below\), which then passes this event structure into the ZCL using the function **vZCL\_EventHandler\(\)**, described in [Section 5.1](../../Core_functions/topics/general_functions_.md#id_1f0df55c-1a42-4a30-9031-deb3d5393ead). The ZCL processes the event and, if necessary, invokes the relevant endpoint callback function. Refer to [Section 3.2](processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38) for more details of event processing.


```{include} ../../ZCL_event_handling/topics/event_structure.md
:heading-offset: 1
```

```{include} ../../ZCL_event_handling/topics/processing_events.md
:heading-offset: 1
```

```{include} ../../ZCL_event_handling/topics/events.md
:heading-offset: 1
```

