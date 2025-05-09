# tsZCL\_AttributeReportingConfigurationResponse

This structure contains information from a ‘configure reporting’ response.

```
typedef struct
{
    teZCL_CommandStatus  eCommandStatus;
    tsZCL_AttributeReportingConfigurationRecord
                  sAttributeReportingConfigurationRecord;
}tsZCL_AttributeReportingConfigurationResponse;

```

Where:

-   `eCommandStatus` is an enumeration representing the status from the response \(see [Section 7.1.4](../../ZCL_enums_codes/topics/command_status_tezcl_commandstatus.md#id_6d04a321-4eed-4358-989a-b7a0c5505832)\).

-   `sAttributeReportingConfigurationRecord` is a configuration record structure \(see [Section 6.1.5](tszcl_attributereportingconfigurationrecord.md#id_c2f733a8-402b-4ac2-8298-0af54d2ca2fd)\), but only the fields `u16AttributeEnum` and `u8DirectionIsReceived` are used in the response.


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

