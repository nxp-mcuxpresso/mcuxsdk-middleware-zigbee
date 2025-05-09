# Updating ZCL Time Following Sleep

In the case of a device that sleeps, on waking from sleep, the application should update the ZCL time using the function **vZCL\_SetUTCTime\(\)**according to the duration for which the device was asleep. This requires the sleep duration to be timed.

While sleeping, the device normally uses its RC oscillator for timing purposes, which may not maintain the required accuracy. It is therefore recommended that a more accurate external crystal is used to time the sleep periods.

The **vZCL\_SetUTCTime\(\)** function does not cause timer events to be executed. If the device is awake for less than one second, the application should generate a E\_ZCL\_CBET\_TIMER event to prompt the ZCL to run any timer-related functions. Note that when passed into **vZCL\_EventHandler\(\)**, this event will increment the ZCL time by one second.

**Parent topic:**[Maintaining ZCL Time](../../Time_cluster/topics/maintaining_zcl_time.md)

