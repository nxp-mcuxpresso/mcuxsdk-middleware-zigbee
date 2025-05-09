# Compile-time Options

This section describes the compile-time options that may be configured in the **zcl\_options.h** file of an application that uses the Power Profile cluster.

To enable the Power Profile cluster in the code to be built, it is necessary to add the following line to the file:

```
#define CLD_PP

```

In addition, to enable the cluster as a client or server, it is also necessary to add one of the following lines to the same file:

```
#define PP_SERVER
#define PP_CLIENT

```

The following options can also be configured at compile-time in the **zcl\_options.h** file.

## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_PP_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_PP_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Enabling ‘Get Power Profile Price’ Command 

The optional ‘Get Power Profile Price’ command can be enabled by adding:

```
#define CLD_PP_CMD_GET_POWER_PROFILE_PRICE

```

## Enabling ‘Get Power Profile Price Extended’ Command 

The optional ‘Get Power Profile Price Extended’ command can be enabled by adding:

```
#define CLD_PP_CMD_GET_POWER_PROFILE_PRICE_EXTENDED

```

## Enable ‘Get Overall Schedule Price’ Command 

The optional ‘Get Overall Schedule Price’ command can be enabled by adding:

```
#define CLD_PP_CMD_GET_OVERALL_SCHEDULE_PRICE

```

## Number of Power Profiles 

The number of power profiles on the local device can be defined as `n` by adding:

```
#define CLD_PP_NUM_OF_PROFILES n

```

## Maximum Number of Energy Phases 

The maximum number of energy phases in a power profile can be defined as `n` by adding:

```
#define CLD_PP_NUM_OF_ENERGY_PHASES n

```

By default, this value is 3.

## Disabling APS Acknowledgments for Bound Transmissions 

APS acknowledgements for bound transmissions from this cluster can be disabled by adding:

```
#define CLD_PP_BOUND_TX_WITH_APS_ACK_DISABLED

```

**Parent topic:**[Power Profile Cluster](../../power_profile_cluster/topics/power_profile_cluster.md)

