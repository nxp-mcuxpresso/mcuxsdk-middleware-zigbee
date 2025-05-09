# Handling Commands for Unsupported Clusters

A node might receive a cluster-specific command or general command for a cluster that is not supported. In such a case, the ZCL sends a ‘default response’ containing the status code E\_ZCL\_CMDS\_UNSUPPORTED\_CLUSTER to the originator of the command. This is the standard method of handling the unsupported command \(as described in the ZCL specification\). Default responses are described in [Section 2.5](default_responses.md#id_8a92ceef-63d4-47f2-89e2-6a53f4167395).

The NXP implementation of the ZCL provides an alternative method for dealing with commands for unsupported clusters. A user-defined callback function can be introduced which is invoked when a command is received for an unsupported cluster. This function determines whether the application will handle the command and returns a Boolean value:

-   If the callback function returns TRUE, the ZCL passes the unsupported command to the application in an appropriate event. For example, consider the case when a Report Attribute command is received for the Occupancy Sensing cluster which is not supported by the device. If the callback function opts to allow the application to handle this command, the callback function returns TRUE and the ZCL then passes the command to the main application in the event *E\_ZCL\_CBET\_REPORT\_INDIVIDUAL\_ATTRIBUTE* or *E\_ZCL\_CBET\_REPORT\_ATTRIBUTES*, as appropriate.

-   If the callback function returns FALSE, the ZCL handles the unsupported command in the standard way by sending a default response containing the status *E\_ZCL\_CMDS\_UNSUPPORTED\_CLUSTER*. The application is not notified about the received command.


The prototype for the user-defined callback function is as follows:
``````
bool_t bZCL_OverrideHandlingEntireProfileCmd(uint16 u16ClusterId);
``````

where *u16ClusterId* is the ZigBee identifier of the cluster to which the command relates.

This callback function can be registered with the ZCL using the function **vZCL\_RegisterHandleGeneralCmdCallBack\(\)**, detailed in [Section 5.1](../../Core_functions/topics/general_functions_.md#id_1f0df55c-1a42-4a30-9031-deb3d5393ead).

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

