# Compile-time options

This section describes the compile-time options that may be enabled in the **zcl\_options.h** file of an application that uses the Electrical Measurement cluster.

To enable the Electrical Measurement cluster in the code to be built, it is necessary to add the following line to the file:

```
#define CLD_ELECTRICAL_MEASUREMENT

```

In addition, to enable the cluster as a client or server, it is also necessary to add one of the following lines to the same file:

```
#define ELECTRICAL_MEASUREMENT_SERVER
#define ELECTRICAL_MEASUREMENT_CLIENT

```

## Optional Attributes 

The optional attributes for the Electrical Measurement cluster \(see [Section 30.2](cluster_structure_and_attributes.md#id_ab865248-0ff3-4f63-94bd-dd14a8edf2ac)\) are enabled by defining:

-   CLD\_ELECTMEAS\_ATTR\_AC\_FREQUENCY

-   CLD\_ELECTMEAS\_ATTR\_RMS\_VOLTAGE

-   CLD\_ELECTMEAS\_ATTR\_RMS\_CURRENT

-   CLD\_ELECTMEAS\_ATTR\_ACTIVE\_POWER

-   CLD\_ELECTMEAS\_ATTR\_REACTIVE\_POWER

-   CLD\_ELECTMEAS\_ATTR\_APPARENT\_POWER

-   CLD\_ELECTMEAS\_ATTR\_POWER\_FACTOR

-   CLD\_ELECTMEAS\_ATTR\_AC\_VOLTAGE\_MULTIPLIER

-   CLD\_ELECTMEAS\_ATTR\_AC\_VOLTAGE\_DIVISOR

-   CLD\_ELECTMEAS\_ATTR\_AC\_CURRENT\_MULTIPLIER

-   CLD\_ELECTMEAS\_ATTR\_AC\_CURRENT\_DIVISOR

-   CLD\_ELECTMEAS\_ATTR\_AC\_POWER\_MULTIPLIER

-   CLD\_ELECTMEAS\_ATTR\_AC\_POWER\_DIVISOR

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_APPARENT\_POWER

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_NON\_ACTIVE\_POWER

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_FNDMTL\_REACTIVE\_POWER

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_FNDMTL\_APPARENT\_POWER

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_FNDMTL\_POWER\_FACTOR

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_NON\_FNDMTL\_APPARENT\_POWER

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_TOTAL\_HARMONIC\_DISTORTION

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_VBIAS

-   CLD\_ELECTMEAS\_ATTR\_MAN\_SPEC\_DIVISOR


## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_APPLIANCE_STATISTICS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Electrical Measurement Cluster](../../electrical_measurement_cluster/topics/electrical_measurement_cluster.md)

