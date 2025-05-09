# Initialization

The Power Profile cluster must be initialized on both the cluster server and client. This can be done using the function **eCLD\_PPCreatePowerProfile\(\)**, which creates an instance of the Power Profile cluster on a local endpoint.

If you are using a Zigbee device that includes the Power Profile cluster, the above function is automatically called by the initialization function for the device. The function **eCLD\_PPCreatePowerProfile\(\)** should be called explicitly when setting up a custom endpoint containing one or more selected clusters rather than the whole set of clusters supported by a standard Zigbee device.

**Parent topic:**[Power profile operations](../../power_profile_cluster/topics/power_profile_operations.md)

