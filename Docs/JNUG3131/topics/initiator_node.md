# Initiator Node

Finding and Binding is started on an initiator node by calling the function **BDB\_eFbTriggerAsInitiator\(\)**. This function is called as the result of a user action on the node, such as a button-press. The initiator then remains in Finding and Binding mode for a fixed time-interval \(in seconds\) defined by the constant BDBC\_MIN\_COMMISSIONING\_TIME. If Finding and Binding does not succeed within this time, the event BDB\_EVENT\_FB\_TIMEOUT is generated and passed into the callback function **APP\_vBdbCallback\(\)**.

Once Finding and Binding starts, the initiator node searches for target endpoints by broadcasting an Identify Query command periodically with a period \(in seconds\) defined through the macro BDB\_FB\_RESEND\_IDENTIFY\_QUERY\_TIME.

**Note:** Before each broadcast attempt, the event BDB\_EVENT\_FB\_NO\_QUERY\_RESPONSE is generated and passed into **APP\_vBdbCallback\(\)**. This event allows the application to exit the current Finding and Binding process \(see below\).

If the initiator receives an Identify Query response from a remote endpoint, the application must pass the ZCL event BDB\_E\_ZCL\_EVENT\_IDENTIFY\_QUERY to the Base Device using the function **BDB\_vZclEventHandler\(\)**. This event allows the Base Device to gather information about the identifying device by sending a Simple Descriptor request to the relevant endpoint. If the requested Simple Descriptor is successfully received back, the callback function checks this descriptor for clusters that match those on the initiator. The application is notified of via a BDB\_EVENT\_FB\_HANDLE\_SIMPLE\_DESC\_RESP\_OF\_TARGET event passed into **APP\_vBdbCallback\(\)**.

If there is at least one matching cluster, the initiator does one of the following:

-   If binding is required \(indicated by the *u16bdbCommissioningGroupID* attribute being equal to 0xFFFF\), the initiator adds the remote endpoint to the local Binding table \(but should first request the IEEE/MAC address of the remote node\).

-   If grouping is required \(indicated by the *u16bdbCommissioningGroupID* attribute being equal to a 16-bit group address\), the initiator requests that the target endpoint adds the group address to its Group Address table.


The application is notified of a successful binding or grouping via the following events:

-   For a binding:

    -   BDB\_EVENT\_FB\_BIND\_CREATED\_FOR\_TARGET for success

    -   BDB\_EVENT\_FB\_ERR\_BINDING\_FAILED for failure

-   For a grouping:

    -   BDB\_EVENT\_FB\_GROUP\_ADDED\_TO\_TARGET for success

    -   BDB\_EVENT\_FB\_ERR\_GROUPING\_FAILED for failure


At this point, the application can remotely stop identification mode \(and therefore Finding and Binding\) on the target node by calling the Identify cluster function **eCLD\_IdentifyCommandIdentifyRequestSend\(\)** to request that the identification mode period is set to zero.

A Finding and Binding process is stopped on the initiator endpoint using the function **BDB\_vFbExitAsInitiator\(\)**. This function is typically called in the callback function **APP\_vBdbCallback\(\)** as the result of a user action, such as a button-press or button-release.

**Parent topic:**[Finding and Binding](../topics/finding_and_binding.md)

