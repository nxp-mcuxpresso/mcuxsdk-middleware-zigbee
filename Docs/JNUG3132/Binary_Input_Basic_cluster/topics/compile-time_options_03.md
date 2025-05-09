# Compile-time options

To enable the Binary Output \(Basic\) cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_BINARY_OUTPUT_BASIC

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define BINARY_OUTPUT_BASIC_CLIENT
#define BINARY_OUTPUT_BASIC_SERVER

```

## Optional Attributes 

The optional attributes for the Binary Output \(Basic\) cluster \(see [Section 19.4.2](binary_output_basic_structure_and_attributes.md#id_02215436-44b7-465f-a8f9-ffd02c25195d)\) are enabled by defining:

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_ACTIVE\_TEXT

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_DESCRIPTION

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_INACTIVE\_TEXT

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_MINIMUM\_OFF\_TIME

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_MINIMUM\_ON\_TIME

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_POLARITY

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_RELIABILITY

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_RELINQUISH\_DEFAULT

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_APPLICATION\_TYPE

-   CLD\_BINARY\_OUTPUT\_BASIC\_ATTR\_ATTRIBUTE\_REPORTING\_STATUS


**Parent topic:**[Binary Output \(Basic\)](../../Binary_Input_Basic_cluster/topics/binary_output_basic.md)

