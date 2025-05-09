# Obtaining Information about Scenes

The following functions are provided for obtaining information about scenes:

-   **eCLD\_ScenesCommandViewSceneRequestSend\(\)** can be used to request information on a particular scene on the destination endpoint. Only one device may be targeted by this function. The target device returns a response containing the relevant information.

    -   Alternatively, **eCLD\_ScenesCommandEnhancedViewSceneRequestSend\(\)** can be used, which allows the transition time for the scene to be obtained in units of tenths of a second \(rather than seconds\).
-   **eCLD\_ScenesCommandGetSceneMembershipRequestSend\(\)** can be used to discover which scenes are associated with a particular group on a device. The request can be sent to a single device or to multiple devices. The target device returns a response containing the relevant information \(in the case of multiple target devices, no response is returned from a device that does not contain a scene associated with the specified group ID\). In this way, the function can be used to determine the unused scene IDs.


**Parent topic:**[Sending Remote Commands](../../Scenes_cluster/topics/sending_remote_commands.md)

