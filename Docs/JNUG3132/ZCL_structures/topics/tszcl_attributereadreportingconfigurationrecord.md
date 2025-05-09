# tsZCL\_AttributeReadReportingConfigurationRecord

This structure contains the details of a reporting configuration query for one attribute, to be included in a ‘read reporting configuration’ command:

```
typedef struct
{
    uint8      u8DirectionIsReceived;
    uint16     u16AttributeEnum;
} tsZCL_AttributeReadReportingConfigurationRecord;

```

Where:

-   `u8DirectionIsReceived` specifies whether the required reporting configuration information details how the attribute reports are received or sent.

    -   0x00: Specifies that required information details how a report is sent by the server.

    -   0x01: Specifies that required information details how a report is received by the client.

-   `u16AttributeEnum` is the identifier of the attribute to which the required reporting configuration information relates.


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

