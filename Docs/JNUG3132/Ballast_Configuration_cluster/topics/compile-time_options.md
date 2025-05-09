# Compile-time options

To enable the Ballast Configuration cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_BALLASTCONFIGURATION

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define BALLASTCONFIGURATION_CLIENT
#define BALLASTCONFIGURATION_SERVER

```

The Ballast Configuration cluster contains macros that may be optionally specified at compile-time by adding some or all the following lines to the **zcl\_options.h** file.

## Optional Attributes 

Add this line to enable the optional Physical Minimum Level attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MIN_LEVEL

```

Add this line to enable the optional Physical Maximum Level attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_PHYSICAL_MAX_LEVEL

```

Add this line to enable the optional Ballast Status attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_BALLAST_STATUS

```

Add this line to enable the optional Minimum Level attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_MIN_LEVEL

```

Add this line to enable the optional Maximum Level attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_MAX_LEVEL

```

Add this line to enable the optional Power-on Level attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_LEVEL

```

Add this line to enable the optional Power-on Fade Time attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_POWER_ON_FADE_TIME

```

Add this line to enable the optional Intrinsic Ballast Factor attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_INTRINSIC_BALLAST_FACTOR

```

Add this line to enable the optional Ballast Factor Adjustment attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_BALLAST_FACTOR_ADJUSTMENT

```

Add this line to enable the optional Lamp Quantity attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_QUANTITY

```

Add this line to enable the optional Lamp Type attributes:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_TYPE

```

Add this line to enable the optional Lamp Manufacturer attributes:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_MANUFACTURER

```

Add this line to enable the optional Lamp Rated Hours attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_MANUFACTURER

```

Add this line to enable the optional Lamp Burn Hours attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS

```

Add this line to enable the optional Lamp Alarm Mode attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_ALARM_MODE

```

Add this line to enable the optional Lamp Burn Hours Trip Point attribute:

```
#define E_CLD_BALLASTCONFIGURATION_ATTR_LAMP_BURN_HOURS_TRIP_POINT

```

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_BALLASTCONFIGURATION_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Ballast Configuration Cluster](../../Ballast_Configuration_cluster/topics/ballast_configuration_cluster.md)

