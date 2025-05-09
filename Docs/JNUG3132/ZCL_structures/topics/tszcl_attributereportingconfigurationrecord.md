# tsZCL\_AttributeReportingConfigurationRecord

This structure contains the configuration record for automatic reporting of an attribute.

```
typedef struct
{
    uint8                u8DirectionIsReceived;
    teZCL_ZCLAttributeType          eAttributeDataType;
    uint16                u16AttributeEnum;
    uint16                u16MinimumReportingInterval;
    uint16                u16MaximumReportingInterval;
    uint16                u16TimeoutPeriodField;
    tuZCL_AttributeReportable       uAttributeReportableChange;
} tsZCL_AttributeReportingConfigurationRecord;

```

Where:

-   `u8DirectionIsReceived` indicates whether the record configures how attribute reports can be received or sent:

    -   0x00: Configures how attribute reports are sent by the server - the following fields are included in the message payload:

        `eAttributeDataType`, `u16MinimumReportingInterval`, `u16MaximumReportingInterval`, `uAttributeReportableChange`

    -   0x01: Configures how attribute reports are received by the client - `u16TimeoutPeriodField` is included in the message payload.

-   `eAttributeDataType` indicates the data type of the attribute.

-   `u16AttributeEnum` is the identifier of the attribute to which the configuration record relates.

-   `u``16MinimumReportingInterval` is the minimum time-interval, in seconds, between consecutive reports for the attribute - the value 0x0000 indicates no minimum \(REPORTING\_MINIMUM\_LIMIT\_NONE\).

-   `u16MaximumReportingInterval` is the time-interval, in seconds, between consecutive reports for periodic reporting - the following special values can also be set:

    -   0x0000 indicates that periodic reporting is to be disabled for the attribute \(REPORTING\_MAXIMUM\_PERIODIC\_TURNED\_OFF\).

    -   0xFFFF indicates that automatic reporting is to be completely disabled for the attribute \(REPORTING\_MAXIMUM\_TURNED\_OFF\).

-   `u16TimeoutPeriodField` is the timeout value, in seconds, for an attribute report - if the time elapsed since the last report exceeds this value \(without receiving another report\), it may be assumed that there is a problem with the attribute reporting - the value 0x0000 indicates that no timeout will be applied \(REPORTS\_OF\_ATTRIBUTE\_NOT\_SUBJECT\_TO\_TIMEOUT\).

-   `uAttributeReportableChange` is the minimum change in the attribute value that causes an attribute report to be issued.


**Note:** For successful attribute reporting, the timeout on the receiving client must be set to a higher value than the maximum reporting interval for the attribute on the sending server.

**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

