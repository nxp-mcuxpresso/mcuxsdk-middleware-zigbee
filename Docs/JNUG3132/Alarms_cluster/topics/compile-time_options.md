# Compile-Time Options

To enable the Alarms cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_ALARMS

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define ALARMS_CLIENT
#define ALARMS_SERVER

```

The Alarms cluster contains macros that may be optionally specified at compile time by adding one or more of the following lines to the **zcl\_options.h** file.

To enable the optional Alarm Count attribute, add this line:

```
#define CLD_ALARMS_ATTR_ALARM_COUNT

```

To set the maximum number of entries in the Alarms table on the server, add this line:

```
#define CLD_ALARMS_MAX_NUMBER_OF_ALARMS n

```

where n is the maximum to be set.

To define the value \(n\) of the Cluster Revision attribute, add this line:

```
#define CLD_ALARMS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

