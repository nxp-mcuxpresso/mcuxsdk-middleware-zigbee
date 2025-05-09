# tsZCL\_IndividualAttributesResponse

This structure is contained in a ZCL event of type E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE \(see [Section](event_structure_tszcl_callbackevent.md#id_c4305c06-afe0-4b8a-952a-40536e816bab)\):

```
typedef struct PACK {
    uint16               u16AttributeEnum;
    teZCL_ZCLAttributeType         eAttributeDataType;
    teZCL_CommandStatus          eAttributeStatus;
    void               *pvAttributeData;
} tsZCL_IndividualAttributesResponse;

```

Where:

-   `u16AttributeEnum` identifies the attribute that has been read \(the relevant enumerations are listed in the ‘Enumerations’ section of each cluster-specific chapter\).

-   `eAttributeDataType` is the ZCL data type of the read attribute \(see [Section 7.1.3](../../ZCL_enums_codes/topics/attribute_types_tezcl_zclattributetype.md#id_dd8f72a9-26b2-4b1f-afdd-f6b47fd94abd)\).

-   `eAttributeStatus` is the status of the read operation \(0x00 for success or an error code - see [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832) for enumerations\).

-   `pvAttributeData` is a pointer to the read attribute data which \(if the read was successful\) has been inserted by the ZCL into the shared device structure.


The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_READ\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

