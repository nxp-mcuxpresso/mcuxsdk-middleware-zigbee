# Compile-time options

Before a ZigBee 3.0 application is built, configure compile-time options in the header file **zcl\_options.h** for the application.

**Note:**

1.  Cluster-specific compile-time options are detailed in the cluster descriptions in the *ZCL User Guide \(JNUG3132\)*.
2.  In addition, set compile-time options for the ZigBee Base Device in the file **bdb\_options.h** - see [Section 2.10](compile-time_options_001.md).

## Number of Endpoints 

An application must specify the highest numbered endpoint used by it - for example:

```
#define BDB_FB_NUMBER_OF_ENDPOINTS3

```

Normally, the endpoints starting at endpoint 1 are for application use, so the above case uses endpoints 1 to 3. It is possible, however, to use the lower numbered endpoints for non-application purposes, for example, to run other protocols on endpoints 1 and 2, and the application on endpoint 3. With `BDB_FB_NUMBER_OF_ENDPOINTS` set to 3, some storage is statically allocated for endpoints 1 and 2 but never used. Note that this define applies only to local endpoints - the application can refer to remote endpoints with numbers beyond the locally defined value of `BDB_FB_NUMBER_OF_ENDPOINTS`.

## Manufacturer Code 

The ZCL allows a manufacturer code to define devices developed by a certain manufacturer. The value allocated to a manufacturer by the ZigBee Alliance is a 16-bit and is set as follows:

```
#define ZCL_MANUFACTURER_CODE 0x1037

```

The above example sets the manufacturer code to the default value of 0x1037 \(which belongs to NXP\) but manufacturers should set their own allocated value.

## Enabled Clusters 

Enable all the required clusters in the options header file. For example, an application for an On/Off Light device that uses all the possible clusters requires the following definitions:

```
#define CLD_BASIC
#define CLD_IDENTIFY
#define CLD_GROUPS
#define CLD_SCENES
#define CLD_ONOFF

```

## Server and Client options 

Many clusters have options that indicate whether the cluster acts as a server or a client on the local device. If the cluster is enabled using one of the above definitions, define the server/client status of the cluster. For example, to employ the Groups cluster as a server, include the following in the header file:

```
#define GROUPS_SERVER

```

## Support for attribute Read/Write 
Compile read/write access to cluster attributes into the application explicitly. Separately enable the server and client sides of a cluster using the following macros in the options header file:

```
#define ZCL_ATTRIBUTE_READ_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_READ_CLIENT_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_WRITE_CLIENT_SUPPORTED

```

Each of the above definitions applies to all clusters used in the application.

## Optional attributes 

Many clusters have optional attributes that may enable at compile time via the options header file - for example, the Basic cluster ‘`application version`’ attribute is enabled as follows:

```
#define CLD_BAS_ATTR_APPLICATION_VERSION

```

**Parent topic:**[Introduction](../topics/introduction.md)

