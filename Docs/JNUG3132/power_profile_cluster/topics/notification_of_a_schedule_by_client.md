# Notification of a Schedule \(by Client\)

The cluster client may send an unsolicited notification of a power profile schedule to the server. To do this, the client application must call the function **eCLD\_PPEnergyPhasesScheduleNotificationSend\(\)** which sends an Energy Phases Schedule Notification containing the schedule. This information is supplied to the function in a `tsCLD_PP_EnergyPhasesSchedulePayload` structure \(see [Section 21.10.6](tscld_pp_energyphasesschedulepayload.md#id_7cb84019-37b8-4b94-b6ec-094c6c904565)\).

On receiving the notification on the server, the event E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_NOTIFICATION is generated, containing the sent power profile schedule. One or more of the following outcomes will result:

-   If the attribute `bEnergyRemote` is set to FALSE on the server \(no remote control of the device\), the server will simply reject the received schedule.

-   If the received schedule information contains an `u16MaxActivationDelay` value of zero for an energy phase \(see [Section 21.10.11](tscld_pp_energyphaseinfo.md#id_69a8a2a9-cbb0-4338-a129-ef02e810d0f8)\), this energy phase is rejected by the server although other valid energy phases will be accepted. For each rejected energy phase, the server will send a ZCL default response with status NOT\_AUTHORIZED to the client.

-   If the received schedule information results in an update of the power profile schedule on the server, the server will automatically send an Energy Phases Schedule State Notification back to the client. On receiving this notification, an E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_NOTIFICATION event is generated on the client.


**Parent topic:**[Communicating schedule information](../../power_profile_cluster/topics/communicating_schedule_information.md)

