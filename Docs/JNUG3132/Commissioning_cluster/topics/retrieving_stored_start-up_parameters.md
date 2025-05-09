# Retrieving Stored Start-up Parameters

A set of Start-up Parameter values that have been stored by in non-volatile memory \(as described in [Section 43.5.2.1](saving_start-up_parameters.md#id_3d0acc60-2a3d-4059-92b9-97358ef8ea2c)\) can be retrieved and loaded as the current set of values. The required stored set of values is specified using its unique index number.

The application on a device hosting a cluster client can send a Restore Start-up Parameters command to the cluster server in order to request that the specified set of Start-up Parameter values is loaded from non-volatile memory. This can be done by calling **eCLD\_CommissioningCommandRestoreStartupParamsSend**        **\(\)** or, alternatively, **eCLD\_CommissioningCommandModifyStartupParamsSend**        **\(\)**. The index number of the relevant set must be specified in the request.

It is the responsibility of the user application on the device hosting the server to retrieve the relevant set of values and load them as the current values. When the command arrives, a ZCL custom event will be generated and the request should be handled by the user-defined callback function for the endpoint on which the application is located. The server will automatically send a Restore Start-up Parameters Response to the requesting client.

A device restart is required in order to implement the loaded values, as described in [Section 43.5.1](device_start-up.md#id_b7928bc7-efbc-4c7d-968b-b730f30be996).

**Parent topic:**[Stored Start-up Parameters](../../Commissioning_cluster/topics/stored_start-up_parameters.md)

