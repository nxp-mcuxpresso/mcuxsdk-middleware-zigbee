# Compile-time options

To enable the Fan Control cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_FAN_CONTROL

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define FAN_CONTROL_CLIENT
#define FAN_CONTROL_SERVER

```

**Parent topic:**[Fan Control Cluster](../../Fan_Control_cluster/topics/fan_control_cluster.md)

