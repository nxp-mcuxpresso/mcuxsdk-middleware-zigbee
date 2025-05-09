# tsCLD\_ApplianceStatisticsCallBackMessage

For an Appliance Statistics event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_ApplianceStatisticsCallBackMessage` structure:

```
typedef struct
{
    uint8    u8CommandId;
    union
    {
       tsCLD_ASC_LogNotificationORLogResponsePayload                       
                                   *psLogNotificationORLogResponsePayload;
       tsCLD_ASC_LogQueueResponseORStatisticsAvailablePayload               
                                   *psLogQueueResponseORStatisticsAvailabePayload;
       tsCLD_ASC_LogRequestPayload *psLogRequestPayload;
    } uMessage;
} tsCLD_ApplianceStatisticsCallBackMessage; 

```

where:

-   `u``8CommandId` indicates the type of Appliance Statistics command that has been received, one of:

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_REQUEST

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_REQUEST

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_NOTIFICATION

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_RESPONSE

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_LOG\_QUEUE\_RESPONSE

    -   E\_CLD\_APPLIANCE\_STATISTICS\_CMD\_STATISTICS\_AVAILABLE

-   `u``Message` is a union containing the command payload as one of \(depending on the value of `u8CommandId`\):

    -   `psLogNotificationORLogResponsePayload` is a pointer to the payload of a ‘Log Notification’ or ‘Log Response’ message \(see [Section](tscld_asc_lognotificationorlogresponsepayload.md#id_5db27449-4b3a-4b18-a4d1-a8f63b7b0d61)48.9.3\)

    -   `psLogQueueResponseORStatisticsAvailabePayload` is a pointer to the payload of a ‘Log Queue Response’ or ‘Statistics Available’ message \(see [Section 48.9.4](tscld_asc_logqueueresponseorstatisticsavailablepay.md#id_4cfb8571-5604-4991-b2c3-0c78359ecaf8)\)

    -   `psLogRequestPayload` is a pointer to the payload of a ‘Log Request’ message \(see [Section 48.9.2](tscld_asc_logrequestpayload.md#id_f2d14175-9bec-422f-828f-82d40152ad61)\)


**Parent topic:**[Structures](../../appliance_statistics_cluster/topics/structures.md)

