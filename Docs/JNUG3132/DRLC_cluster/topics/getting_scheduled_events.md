# Getting Scheduled Events

The application on the DRLC cluster client can send a Get Scheduled Events message to the cluster server in order to obtain relevant current and future LCEs. This message may be used in the following situations:

-   On a non-sleeping device, the application may send this message:

    -   immediately after binding with the cluster server in order to get the initial LCEs \(subsequent LCEs are received unsolicited from the server\).

    -   at other times in order to top up its LCE list, if it has previously discarded an LCE due to lack of storage.

-   On a sleeping device \(End Device\), the application may send this message on waking from sleep in order to obtain new LCEs that were distributed by the cluster server during sleep \(and therefore not received\).


The Get Scheduled Events message can be sent from a client using the function `eSE_DRLCGetScheduledEventsSend()`. The message includes the earliest start-time of the LCEs of interest, where zero is used to indicate all LCEs - for a sleeping End Device, this time should be set to zero or the current time, in case there are replacements on the server for LCEs already in the client’s lists. The message also allows the maximum number of returned LCEs to be specified, where zero is used to indicate all LCEs.

**Note:** The arrival of the Get Scheduled Events message results in the generation of the E\_SE\_DRLC\_EVENT\_COMMAND callback event, containing a DRLC\_GET\_SCHEDULED\_EVENTS command on the cluster server. However, the cluster responds to the message automatically.

On receiving the requested LCEs from the cluster server, the cluster client automatically updates the local LCE lists with the reported LCEs.

**Parent topic:**[LCE Handling on Clients](../../DRLC_cluster/topics/lce_handling_on_clients.md)

