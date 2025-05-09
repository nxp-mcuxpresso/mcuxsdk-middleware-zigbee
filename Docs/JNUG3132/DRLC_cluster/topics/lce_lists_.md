# LCE Lists

The DRLC cluster server and clients each hold the following lists of LCEs:

-   `**Active list:**` Contains LCEs that are currently being executed - it is possible for more than one LCE to be active at the same time, provided that their device classes and enrolment groups do not clash.

-   `**Scheduled list:**` Contains LCEs that are due to be executed in the future - that is, their start-time is later than the current time.

-   `**Cancelled list:**` Contains LCEs that have been canceled with a randomized end-time and whose random end-time has not yet been reached.

-   `**Deallocated list:**` Contains expired LCEs and therefore a record of the free storage for LCEs - used internally by the cluster \(and not by the application\).


A new LCE is first added to the Scheduled list, unless it has a ‘start-time of now’ in which case it is added to the Active list. An LCE in the Scheduled list is automatically moved to the Active list at the scheduled start-time \(or at the randomized start-time\). At the end of an active LCE, it is automatically moved to the `Deallocated list`. However, an active LCE which is canceled with a randomised end-time is automatically moved to the `Cancelled list`, where it stays until the end-time has been reached \(when it is moved to the Deallocated list\).

The addition of a new LCE on the cluster server is performed by the server application, as described in [Section 41.5.1](lce_handling_on_server.md#id_0d1bf6da-efa9-41fc-9f9a-6e3ae23e8261), but is done automatically by the cluster on the clients. All other operations on LCE lists, apart from cancelation \(see [Section 41.5.3](cancelling_lces.md#id_6109a002-620c-4d6b-82fe-d7316ac1d9e6)\), are performed automatically by the cluster on both server and client.

Functions are provided to access entries in the local LCE lists:

-   **eSE\_DRLCGetLoadControlEvent\(\)** can be used to obtain a particular LCE entry \(with specified list index\) in any one of the local lists

-   **eSE\_DRLCFindLoadControlEvent\(\)** can be used to search for and obtain a particular LCE \(with specified ID\) in any of the local lists


**Parent topic:**[Load Control Events \(LCEs\)](../../DRLC_cluster/topics/load_control_events_lces.md)

