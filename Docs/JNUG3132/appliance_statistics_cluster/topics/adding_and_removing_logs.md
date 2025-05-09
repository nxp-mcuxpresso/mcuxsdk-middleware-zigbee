# Adding and Removing Logs

A data log can be added to the local log queue \(on the cluster server\) using the function **eCLD\_ASCAddLog\(\)**. The log must be given an identifier and the UTC time at which the log was added must be specified. The length of the log, in bytes, must be less than the value of CLD\_APPLIANCE\_STATISTICS\_ATTR\_LOG\_MAX\_SIZE, which is defined in the **zcl\_options.h** files \(and must be less than or equal to 70\).

The above function also sends a ‘Log Notification’ message to all bound Appliance Statistics cluster clients.

An existing log can be removed from the local log queue using the function **eCLD\_ASCRemoveLog\(\)**. The log is specified using its identifier.

**Parent topic:**[Log Operations on Server](../../appliance_statistics_cluster/topics/log_operations_on_server.md)

