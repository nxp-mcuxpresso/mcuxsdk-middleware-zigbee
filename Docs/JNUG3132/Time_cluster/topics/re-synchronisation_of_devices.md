# Re-synchronisation of Devices

After the initialization described in [Section 18.5.2](initial_synchronisation_of_devices.md#id_4bb38c31-e047-4417-a555-b6c4243e7b95), the ZCL time must be updated by the application on each one-second tick of the local timer. The ZCL time is updated from the timer in the same way as described in [Section 18.4](maintaining_zcl_time.md#id_5b749fdf-f76c-4969-8378-f7a0709cc19c).

Due to the inaccuracy of the local one-second timer, the ZCL time is likely to lose synchronisation with the time on the time-master. It will therefore be necessary to occasionally re-synchronise the local ZCL time with the time-master - the `utctTime` attribute value is also updated at the same time. A device can re-synchronise with the time-master by first remotely reading the `utctTime` attribute using the function **eZCL\_SendReadAttributesRequest\(\)**. On receiving the ‘read attributes’ response from the time-master, the operations performed are the same as those described for initial synchronisation in [Section 18.5.2](initial_synchronisation_of_devices.md#id_4bb38c31-e047-4417-a555-b6c4243e7b95).

**Parent topic:**[Time-Synchronization of Devices](../../Time_cluster/topics/time-synchronisation_of_devices.md)

