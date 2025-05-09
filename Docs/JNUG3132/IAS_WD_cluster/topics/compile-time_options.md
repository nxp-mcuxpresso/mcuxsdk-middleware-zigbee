# Compile-time Options

To enable the IAS WD cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_IASWD

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one of the following to the same file:

```
#define IASWD_SERVER
#define IASWD_CLIENT

```

The IAS WD cluster contains macros that may be specified at compile-time by adding one or more of the following lines to the **zcl\_options.h** file.

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_IASWD_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[IAS Warning Device Cluster](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md)

