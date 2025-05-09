# Analogue Input \(Basic\) Structure and Attributes

The structure definition for the Analogue Input \(Basic\) cluster is:

```
typedef struct
{
#ifdef ANALOG_INPUT_BASIC_SERVER
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_DESCRIPTION
    tsZCL_CharacterString       sDescription;
    zuint8    au8Description[16];
#endif
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_MAX_PRESENT_VALUE
    zsingle   fMaxPresentValue;
#endif
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_MIN_PRESENT_VALUE
    zsingle   fMinPresentValue;
#endif
    zbool     bOutOfService;
    zsingle   fPresentValue;
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_RELIABILITY
    zenum8    u8Reliability;
#endif
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_RESOLUTION
    zsingle   fResolution;
#endif
    zbmap8    u8StatusFlags;
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_ENGINEERING_UNITS
    zenum16   u16EngineeringUnits;
#endif
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32   u32ApplicationType;
#endif
#ifdef CLD_ANALOG_INPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8    u8AttributeReportingStatus;
#endif
#endif
    zuint16   u16ClusterRevision;
} tsCLD_AnalogInputBasic;

```

-   The following optional pair of attributes are used to store a human readable description of the usage of the analogue input \(for example, "Kitchen Temp"\):

    -   `sDescription` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters representing the description

    -   `au8Description[16]` is a byte-array which contains the character data bytes representing the description

    -   `fMaxPresentValue` is an optional attribute which indicates the highest analogue input value that can be reliably obtained and stored in the `fPresentValue` attribute.


-   `fMinPresentValue` is an optional attribute which indicates the lowest analogue input value that can be reliably obtained and stored in the `fPresentValue` attribute.

-   `bOutOfService` is a mandatory attribute which indicates whether the analogue input is currently in or out of service:

    -   TRUE: Out of service

    -   FALSE In service

        -   If this attribute is set to TRUE, the `fPresentValue` attribute will not be updated to contain the current value of the input.
-   `fPresentValue` is a mandatory attribute representing the latest analogue input value \(this attribute is updated when the analogue input is re-sampled\).

-   `u8Reliability` is an optional attribute which indicates whether the value reported through `fPresentValue` is reliable or why it might be unreliable:

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_NO\_FAULT\_DETECTED

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_NO\_SENSOR

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_OVER\_RANGE

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_UNDER\_RANGE

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_OPEN\_LOOP

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_SHORTED\_LOOP

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_NO\_OUTPUT

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_UNRELIABLE\_OTHER

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_PROCESS\_ERROR

    -   E\_CLD\_ANALOG\_INPUT\_BASIC\_RELIABILITY\_CONFIGURATION\_ERROR

-   `fResolution` is an optional attribute which indicates the smallest detectable change in the analogue input value that will result in an update of the attribute fPresentValue.


-   `u8StatusFlags` is a mandatory attribute which is a bitmap representing the following status flags:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|In Alarm|Reserved - unused for Analogue Input \(Basic\) cluster|
|1|Fault|-   1: Optional attribute `u8Reliability` is used and does not have a value of NO\_FAULT\_DETECTED

-   0: Otherwise


|
|2|Overridden|-   1: Cluster has been overridden by a local mechanism

\(`fP``resentValue` and `u8Reliability` will not track input\)

-   0: Otherwise


|
|3|Out Of Service|-   1: Attribute `bOutOfService` is set to TRUE

-   0: Otherwise


|
|4-7|-|Reserved|

-   `u16EngineeringUnits` is an optional attribute which indicates the physical unit of measure for the analogue input value recorded in the attribute `fPresentValue`. The values 0x0000 to 0x00FE are used to represent the units specified in Clause 21 of the BACnet standard. The value 0x00FF represents 'other' unit, and the values 0x0100 to 0xFFFF are for proprietary use. If the attribute `u32ApplicationType` is used and specifies an application type with an associated unit of measure, this unit will take precedence over the one specified in `u16EngineeringUnits`.

-   `u32ApplicationType` is an optional attribute which is a bitmap representing the application type, as follows:


|**Bits**|**Field Name**|**Description**|
|--------|--------------|---------------|
|0-15|Index|Specific application usage \(for example,Boiler Entering Temperature\). There is a set of possible usages for each value of Type \(see below\). For these lists, refer to the attribute description in the ZCL Specification.|
|16-23|Type|Physical quantity measured \(for example,Temperature\). For the Analogue Input cluster, this can be a value in the range 0x00 to 0x0E. For the corresponding quantities, refer to the attribute description in the ZCL Specification.|
|24-31|Group|Identifier for the cluster that this attribute is part of \(not the Cluster ID\). For the Analogue Input cluster, this is 0x00.|

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Analogue Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/analogue_input_basic.md)

