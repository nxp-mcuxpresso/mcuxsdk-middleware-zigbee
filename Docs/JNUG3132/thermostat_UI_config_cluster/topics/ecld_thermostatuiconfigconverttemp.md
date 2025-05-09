# eCLD\_ThermostatUIConfigConvertTemp

```
teZCL_Status eCLD_ThermostatUIConfigConvertTemp(
     uint8 u8SourceEndPointId,
     bool bConvertCToF,
     int16 *pi16Temperature);

```

## Description 

This function can be used on a Thermostat UI Configuration cluster server to convert a temperature from units of Celsius to Fahrenheit or vice-versa \(the direction must be specified\). The temperature value to be converted is provided to the function as a pointer to a memory location where the input value is stored. This stored value is replaced with the converted temperature value by the function \(over-writing the input value\).

## Parameters 

-   *u8SourceEndPointId*: Number of the endpoint on which the Thermostat UI Configuration cluster resides
-   *bConvertCToF*: Direction of temperature conversion:
-   TRUE - Celsius to Fahrenheit
-   FALSE - Fahrenheit to Celsius
-   *pi16Temperature*: Pointer to location containing the temperature value to be converted. The converted temperature value is also output to this location by the function

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Functions](../../thermostat_UI_config_cluster/topics/functions.md)

