# Target Node

Finding and Binding is started on a target node by calling the function **BDB\_eFbTriggerAsTarget\(\)**. This function is called as the result of a user action on the node, such as a button-press.

The target node then uses the Identify cluster to put itself into identification mode for a fixed time period. This period \(in seconds\) is determined by `u16IdentifyTime`, an Identify cluster attribute which is automatically set to the value of the constant BDBC\_MIN\_COMMISSIONING\_TIME. In identification mode, the cluster responds to any received Identify Query commands, as well as other Finding and Binding commands. The node may also visually or audibly indicate that it is in identification mode. On exiting identification mode at the end of the above period, the cluster is no longer able to process Identify Query commands but the node is still able to service other commands from the initiator related to the binding/grouping. The Identify cluster is fully described in the *ZigBee Cluster Library User Guide \(JNUG3132\)*.

A target node can be brought out of the Finding and Binding process in either of the following ways:

-   The local application can call the function **BDB\_vFbExitAsTarget\(\)** as the result of a user action, such as a button-press or button-release.

-   The remote application \(on the initiator\) can call the Identify cluster function **eCLD\_IdentifyCommandIdentifyRequestSend\(\)** to request that the identification mode period is set to zero. To indicate to the Base Device that the identification process has ended, the application must pass the ZCL event BDB\_E\_ZCL\_EVENT\_IDENTIFY to the Base Device using the **BDB\_vZclEventHandler\(\)** function. This allows the Base Device to exit the 'Finding and Binding' process on the target endpoint.


**Parent topic:**[Finding and Binding](../topics/finding_and_binding.md)

