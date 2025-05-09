# tsZCL\_CommandDiscoveryIndividualResponse

This structure contains information about an individual command reported in a Command Discovery response \(see [Section 2.9](../../ZCL_fundamentals/topics/command_discovery.md#id_49f32120-da2a-4a82-87b4-9f9f8cb1b193)\).

```
typedef struct
{
    uint8  u8CommandEnum;
    uint8  u8CommandIndex;
} tsZCL_CommandDiscoveryIndividualResponse;

```

where:

-   `u8CommandEnum` is the Command ID of the reported command

-   `u8CommandIndex` is the index of the reported command in the response payload


The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_COMMAND\_RECEIVED\_RESPONSE or E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_COMMAND\_GENERATED\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

