# tsZCL\_CommandDiscoveryResponse

This structure contains information about a Command Discovery response \(see [Section 2.9](../../ZCL_fundamentals/topics/command_discovery.md#id_49f32120-da2a-4a82-87b4-9f9f8cb1b193)\).

```
typedef struct
{
    bool_t bDiscoveryComplete;
    uint8  u8NumberOfCommands;
} tsZCL_CommandDiscoveryResponse;

```

Where:

-   `bDiscoveryComplete` is a Boolean flag which indicates whether the Command Discovery is complete, i.e. whether there are any commands remaining to be discovered:

    -   TRUE - all commands have been discovered

    -   FALSE - there are further commands to be discovered

-   `u8NumberOfCommands` is the number of discovered commands reported in the response \(the individual commands are reported in a structure of the type `tsZCL_CommandDiscoveryIndividualResponse` - see [Section 6.1.17](tszcl_commanddiscoveryindividualresponse.md#id_774223ee-162c-4f02-a046-ffba16728d4f)\)


The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_DISCOVER\_COMMAND\_RECEIVED\_RESPONSE or E\_ZCL\_CBET\_DISCOVER\_COMMAND\_GENERATED\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

