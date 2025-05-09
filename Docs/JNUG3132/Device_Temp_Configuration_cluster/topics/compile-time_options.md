# Compile-time options

To enable the Device Temperature Configuration cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_DEVICE_TEMPERATURE_CONFIGURATION

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define DEVICE_TEMPERATURE_CONFIGURATION_CLIENT
#define DEVICE_TEMPERATURE_CONFIGURATION_SERVER

```

The Device Temperature Configuration cluster contains macros that may be optionally specified at compile time by adding some or all the following lines to the **zcl\_options.h** file.

## Optional Attributes 

Add this line to enable the optional Minimum Temperature Experienced attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_MIN_TEMP_EXPERIENCED

```

Add this line to enable the optional Maximum Temperature Experienced attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_MAX_TEMP_EXPERIENCED

```

Add this line to enable the optional Over Temperature Total attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_OVER_TEMP_TOTAL_DWELL

```

Add this line to enable the optional Temperature Alarm Mask attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_DEVICE_TEMP_ALARM_MASK

```

Add this line to enable the optional Low Temperature Threshold attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_THRESHOLD

```

Add this line to enable the optional High Temperature Threshold attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_THRESHOLD

```

Add this line to enable the optional Low Temperature Trip Point attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_LOW_TEMP_DWELL_TRIP_POINT

```

Add this line to enable the optional High Temperature Trip Point attribute:

```
#define CLD_DEVTEMPCFG_ATTR_ID_HIGH_TEMP_DWELL_TRIP_POINT

```

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_DEVTEMPCFG_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Device Temperature Configuration Cluster](../../Device_Temp_Configuration_cluster/topics/device_temperature_configuration_cluster.md)

