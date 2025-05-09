# Compile-time options

To enable the Identify cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_IDENTIFY

```

In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

```
#define IDENTIFY_CLIENT
#define IDENTIFY_SERVER

```

The following cluster functionality can be enabled or configured in **zcl\_options.h**.

## Cluster Revision 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_IDENTIFY_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Trigger Effect 

Add this line to enable use of the **eCLD\_IdentifyCommandTriggerEffectSend\(\)** function to remotely start/stop identification mode:

```
#define CLD_IDENTIFY_CMD_TRIGGER_EFFECT

```

## Enhanced Functionality for EZ-mode Commissioning 

To enable the optional ‘Commission State’ attribute, you must include:

```
#define CLD_IDENTIFY_ATTR_COMMISSION_STATE

```

To enable the optional ‘EZ-mode Invoke’ command, you must include:

```
#define CLD_IDENTIFY_CMD_EZ_MODE_INVOKE

```

EZ-mode commissioning is part of the ZigBee Base Device functionality and is described in the *ZigBee Devices User Guide \(JNUG3131\)*.

**Parent topic:**[Identify Cluster](../../Identify_cluster/topics/identify_cluster.md)

