# Cluster structure and attributes

The Thermostat UI Configuration cluster is contained in the following `tsCLD_ThermostatUIConfig` structure:

```
typedef struct
{
#ifdef THERMOSTAT_UI_CONFIG_SERVER    
    zenum8         eTemperatureDisplayMode;  
    zenum8         eKeypadLockout;
#endif
    zuint16        u16ClusterRevision;
} tsCLD_ThermostatUIConfig;;

```

where:

-   `eTemperatureDisplayMode` specifies the units \(Celsius or Fahrenheit\) used to display temperature on the screen of the user interface. Enumerations are provided:

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_TEMPERATURE\_DISPLAY\_MODE\_CELSIUS

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_TEMPERATURE\_DISPLAY\_MODE\_FAHRENHEIT

-   `eKeypadLockout` specifies the level of functionality that is available via the keypad of the user interface. Enumerations are provided:

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_NO\_LOCKOUT

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_LEVEL\_1\_LOCKOUT

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_LEVEL\_2\_LOCKOUT

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_LEVEL\_3\_LOCKOUT

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_LEVEL\_4\_LOCKOUT

    -   E\_CLD\_THERMOSTAT\_UI\_CONFIG\_KEYPAD\_LOCKOUT\_LEVEL\_5\_LOCKOUT

        -   The functionality of each level is manufacturer-defined but level 5 represents the minimum functionality.
-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).

**Parent topic:**[Thermostat UI Configuration Cluster](../../thermostat_UI_config_cluster/topics/thermostat_ui_configuration_cluster.md)

