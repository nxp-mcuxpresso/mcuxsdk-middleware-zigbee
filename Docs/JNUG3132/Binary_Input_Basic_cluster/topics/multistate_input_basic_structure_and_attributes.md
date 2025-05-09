# Multistate Input \(Basic\) Structure and Attributes

The structure definition for the Multistate Input \(Basic\) cluster is:

```
typedef struct
{
#ifdef MULTISTATE_INPUT_BASIC_SERVER
#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_DESCRIPTION                
    tsZCL_CharacterString       sDescription;
    uint8                       au8Description[16];
#endif
    zuint16                     u16NumberOfStates;
    zbool                       bOutOfService;
    zuint16                     u16PresentValue;
#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_RELIABILITY
    zenum8                      u8Reliability;
#endif
    zbmap8                      u8StatusFlags;
#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_APPLICATION_TYPE
    zuint32                     u32ApplicationType;
#endif
#ifdef CLD_MULTISTATE_INPUT_BASIC_ATTR_ATTRIBUTE_REPORTING_STATUS
    zenum8                      u8AttributeReportingStatus;
#endif
#endif
    zuint16                     u16ClusterRevision;
} tsCLD_MultistateInputBasic;

```

-   The following optional pair of attributes are used to store a human readable description of the usage of the multistate input \(e.g. "Alarm Status"\):

    -   `sDescription` is a `tsZCL_CharacterString` structure \(see [Section](../../ZCL_structures/topics/tszcl_characterstring.md#id_cc588539-35ef-431b-9cc8-636b6feb992b)6.1.14\) for a string of up to 16 characters representing the description

    -   `au8Description[16]` is a byte-array which contains the character data bytes representing the description


`u16NumberOfStates` is a mandatory attribute which indicates the number of discrete states that the input can take.

-   `bOutOfService` is a mandatory attribute which indicates whether the multistate input is currently in or out of service:

    -   TRUE: Out of service

    -   FALSE In service

        -   If this attribute is set to TRUE, the `u16PresentValue` attribute is not updated to contain the current state of the input.
-   `u16PresentValue` is a mandatory attribute representing the latest state of the input \(this attribute is updated when the multistate input changes\).

    -   By default this attribute is read-only, but it becomes readable and writable when `bOutOfService` is set to TRUE.
-   `u8Reliability` is an optional attribute which indicates whether the value reported through `fPresentValue` is reliable or why it might be unreliable:

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_NO\_FAULT\_DETECTED

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_NO\_SENSOR

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_OVER\_RANGE

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_UNDER\_RANGE

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_OPEN\_LOOP

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_SHORTED\_LOOP

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_NO\_OUTPUT

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_UNRELIABLE\_OTHER

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_PROCESS\_ERROR

    -   E\_CLD\_MULTISTATE\_INPUT\_BASIC\_RELIABILITY\_MULTISTATE\_FAULT

-   `u8StatusFlags` is a mandatory attribute which is a bitmap representing the following status flags:


|**Bits**|**Name**|**Description**|
|--------|--------|---------------|
|0|In Alarm|Reserved - unused for Multistate Input \(Basic\) cluster|
|1|Fault|-   1: Optional attribute `u8Reliability` is used and does not have a value of NO\_FAULT\_DETECTED

-   0: Otherwise


|
|2|Overridden|-   1: Cluster has been over-ridden by a local mechanism

\(`fP``resentValue` and `u8Reliability` will not track input\)

-   0: Otherwise


|
|3|Out Of Service|-   1: Attribute `bOutOfService` is set to TRUE

-   0: Otherwise


|
|4-7|-|Reserved|

-   `u32ApplicationType` is an optional attribute that is a bitmap representing the application type, as follows:


|**Bits**|**Field Name**|**Description**|
|--------|--------------|---------------|
|0-15|Index|Specific application usage in terms of the states supported

 \(e.g. Off/On/Auto\). For the list of usages, refer to the attribute description in the ZCL Specification.

|
|16-23|Type|Application domain. For the Multistate Input cluster, this can only be is set to 0x00 \(HVAC\).|
|24-31|Group|Identifier for the cluster that this attribute is part of \(not the Clus-ter ID\). For the Multistate Input cluster, this is 0x0D.|

-   `u8AttributeReportingStatus` is an optional attribute that should be enabled when attribute reporting is used for the cluster \(see [Section 2.3.5](../../ZCL_fundamentals/topics/attribute_reporting.md#id_d3e2d682-d5e6-4aa5-870f-4d2e0320637e)\). The value of this attribute indicates whether there are attribute reports still pending \(0x00\) or the attribute reports are complete \(0x01\) - all other values are reserved. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of `1`. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Multistate Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/multistate_input_basic.md)

