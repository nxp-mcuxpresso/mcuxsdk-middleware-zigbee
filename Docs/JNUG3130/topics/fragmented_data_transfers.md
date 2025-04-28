# Fragmented data transfers

The send ‘with acknowledgment’ functions \(**ZPS\_eAplAfUnicastAckDataReq\(\)**, **ZPS\_eAplAfUnicastIeeeAckDataReq\(\)**, and **ZPS\_eAplAfBoundAckDataReq\(\)**\) allow a large data packet to be sent that may be fragmented into multiple messages/ frames during transmission. As a general rule, one of these two functions should be used when sending a data packet with a payload size greater than 80 bytes. It is important to note, however, that the use of APS security will reduce this limit, as payload bytes are taken up by security data.

The processes of fragmentation at the sender and de-fragmentation at the receiver are transparent to the applications at the two ends, but the points described in the sub-sections below should be noted.

**Note:**

1.  Fragmentation is described further in [Fragmented data transmission to sleeping End Device](fragmented_data_transmission_to_sleeping_end_devic.md): in connection with fragmented data transfers to sleeping End Devices.
2.  The ZigBee network parameters referenced in this section are configured using the ZPS Configuration Editor and are described in [Chapter 13, "ZigBee Network Parameters"](zigbee_network_parameters.md). When setting up the APDUs to handle Rx fragmentation, care must be taken to ensure that the configuration setting in the ZPS Configuration Editor is sized to be able to handle 3\* Tx Fragments.


```{include} ../topics/enabling_disabling_fragmentation.md
:heading-offset: 2
```

```{include} ../topics/configuring_acknowledgments.md
:heading-offset: 2
```

```{include} ../topics/acknowledgment_timeout.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

