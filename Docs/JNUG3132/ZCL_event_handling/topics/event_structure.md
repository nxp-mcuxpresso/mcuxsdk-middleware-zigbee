# Event Structure

The `tsZCL_CallBackEvent` structure, in which an event is wrapped, is as follows:

```
typedef struct
{
    teZCL_CallBackEventType         eEventType;
    uint8                           u8TransactionSequenceNumber;
    uint8                           u8EndPoint;
    teZCL_Status                    eZCL_Status;
union {
    tsZCL_IndividualAttributesResponse         sIndividualAttributeResponse;
    tsZCL_DefaultResponse                      sDefaultResponse;
    tsZCL_TimerMessage                         sTimerMessage;
    tsZCL_ClusterCustomMessage                 sClusterCustomMessage;
    tsZCL_AttributeReportingConfigurationRecord
                                 sAttributeReportingConfigurationRecord;
    tsZCL_AttributeReportingConfigurationResponse
                                 sAttributeReportingConfigurationResponse;
    tsZCL_AttributeDiscoveryResponse         sAttributeDiscoveryResponse;
                 ZCL_AttributeStatusRecord sReportingConfigurationResponse;
    tsZCL_ReportAttributeMirror sReportAttributeMirror;
    uint32              u32TimerPeriodMs;
    tsZCL_CommandDiscoveryIndividualResponse
                        sCommandsReceivedDiscoveryIndividualResponse;
    tsZCL_CommandDiscoveryResponse      sCommandsReceivedDiscoveryResponse;
    tsZCL_CommandDiscoveryIndividualResponse
                            sCommandsGeneratedDiscoveryIndividualResponse;
    tsZCL_CommandDiscoveryResponse     sCommandsGeneratedDiscoveryResponse;
    tsZCL_AttributeDiscoveryExtendedResponse
                                        sAttributeDiscoveryExtenedResponse;
}uMessage ;
    ZPS_tsAfEvent         *pZPSevent;
    tsZCL_ClusterInstance *psClusterInstance;
} tsZCL_CallBackEvent;
```

The fields of this structure are fully described [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1).

In the `tsZCL_CallBackEvent` structure, the `eEventType` field defines the type of event being posted - the various event types are described in [Section 3.3](events.md#id_f2e2cabc-f0bf-4a7b-891a-3aa6c1e9b8cb) below. The union and remaining fields are each relevant to only specific event types.

**Parent topic:**[Event Handling](../../ZCL_event_handling/topics/event_handling.md)

