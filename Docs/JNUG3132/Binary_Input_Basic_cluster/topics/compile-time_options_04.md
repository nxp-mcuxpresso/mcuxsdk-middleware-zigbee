# Compile-time options

To enable the Multistate Input \(Basic\) cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_MULTISTATE_INPUT_BASIC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define MULTISTATE_INPUT_BASIC_CLIENT
#define MULTISTATE_INPUT_BASIC_SERVER

```

## Optional Attributes 

The optional attributes for the Multistate Input \(Basic\) cluster \(see [Section 19.5.2](multistate_input_basic_structure_and_attributes.md#id_19185b2c-61a7-4dd7-b6c7-3149a44b02d5)\) are enabled by defining:

-   CLD\_MULTISTATE\_INPUT\_BASIC\_ATTR\_DESCRIPTION

-   CLD\_MULTISTATE\_INPUT\_BASIC\_ATTR\_RELIABILITY

-   CLD\_MULTISTATE\_INPUT\_BASIC\_ATTR\_APPLICATION\_TYPE

-   CLD\_MULTISTATE\_INPUT\_BASIC\_ATTR\_ATTRIBUTE\_REPORTING\_STATUS


## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_MULTISTATE_INPUT_BASIC_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_MULTISTATE_INPUT_BASIC_CLUSTER_REVISION <n>

```

The default value is `1`, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Multistate Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/multistate_input_basic.md)

