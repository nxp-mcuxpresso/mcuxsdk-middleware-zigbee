# Using EZ-mode Commissioning Features

The Identify cluster also contains the following optional features that can be used with EZ-mode commissioning, which is a part of the ZigBee Base Device functionality and is described in the *ZigBee Devices User Guide \(JNUG3131\)*.

## ‘EZ-mode Invoke’ Command 

The ‘EZ-mode Invoke’ command is supported which allows a device to schedule and start one or more stages of EZ-mode commissioning on a remote device. The command is issued by calling the **eCLD\_IdentifyEZModeInvokeCommandSend\(\)** function and allows the following stages to be specified:

1. **Factory Reset:** EZ-mode commissioning configuration of the destination device to be reset to ‘Factory Fresh’ settings.

2. **Network Steering:** Destination device to be put into the ‘Network Steering’ phase.

3. **Find and Bind:** Destination device to be put into the ‘Find and Bind’ phase.

On receiving the command, the event E\_CLD\_IDENTIFY\_CMD\_EZ\_MODE\_INVOKE is generated on the remote device, indicating one or more requested commissioning actions. The local application must perform these actions using the functions of the EZ-mode Commissioning module. If more than one stage is specified, they must be performed sequentially in the above order and must be contiguous.

If the ‘EZ-mode Invoke’ command is to be used by an application, its use must be enabled at compile time \(see [Section 11.9](compile-time_options.md#id_585cc0f6-5292-4da8-bbbe-79babb2e0a4d)\).

## ‘Commissioning State’ Attribute 

The Identify cluster server contains an optional ‘Commissioning State’ attribute, `u8CommissionState` \(see [Section 11.2](identify_cluster_structure_and_attribute.md#id_86938f11-d9bb-4b1f-b371-16fda734a43f)\), which indicates whether the local device is:

-   a member of the \(correct\) network

-   in a commissioned state and ready for operation


If the ‘Commissioning State’ attribute is to be used by an application, its use must be enabled at compile time \(see [Section 11.9](compile-time_options.md#id_585cc0f6-5292-4da8-bbbe-79babb2e0a4d)\).

The EZ-mode initiator can send an ‘Update Commission State’ command to the target device in order to update the commissioning state of the target. The command is issued by calling the **eCLD\_IdentifyUpdateCommissionStateCommandSend\(\)** function. On receiving this command on the target, the ‘Commissioning State’ attribute is automatically updated. It is good practice for the EZ-mode initiator to send this command to notify the target device when commissioning is complete.

**Parent topic:**[Sending Commands](../../Identify_cluster/topics/sending_commands.md)

