# Requesting the Scheduled Energy Phases \(by Client\)

The client application can use the function **eCLD\_PPEnergyPhasesScheduleStateReqSend\(\)** to send an Energy Phases Schedule State Request to the cluster server, in order to obtain the schedule of energy phases for a particular power profile on the server.

On receiving the response on the client, the event E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_RSP is generated, containing the requested schedule information. The obtained schedule can be used to re-align the schedule information on the client with the information on the server - for example, after a reset of the client device.

**Parent topic:**[Communicating schedule information](../../power_profile_cluster/topics/communicating_schedule_information.md)

