# Compile-time options

To enable the Analogue Output \(Basic\) cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_ANALOG_OUTPUT_BASIC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define ANALOG_OUTPUT_BASIC_CLIENT
#define ANALOG_OUTPUT_BASIC_SERVER

```

## Optional Attributes 

The optional attributes for the Analogue Output \(Basic\) cluster \(see [Section 19.2.2](analogue_output_basic_structure_and_attributes.md#id_faec7125-e579-40da-8886-6ecc29232249)\) are enabled by defining:

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_DESCRIPTION

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_MAX\_PRESENT\_VALUE

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_MIN\_PRESENT\_VALUE

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_RELIABILITY

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_RELINQUISH\_DEFAULT

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_RESOLUTION

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_ENGINEERING\_UNITS

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_APPLICATION\_TYPE

-   CLD\_ANALOG\_OUTPUT\_BASIC\_ATTR\_ATTRIBUTE\_REPORTING\_STATUS


## Global Attributes 

Add this line to enable the optional Attribute Reporting Status attribute:

```
#define CLD_ANALOG_OUTPUT_BASIC_ATTR_ID_ATTRIBUTE_REPORTING_STATUS

```

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_ANALOG_OUTPUT_BASIC_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Analogue Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/analogue_output_basic.md)

