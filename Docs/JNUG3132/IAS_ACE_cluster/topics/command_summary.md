# Command Summary

The IAS ACE cluster includes a number of commands that can be sent by the application on the client or server. These commands are summarised below.

-   [Table 50](#id_b3971864-e47c-4d3e-b615-22ab9fa3a13d) lists the commands that can be issued on the client.

-   [Table 51](#id_2ecc000b-8fba-43c4-946f-982d71abbdbf) lists the commands that can be issued on the server.


Functions are provided to send these commands - these functions are indicated in the descriptions below and detailed in [Section 38.6](functions.md#id_74e7490a-9a33-4872-a939-c37c6a4f4c28).

**IAS ACE Cluster Commands from Client to Server**

| Command                | Description and Function                                                                                                                                                                                                                                                                                                             |
| ---------------------- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| Arm                    | Instructs the server to put all or certain enrolled zones into the ‘armed’ state or put all of them into the ‘disarmed’ state.<br>eCLD_IASACE_ArmSend()                                                                                                                                                                              |
| Bypass                 | Instructs the server to take one or more specified zones out of the system for the current activation (these zones are reinstated the next time the system is dis-armed and to exclude them again the next time the system is armed, the Bypass command must be re-sent before sending the Arm command).<br>eCLD_IASACE_BypassSend() |
| Emergency              | Instructs the server to put the alarm in the ‘Emergency’ state.<br>eCLD_IASACE_EmergencySend()                                                                                                                                                                                                                                       |
| Fire                   | Instructs the server to put the alarm in the ‘Fire’ state.<br>eCLD_IASACE_FireSend()                                                                                                                                                                                                                                                 |
| Panic                  | Instructs the server to put the alarm in the ‘Panic’ state.<br>eCLD_IASACE_PanicSend()                                                                                                                                                                                                                                               |
| Get Zone ID Map        | Requests the Zone IDs that have been allocated to zones.<br>eCLD_IASACE_GetZoneIDMapSend()                                                                                                                                                                                                                                           |
| Get Zone Information   | Requests information on a specified zone.<br>eCLD_IASACE_GetZoneInfoSend()                                                                                                                                                                                                                                                           |
| Get Panel Status       | Requests the current status of the (display) panel.<br>eCLD_IASACE_GetPanelStatusSend()                                                                                                                                                                                                                                              |
| Get Bypassed Zone List | Requests a list of the currently bypassed zones. <br>eCLD_IASACE_GetBypassedZoneListSend()                                                                                                                                                                                                                                           |
| Get Zone Status        | Requests a list of either all zones with their status or those zones with a particular status (that is, all zones with the b16ZoneStatus attribute of the IAS Zone cluster having a certain value). eCLD_IASACE_GetZoneStatusSend()                                                                                                  |


**IAS ACE Cluster Commands from Server to Client**
| Command                | Description and Function                                                                                                                                                   |
| ---------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| Set Bypassed Zone List | Informs the client which zones are currently bypassed and can be sent in response to a Bypassed Zone List command, Get eCLD_IASACE_SetBypassedZoneListSend()               |
| Zone Status Changed    | Informs the client that the status (value of the b16ZoneStatus attribute of the IAS Zone cluster) of a particular zone has changed.<br>eCLD_IASACE_ZoneStatusChangedSend() |
| Panel Status Changed   | Informs the client that the status of the (display) panel has changed. eCLD_IASACE_PanelStatusChanged()                                                                    |

**Parent topic:**[IAS Ancillary Control Equipment Cluster](../../IAS_ACE_cluster/topics/ias_ancillary_control_equipment_cluster.md)

