# Binary Output \(Basic\) Structure and Attributes

The structure definition for the Binary Output \(Basic\) cluster is:

```
typedef struct
{
#ifdef BINARY_OUTPUT_BASIC_SERVER
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ACTIVE_TEXT
    tsZCL_CharacterString       sActiveText;
    uint8                       au8ActiveText[16];
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_DESCRIPTION                
    tsZCL_CharacterString       sDescription;
    uint8                       au8Description[16];
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_INACTIVE_TEXT
    tsZCL_CharacterString       sInactiveText;
    uint8                       au8InactiveText[16];
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_OFF_TIME
    zuint32                     u32MinimumOffTime;
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_MINIMUM_ON_TIME
    zuint32                     u32MinimumOnTime;
#endif
    zbool                       bOutOfService;
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_POLARITY
    zenum8                      u8Polarity;
#endif
    zbool                       bPresentValue;
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELIABILITY
    zenum8                      u8Reliability;
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_RELINQUISH_DEFAULT
    zbool                       bRelinquishDefault;
#endif
    zbmap8                      u8StatusFlags;
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32                     u32ApplicationType;
#endif
#ifdef CLD_BINARY_OUTPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                      u8AttributeReportingStatus;
#endif
#endif
    zuint16                     u16ClusterRevision;
} tsCLD_BinaryOutputBasic;

```

-   The following optional pair of attributes are used to store a human readable description of the active state of a binary output \(e.g. "Open Window 3"\):

    -   `sActiveText` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters representing the description

    -   `au8ActiveText[16]` is a byte-array which contains the character data bytes representing the description

        -   If these attributes are used, the ‘Inactive Text’ attributes must also be used.
-   The following optional pair of attributes are used to store a human readable description of the usage of the binary output \(e.g. "Control Window 3"\):

    -   `sDescription` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters representing the description

    -   `au8Description[16]` is a byte-array which contains the character data bytes representing the description

-   The following optional pair of attributes are used to store a human readable description of the inactive state of a binary output \(e.g. "Close Window 3"\):

    -   `sInactiveText` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters representing the description

    -   `au8InactiveText[16]` is a byte-array which contains the character data bytes representing the description

        -   If these attributes are used, the ‘Active Text’ attributes must also be used.

`u32MinimumOffTime` is an optional attribute which represents the minimum time, in seconds, for which the binary output will remain in the inactive state \(0\).

-   `u32MinimumOnTime` is an optional attribute which represents the minimum time, in seconds, for which the binary output will remain in the active state \(1\).

-   `bOutOfService` is a mandatory attribute which indicates whether the binary output is currently in or out of service:

    -   TRUE: Out of service

    -   FALSE: In service

        -   If this attribute is set to TRUE, the `bPresentValue` attribute will not be used to control the binary output.
-   `u8Polarity` is an optional attribute which indicates the relationship between the value of the `bPresentValue` attribute and the physical state of the output:

    -   E\_CLD\_ BINARY\_OUTPUT\_BASIC\_POLARITY\_NORMAL \(0x00\): The active \(1\) state of `bPresentValue` corresponds to the active/on state of the physical output

    -   E\_CLD\_ BINARY\_OUTPUT\_BASIC\_POLARITY\_REVERSE \(0x01\): The active \(1\) state of `bPresentValue` corresponds to the inactive/off state of the physical output

-   `bPresentValue` is a mandatory attribute representing the current state of the binary output \(this attribute is updated by the application\):

    -   TRUE: Output is in the ‘active’ state

    -   FALSE: Output is in the ‘inactive’ state

        -   The interpretation `bPresentValue` in relation to the physical state of the output is determined by the setting of the `u8Polarity` attribute.
-   `u8Reliability` is an optional attribute which indicates whether the value contained in `bPresentValue` is reliable or why it might be unreliable:

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_NO\_FAULT\_DETECTED

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_OVER\_RANGE

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_UNDER\_RANGE

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_OPEN\_LOOP

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_SHORTED\_LOOP

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_UNRELIABLE\_OTHER

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_PROCESS\_ERROR

    -   E\_CLD\_BINARY\_OUTPUT\_BASIC\_RELIABILITY\_CONFIGURATION\_ERROR


`fRelinquishDefault` is an optional attribute representing the default value to be used for `bPresentValue` when the supplied value is invalid.

-   `u8StatusFlags` is a mandatory attribute which is a bitmap representing the following status flags:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|In Alarm|Reserved - unused for Binary Output \(Basic\) cluster|
|1|Fault|-   1: Optional attribute `u8Reliability` is used and does not have a value of NO\_FAULT\_DETECTED

-   0: Otherwise


|
|2|Overridden|-   1: Cluster has been over-ridden by a local mechanism

\(`bPresentValue` and `u8Reliability` will not track input\)

-   0: Otherwise


|
|3|Out Of Service|-   1: Attribute `bOutOfService` is set to TRUE

-   0: Otherwise


|
|4-7|-|Reserved|

-   `u32ApplicationType` is an optional attribute which is a bitmap representing the application type, as follows:


|**Bits**|**Field Name**|**Description**|
|--------|--------------|---------------|
|0-15|Index|Specific application usage \(e.g. Heating Valve\). There is a set of possible usages for each value of Type \(see below\). For these lists, refer to the attribute description in the ZCL Specification.|
|16-23|Type|Application domain. For the Basic Output cluster, this can be set to 0x00 \(HVAC\) or 0x01 \(Security\).|
|24-31|Group|Identifier for the cluster that this attribute is part of \(not the Clus-ter ID\). For the Binary Output \(Basic\) cluster, this is 0x04.|

```
u8AttributeReportingStatus is an optional attribute that should be enabled when attribute reporting is used for the cluster (see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)). The value of this attribute indicates whether there are attribute reports still pending (0x00) or the attribute reports are complete (0x01) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
u16ClusterRevision is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

```

**Parent topic:**[Binary Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/binary_output_basic.md)

