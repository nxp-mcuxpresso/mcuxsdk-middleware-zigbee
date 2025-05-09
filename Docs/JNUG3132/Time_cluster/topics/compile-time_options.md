# Compile-time Options

To enable the Time cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_TIME

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define TIME_CLIENT
#define TIME_SERVER

```

The Time cluster contains macros that may be optionally specified at compile-time by adding some or all of the following lines to the **zcl\_options.h** file.

Add this line to enable the optional Time Zone attribute

```
#define CLD_TIME_ATTR_TIME_ZONE

```

Add this line to enable the optional DST Start attribute

```
#define CLD_TIME_ATTR_DST_START

```

Add this line to enable the optional DST End attribute

```
#define CLD_TIME_ATTR_DST_END

```

Add this line to enable the optional DST Shift attribute

```
#define CLD_TIME_ATTR_DST_SHIFT

```

Add this line to enable the optional Standard Time attribute

```
#define CLD_TIME_ATTR_STANDARD_TIME

```

Add this line to enable the optional Local Time attribute

```
#define CLD_TIME_ATTR_LOCAL_TIME

```

**Note:** Some attributes must always be enabled together - for example, if daylight saving is to be implemented then CLD\_TIME\_ATTR\_DST\_START, CLD\_TIME\_ATTR\_DST\_END and CLD\_TIME\_ATTR\_DST\_SHIFT must all be included in the **zcl\_options.h** file.

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_TIME_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

