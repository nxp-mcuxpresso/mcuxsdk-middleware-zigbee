# ‘LCE Data Modification’ Enumerations

The load control data items that can be locally modified in an LCE are enumerated in the `teSE_DRLCUserEventSet` structure below:

```
typedef enum PACK
{
    E_SE_DRLC_CRITICALITY_LEVEL_APPLIED =0x00,
    E_SE_DRLC_COOLING_TEMPERATURE_SET_POINT_APPLIED,
    E_SE_DRLC_HEATING_TEMPERATURE_SET_POINT_APPLIED,
    E_SE_DRLC_AVERAGE_LOAD_ADJUSTMENT_PERCENTAGE_APPLIED,
    E_SE_DRLC_DUTY_CYCLE_APPLIED,
    E_SE_DRLC_USER_EVENT_ENUM_END,
} teSE_DRLCUserEventSet;

```

The above options are described in the table below \(the data items are fully described in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1)\).

|**LCE Participation Enumeration**|**Description**|
|---------------------------------|---------------|
|E\_SE\_DRLC\_CRITICALITY\_LEVEL\_APPLIED|Specifies that ‘criticality level’ is to be modified.|
|E\_SE\_DRLC\_COOLING\_TEMPERATURE\_SET\_POINT\_APPLIED|Specifies that ‘cooling temperature set-point’ is to be modified|
|E\_SE\_DRLC\_HEATING\_TEMPERATURE\_SET\_POINT\_APPLIED|Specifies that ‘heating temperature set-point’ is to be modified|
|E\_SE\_DRLC\_AVERAGE\_LOAD\_ADJUSTMENT\_PERCENTAGE\_APPLIED|Specifies that ‘average load adjustment percentage’ is to be modified|
|E\_SE\_DRLC\_DUTY\_CYCLE\_APPLIED|Specifies that ‘duty cycle’ is to be modified|

**Parent topic:**[Enumerations](../../DRLC_cluster/topics/enumerations.md)

