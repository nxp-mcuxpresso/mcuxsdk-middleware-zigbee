# Compile-time Options

To enable the Groups cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_GROUPS

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define GROUPS_CLIENT
#define GROUPS_SERVER

```

The Groups cluster contains macros that may be optionally specified at compile time by adding one or both of the following lines to the **zcl\_options.h** file.

To set the size used for the group addressing table in the **.zpscfg** file,

Add this line:

```
#define CLD_GROUPS_MAX_NUMBER_OF_GROUPS             (8)

```

To configure the maximum length of the group name, add the following line:

```
#define CLD_GROUPS_MAX_GROUP_NAME_LENGTH            (16)

```

To define the value \(n\) of the Cluster Revision attribute, add the following line:

```
#define CLD_GROUPS_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[Groups Cluster](../../Groups_cluster/topics/groups_cluster.md)

