# Sending data to sleeping end devices

As described in [Polling for Data](polling_for_data.md), data sent to a sleeping End Device is buffered in the node’s parent until the End Device collects the data through a polling mechanism, typically on waking from sleep. It is important that the polling interval is not too long, as the buffered data is discarded after 7 seconds. In addition, there is limited buffering space in the parent and the buffers are shared by all the children of the parent. Therefore, applications should be designed in such a way that data is only sent to a sleeping End Device when it is either awake or will wake in a timely manner to collect the data from its parent.

The following issues should also be considered when sending data to a sleeping End Device using one of the send ‘**with acknowledgment**’ functions:

-   `ZPS_eAplAfUnicastAckDataReq()`
-   `ZPS_eAplAfUnicastIeeeAckDataReq()`
-   `ZPS_eAplAfBoundAckDataReq()`

**Note:** The ZigBee network parameters referenced in this appendix are configured using the steps described in [Chapter 13, ZPS Configuration Editor](zps_configuration_editor.md).


```{include} ../topics/acknowledged_data_transmission_to_sleeping_end_dev.md
:heading-offset: 2
```

```{include} ../topics/fragmented_data_transmission_to_sleeping_end_devic.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

