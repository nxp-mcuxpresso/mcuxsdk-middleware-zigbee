# eCLD\_ThermostatSetAttribute

```
teZCL_Status eCLD_ThermostatSetAttribute(
    uint8 u8SourceEndPointId,
    uint8 u8AttributeId,
    int16 i16AttributeValue);

```

## Description 

This function can be used on a Thermostat cluster server to update the Thermostat attributes - specifically to write a value to one of the following attributes:

```
i16LocalTemperature
i16OccupiedCoolingSetpoint
i16OccupiedHeatingSetpoint

```

The function first checks whether the value to be written falls within the valid range for the relevant attribute. If not, it returns with status E\_ZCL\_ERR\_INVALID\_VALUE. If the server attempts to write to an attribute other than those specified above, the function returns with status E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS. If the cluster does not exist, it returns with status E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND.

## Parameters 

-   *u8SourceEndPointId*        Number of the endpoint on which the Thermostat cluster resides
-   *u8AttributeId*         Identifier of attribute to be updated, one of:
-           E\_CLD\_THERMOSTAT\_ATTR\_ID\_LOCAL\_TEMPERATURE
-   E\_CLD\_THERMOSTAT\_ATTR\_ID\_OCCUPIED\_COOLING\_SETPOINT
-   E\_CLD\_THERMOSTAT\_ATTR\_ID\_OCCUPIED\_HEATING\_SETPOINT
-   *i16AttributeValue*        Value to be written to attribute

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Functions](../../thermostat_cluster/topics/functions.md)

