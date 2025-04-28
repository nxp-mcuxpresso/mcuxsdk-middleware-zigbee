# Polling for Data

In the case of an End Device which is capable of sleeping, messages are not delivered directly to the device, since it may be asleep when the messages arrive. Instead, the messages are temporarily buffered by the End Device’s parent. Once awake, the End Device can then ask or ‘poll’ its parent for data.

**Note:** End Devices that are not enabled for sleep can receive messages directly and therefore do not need to poll. An End Device is pre-configured as either sleeping or non-sleeping via the End Device parameter Sleeping in the ZPS Configuration Editor \(see Section 12.4.2\).

Data polling is performed using the function **zps\_eAplZdoPoll\(\)** in the End Device application. This function requests the buffered data and should normally be called immediately after waking from sleep. If the poll request is successfully sent to the parent, a zps\_EVENT\_NWK\_POLL\_CONFIRM stack event will occur on the End Device. The subsequent arrival of data from the parent is indicated by the stack event zps\_EVENT\_AF\_DATA\_INDICATION. Any messages forwarded from the parent should then be collected from the relevant message queue using the function **ZQ\_bZQueueReceive\(\)**, just as for normal data reception described in [Section 6.5.2](receiving_data.md).

Application design issues concerned with transferring data to a sleeping End Device are outlined in [Appendix B.2](sending_data_to_sleeping_end_devices.md).

**Parent topic:**[Transferring data](../topics/transferring_data.md)

