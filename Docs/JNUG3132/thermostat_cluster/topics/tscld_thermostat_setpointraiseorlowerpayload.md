# tsCLD\_Thermostat\_SetpointRaiseOrLowerPayload

This stucture contains the payload of a ‘Setpoint Raise Or Lower’ command \(from the cluster client\) which requests a change the value of the attribute `i16OccupiedHeatingSetpoint` and/or the attribute `i16OccupiedCoolingSetpoint`.

```
typedef struct
{
    zenum8                 eMode;
    zint8                  i8Amount;
}tsCLD_Thermostat_SetpointRaiseOrLowerPayload;

```

where:

-   `eMode` indicates the Thermostat operating mode to which the command relates, one of:

    -   E\_CLD\_THERMOSTAT\_SRLM\_HEAT \(Heating\)

    -   E\_CLD\_THERMOSTAT\_SRLM\_COOL \(Cooling\)

    -   E\_CLD\_THERMOSTAT\_SRLM\_BOTH \(Heating and Cooling\)

-   `i8Amount` represents the value \(in two’s complement form\) by which the setpoint corresponding to the specified operating mode is to be changed


**Parent topic:**[Structures](../../thermostat_cluster/topics/structures.md)

