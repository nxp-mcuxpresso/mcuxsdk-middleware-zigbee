# Compile-time options

To enable the On/Off Switch Configuration cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_OOSC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define OOSC_CLIENT
#define OOSC_SERVER

```

To define the value \(n\) of the Cluster Revision attribute, add this line:

```
#define CLD_OOSC_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[On/Off Switch Configuration Cluster](../../OnOff_Switch_Config_cluster/topics/onoff_switch_configuration_cluster.md)

