# Noise threshold for forming a network

The ZigBee PRO stack provides a mechanism for forming a new network in the quietest IEEE802.15.4 radio channel. The Coordinator \(centralized network\) or Router \(distributed network\) that forms the network performs a channel scan to listen for activity from other local networks.

During the channel scan, the activity in each channel is assigned a noise level in the range 0 to 254. This result is compared with a noise level threshold, which is defined by the NIB value `u8VsFormEdThreshold` \(which is part of the structure `ZPS_tsNwkNibInitialValues`\). If the measured noise level for a channel is above this threshold, the channel is excluded from further consideration. Therefore, if all the channels in the scan are noisier than the threshold allows, no network is formed.

The stack then re-scans the channels that passed the noise threshold test \(if any\) and selects the one with the lowest beacon count in which to form the network.

**Note:**

-   This assessment takes into account IEEE802.15.4 beacons only and no activity from networks based on other systems, such as Wi-Fi.
-   The assessment is based on beacons only and does not consider the noise levels of the shortlisted channels.


```{include} ../topics/default_behavior.md
:heading-offset: 2
```

```{include} ../topics/customizing_the_scan.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

