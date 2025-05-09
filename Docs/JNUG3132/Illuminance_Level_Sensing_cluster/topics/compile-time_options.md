# Compile-time Options

To enable the Illuminance Level Sensing cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_ILLUMINANCE_LEVEL_SENSING

```

In addition, to include the software for a cluster client or server, it is necessary to add one of the following to the same file:

```
#define ILLUMINANCE_LEVEL_SENSING_CLIENT
#define ILLUMINANCE_LEVEL_SENSING_SERVER

```

## Optional Attribute 

Add this line to enable the optional Light Sensor Type attribute:

```
#define E_CLD_ILS_ATTR_ID_LIGHT_SENSOR_TYPE

```

## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_ILS_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_ILS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Illuminance Level Sensing Cluster](../../Illuminance_Level_Sensing_cluster/topics/illuminance_level_sensing_cluster.md)

