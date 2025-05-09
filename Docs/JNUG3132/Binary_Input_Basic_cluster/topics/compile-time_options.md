# Compile-time Options

To enable the Analogue Input \(Basic\) cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_ANALOG_INPUT_BASIC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define ANALOG_INPUT_BASIC_CLIENT
#define ANALOG_INPUT_BASIC_SERVER

```

## Optional Attributes 

The optional attributes for the Analogue Input \(Basic\) cluster \(see [Section 19.1.2](analogue_input_basic_structure_and_attributes.md#id_967641e8-69ea-46e6-9766-a066d430e078)\) are enabled by defining:

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_DESCRIPTION

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_MAX\_PRESENT\_VALUE

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_MIN\_PRESENT\_VALUE

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_RELIABILITY

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_RESOLUTION

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_ENGINEERING\_UNITS

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_APPLICATION\_TYPE

-   CLD\_ANALOG\_INPUT\_BASIC\_ATTR\_ATTRIBUTE\_REPORTING\_STATUS


## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_ANALOG_INPUT_BASIC_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_ANALOG_INPUT_BASIC_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Analogue Input \(Basic\)](../../Binary_Input_Basic_cluster/topics/analogue_input_basic.md)

