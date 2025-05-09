# Requesting a schedule \(by server\)

The server application can request a schedule for a supported power profile from the client by calling the function **eCLD\_PPEnergyPhasesScheduleReqSend\(\)**, which sends an Energy Phases Schedule Request to the client.

The client can only return the requested schedule information if it stores this type of information for the power profile. If this is the case, an E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_REQ event is generated on the client, with the `bIsInfoAvailable` field set to TRUE in the event structure `tsCLD_PPCallBackMessage`, and the client will send an Energy Phases Schedule Response back to the server. Otherwise, the client sends a ZCL default response with status NOT\_FOUND.

On receiving an Energy Phases Schedule Response from the client, the event E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_RSP is generated on the server, containing the requested schedule information in a `tsCLD_PP_EnergyPhasesSchedulePayload` structure \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\). One or more of the following outcomes result:

-   If the attribute`bEnergyRemote` is set to FALSE on the server \(no remote control of the device\), the server simply rejects the received schedule.

-   If the received schedule information contains an `u16MaxActivationDelay` value of zero for an energy phase \(see [tsCLD\_PP\_EnergyPhaseInfo](tscld_pp_energyphaseinfo.md)\), this energy phase is rejected by the server although other valid energy phases are accepted. For each rejected energy phase, the server sends a ZCL default response with status NOT\_AUTHORIZED to the client.

-   If the received schedule information results in an update of the power profile schedule on the server, the server automatically sends an Energy Phases Schedule State Notification back to the client. On receiving this notification, an E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_NOTIFICATION event is generated on the client.


**Note:** Before requesting a power profile schedule, the server application may send the schedule’s timing constraints to the client using the function **eCLD\_PPPowerProfileScheduleConstraintsNotificationSend\(\)**. The client application can alternatively request these schedule constraints from the server by calling **eCLD\_PPPowerProfileScheduleConstraintsReqSend\(\)**.

**Parent topic:**[Communicating schedule information](../../power_profile_cluster/topics/communicating_schedule_information.md)

