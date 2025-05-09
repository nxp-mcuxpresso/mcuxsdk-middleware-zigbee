# tsZCL\_AttributeDiscoveryExtendedResponse

This structure contains details of an attribute reported in a ‘discover attributes extended’ response. It is contained in a ZCL event of type E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_EXTENDED\_RESPONSE.

```
typedef struct
{
    bool_t                  bDiscoveryComplete;
    uint16                  u16AttributeEnum;
    teZCL_ZCLAttributeType  eAttributeDataType;
    uint8                   u8AttributeFlags;
}tsZCL_AttributeDiscoveryExtendedResponse;

```

where:

-   `bDiscoveryComplete` indicates whether this is the final attribute from a ‘discover attributes’ to be reported:

    -   TRUE - final attribute

    -   FALSE - not final attribute

-   `u16AttributeEnum` is the identifier of the attribute being reported

-   `eAttributeDataType` indicates the data type of the attribute being reported \(see [Section 7.1.3](../../ZCL_enums_codes/topics/attribute_types_tezcl_zclattributetype.md#id_dd8f72a9-26b2-4b1f-afdd-f6b47fd94abd)\)

-   `u8AttributeFlags` is a 5-bit bitmap indicating the accessibility of the reported attribute \(for details of the access types, refer to [Section 2.3.1](../../ZCL_fundamentals/topics/attribute_access_permissions.md#id_b9c8257a-3935-4e57-a73d-26b186de0b60)\) - a bit is set to ‘1’ if the corresponding access type is supported, as follows:


|**Bit**|**Access Type**|
|-------|---------------|
|0|Read|
|1|Write|
|2|Reportable|
|3|Scene|
|4|Global|
|5-7|Reserved|

The above structure is contained in the `tsZCL_CallBackEvent` event structure, detailed in [Section 6.2](event_structure_tszcl_callbackevent.md#id_c6231189-b132-4d5f-a3a5-ba46823a55c1), when the field `eEventType` is set to E\_ZCL\_CBET\_DISCOVER\_INDIVIDUAL\_ATTRIBUTE\_EXTENDED\_RESPONSE.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

