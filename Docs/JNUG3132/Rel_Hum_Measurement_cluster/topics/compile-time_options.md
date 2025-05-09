# Compile-time Options

To enable the Relative Humidity Measurement cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_RELATIVE_HUMIDITY_MEASUREMENT

```

In addition, to include the software for a cluster client or server, it is necessary to add one of the following to the same file:

```
#define RELATIVE_HUMIDITY_MEASUREMENT_CLIENT
#define RELATIVE_HUMIDITY_MEASUREMENT_SERVER

```

## Optional Attribute 

Add this line to enable the optional Tolerance attribute:

```
#define CLD_RHMEAS_ATTR_TOLERANCE

```

## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_RHMEAS_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_RHMEAS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Relative Humidity Measurement Cluster](../../Rel_Hum_Measurement_cluster/topics/relative_humidity_measurement_cluster.md)

