# Event Structure \(tsZCL\_CallBackEvent\)

A ZCL event must be wrapped in the following `tsZCL_CallBackEvent` structure before being passed into the function **vZCL\_EventHandler\(\)**:

```
typedef struct
 {
teZCL_CallBackEventType                     eEventType;
uint8                                       u8TransactionSequenceNumber;
uint8                                       u8EndPoint;
teZCL_Status                                eZCL_Status;
union {
tsZCL_IndividualAttributesResponse          sIndividualAttributeResponse;
tsZCL_DefaultResponse                       sDefaultResponse;
tsZCL_TimerMessage                          sTimerMessage;
tsZCL_ClusterCustomMessage                  sClusterCustomMessage;
tsZCL_AttributeReportingConfigurationRecord
                                        sAttributeReportingConfigurationRecord;
tsZCL_AttributeReportingConfigurationResponse
                                        sAttributeReportingConfigurationResponse;
tsZCL_AttributeDiscoveryResponse        sAttributeDiscoveryResponse;
tsZCL_AttributeStatusRecord             sReportingConfigurationResponse;
tsZCL_ReportAttributeMirror             sReportAttributeMirror;
uint32                                  u32TimerPeriodMs;
tsZCL_CommandDiscoveryIndividualResponse
                                        sCommandsReceivedDiscoveryIndividualResponse;
tsZCL_CommandDiscoveryResponse          sCommandsReceivedDiscoveryResponse;
tsZCL_CommandDiscoveryIndividualResponse
                                        sCommandsGeneratedDiscoveryIndividualResponse;
tsZCL_CommandDiscoveryResponse          sCommandsGeneratedDiscoveryResponse;
tsZCL_AttributeDiscoveryExtendedResponse
                                        sAttributeDiscoveryExtenedResponse;
 }uMessage ;
      ZPS_tsAfEvent *pZPSevent;
      tsZCL_ClusterInstance *psClusterInstance;
} tsZCL_CallBackEvent;
```

where

-   `eEventType`: specifies the type of event generated - see [Section 7.3](../../ZCL_enums_codes/topics/zcl_event_enumerations.md#id_268cf61b-35c8-46ec-9e2b-53630fd750ee).

-   `u8TransactionSequenceNumber` is the Transaction Sequence Number \(TSN\) of the incoming ZCL message \(if any\) which triggered the ZCL event.

-   `u8EndPoint` is the endpoint on which the ZCL message \(if any\) was received.

-   `eZCL_Status` is the status of the operation that the event reports - see [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

-   `uMessage` is a union containing information that is only valid for specific events:

    -   `s``I``ndividualAttributeResponse` contains the response to a ‘read attributes’ or ‘write attributes’ request - see [Section 6.1.8](tszcl_individualattributesresponse.md#id_62fa28a0-ef36-42c3-b632-5cb78cbc9dff).

    -   `sDefaultResponse` contains the response to a request \(other than a read request\) - see [Section 6.1.9](tszcl_defaultresponse.md#id_6adc0c37-aa71-4b92-9597-53c4af5d35e1).

    -   `sTimerMessage` contains the details of a timer event - this feature is included for future use.

    -   `sClusterCustomMessage` contains details of a cluster custom command - see [Section 6.1.15](tszcl_clustercustommessage.md#id_78bfa34d-151f-4908-a056-d83228e45d56)

    -   `sAttributeReportingConfigurationRecord` contains the attribute reporting configuration data from the ‘configure reporting’ request for an attribute - see [Section 6.1.5](tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd).

    -   `sAttributeReportingConfigurationResponse` is reserved for future use.

    -   `sAttributeDiscoveryResponse` contains the details of an attribute reported in a ‘discover attributes’ response - see [Section 6.1.10](tszcl_attributediscoveryresponse.md#id_87716210-2818-4a28-a46a-12db46ad90c9).

    -   `sReportingConfigurationResponse` is reserved for future use.

    -   `sReportAttributeMirror` contains information on the device from which a ZCL ‘report attribute’ command has been received.

    -   `u32TimerPeriodMs` contains the timed period of the millisecond timer which is enabled by the application when the event E\_ZCL\_CBET\_ENABLE\_MS\_TIMER occurs.

    -   `s``CommandsReceivedDiscoveryIndividualResponse` contains information about an individual command \(that can be received\) reported in a Command Discovery response - see [Section 6.1.17](tszcl_commanddiscoveryindividualresponse.md#id_774223ee-162c-4f02-a046-ffba16728d4f).

    -   `sCommandsReceivedDiscoveryResponse` contains information about a Command Discovery response which reports commands that can be received - see [Section 6.1.18](tszcl_commanddiscoveryresponse.md#id_bc505fda-3cfb-436a-a3a1-10216504afca).

    -   `sCommandsGeneratedDiscoveryIndividualResponse` contains information about an individual command \(that can be generated\) reported in a Command Discovery response - see [Section 6.1.17](tszcl_commanddiscoveryindividualresponse.md#id_774223ee-162c-4f02-a046-ffba16728d4f).

    -   `sCommandsGeneratedDiscoveryResponse` contains information about a Command Discovery response which reports commands that can be generated - see [Section 6.1.18](tszcl_commanddiscoveryresponse.md#id_bc505fda-3cfb-436a-a3a1-10216504afca).

    -   `sAttributeDiscoveryExtenedResponse` contains information from a Discover Attributes Extended response - see [Section 6.1.11](tszcl_attributediscoveryextendedresponse.md#id_007da05d-ef21-441e-9f00-1ab9660c0426).


The remaining fields are common to more than one event type but are not valid for all events:

-   `pZPSevent` is a pointer to the stack event \(if any\) that caused the ZCL event.

-   `psClusterInstance` is a pointer to the cluster instance structure that holds the information relating to the cluster being accessed.


**Parent topic:**[ZCL Structures](../../ZCL_structures/topics/zcl_structures.md)

