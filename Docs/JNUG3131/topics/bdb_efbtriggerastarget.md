# BDB\_eFbTriggerAsTarget

```
BDB_teStatus BDB_eFbTriggerAsTarget(uint8 u8EndPoint);

```

## Description 

This function starts the Finding and Binding process on a target endpoint and must be called locally by the application on the target endpoint. The function may be called as the result of a user action, such as a button-press.

The functions put the device into identification mode of the Identify cluster for a time-interval \(in seconds\) which is at least equal to the value defined using the macro BDBC\_MIN\_COMMISSIONING\_TIME in the **bdb\_options.h** file. During this time, the target device generates responses to Identify Query commands, as well as other Finding and Binding commands.

The endpoint is then brought out of Find and Binding mode locally using the function **BDB\_vFbExitAsTarget\(\)** or remotely \(by the initiator\) using the Identify cluster function **eCLD\_IdentifyCommandIdentifyRequestSend\(\)**.

Finding and Binding mode is described in [Finding and Binding](finding_and_binding.md#).

## Parameters 

-   *u8EndPoint*: Number of target endpoints

## Returns 

-   BDB\_E\_SUCCESS

    \(Finding and Binding has been successfully started\).

-   BDB\_E\_FAILURE

    \(invalid endpoint number or Identify cluster is inaccessible\).


**Parent topic:**[Functions](../topics/functions.md)

