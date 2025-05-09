# vZCL\_RegisterHandleGeneralCmdCallBack

```
void vZCL_RegisterHandleGeneralCmdCallBack(void *fnPtr);

```

## Description 

This function is used to register an optional user-defined callback function that is invoked when a cluster-specific or general command is received for a cluster that is not supported on the local device.

The purpose of the registered callback function is to determine whether the application would handle the unsupported command. The prototype of the callback function is as follows:

```
bool_t bZCL_OverrideHandlingEntireProfileCmd(uint16 u16ClusterId);
```

where *u16ClusterId* is the ZigBee identifier of the cluster to which the command relates. The function returns a Boolean value, which is TRUE if the main application handles the command and FALSE if the ZCL would handle the command:

-   If the function returns TRUE, the ZCL passes the command to the main application in an appropriate event.

-   If the function returns FALSE, the ZCL sends a ‘default response’ containing the status E\_ZCL\_CMDS\_UNSUPPORTED\_CLUSTER to the originator of the command \(this is also the standard way of handling a command for an unsupported cluster when a callback function has not been registered\).


For more information on handling commands for unsupported clusters, refer to [Section 2.6](../../ZCL_fundamentals/topics/handling_commands_for_unsupported_clusters.md#id_83d772c9-8440-4d6c-b47c-f91528e12bab).

## Parameters 

-   *fnPtr*: Pointer to user-defined callback function to be registered

## Returns

-   None

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

