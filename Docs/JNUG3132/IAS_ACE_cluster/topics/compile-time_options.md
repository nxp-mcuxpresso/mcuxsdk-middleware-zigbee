# Compile-time options

To enable the IAS ACE cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_IASACE

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one of the following to the same file:

```
#define IASACE_SERVER
#define IASACE_CLIENT

```

The IAS ACE cluster contains macros that may be specified at compile-time by adding one or more of the following lines to the **zcl\_options.h** file.

## Maximum Size of Zone Table 

The maximum number of entries in a Zone table on the cluster server can be defined using the following line:

```
#define CLD_IASACE_ZONE_TABLE_SIZE n

```

where n is the desired maximum \(e.g. 8\).

## Maximum Length of Arm/Disarm Code 

        The maximum length of string allowed for the arm/disarm code can be defined using the following line:

```
#define CLD_IASACE_MAX_LENGTH_ARM_DISARM_CODE n

```

where n is the desired maximum.

## Maximum Length of Zone Label 

        The maximum length of string allowed for a zone name/label can be defined using the following line:

```
#define CLD_IASACE_MAX_LENGTH_ZONE_LABEL n

```

where n is the desired maximum.

## Disable APS Acknowledgements for Bound Transmissions 

APS acknowledgements for bound transmissions from this cluster can be disabled using the following line:

```
#define CLD_IASACE_BOUND_TX_WITH_APS_ACK_DISABLED

```

## Cluster Revision 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_IASACE_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[IAS Ancillary Control Equipment Cluster](../../IAS_ACE_cluster/topics/ias_ancillary_control_equipment_cluster.md)

