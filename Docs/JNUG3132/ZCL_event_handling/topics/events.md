# Events

The events that are not cluster-specific are divided into four categories \(Input, Read, Write, General\), as shown in the following table. The ‘input events’ originate externally to the ZCL and are passed into the ZCL for processing \(see [Section 3.2](processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38)\). The remaining events are generated as part of this processing.

**Note:** Cluster-specific events are covered in the chapter for the relevant cluster.

|**Category**|**Event**|
|------------|---------|
|Input Events|E\_ZCL\_ZIGBEE\_EVENT|
|E\_ZCL\_CBET\_TIMER|
|E\_ZCL\_CBET\_TIMER\_MS|
|Read Events|E\_ZCL\_CBET\_READ\_REQUEST|
|E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|
|E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE|
|Write Events|E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE|
|E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE|
|E\_ZCL\_CBET\_WRITE\_ATTRIBUTES|
|E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE|
|E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE|
|General Events|E\_ZCL\_CBET\_LOCK\_MUTEX|
|E\_ZCL\_CBET\_UNLOCK\_MUTEX|
|E\_ZCL\_CBET\_DEFAULT\_RESPONSE|
|E\_ZCL\_CBET\_UNHANDLED\_EVENT|
|E\_ZCL\_CBET\_ERROR|
|E\_ZCL\_CBET\_CLUSTER\_UPDATE|

The above events are described below.

## Input Events 

The ‘input events’ are generated externally to the ZCL. Such an event is received by the application, which wraps the event in a `tsZCL_CallBackEvent` structure and passes it into the ZCL using the function **vZCL\_EventHandler\(\)** - for further details of event processing, refer to [Section 3.2](processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38).

-   **E\_ZCL\_ZIGBEE\_EVENT**

    -   All ZigBee PRO stack events to be processed by the ZCL are designated as this type of event by setting the `eEventType` field in the `tsZCL_CallBackEvent` structure to E\_ZCL\_ZIGBEE\_EVENT.
-   **E\_ZCL\_CBET\_TIMER**

    -   A timer event \(indicating that a timer has expired\) which is to be processed by the ZCL is designated as this type of event by setting the `eEventType` field in the `tsZCL_CallBackEvent` structure to E\_ZCL\_CBET\_TIMER.
-   **E\_ZCL\_CBET\_TIMER\_MS**

    -   A millisecond timer event \(indicating that a timer has expired\) which is to be processed by the ZCL is designated as this type of event by setting the `eEventType` field in the `tsZCL_CallBackEvent` structure to E\_ZCL\_CBET\_TIMER\_MS.

## Read Events 

The ‘read events’ are generated as the result of a ‘read attributes’ request \(see [Section](../../ZCL_fundamentals/topics/reading_attributes.md#id_cc7e89d1-915c-4667-9cd9-85905a6d06ae)2.3.2\). Some of these events are generated on the remote node and some of them are generated on the local \(requesting\) node, as indicated in the table below.

|**Generated on local node \(client\):**|**Generated on remote node \(server\):**|
|---------------------------------------|----------------------------------------|
||E\_ZCL\_CBET\_READ\_REQUEST|
|E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE||
|E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE||

The circumstances surrounding the generation of the ‘read events’ are outlined below:

-   **E\_ZCL\_CBET\_READ\_REQUEST**

    -   When a ‘read attributes’ request has been received and passed to the ZCL \(as a stack event\), the ZCL generates the event E\_ZCL\_CBET\_READ\_REQUEST for the relevant endpoint to indicate that the endpoint’s shared device structure is going to be read. This gives an opportunity for the application to access the shared structure first, if required - for example, to update attribute values before they are read. This event may be ignored if the application reads the hardware asynchronously - for example, driven by a timer or interrupt.
-   **E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE**

    -   When a ‘read attributes’ response has been received by the requesting node and passed to the ZCL \(as a stack event\), the ZCL generates the event E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE for each individual attribute in the response. Details of the attribute are incorporated in the structure `tsZCL_ReadIndividualAttributesResponse`, described in [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1).
    -   Note that this event is often ignored by the application, while the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE \(see next event\) is handled.
-   **E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE**

    -   When a ‘read attributes’ response has been received by the requesting node and the ZCL has completed updating the local copy of the shared device structure, the ZCL generates the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE. The transaction sequence number and cluster instance fields of the `tsZCL_CallBackEvent` structure are used by this event.

## Write Events 

The ‘write events’ are generated as the result of a ‘write attributes’ request \(see [Section 2.3.3](../../ZCL_fundamentals/topics/writing_attributes.md#id_95e537b2-9aab-40dc-a755-cd593fe867b6)\). Some of these events are generated on the remote node and some of them are generated on the local \(requesting\) node, as indicated in the table below.

|**Generated on local node \(client\):**|**Generated on remote node \(server\):**|
|---------------------------------------|----------------------------------------|
||E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE|
||E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE|
||E\_ZCL\_CBET\_WRITE\_ATTRIBUTES|
|E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE||
|E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE||

During the process of receiving and processing a ‘write attributes’ request, the receiving application maintains a `tsZCL_IndividualAttributesResponse` structure for each individual attribute in the request:

```
typedef struct PACK {
uint16                  u16AttributeEnum;
teZCL_ZCLAttributeType  eAttributeDataType;
teZCL_CommandStatus     eAttributeStatus;
void                    *pvAttributeData;
tsZCL_AttributeStatus   *psAttributeStatus;
} tsZCL_IndividualAttributesResponse;
```

The `u16AttributeEnum` field identifies the attribute.

The field `eAttributeDataType` is set to the ZCL data type of the attribute in the request, which is checked by the ZCL to ensure that the attribute type in the request matches the expected attribute type.

The above structure is fully detailed in [Section 6.2](../../ZCL_structures/topics/event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1).

The circumstances surrounding the generation of the ‘write events’ are outlined below:

-   **E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE**

    When a ‘write attributes’ request has been received and passed to the ZCL \(as a stack event\), for each attribute in the request the ZCL generates the event E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE for the relevant endpoint. This indicates that a ‘write attributes’ request has arrived and gives an opportunity for the application to do either or both of the following:

    -   Check that the attribute value to be written falls within the valid range \(range checking is not performed in the ZCL because the range may depend on application-specific rules\).
    -   Decide whether the requested write access to the attribute in the shared structure is allowed or not allowed.
-   The value to be written is pointed to by `pvAttributeData` in the above structure \(this does not point to the field of the shared structure containing this attribute, as the shared structure field still has its existing value\).
-   The attribute status field `eAttributeStatus` in the above structure is initially set to E\_ZCL\_SUCCESS. The application should set this field to E\_ZCL\_ERR\_ATTRIBUTE\_RANGE if the attribute value is out-of-range or to E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS if it decides to disallow the write. Also note the following:
-   If a conventional ‘write attributes’ request is received and an attribute value fails the range check or write access to an attribute is denied, this attribute is left unchanged in the shared structure but other attributes are updated.
-   If an ‘undivided write attributes’ request is received and any attribute fails the range check or write access to any attribute is denied, no attribute values are updated in the shared structure.
-   **E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE**

    -   Following an attempt to write an attribute value to the shared structure, the ZCL generates the event E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE for the relevant endpoint. The field `eAttributeStatus` in the structure `tsZCL_IndividualAttributesResponse` indicates to the application whether the attribute value was updated successfully:
    -   If the write is successful, this status field is left as E\_ZCL\_SUCCESS.
    -   If the write is unsuccessful, this status field is set to a suitable error status \(see [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832)\).
-   **E\_ZCL\_CBET\_WRITE\_ATTRIBUTES**

    -   Once all the attributes in a ‘write attributes’ request have been processed, the ZCL generates the event E\_ZCL\_CBET\_WRITE\_ATTRIBUTES for the relevant endpoint.
-   **E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE**

    -   The E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event is generated for each attribute that is listed in an incoming ‘write attributes’ response message. Only attributes that have failed to be written are contained in the message. The field `eAttributeStatus` of the structure `tsZCL_IndividualAttributesResponse` indicates the reason for the failure \(see [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832)\).
-   **E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE**

    -   The E\_ZCL\_CBET\_WRITE\_ATTRIBUTES\_RESPONSE event is generated when the parsing of an incoming ‘write attributes’ response message is complete. This event is particularly useful following a write where all the attributes have been written without errors since, in this case, no E\_ZCL\_CBET\_WRITE\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE event is generated.

## General Events 

-   **E\_ZCL\_CBET\_LOCK\_MUTEX and E\_ZCL\_CBET\_UNLOCK\_MUTEX**

    -   When an application task accesses the shared device structure of an endpoint, a mutex should be used by the task to protect the shared structure from conflicting accesses. Thus, the ZCL may need to lock or unlock a mutex in handling an event - for example, when a "read attributes" request has been received and passed to the ZCL \(as a stack event\). In these circumstances, the ZCL generates the following events:
    -   E\_ZCL\_CBET\_LOCK\_MUTEX when a mutex is to be locked
    -   E\_ZCL\_CBET\_UNLOCK\_MUTEX when a mutex is to be unlocked
    -   The ZCL specifies one of the above events in invoking the callback function for the endpoint. Thus, the endpoint callback function must include the necessary code to lock and unlock a mutex - for further information, refer to [Appendix A.](../../appendix/topics/mutex_callbacks.md#id_3604e1a6-d753-4b1f-a7bb-2f6b4334e0d3)
    -   The locking and unlocking of a mutex are useful if the tasks in the application are non-cooperative while sharing the same resource. To optimize the code, the above events are not generated when the tasks are in a cooperative group. Tasks are cooperative by default and, if not required, this feature can be disabled in the **zcl\_options.h** file \(see [Section 1.3](../../ZCL_intro/topics/zcl_compile-time_options.md#id_9a025580-0b33-48c7-b195-7b3e004c4987)\).
-   **E\_ZCL\_CBET\_DEFAULT\_RESPONSE**

    -   The E\_ZCL\_CBET\_DEFAULT\_RESPONSE event is generated when a ZCL default response message has been received. These messages indicate that either an error has occurred or a message has been processed. The payload of the default response message is contained in the structure `tsZCL_DefaultResponseMessage` below:

```
typedef struct PACK {
    uint8         u8CommandId;
    uint8         u8StatusCode;
} tsZCL_DefaultResponseMessage;
```

-   `u8CommandId` is the ZCL command identifier of the command which triggered the default response message.
-   `u8StatusCode` is the status code from the default response message. It is set to 0x00 for OK or to an error code defined in the ZCL Specification.
-   **E\_ZCL\_CBET\_UNHANDLED\_EVENT and E\_ZCL\_CBET\_ERROR**
-   The E\_ZCL\_CBET\_UNHANDLED\_EVENT and E\_ZCL\_CBET\_ERROR events indicate that a stack message has been received which cannot be handled by the ZCL. The `*pZPSevent` field of the `tsZCL_CallBackEvent` structure points to the stack event that caused the event.
-   **E\_ZCL\_CBET\_CLUSTER\_UPDATE**
-   The E\_ZCL\_CBET\_CLUSTER\_UPDATE event indicates that one or more attribute values for a cluster on the local device may have changed.

**Note:** ZCL error events and default responses \(see [Section 6.1.9](../../ZCL_structures/topics/tszcl_defaultresponse.md#id_6adc0c37-aa71-4b92-9597-53c4af5d35e1)\) may be generated when problems occur in receiving commands. The possible ZCL status codes contained in the events and responses are detailed in [Section 4.2](../../ZCL_error_handling/topics/errorcommand_status_on_receiving_command.md#id_0f838bb9-eb56-4aea-a490-86160a9d244f).

**Parent topic:**[Event Handling](../../ZCL_event_handling/topics/event_handling.md)

