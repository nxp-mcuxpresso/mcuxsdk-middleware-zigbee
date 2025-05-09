# Configuring Heating and Cooling Setpoints

Functions are provided to update the following two optional attributes that are used to specify setpoints \(target temperatures\) for heating and cooling:

```
i16OccupiedHeatingSetpoint
i16OccupiedCoolingSetpoint

```

If both of these setpoints are used, the cooling setpoint value must be greater than the heating setpoint value. These attributes are fully detailed in [Section 33.2](thermostat_cluster_structure_and_attributes.md#id_2ef68b17-5921-48db-ba27-b9070b7f39e5).

These server attributes can be controlled remotely from a client using the function **eCLD\_ThermostatCommandSetpointRaiseOrLowerSend\(\)**, usually as the result of user input on a controlling device. This function is used on the client to send a SetpointRaiseOrLower command to the server to increase or decrease the value of one or both of these setpoint attributes by a specified amount. On receipt of this command, an E\_CLD\_THERMOSTAT\_CMD\_SETPOINT\_RAISE\_LOWER event is generated on the server to notify the server application.

The server application can modify the values of these attributes using the function **eCLD\_ThermostatSetAttribute\(\)**.

**Note:** These and other attributes of the Thermostat cluster can also be written and read using the general attribute access functions, as described in [Section 2.3](../../ZCL_fundamentals/topics/accessing_attributes.md#id_9f17ffc2-9472-40fa-9365-07ad9a0f505b).

**Parent topic:**[Thermostat Operations](../../thermostat_cluster/topics/thermostat_operations.md)

