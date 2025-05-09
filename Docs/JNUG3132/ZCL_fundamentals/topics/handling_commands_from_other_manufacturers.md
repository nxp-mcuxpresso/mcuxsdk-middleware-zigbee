# Handling Commands from Other Manufacturers

Every manufacturer of ZigBee Certified Products is allocated a manufacturer code by the ZigBee Alliance. The manufacturer code for NXP is 0x1037. A manufacturer-specific command that is sent by a node contains the manufacturer code for the node manufacturer.

By default, the NXP implementation of the ZCL rejects manufacturer-specific commands containing manufacturer codes other than NXP’s own code. For a rejected command, the ZCL sends a ‘default response’ containing the status code E\_ZCL\_CMDS\_UNSUP\_MANUF\_CLUSTER\_COMMAND to the originator of the command. Default responses are described in [Section 2.5](default_responses.md#id_8a92ceef-63d4-47f2-89e2-6a53f4167395).

However, a mechanism is available to handle multiple manufacturer codes. A user-defined callback function can be introduced, which is invoked when a manufacturer-specific command is received containing a non-NXP manufacturer code. This function determines whether the application handles the command and returns a Boolean value:

-   If the callback function returns TRUE, the ZCL passes the command to the application in an appropriate event.

-   If the callback function returns FALSE, the ZCL handles the command with in the standard way by sending a default response containing the status E\_ZCL\_CMDS\_UNSUP\_MANUF\_CLUSTER\_COMMAND. The application is not notified about the received command.


The prototype for the user-defined callback function is as follows:

```
bool_t bZCL_IsManufacturerCodeSupported(uint16 u16ManufacturerCode);

```

where *u16ManufacturerCode* is the manufacturer code in the received command.

This callback function can be registered with the ZCL using the function **vZCL\_RegisterCheckForManufCodeCallBack\(\)**, detailed in [Section 5.1](../../Core_functions/topics/general_functions_.md#id_1f0df55c-1a42-4a30-9031-deb3d5393ead).

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

