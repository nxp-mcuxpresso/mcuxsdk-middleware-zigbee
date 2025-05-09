# EZ-mode Commissioning Command Payloads

The structures described below may be used when the Identify cluster is used with EZ-mode commissioning \(which is part of the ZigBee Base Device functionality and is described in the *ZigBee Devices User Guide \(JNUG3131\)*\).

## ‘EZ-Mode Invoke’ Command Payload 

The following structure is used when sending an ‘EZ-mode Invoke’ command \(using the **eCLD\_IdentifyEZModeInvokeCommandSend\(\)** function\).

```
typedef struct
{
    zbmap8    u8Action;
} tsCLD_Identify_EZModeInvokePayload;

```

where `u8Action` is a bitmap specifying the EZ-mode commissioning actions to be performed on the destination device - a bit is set to ‘1’ if the corresponding action is required, or to ‘0’ if it is not required:

|**Bits**|**Action**|
|--------|----------|
|0|Factory Reset - clears all bindings, group table entries, and the `u8CommissionState` attribute, and reverts to the ‘Factory Fresh’ settings|
|1|Network Steering - puts the device into the ‘Network Steering’ phase|
|2|Find and Bind - puts the device into the ‘Find and Bind’ phase|
|3 - 7|Reserved|

## ‘Update Commission State’ Command Payload 

The following structure is used when sending an ‘Update Commission State’ command \(using the **eCLD\_IdentifyUpdateCommissionStateCommandSend\(\)** function\), which requests an update to the value of the `u8CommissionState` attribute \(for the definition of the attribute, refer to [Section 11.2](identify_cluster_structure_and_attribute.md#id_86938f11-d9bb-4b1f-b371-16fda734a43f)\).

```
typedef struct
{
    zenum8    u8Action;
    zbmap8    u8CommissionStateMask;
} tsCLD_Identify_UpdateCommissionStatePayload;

```

where:

-   `u8Action` is a value specifying the action to perform \(set or clear\) on the `u8CommissionState` bits specified through `u8CommissionStateMask`:

    -   1: Set the specified bits to ‘1’.

    -   2: Clear the specified bits to ‘0’.

        -   All other values are reserved.
-   `u8CommissionStateMask` is a bitmap in which the bits correspond to the bits of the `u8CommissionState` attribute. A bit of this field indicates whether the corresponding attribute bit is to be updated \(according to the action specified in `u8Action`\):

    -   If a bit is set to ‘1’, the corresponding `u8CommissionState` bit should be updated.

    -   If a bit is set to ‘0’, the corresponding `u8CommissionState` bit should not be updated.


**Parent topic:**[Structures](../../Identify_cluster/topics/structures.md)

