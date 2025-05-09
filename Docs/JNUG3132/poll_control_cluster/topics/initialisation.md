# Initialization

The Poll Control cluster must be initialized on both the cluster server and client. This can be done using the function **eCLD\_PollControlCreatePollControl\(\)**, which creates an instance of the Poll Control cluster on a local endpoint.

If you are using a standard ZigBee device which includes the Poll Control cluster, the above function is automatically called by the initialization function for the device. You only need to call **eCLD\_PollControlCreatePollControl\(\)** explicitly when setting up a custom endpoint containing one or more selected clusters \(rather than the whole set of clusters supported by a standard ZigBee device\).

**Parent topic:**[Poll Control Operations](../../poll_control_cluster/topics/poll_control_operations.md)

