# Processing Events

This section outlines how the application should deal with stack events and timer events that are generated externally to the ZCL. A cluster-specific event initially arrives as one of these events.

The occurrence of an event in the ZCL queue activates a ZCL user function. The following actions must then be performed in the application:

1. The task checks whether the event that has occurred is a timer event \(timer messages are collected by a user-defined function\).

2. The task sets fields of the event structure `tsZCL_CallBackEvent` \(see [Section 3.1](event_structure.md#id_b693aa7f-8a8b-424a-87a8-1799a7c87f1e)\), as follows \(all other fields are ignored\):

-   For a timer event, sets the field `eEventType` to E\_ZCL\_CBET\_TIMER.

-   For a millisecond timer event, sets the field `eEventType` to E\_ZCL\_CBET\_TIMER\_MS.

-   For a stack event, sets the field `eEventType` to E\_ZCL\_ZIGBEE\_EVENT and sets the field `pZPSevent` to point to the `ZPS_tsAfEvent` structure received by the application. This structure is defined in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

3. The task passes this event structure to the ZCL using **vZCL\_EventHandler\(\)** - the ZCL then identifies the event type \(see [Section 3.3](events.md#id_f2e2cabc-f0bf-4a7b-891a-3aa6c1e9b8cb)\) and invokes the appropriate endpoint callback function.

**Note:** For a cluster-specific event \(which arrives as a stack event or a timer event\), the cluster normally contains its own event handler which is invoked by the ZCL. If the event requires the attention of the application, the ZCL replaces the `eEventType` field with E\_ZCL\_CBET\_CLUSTER\_CUSTOM and populates the `tsZCL_ClusterCustomMessage` structure with the event data. The ZCL then invokes the user-defined endpoint callback function to perform any application-specific event handling that is required.

**Parent topic:**[Event Handling](../../ZCL_event_handling/topics/event_handling.md)

