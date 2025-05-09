# Compile-time options

To enable the Basic cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_BASIC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define BASIC_CLIENT
#define BASIC_SERVER

```

The Basic cluster contains macros that may be optionally specified at compile-time by adding some or all of the following lines to the **zcl\_options.h** file.

## Optional Attributes 

Add this line to enable the optional Application Version attribute:

```
#define   CLD_BAS_ATTR_APPLICATION_VERSION

```

Add this line to enable the optional Stack Version attribute:

```
#define   CLD_BAS_ATTR_STACK_VERSION

```

Add this line to enable the optional Hardware Version attribute:

```
#define   CLD_BAS_ATTR_HARDWARE_VERSION

```

Add this line to enable the optional Manufacturer Name attribute:

```
#define   CLD_BAS_ATTR_MANUFACTURER_NAME

```

Add this line to enable the optional Model Identifier attribute:

```
#define   CLD_BAS_ATTR_MODEL_IDENTIFIER

```

Add this line to enable the optional Date Code attribute:

```
#define   CLD_BAS_ATTR_DATE_CODE

```

Add this line to enable the optional Generic Class Device attribute:

```
#define CLD_BAS_ATTR_GENERIC_DEVICE_CLASS

```

Add this line to enable the optional Generic Device Type attribute:

```
#define CLD_BAS_ATTR_GENERIC_DEVICE_TYPE

```

Add this line to enable the optional Product Code attribute:

```
#define CLD_BAS_ATTR_PRODUCT_CODE

```

Add this line to enable the optional Product URL attribute:

```
#define CLD_BAS_ATTR_PRODUCT_URL

```

Add this line to enable the optional Location Description attribute:

```
#define   CLD_BAS_ATTR_LOCATION_DESCRIPTION

```

Add this line to enable the optional Physical Environment attribute:

```
#define   CLD_BAS_ATTR_PHYSICAL_ENVIRONMENT

```

Add this line to enable the optional Device Enabled attribute:

```
#define   CLD_BAS_ATTR_DEVICE_ENABLED

```

Add this line to enable the optional Alarm Mask attribute:

```
#define   CLD_BAS_ATTR_ALARM_MASK

```

Add this line to enable the optional Disable Local Config attribute:

```
#define   CLD_BAS_ATTR_DISABLE_LOCAL_CONFIG

```

Add this line to enable the optional Software Build ID attribute:

```
#define   CLD_BAS_ATTR_SW_BUILD_ID

```

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_BAS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Optional Commands 

Add this line to enable the optional Reset To Factory Defaults command on the client and server:

```
#define CLD_BAS_CMD_RESET_TO_FACTORY_DEFAULTS

```

## Product Code Length 

The default length of the product code contained in the attributes `sProductCode` and `au8ProductCode[]` can be defined by adding the following line:

```
#define CLD_BAS_PCODE_SIZE <n>

```

where `<n>` is the default number characters in the product code.

The maximum length of the product code contained in the attributes `sProductCode` and `au8ProductCode[]` can be defined by adding the following line:

```
#define CLD_BASIC_MAX_NUMBER_OF_BYTES_PRODUCT_CODE <n>

```

where `<n>` is the maximum number characters in the product code.

## Product URL Length 

The default length of the product URL contained in the attributes `sProductURL` and `au8ProductURL[]` can be defined by adding the following line:

```
#define CLD_BAS_URL_SIZE <n>

```

where `<n>` is the default number characters in the product URL.

The maximum length of the product URL contained in the attributes `sProductURL` and `au8ProductURL[]` can be defined by adding the following line:

```
#define CLD_BASIC_MAX_NUMBER_OF_BYTES_PRODUCT_URL <n>

```

where `<n>` is the maximum number characters in the product URL.

**Parent topic:**[Basic Cluster](../../Basic_cluster/topics/basic_cluster.md)

