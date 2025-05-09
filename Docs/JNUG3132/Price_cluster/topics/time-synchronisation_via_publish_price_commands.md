# Time-synchronization via Publish Price commands

As an alternative to using the Time cluster to time-synchronize a ZigBee device with the ESP \(as described in [Section 18.5.3](../../Time_cluster/topics/re-synchronisation_of_devices.md#id_6793b4ef-f442-4cea-ab69-f57f852da7a1)\), the local application can use the time embedded in a Publish Price command from the ESP \(see [Section 40.5](publishing_price_information.md#id_0e05590b-cdd5-46ef-81a0-e55d97df116b)\), as described below.

**Note:** A device that implements the Price cluster must also implement the Time cluster.

It is the responsibility of the application on a ZigBee device to perform time-synchronization with the ESP. This involves updating the ZCL time on the local device.

The initialization of the ZCL time on a device should be performed using the Time cluster by requesting the current time from the ESP, as described in [Section 18.5.2](../../Time_cluster/topics/initial_synchronisation_of_devices.md#id_4bb38c31-e047-4417-a555-b6c4243e7b95) \(this method also gets the time-zone and daylight saving information\).

Subsequent re-synchronizations of a device with the time-master can use the time contained in Publish Price commands from the ESP \(but note that no time-zone or daylight saving information is included\). Therefore, a device can update its ZCL time whenever it receives a Publish Price command. On receiving this command, a ‘data indication’ stack event is generated, which causes a ZCL user task to be activated. The event is initially handled by this task as described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee), resulting in an E\_ZCL\_ZIGBEE\_EVENT event being passed to the ZCL via **vZCL\_EventHandler\(\)**. The ZCL invokes the relevant user-defined callback function \(see [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee)\) which, provided that the event is of the type E\_SE\_PRICE\_TIME\_UPDATE, must update the ZCL time using **vZCL\_SetUTCTime\(\)**.

Note that the `utctTime` field of the local copy of the Time cluster is not updated, since this should only be done following a read of the Time cluster attributes from the server.

CAUTION:

If a device is handling Publish Price commands from more than one server, the time must only be updated with time events from one server, to prevent the time from jittering forwards and backwards if the servers’ times are not in sync.

The time-synchronization of a device \(with the time-master\) should be performed regularly. As a rule, if no Publish Price commands have been received from the ESP in the last 48 hours, the device should request the current time from the ESP and update its own times as described in [Section 18.5.3](../../Time_cluster/topics/re-synchronisation_of_devices.md#id_6793b4ef-f442-4cea-ab69-f57f852da7a1).

It is worth noting that an undefined ZCL time causes the following issues in the Price cluster:

-   A Price cluster server without a ZCL time cannot issue any Publish Price commands, since the current time is a mandatory field of this command.

-   A Price cluster client without a ZCL time cannot process a Publish Price command with a ‘start-time of now', unless the ZCL time is first set with the time extracted from the received command.

-   If the price at the head of the price list has a specified start-time, it is not possible to know whether this price is active or not.


Regarding the last point, a device should be time-synchronized with the ESP \(as described in [Section 18.5.2](../../Time_cluster/topics/initial_synchronisation_of_devices.md#id_4bb38c31-e047-4417-a555-b6c4243e7b95)\) before an attempt is made to add scheduled prices to the device’s price list. Then, if the device receives a scheduled price with a ‘start-time of now’, it is permissible to add this price to the list.

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

