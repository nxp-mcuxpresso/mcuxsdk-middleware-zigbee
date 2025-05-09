# Sleeping Devices in Identification Mode

In some cases, a device might sleep between activities \(for example, a switch that is configured as a sleeping End Device\) and is also operating in identification mode. In such a case, the device must wake once per second for the ZCL to decrement the *u16IdentifyTime* attribute \(see [Section 11.2](identify_cluster_structure_and_attribute.md#id_86938f11-d9bb-4b1f-b371-16fda734a43f)\), which represents the time remaining in identification mode. The device may also use this wake time to highlight itself, for example, flash an LED. The attribute is automatically updated by the ZCL when the application passes an E\_ZCL\_CBET\_TIMER event to the ZCL via the **vZCL\_EventHandler\(\)** function. The ZCL also automatically increments ZCL time as a result of this event.

When in identification mode, it is not permissible for a device to sleep for longer than 1 second, and to generate one timer event on waking. Before entering sleep, the value of the *u16IdentifyTime* attribute can be checked. If this value is zero, the device is not in identification mode and is therefore allowed to sleep for longer than 1 second.

For details of updating ZCL time following a prolonged sleep, refer to [Section 18.4.1](../../Time_cluster/topics/updating_zcl_time_following_sleep.md#id_7d465576-19ff-4edb-84c1-ea4c196ba26e).

**Parent topic:**[Identify Cluster](../../Identify_cluster/topics/identify_cluster.md)

