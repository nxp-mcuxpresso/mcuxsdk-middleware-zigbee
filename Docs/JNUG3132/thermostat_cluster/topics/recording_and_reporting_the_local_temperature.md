# Recording and Reporting the Local Temperature

A record of the local temperature is kept in the mandatory attribute `i16LocalTemperature` on the cluster server - this attribute is fully detailed in [Section 33.2](thermostat_cluster_structure_and_attributes.md#id_2ef68b17-5921-48db-ba27-b9070b7f39e5). The value of this attribute can be updated by the server application using the function **eCLD\_ThermostatSetAttribute\(\)** - for example, as the result of a local temperature measurement.

The value of the attribute `i16LocalTemperature` can be regularly reported to a cluster client - for example, to allow the local temperature to be displayed to the user. This automated reporting can be configured and started on the server using the function **eCLD\_ThermostatStartReportingLocalTemperature\(\)**. Reports is sent regularly, but not periodically - maximum and minimum time-intervals between consecutive reports can be specified.

**Parent topic:**[Thermostat Operations](../../thermostat_cluster/topics/thermostat_operations.md)

