# tsZCL\_AttributeDefinition

This structure defines an attribute used in a cluster:

```
struct tsZCL_AttributeDefinition
{
    uint16                  u16AttributeEnum;
    uint8                   u8AttributeFlags;
    teZCL_ZCLAttributeType  eAttributeDataType;
    uint16                  u16OffsetFromStructBase;
    uint16                  u16AttributeArrayLength;
};

```

Where:

-   `u16AttributeEnum` is the Attribute ID.

-   `u8AttributeFlags` is a 5-bit bitmap indicating the accessibility of the attribute \(for details of the access types, refer to [Section 2.3.1](../../ZCL_fundamentals/topics/attribute_access_permissions.md#id_b9c8257a-3935-4e57-a73d-26b186de0b60)\) - a bit is set to ‘1’ if the corresponding access type is supported, as follows:


|**Bit**|**Access Type**|
|-------|---------------|
|0|Read|
|1|Write|
|2|Reportable|
|3|Scene|
|4|Global|
|5-7|Reserved|

-   `eAttributeDataType` is the data type of the attribute - see [Section 7.1.3](../../ZCL_enums_codes/topics/attribute_types_tezcl_zclattributetype.md#id_dd8f72a9-26b2-4b1f-afdd-f6b47fd94abd).

-   `u16O``ffsetFromStructBase` is the offset of the attribute’s location from the start of the cluster.

-   `u16AttributeArrayLength` is the number of consecutive attributes of the same type.


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

