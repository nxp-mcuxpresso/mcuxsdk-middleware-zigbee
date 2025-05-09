# Obtaining Logs

A list of the logs that are currently in the local log queue \(on the cluster server\) can be obtained by calling the function **eCLD\_ASCGetLogsAvailable\(\)**. This function provides the number of logs in the queue and a list of the log identifiers.

An individual log from the local log queue can be obtained using the function **eCLD\_ASCGetLogEntry\(\)**. The required log is specified by means of its identifier.

Normally, **eCLD\_ASCGetLogsAvailable\(\)**is called first to obtain a list of the available logs and then **eCLD\_ASCGetLogEntry\(\)**is called for each log.

**Parent topic:**[Log Operations on Server](../../appliance_statistics_cluster/topics/log_operations_on_server.md)

