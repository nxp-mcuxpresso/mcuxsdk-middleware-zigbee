# Zone Parameters

The following structure is used to store the ‘zone parameters’ on the IAS ACE cluster server.

```
typedef struct
{
    zbmap8                        u8ZoneConfigFlag;
    zbmap8                        u8ZoneStatusFlag;
    zbmap16                       eZoneStatus;
    zenum8                        eAudibleNotification;
    tsZCL_CharacterString         sZoneLabel;
    uint8                                   
          au8ZoneLabel[CLD_IASACE_MAX_LENGTH_ZONE_LABEL];
    tsZCL_CharacterString         sArmDisarmCode;
    uint8                                   
          au8ArmDisarmCode[CLD_IASACE_MAX_LENGTH_ARM_DISARM_CODE];
}tsCLD_IASACE_ZoneParameter;

```

where:

-   `u8ZoneConfigFlag` is is a bitmap used to configure the temporal role of a zone \(as Day, Night or Day/Night\) and whether the zone is allowed to be bypassed. Macros are provided as follows:


|**Bit**|**Macro**|
|-------|---------|
|0|CLD\_IASACE\_ZONE\_CONFIG\_FLAG\_BYPASS \*|
|1|CLD\_IASACE\_ZONE\_CONFIG\_FLAG\_DAY\_HOME|
|2|CLD\_IASACE\_ZONE\_CONFIG\_FLAG\_NIGHT\_SLEEP|
|3|CLD\_IASACE\_ZONE\_CONFIG\_FLAG\_NOT\_BYPASSED \*\*|
|4-7|Reserved|

-   \* Determines whether the zone is allowed to be bypassed: 1 - allowed, 0 - not allowed
-   \*\* Used to configure a status of ZONE\_NOT\_BYPASSED in responses to Bypass commands
-   `u8ZoneStatusFlag` is a bitmap used to indicate the current status of a zone as armed or bypassed. Macros are provided as follows:

|**Bit**|**Macro**|
|-------|---------|
|0|CLD\_IASACE\_ZONE\_STATUS\_FLAG\_BYPASS|
|1|CLD\_IASACE\_ZONE\_STATUS\_FLAG\_ARM|
|2-7|Reserved|

-   `e``ZoneStatus` is the zone status as the value of the `b16ZoneStatus` attribute of the IAS Zone cluster \(see [Section 37.2](../../IAS_Zone_cluster/topics/ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

-   `eAudibleNotification` is a value specifying whether an audible notification \(e.g. a chime\) is required to signal a zone status change \(enumerations are available in `teCLD_IASACE_AudibleNotification` - see [Section 38.8.4](tecld_iasace_audiblenotification.md#id_3be77966-a0dd-4c6d-8068-4b85a3d9a4ee)\):


|**Value**|**Status**|
|---------|----------|
|0x00|Audible notification muted|
|0x01|Audible notification sounded|
|0x02 - 0xFF|Reserved|

-   `sZoneLabel` is the name/label for the zone represented as a character string

-   `au8ZoneLabel[]` is the name/label for the zone represented as an array of ASCII values

-   `sArmDisarmCode` is the arm/disarm code for the zone represented as a character string

-   `au8ArmDisarmCode[]` is the arm/disarm code for the zone represented as an array of ASCII values


**Parent topic:**[Structures](../../IAS_ACE_cluster/topics/structures.md)

