# ‘Criticality Level’ Enumerations

The criticality levels that are available for an LCE are enumerated in the `teSE_DRLCCriticalityLevels` structure below:

```
typedef enum
{
    E_SE_DRLC_RESERVED_0_CRITICALITY = 0x00,
    E_SE_DRLC_GREEN_CRITICALITY,
    E_SE_DRLC_VOLUNTARY_1_CRITICALITY,
    E_SE_DRLC_VOLUNTARY_2_CRITICALITY,
    E_SE_DRLC_VOLUNTARY_3_CRITICALITY,
    E_SE_DRLC_VOLUNTARY_4_CRITICALITY,
    E_SE_DRLC_VOLUNTARY_5_CRITICALITY,
    E_SE_DRLC_EMERGENCY_CRITICALITY,
    E_SE_DRLC_PLANNED_OUTAGE_CRITICALITY,
    E_SE_DRLC_SERVICE_DISCONNECT_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_1_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_2_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_3_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_4_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_5_CRITICALITY,
    E_SE_DRLC_UTILITY_DEFINED_6_CRITICALITY,
    E_SE_DRLC_FIRST_RESERVED_CRITICALITY
} teSE_DRLCCriticalityLevels;

```

The above criticality levels are described in the table below.

|**Criticality Level Enumeration**|**Description**|
|---------------------------------|---------------|
|E\_SE\_DRLC\_RESERVED\_0\_CRITICALITY|Reserved for future use|
|E\_SE\_DRLC\_GREEN\_CRITICALITY|**Green:** Indicates that there will be a significant contribution from non-green sources during the LCE - participation in the LCE is voluntary|
|E\_SE\_DRLC\_VOLUNTARY\_1\_CRITICALITY|**Voluntary 1-6:** Represent increasing levels of load reduction as move through levels 1 to 6, as defined by the utility company - intended to be used in a sequence of LCEs to gradually reduce loads, where participation in the LCEs is voluntary|
|E\_SE\_DRLC\_VOLUNTARY\_2\_CRITICALITY|
|E\_SE\_DRLC\_VOLUNTARY\_3\_CRITICALITY|
|E\_SE\_DRLC\_VOLUNTARY\_4\_CRITICALITY|
|E\_SE\_DRLC\_VOLUNTARY\_5\_CRITICALITY|
|E\_SE\_DRLC\_EMERGENCY\_CRITICALITY|**Emergency:** Indicates that the LCE represents an emergency situation \(normally demanding the termination of all non-essential loads, as defined by the utility company\) - participation in the LCE is mandatory|
|E\_SE\_DRLC\_PLANNED\_OUTAGE\_CRITICALITY|**Planned Outage:** Indicates that the LCE represents an intentional outage \(normally demanding the termination of all non-essential loads, as defined by the utility company\) - participation in the LCE is mandatory|
|E\_SE\_DRLC\_SERVICE\_DISCONNECT\_CRITICALITY|**Service Disconnect:** Indicates that the LCE represents a service disconnection \(normally demanding the termination of all non-essential loads, as defined by the utility company\) - participation in the LCE is mandatory|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_1\_CRITICALITY|**Utility-defined 1-6:** Criticality levels completely defined by the utility company - participation in the LCE is voluntary|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_2\_CRITICALITY|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_3\_CRITICALITY|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_4\_CRITICALITY|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_5\_CRITICALITY|
|E\_SE\_DRLC\_UTILITY\_DEFINED\_6\_CRITICALITY|
|E\_SE\_DRLC\_FIRST\_RESERVED\_CRITICALITY|Reserved for future use|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

