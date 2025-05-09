# vZCL\_EventHandler

```
void vZCL_EventHandler(
    tsZCL_CallBackEvent *psZCLCallBackEvent);

```

## Description 

This function should be called when an event \(ZigBee stack, peripheral, timer, or cluster event\) occurs. The function is used to pass the event to the ZCL. The ZCL then processes the event, including a call to any necessary callback function.

The event is passed into the function in a `tsZCL_CallBackEvent` structure, which the application must fill in - refer to [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1) for details of this structure.

## Parameters 

-   *psZCLCallBackEvent*: Pointer to a `tsZCL_CallBackEvent` event structure \(see [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1)\) containing the event to process

## Returns 

-   None

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

