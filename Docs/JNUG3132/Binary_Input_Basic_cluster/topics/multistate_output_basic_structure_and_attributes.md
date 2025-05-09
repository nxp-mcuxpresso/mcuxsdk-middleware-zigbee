# Multistate Output \(Basic\) Structure and Attributes

The structure definition for the Multistate Output \(Basic\) cluster is:

```
typedef struct
{
#ifdef MULTISTATE_OUTPUT_BASIC_SERVER    
#ifdef CLD_MULTISTATE_OUTPUT_BASIC_ATTR_DESCRIPTION         
    tsZCL_CharacterString       sDescription;
    uint8                      au8Description[16];
#endif
    zuint16                     u16NumberOfStates;
    zbool                      bOutOfService;
    zuint16                     u16PresentValue;
#ifdef CLD_MULTISTATE_OUTPUT_BASIC_ATTR_RELIABILITY
    zenum8                    u8Reliability;
#endif
#ifdef CLD_MULTISTATE_OUTPUT_BASIC_ATTR_RELINQUISH_DEFAULT
    zuint16                   u16RelinquishDefault;
#endif
    zbmap8                    u8StatusFlags;
#ifdef CLD_MULTISTATE_OUTPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32                    u32ApplicationType;
#endif
#ifdef CLD_MULTISTATE_OUTPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                    u8AttributeReportingStatus;
#endif
#endif
    zuint16                u16ClusterRevision;
} tsCLD_MultistateOutputBasic;

```

-   The following optional pairs of attributes are used to store a human readable description of the usage of the multistate output \(for example "Alarm State"\):

    -   `sDescription` is a `tsZCL_CharacterString` structure \(see [Section 6.1.14](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)\) for a string of up to 16 characters representing the description

    -   `au8Description[16]` is a byte-array which contains the character data bytes representing the description.


-   `u16NumberOfStates` is a mandatory attribute that indicates the number of discrete states that the output can take.
-   `bOutOfService` is a mandatory attribute that indicates whether the multistate output is in or out of service currently:

    -   TRUE: Out of service

    -   FALSE: In service

        -   If this attribute is set to TRUE, the `u16PresentValue` attribute is not used to control the multistate output.
-   `u16PresentValue` is a mandatory attribute representing the latest multistate output value \(this attribute is used to control the physical output\).

-   `u8Reliability` is an optional attribute that indicates whether the value contained in `u16PresentValue` is reliable or why it might be unreliable:

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_NO_FAULT_DETECTED`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_OVER_RANGE`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_UNDER_RANGE`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_OPEN_LOOP`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_SHORTED_LOOP`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_UNRELIABLE_OTHER`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_PROCESS_ERROR`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_MULTISTATE_FAULT`

    -   `E_CLD_MULTISTATE_OUTPUT_BASIC_RELIABILITY_CONFIGURATION_ERROR`


-   `fRelinquishDefault` is an optional attribute representing the default value to be used for `u16PresentValue` when the supplied value is invalid.
-   `u8StatusFlags` is a mandatory attribute, which is a bitmap representing the following status flags:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|In Alarm|Reserved - unused for Multistate Output \(Basic\) cluster|
|1|Fault|-   1: Optional attribute `u8Reliability` is used and does not have a value of `NO_FAULT_DETECTED`

-   0: Otherwise


|
|2|Overridden|-   1: Cluster has been over-ridden by a local mechanism

\(`u16P``resentValue` and `u8Reliability` do not track input\)

-   0: Otherwise


|
|3|Out Of Service|-   1: Attribute `bOutOfService` is set to TRUE

-   0: Otherwise


|
|4-7|-|Reserved|

-   `u32ApplicationType` is an optional attribute which is a bitmap representing the application type, as follows:


|**Bits**|**Field Name**|**Description**|
|--------|--------------|---------------|
|0-15|Index|Specific application usage in terms of the states supported

 \(for example, Off/On/Auto\). For the list of usages, refer to the attribute description in the ZCL Specification.

|
|16-23|Type|Application domain. For the Multistate Output cluster, this field can only be set to 0x00 \(HVAC\).|
|24-31|Group|Identifier for the cluster that this attribute is part of \(not the Cluster ID\). For the Multistate Output cluster, this is 0x0E.|

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Multistate Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/multistate_output_basic.md)

