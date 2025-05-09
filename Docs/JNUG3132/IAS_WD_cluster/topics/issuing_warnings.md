# Issuing Warnings

The IAS WD cluster allows a device which detects warning conditions \(example, fire\) to trigger a warning on an IAS Warning Device which, in turn, initiates a physical alarm such as a siren and/or strobe. The IAS Warning Device hosts the cluster server and the triggering device hosts the cluster client.

Two types of warning can be initiated:

-   **Warning mode:** This mode indicates a genuine emergency, such as a fire or an intruder. On detection of the emergency condition, the application on the triggering device must call the **eCLD\_IASWDStartWarningReqSend\(\)** function, which sends a Start Warning command to the Warning Device. The payload of this command contains the time-duration for which the Warning Device must remain in warning mode. The specified duration must not exceed the maximum duration defined in the `u16MaxDuration` attribute on the Warning Device \(see [Section 39.2](ias_wd_structure_and_attribute.md#id_c5ba410e-819f-4976-9192-55f03054499b)\). The payload also contains details of the warning and the strobe requirements, if any. On receiving this command, an E\_CLD\_IASWD\_CMD\_WD\_START\_WARNING event is generated on the Warning Device \(see [Section 39.4](ias_wd_events.md#id_529369fc-27f8-4297-9236-1995a43bf37b)\) for the attention of the application.

-   **Squawk mode:** This mode indicates a change of state of the IAS system - that is, armed or disarmed. Thus, this is typically a short audible beep or ‘squawk’ that is emitted when the system is armed or disarmed. To initiate a squawk, the application on the triggering device must call the function **eCLD\_IASWDSquawkReqSend\(\)**, which sends a Squawk command to the Warning Device. The payload also contains details of the squawk and the strobe requirements, if any. On receiving this command, an E\_CLD\_IASWD\_CMD\_WD\_SQUAWK event is generated on the Warning Device \(see [Section 39.4](ias_wd_events.md#id_529369fc-27f8-4297-9236-1995a43bf37b)\) for the attention of the application.


The payloads of the commands are detailed in [Section 39.6.2](custom_command_payloads.md#id_32e3eeca-7fb1-44b3-84c4-aab62a0010d2).

**Note:** In order to maintain timing information on the cluster server, the application on the Warning Device must periodically call the **eCLD\_IASWDUpdate\(\)** function every 100 ms. These calls can be prompted using a software timer.

**Note:** The `u16MaxDuration` attribute on the Warning Device can be updated by the application on this device by calling the function **eCLD\_IASWDUpdateMaxDuration\(\)**.

**Parent topic:**[IAS Warning Device Cluster](../../IAS_WD_cluster/topics/ias_warning_device_cluster.md)

