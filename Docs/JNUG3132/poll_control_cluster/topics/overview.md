# Overview

An End Device cannot receive data packets directly, as it might be asleep when a packet arrives. The data packets for an End Device are therefore buffered by the device’s parent and the End Device polls its parent for data while awake. An individual data packet is only held on the parent node for a maximum of 7.68 seconds and if many packets for the End Device are expected over a short period of time, the End Device should retrieve these packets as quickly as possible. An End Device can implement two polling modes, which are dependent on the poll interval \(time-period between consecutive polls\):

-   **Normal poll mode:** A long poll interval is used - this mode is appropriate when the End Device is not expecting data packets.

-   **Fast poll mode:** A short poll interval is used - this mode is appropriate when the End Device is expecting data packets.


The End Device may enable fast poll mode itself when it is expecting data packets \(for example, after it has requested data from remote nodes\). The Poll Control cluster allows fast poll mode to be selected from a remote control device to force the End Device to be more receptive to data packets \(for example, when a download to the End Device involving a large number of unsolicited data packets is to be initiated\).

The two sides of the cluster are located as follows:

-   The cluster server is implemented on the End Device to be controlled

-   The cluster client is implemented on the remote controller device


The cluster server \(End Device\) periodically checks whether the cluster client \(remote controller\) requires the poll mode to be changed. This ‘check-in’ method is used since an unsolicited instruction from the controller may arrive when the End Device is asleep. The automatic ‘check-ins’ are conducted with all the remote endpoints \(on controller nodes\) to which the local endpoint \(on which the cluster resides\) is bound.

The cluster is enabled by defining CLD\_POLL\_CONTROL in the **zcl\_options.h** file. Further compile-time options for the Poll Control cluster are detailed in [Section 20.10](compile-time_options.md#id_7d993789-e40c-4abc-8761-8252637123ed).

**Parent topic:**[Poll Control Cluster](../../poll_control_cluster/topics/poll_control_cluster.md)

