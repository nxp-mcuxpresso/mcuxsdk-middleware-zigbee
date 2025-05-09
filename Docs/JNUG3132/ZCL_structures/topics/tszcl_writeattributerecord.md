# tsZCL\_WriteAttributeRecord

The is structure contains the details for a ‘write attribute’ operation.

```
typedef struct
{
           teZCL_ZCLAttributeType   eAttributeDataType;  
           uint16                   u16AttributeEnum;
           uint8                                                                   *pu8AttributeData;
}tsZCL_WriteAttributeRecord;

```

Where:

-   `eAttributeDataType` is an enumeration indicating the attribute data type \(for the enumerations, refer to [Section 7.1.3](../../ZCL_enums_codes/topics/attribute_types_tezcl_zclattributetype.md#id_dd8f72a9-26b2-4b1f-afdd-f6b47fd94abd)\).

-   `u16AttributeEnum` is an enumeration for the attribute identifier \(for the relevant ‘Attribute ID’ enumerations, refer to the ‘Enumerations’ section of each cluster-specific chapter\).

-   `pu8AttributeData` is a pointer to the attribute data to be written.


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

