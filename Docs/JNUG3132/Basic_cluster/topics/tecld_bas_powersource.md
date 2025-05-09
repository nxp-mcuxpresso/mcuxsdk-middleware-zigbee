# teCLD\_BAS\_PowerSource

The following enumerations are used in the Basic cluster to specify the power source for a device \(see above\):

```
typedef enum 
{
    E_CLD_BAS_PS_UNKNOWN = 0x00,
    E_CLD_BAS_PS_SINGLE_PHASE_MAINS,
    E_CLD_BAS_PS_THREE_PHASE_MAINS,
    E_CLD_BAS_PS_BATTERY,
    E_CLD_BAS_PS_DC_SOURCE,
    E_CLD_BAS_PS_EMERGENCY_MAINS_CONSTANTLY_POWERED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_AND_TRANSFER_SWITCH,
    E_CLD_BAS_PS_UNKNOWN_BATTERY_BACKED = 0x80,
    E_CLD_BAS_PS_SINGLE_PHASE_MAINS_BATTERY_BACKED,
    E_CLD_BAS_PS_THREE_PHASE_MAINS_BATTERY_BACKED,
    E_CLD_BAS_PS_BATTERY_BATTERY_BACKED,
    E_CLD_BAS_PS_DC_SOURCE_BATTERY_BACKED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_CONSTANTLY_POWERED_BATTERY_BACKED,
    E_CLD_BAS_PS_EMERGENCY_MAINS_AND_TRANSFER_SWITCH_BATTERY_BACKED,
} teCLD_BAS_PowerSource;

```

The power source enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_BAS\_PS\_UNKNOWN|Unknown power source|
|E\_CLD\_BAS\_PS\_SINGLE\_PHASE\_MAINS|Single-phase mains powered|
|E\_CLD\_BAS\_PS\_THREE\_PHASE\_MAINS|Three-phase mains powered|
|E\_CLD\_BAS\_PS\_BATTERY|Battery powered|
|E\_CLD\_BAS\_PS\_DC\_SOURCE|DC source|
|E\_CLD\_BAS\_PS\_EMERGENCY\_MAINS\_CONSTANTLY\_POWERED|Constantly powered from emergency mains supply|
|E\_CLD\_BAS\_PS\_EMERGENCY\_MAINS\_AND\_TRANSFER\_SWITCH|Powered from emergency mains supply via transfer switch|
|E\_CLD\_BAS\_PS\_UNKNOWN\_BATTERY\_BACKED|Unknown power source but battery back-up|
|E\_CLD\_BAS\_PS\_SINGLE\_PHASE\_MAINS\_BATTERY\_BACKED|Single-phase mains powered with battery back-up|
|E\_CLD\_BAS\_PS\_THREE\_PHASE\_MAINS\_BATTERY\_BACKED|Three-phase mains powered with battery back-up|
|E\_CLD\_BAS\_PS\_BATTERY\_BATTERY\_BACKED|Battery powered with battery back-up|
|E\_CLD\_BAS\_PS\_DC\_SOURCE\_BATTERY\_BACKED|DC source with battery back-up|
|E\_CLD\_BAS\_PS\_EMERGENCY\_MAINS\_CONSTANTLY\_POWERED\_BATTERY\_BACKED|Constantly powered from emergency mains supply with battery back-up|
|E\_CLD\_BAS\_PS\_EMERGENCY\_MAINS\_AND\_TRANSFER\_SWITCH\_BATTERY\_BACKED|Powered from emergency mains supply via transfer switch with battery back-up|

**Parent topic:**[Enumerations](../../Basic_cluster/topics/enumerations.md)

