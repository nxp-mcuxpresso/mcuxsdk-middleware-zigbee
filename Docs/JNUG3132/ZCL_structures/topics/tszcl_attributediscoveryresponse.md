# tsZCL\_AttributeDiscoveryResponse

This structure contains details of an attribute reported in a ‘discover attributes’ response. It is contained in a ZCL event of type E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE.

```
typedef struct
{
    bool_t                bDiscoveryComplete;
    uint16                u16AttributeEnum;
     teZCL_ZCLAttributeType          eAttributeDataType;
} tsZCL_AttributeDiscoveryResponse;

```

where:

-   `bDiscoveryComplete` indicates whether this is the final attribute from a ‘discover attributes’ to be reported:

    -   TRUE - final attribute

    -   FALSE - not final attribute

-   `u16AttributeEnum` is the identifier of the attribute being reported

-   `eAttributeDataType` indicates the data type of the attribute being reported \(see [Section 7.1.3](../../ZCL_enums_codes/topics/attribute_types_tezcl_zclattributetype.md#id_dd8f72a9-26b2-4b1f-afdd-f6b47fd94abd)\)


The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

