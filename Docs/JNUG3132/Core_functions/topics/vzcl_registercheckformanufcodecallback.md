# vZCL\_RegisterCheckForManufCodeCallBack

```
void vZCL_RegisterCheckForManufCodeCallBack(void *fnPtr);

```

## Description 

This function is used to register an optional user-defined callback function that is invoked when a manufacturer-specific command is received containing a manufacturer code other than NXP’s own code \(0x1037\).

The purpose of the registered callback function is to determine whether the application would handle a received command with a given manufacturer code. The prototype of the callback function is as follows:

``````
bool_t bZCL_IsManufacturerCodeSupported(uint16 u16ManufacturerCode);
``````

where *u16ManufacturerCode* is the manufacturer code contained in the received command. The function returns a Boolean value, which is TRUE if the main application handles the command and FALSE if the ZCL handles the command:

-   If the function returns TRUE, the ZCL passes the command to the main application in an appropriate event.

-   If the function returns FALSE, the ZCL sends a ‘default response’ containing the status E\_ZCL\_CMDS\_UNSUP\_MANUF\_CLUSTER\_COMMAND to the originator of the command \(this is also the standard way of handling a command with a non-NXP manufacturer code when a callback function has not been registered\).


For more information on handling manufacturer-specific commands containing non-NXP manufacturer codes, refer to [Section 2.7](../../ZCL_fundamentals/topics/handling_commands_from_other_manufacturers.md#id_5651bcdf-4539-4a17-a5ae-24d497f90bd1).

## Parameters 

-   *fnPtr*: Pointer to user-defined callback function to be registered

## Returns 

-   None

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

