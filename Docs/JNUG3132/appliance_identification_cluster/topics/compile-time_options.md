# Compile-time options

This section describes the compile-time options that may be enabled in the **zcl\_options.h** file of an application that uses the Appliance Identification cluster.

To enable the Appliance Identification cluster in the code to be built, it is necessary to add the following line to the file:

```
#define CLD_APPLIANCE_IDENTIFICATION

```

In addition, to enable the cluster as a client or server, it is also necessary to add one of the following lines to the same file:

```
#define APPLIANCE_IDENTIFICATION_SERVER
#define APPLIANCE_IDENTIFICATION_CLIENT

```

The Appliance Identification cluster contains macros that may be optionally specified at compile-time by adding one or more of the following lines to the **zcl\_options.h** file.

## Optional Attributes 

Add this line to enable the optional Company Name attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_COMPANY_NAME

```

Add this line to enable the optional Company ID attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_COMPANY_ID

```

Add this line to enable the optional Brand Name attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_BRAND_NAME

```

Add this line to enable the optional Brand ID attribute:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_BRAND_ID

```

Add this line to enable the optional Model attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_MODEL

```

Add this line to enable the optional Part Number attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_PART_NUMBER

```

Add this line to enable the optional Product Revision attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_REVISION

```

Add this line to enable the optional Software Revision attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_SOFTWARE_REVISION

```

Add this line to enable the optional Product Type Name attributes:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_TYPE_NAME

```

Add this line to enable the optional Product Type ID attribute:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_PRODUCT_TYPE_ID

```

Add this line to enable the optional CECED Specification Version attribute:

```
#define CLD_APPLIANCE_IDENTIFICATION_ATTR_CECED_SPEC_VERSION

```

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_APPLIANCE_IDENTIFICATION_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Appliance Identification Cluster](../../appliance_identification_cluster/topics/appliance_identification_cluster.md)

