# BDB_eFbTriggerAsInitiator

```
BDB_teStatus BDB_eFbTriggerAsInitiator(
uint8 u8SourceEndPointId);
```

## Description 

This function starts the Finding and Binding process on an initiator endpoint. The function may be called as the result of a user action, such as a button-press. The initiator remains in Finding and Binding mode for a fixed time-interval \(in seconds\) defined using the macro BDBC\_MIN\_COMMISSIONING\_TIME in the **bdb\_options.h** file.

The initiator node first searches for target endpoints by broadcasting an Identify Query command. If the initiator receives a response from a remote endpoint, it then sends a Simple Descriptor request to this endpoint. If the requested Simple Descriptor is successfully received back, then the initiator checks this descriptor for clusters on the remote endpoint that match its own clusters. If there is at least one matching cluster, the initiator does one of the following:

-   If binding is required \(indicated by the *u16bdbCommissioningGroupID* attribute being equal to 0xFFFF\), the initiator adds the remote endpoint to the local Binding table.

-   If grouping is required \(indicated by the *u16bdbCommissioningGroupID* attribute being equal to a 16-bit group address\), the initiator requests that the target endpoint adds the group address to its Group Address table.


Finding and Binding mode is described in [Finding and Binding](finding_and_binding.md#).

**Note:** Events are generated during this function call - for details, refer to [Initiator Node](initiator_node.md#).

## Parameters 

-   *u8SourceEndPointId*: Number of initiator endpoints

## Returns 

-   BDB\_E\_SUCCESS

    \(Finding and Binding has been successfully started\).

-   BDB\_E\_FAILURE

    \(invalid endpoint number or unable to broadcast Identify Query command\).

-   BDB\_E\_ERROR\_COMMISSIONING\_IN\_PROGRESS

    \(Finding and Binding already on-going\).


**Parent topic:**[Functions](../topics/functions.md)

