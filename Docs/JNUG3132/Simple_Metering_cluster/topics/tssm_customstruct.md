# tsSM\_CustomStruct

This structure contains data relating to a command/message for a mirror endpoint.

**Note:** This structure is only for use by the ZCL software and should not be modified by the application.

```
typedef struct
{
    tsZCL_ReceiveEventAddress  sReceiveEventAddress;
    tsZCL_CallBackEvent        sSMCustomCallBackEvent;
    tsSM_CallBackMessage       sSMCallBackMessage;
} tsSM_CustomStruct;

```

where:

-   `sReceiveEventAddress` is a `tsZCL_ReceiveEventAddress` structure which contains addressing information relating to a received mirroring command/message

-   `sSMCustomCallBackEvent` is a `tsZCL_CallBackEvent` structure \(see [Section 3.1](../../ZCL_event_handling/topics/event_structure.md#id_b693aa7f-8a8b-424a-87a8-1799a7c87f1e)\) which contains the event that has been generated as a result of the received command/message

-   `sSMCallBackMessage` is a `tsSM_CallBackMessage` structure \(see [Section](tssm_callbackmessage.md#id_988a6411-1dfd-40bd-bc56-82c13b49c367)42.11.1\) which contains details of the event and the command/message that caused the event


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

