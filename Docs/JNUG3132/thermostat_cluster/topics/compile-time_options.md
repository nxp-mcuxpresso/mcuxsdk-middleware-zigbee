# Compile-time options

To enable the Thermostat cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_THERMOSTAT

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define THERMOSTAT_SERVER
#define THERMOSTAT_CLIENT

```

## Optional Attributes 

The optional attributes for the Thermostat cluster \(see [Section 33.2](thermostat_cluster_structure_and_attributes.md#id_2ef68b17-5921-48db-ba27-b9070b7f39e5)\) are enabled by defining:

-   CLD\_THERMOSTAT\_ATTR\_ID\_LOCAL\_TEMPERATURE

-   CLD\_THERMOSTAT\_ATTR\_ID\_OUTDOOR\_TEMPERATURE

-   CLD\_THERMOSTAT\_ATTR\_ID\_OCCUPANCY

-   CLD\_THERMOSTAT\_ATTR\_ID\_ABS\_MIN\_HEAT\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_ABS\_MAX\_HEAT\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_ABS\_MIN\_COOL\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_ABS\_MAX\_COOL\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_PI\_COOLING\_DEMAND

-   CLD\_THERMOSTAT\_ATTR\_ID\_PI\_HEATING\_DEMAND

-   CLD\_THERMOSTAT\_ATTR\_ID\_LOCAL\_TEMPERATURE\_CALIBRATION

-   CLD\_THERMOSTAT\_ATTR\_ID\_OCCUPIED\_COOLING\_SETPOINT

-   CLD\_THERMOSTAT\_ATTR\_ID\_OCCUPIED\_HEATING\_SETPOINT

-   CLD\_THERMOSTAT\_ATTR\_ID\_UNOCCUPIED\_COOLING\_SETPOINT

-   CLD\_THERMOSTAT\_ATTR\_ID\_UNOCCUPIED\_HEATING\_SETPOINT

-   CLD\_THERMOSTAT\_ATTR\_ID\_MIN\_HEAT\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_MAX\_HEAT\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_MIN\_COOL\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_MAX\_COOL\_SETPOINT\_LIMIT

-   CLD\_THERMOSTAT\_ATTR\_ID\_MIN\_SETPOINT\_DEAD\_BAND

-   CLD\_THERMOSTAT\_ATTR\_ID\_REMOTE\_SENSING

-   CLD\_THERMOSTAT\_ATTR\_ID\_CONTROL\_SEQUENCE\_OF\_OPERATION

-   CLD\_THERMOSTAT\_ATTR\_ID\_SYSTEM\_MODE

-   CLD\_THERMOSTAT\_ATTR\_ID\_ALARM\_MASK


## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_THERMOSTAT_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_THERMOSTAT_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Minimum Cooling Setpoint 

The value of the attribute `i16MinCoolSetpointLimit` can be set as follows:

```
#define CLD_THERMOSTAT_MIN_COOLING_SETPOINT         n

```

where n is the value to be set \(in two’s complement form\). The default value is 0x954D.

## Maximum Cooling Setpoint 

The value of the attribute `i16MaxCoolSetpointLimit` can be set as follows:

```
#define CLD_THERMOSTAT_MAX_COOLING_SETPOINT n

```

where n is the value to be set \(in two’s complement form\). The default value is 0x7FFF.

## Minimum Heating Setpoint 

The value of the attribute `i16MinHeatSetpointLimit` can be set as follows:

```
#define CLD_THERMOSTAT_MIN_HEATING_SETPOINT n

```

where n is the value to be set \(in two’s complement form\). The default value is 0x954D.

## Maximum Heating Setpoint 

The value of the attribute `i16MaxHeatSetpointLimit` can be set as follows:

```
#define CLD_THERMOSTAT_MAX_HEATING_SETPOINT n

```

        where n is the value to be set \(in two’s complement form\). The default value is 0x7FFF.

**Parent topic:**[Thermostat Cluster](../../thermostat_cluster/topics/thermostat_cluster.md)

