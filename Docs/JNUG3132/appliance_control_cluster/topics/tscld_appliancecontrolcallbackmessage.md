# tsCLD\_ApplianceControlCallBackMessage

For an Appliance Control event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceControlCallBackMessage` structure:

```
typedef struct
{
    uint8    u8CommandId;
    bool    *pbApplianceStatusTwoPresent;
    union
    {
        tsCLD_AC_ExecutionOfCommandPayload                                 *psExecutionOfCommandPayload;
        tsCLD_AC_SignalStateResponseORSignalStateNotificationPayload                   
                                    *psSignalStateResponseAndNotificationPayload;
    } uMessage;
} tsCLD_ApplianceControlCallBackMessage; 

```

where:

-   `u8CommandId` indicates the type of Appliance Control command that has been received, one of:

    -   E\_CLD\_APPLIANCE\_CONTROL\_CMD\_EXECUTION\_OF\_COMMAND

    -   E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE

    -   E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_RESPONSE

    -   E\_CLD\_APPLIANCE\_CONTROL\_CMD\_SIGNAL\_STATE\_NOTIFICATION

-   `pbApplianceStatusTwoPresent` is a pointer to a boolean indicating whether a second set of non-standard or proprietary status data is available:

    -   TRUE - additional status data available

    -   FALSE - additional status data unavailable

-   `uMessage` is a union containing the command payload as one of \(depending on the value of `u8CommandId`\):
-   `psExecutionOfCommandPayload` is a pointer to the payload of an ‘Execution of Command’ message \(see [Section 45.9.2](tscld_ac_executionofcommandpayload.md#id_dd9eab9f-773f-4836-aa62-b17497b01b1b)\)
-   `psSignalStateResponseAndNotificationPayload` is a pointer to the payload of a ‘Signal State’ response or notification message \(see [Section 45.9.3](tscld_ac_signalstateresponseorsignalstatenotificat.md#id_62cbbba6-9e68-43f7-8ffc-b7f9112099d1)\)

**Parent topic:**[Structures](../../appliance_control_cluster/topics/structures.md)

