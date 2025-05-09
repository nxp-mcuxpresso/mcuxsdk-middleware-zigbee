# Reset Start-up Parameters to Default Values

A set of Start-up Parameters on the cluster server can be reset to their default values.

The application on a device hosting a cluster client can send a Reset Start-up Parameters command to the cluster server in order to request that the Start-up Parameters are reset to their default values. This can be done by calling **eCLD\_CommissioningCommandResetStartupParamsSend**        **\(\)** or, alternatively, **eCLD\_CommissioningCommandModifyStartupParamsSend**        **\(\)**. Options are available concerning the set\(s\) of Start-up Parameters to reset - any combination of the following can be performed:

-   Reset the current set of Start-up Parameters

-   Reset all stored sets of Start-up Parameters or the stored set with given index

-   Erase the stored set of Start-up Parameters with given index


The required options must be specified in the request. The option to erase a stored set of Start-up Parameters allows storage space to be freed up.

It is the responsibility of the user application on the device hosting the server to reset the relevant set\(s\) of values. When the command arrives, a ZCL custom event will be generated and the request should be handled by the user-defined callback function for the endpoint on which the application is located. The server will automatically send a Reset Start-up Parameters Response to the requesting client.

A device restart is required in order to implement the reset \(current\) values, as described in [Section 43.5.1](device_start-up.md#id_b7928bc7-efbc-4c7d-968b-b730f30be996).

**Parent topic:**[Commissioning Commands](../../Commissioning_cluster/topics/commissioning_commands.md)

