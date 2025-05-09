# ‘Temperature Display Mode’ Enumerations

The following enumerations are used to set the optional attribute `eTemperatureDisplayMode` in the Thermostat UI Configuration cluster structure `tsCLD_ThermostatUIConfig`.

```
typedef enum 
{
  E_CLD_THERMOSTAT_UI_CONFIG_TEMPERATURE_DISPLAY_MODE_CELSIUS = 0x00,
  E_CLD_THERMOSTAT_UI_CONFIG_TEMPERATURE_DISPLAY_MODE_FAHRENHEIT
} teCLD_ThermostatUIConfig_TemperatureDisplay;

```

The above enumerations represent the units of temperature available to display temperature on the screen of the user interface and are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_THERMOSTAT\_UI\_CONFIG\_TEMPERATURE\_DISPLAY\_MODE\_CELSIUS|Display temperature in Celsius|
|E\_CLD\_THERMOSTAT\_UI\_CONFIG\_TEMPERATURE\_DISPLAY\_MODE\_FAHRENHEIT|Display temperature in Fahrenheit|

**Parent topic:**[Enumerations](../../thermostat_UI_config_cluster/topics/enumerations.md)

