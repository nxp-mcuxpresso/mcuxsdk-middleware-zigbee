# Mandatory Attributes

The mandatory attributes of the Time cluster are set as follows:

## utctTime 

This is a mandatory 32-bit attribute which holds the current time \(UTC\). On the time-master, this attribute value is incremented once per second. On all other devices, it is the responsibility of the local application to synchronise this time with the time-master. For more information on time-synchronisation, refer to [Section 18.5](time-synchronisation_of_devices.md#id_941f0eac-72a8-40fc-a023-95c2023ab511).

## u8TimeStatus 

This is a mandatory 8-bit attribute containing the bitmap detailed in [Table 28 on](time_cluster_structure_and_attributes.md#id_5272357b-bd17-44bf-89f4-778586e84d7e)page 389. This attribute must be set as follows on the time-master \(Time cluster server\):

-   The ‘Master’ bit should initially be zero until the current time has been obtained from an external time-of-day source. Once the time has been obtained and set, the ‘Master’ bit should be set \(to ‘1’\).

-   The ‘Synchronised’ bit must always be zero, as the time-master does not obtain its time from another device within the ZigBee network \(this bit is set to ‘1’ only for a secondary Time cluster server that is synchronized to the time-master\).

-   The ‘Master for Time Zone and DST’ bit must be set \(to ‘1’\) once the time-zone and Daylight Saving Time \(DST\) attributes \(see below\) have been correctly set for the device.


Macros are provided for setting the individual bits of the `u8TimeStatus` bitmap - for example, the macro CLD\_TM\_TIME\_STATUS\_MASTER\_MASK is used to set the Master bit. These macros are defined in the header file **time.h** and are also listed in [Section 18.2](time_cluster_structure_and_attributes.md#id_0641e5fe-7531-4a59-8378-862128710a31).

**Parent topic:**[Attribute Settings](../../Time_cluster/topics/attribute_settings.md)

