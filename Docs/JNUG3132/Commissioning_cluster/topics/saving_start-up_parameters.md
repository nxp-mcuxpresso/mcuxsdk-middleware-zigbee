# Saving Start-up Parameters

In order to save a set of Start-up Parameter values, it is first necessary to set them as the current attribute values - this must be done locally by the application on the device hosting the server, possibly using the function **eCLD\_CommissioningSetAttribute\(\)**.

The application on a device hosting a cluster client can send a Save Start-up Parameters command to the cluster server in order to request that the current set of Start-up Parameter values is saved to non-volatile memory. This can be done by calling **eCLD\_CommissioningCommandSaveStartupParamsSend**        **\(\)** or, alternatively, **eCLD\_CommissioningCommandModifyStartupParamsSend**        **\(\)**. The index number of the saved record must be specified in the request. If this number has already been used, the existing stored values will be over-written with the new values.

It is the responsibility of the user application on the device hosting the server to perform the save. When the command arrives, a ZCL custom event will be generated and the request should be handled by the user-defined callback function for the endpoint on which the application is located. The server will automatically send a Save Start-up Parameters Response to the requesting client.

**Parent topic:**[Stored Start-up Parameters](../../Commissioning_cluster/topics/stored_start-up_parameters.md)

