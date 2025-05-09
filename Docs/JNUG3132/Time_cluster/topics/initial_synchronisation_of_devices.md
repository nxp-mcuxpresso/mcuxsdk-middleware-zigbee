# Initial Synchronisation of Devices

It is the responsibility of the application on a ZigBee PRO device to perform time-synchronisation with the time-master. The application can remotely read the Time cluster attributes from the time-master by calling the function **eZCL\_SendReadAttributesRequest\(\)**, which will result in a ‘read attributes’ response containing the Time cluster data. On receiving this response, a ‘data indication’ stack event is generated on the local device, which causes a ZCL user task to be activated. The event is initially handled by this task as described in [Section 3.2](../../ZCL_event_handling/topics/processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38), resulting in an E\_ZCL\_ZIGBEE\_EVENT event being passed to the ZCL via the function **vZCL\_EventHandler\(\)**. Provided that the event contains a message incorporating a ‘read attributes’ response, the ZCL:

1. automatically sets the `utctTime` field of the `tsCLD_Time` structure to the value of the same attribute in the ‘read attributes’ response \(and also sets other Time cluster attributes, if requested\)

2. invokes the relevant user-defined callback function \(see [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee)\), which must read the local `utctTime` attribute \(securing access with a mutex\) and use this value to set the ZCL time by calling the function **vZCL\_SetUTCTime\(\)**

**Note:** When a device attempts to time-synchronise with the time-master, it should check the `u8TimeStatus` attribute in the ‘read attributes’ response. If the ‘Master’ bit of this attribute is not equal to ‘1’, the obtained time should not be trusted and the time should not be set. The device should wait and try to synchronise again later.

It may also be possible to obtain time-zone and daylight saving information from the time-master. If available, this information will be returned in the ‘read attributes’ response. However, before using these optional Time cluster attributes from the response, the application should first check that the ‘Master for Time Zone and DST’ bit of the `u8TimeStatus` attribute is set \(to ‘1’\) in the response.

The ZCL time and `utctTime` attribute value on the local device are subsequently maintained as described in [Section 18.5.3](re-synchronisation_of_devices.md#id_6793b4ef-f442-4cea-ab69-f57f852da7a1).

**Parent topic:**[Time-Synchronization of Devices](../../Time_cluster/topics/time-synchronisation_of_devices.md)

