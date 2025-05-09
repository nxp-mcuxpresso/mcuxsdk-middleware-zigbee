# Reporting LCE Actions to Server

By default, a DRLC cluster client sends a Report Event Status message to the cluster server when an LCE is actioned on the client - that is, when an LCE is moved between lists on the client, such as from ‘Scheduled’ to ‘Active’ or from ‘Active’ to ‘Deallocated’ \(see [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11)\). Details of the actioned LCE are sent in a `tsSE_DRLCReportEvent` structure \(see [Section 41.11.4](tsse_drlcreportevent.md#id_ad267160-eaa3-467d-b21b-caa82083dbd5)\). The nature of the action is indicated in this structure using an enumeration \(see [Section 41.10.8](lce_status_enumerations.md#id_a042c90e-cd3d-45f8-8472-9845f41ecca4)\).

**Note:** The DRLC cluster server is informed of the arrival of a Report Event Status message via the callback event **E\_SE\_DRLC\_EVENT\_COMMAND**, containing a SE\_DRLC\_REPORT\_EVENT\_STATUS command. The ESP/server may inform the utility company of the reported status - if the message cannot be forwarded immediately then it must be buffered by the application.

If a DRLC cluster client opts out of a particular LCE using the function **eSE\_DRLCSetEventUserOption\(\)**, a Report Event Status message is sent to the cluster server to indicate this. On reaching the end-time of the LCE, another Report Event Status message is sent to the server to confirm that the LCE has completed without the participation of the local client.

**Parent topic:**[LCE Handling on Clients](../../DRLC_cluster/topics/lce_handling_on_clients.md)

