# Initialising and Maintaining Master Time

The time-master must initially obtain a master time from an external source. The application on the time-master must use this time to set its ZCL time by calling the function **vZCL\_SetUTCTime\(\)** and to set the value of the Time cluster attribute `utctTime` in the local `tsCLD_Time` structure within the shared device structure \(securing access with a mutex\). The application must also set \(to ‘1’\) the ‘Master’ bit of the `u8TimeStatus` attribute of the `tsCLD_Time` structure, to indicate that this device is the time-master and that the time has been set.

**Note:** The ‘Synchronised’ bit of the `u8TimeStatus` attribute should always be zero on the time-master, as this device does not synchronise to any other device within the ZigBee network.

If the time-master has also obtained time-zone and daylight saving information \(or has been pre-programmed with this information\), its application must set \(to ‘1’\) the ‘Master for Time Zone and DST’ bit of the `u8TimeStatus` attribute and write the relevant optional attributes. These optional attributes can then be used to provide time-zone and daylight saving information to other devices \(see [Section 18.3](attribute_settings.md#id_466de93a-a275-47e8-baa5-69915f98bf8b)\).

**Note:** The time-master can prevent other devices from attempting to read its Time cluster attributes before the time has been set - the initialization of the master time should be done after registering the endpoint for the device and before starting the ZigBee PRO stack.

The ZCL time and the `utctTime` attribute are subsequently incremented from a local one-second timer, as follows. On expiration of the timer, an event is generated \(from the hardware/software timer that drives the one-second timer\), which causes a ZCL user task to be activated. The event is initially handled by this task as described in [Section 3.2](../../ZCL_event_handling/topics/processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38), resulting in an E\_ZCL\_CBET\_TIMER event being passed to the ZCL via the function **vZCL\_EventHandler\(\)**. The following actions should then be performed:

1. The ZCL automatically increments the ZCL time and may run cluster-specific schedulers \(e.g. for maintaining a price list\).

2. The user task updates the value of the `utctTime` attribute of the `tsCLD_Time` structure within the shared device structure \(securing access with a mutex\).

3. The user task resumes the one-second timer.

Both the ZCL time and the `utctTime` attribute must also be updated by the application when an update of the master time is received.

**Parent topic:**[Time-Synchronization of Devices](../../Time_cluster/topics/time-synchronisation_of_devices.md)

