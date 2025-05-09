# ‘Operating Capabilities’ Enumerations

The following enumerations are used to set the optional attribute `eControlSequenceOfOperation` in the Thermostat cluster structure `tsCLD_Thermostat`.

```
typedef enum 
{
    E_CLD_THERMOSTAT_CSOO_COOLING_ONLY = 0x00,
    E_CLD_THERMOSTAT_CSOO_COOLING_WITH_REHEAT,
    E_CLD_THERMOSTAT_CSOO_HEATING_ONLY,
    E_CLD_THERMOSTAT_CSOO_HEATING_WITH_REHEAT,
    E_CLD_THERMOSTAT_CSOO_COOLING_AND_HEATING_4_PIPES,
    E_CLD_THERMOSTAT_CSOO_COOLING_AND_HEATING_4_PIPES_WITH_REHEAT,
}teCLD_Thermostat_ControlSequenceOfOperation;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_THERMOSTAT\_CSOO\_COOLING\_ONLY|Heat and Emergency Heating are not

 possible

|
|E\_CLD\_THERMOSTAT\_CSOO\_COOLING\_WITH\_REHEAT|Heat and Emergency Heating are not

 possible

|
|E\_CLD\_THERMOSTAT\_CSOO\_HEATING\_ONLY|Cool and Pre-cooling are not possible|
|E\_CLD\_THERMOSTAT\_CSOO\_HEATING\_WITH\_REHEAT|Cool and Pre-cooling are not possible|
|E\_CLD\_THERMOSTAT\_CSOO\_COOLING\_AND\_HEATING\_

 4\_PIPES

|All modes are possible|
|E\_CLD\_THERMOSTAT\_CSOO\_COOLING\_AND\_HEATING\_

 4\_PIPES\_WITH\_REHEAT

|All modes are possible|

**Parent topic:**[Enumerations](../../thermostat_cluster/topics/enumerations.md)

