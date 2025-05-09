# ZCL Compile-time Options

Before the application can be built, the ZCL compile-time options must be configured in the header file **zcl\_options.h** for the application.

## Enabled Clusters 

All required clusters must be enabled in the options header file. For example, to enable the Basic and Time clusters, the following lines are required:

```
#define CLD_BASIC
#define CLD_TIME

```

In addition, to include the software for a cluster client or server or both, it is necessary to select them in the options header file. For example, to select the Basic cluster client and server, the following lines are required:

```
#define BASIC_CLIENT
#define BASIC_SERVER

```

## Support for Attribute Read/Write 

Read/write access to cluster attributes must be explicitly compiled into the application, and must be enabled separately for the server and client sides of a cluster using the following macros in the options header file:

```
#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_CLIENT_SUPPORTED

```

Each of the above definitions apply to all clusters used in the application.

**Tip:** If only read access to attributes is required, then it is recommended not to enable write access. This is because omitting the write options gives the benefit of a reduced application size.

## Optional Attributes 

Many clusters have optional attributes that may be enabled at compile-time via the options header file - for example, to enable the Time Zone attribute in the Time cluster:

```
#define E_CLD_TIME_ATTR_TIME_ZONE

```

**Note:** Cluster-specific compile-time options are described in detail in the chapters for the individual clusters. The attribute reporting feature also has its own compile-time options \(see [Appendix B.3.1](../../appendix/topics/compile-time_options.md#id_84f10234-23ce-42f7-a567-f5415e76352a)\).

## Number of Endpoints 

The following line can be added to set the number of endpoints supported on a node \(to n\):

```
#define ZCL_NUMBER_OF_ENDPOINTS  n

```

The default value is 1.

## Default Responses 

The following line can be added to enable default responses \(see [Section 2.5](../../ZCL_fundamentals/topics/default_responses.md#id_8a92ceef-63d4-47f2-89e2-6a53f4167395)\):

```
#define ZCL_DISABLE_DEFAULT_RESPONSES 

```

By default, they are disabled.

## APS Acknowledgements 

The following line can be added to enable APS acknowledgments:

```
#define ZCL_DISABLE_APS_ACK

```

By default, they are disabled.

## Cooperative Tasks 

By default, tasks within the application are cooperative, and events will therefore not be generated for locking and unlocking mutexes for resources that are shared between the tasks. To disable the cooperative task feature, add the following line:

```
#undefine COOPERATIVE

```

Note that this requires an undefine.

## Parameter Checking 

Parameter checking in various functions can be enabled by including the following line:

```
#define STRICT_PARAM_CHECK

```

This feature is useful for testing during application development. When the testing is complete, the option should be disabled to eliminate the checks and to save code memory. This option can be defined in the **zcl\_options.h** file or the makefile.

## ‘Wild Card’ Profile 

Commands with a ‘wild card’ application profile \(Profile ID of 0xFFFF\) can be accepted and processed by the receiving device by including the following line:

```
#define ZCL_ALLOW_WILD_CARD_PROFILE 

```

**Parent topic:**[ZigBee Cluster Library \(ZCL\)](../../ZCL_intro/topics/zigbee_cluster_library_zcl.md)

