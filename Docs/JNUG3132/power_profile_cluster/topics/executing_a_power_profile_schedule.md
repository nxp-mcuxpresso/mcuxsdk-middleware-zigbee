# Executing a Power Profile Schedule

After receiving a power profile schedule from the client \(as described in [Section](communicating_schedule_information.md#id_791e57a7-03ba-4df8-ac3b-0d557fc90266)21.5.4\), the server can start execution of the schedule. The instruction to start the schedule comes from the client in the form of an Energy Phases Schedule Notification. To issue this instruction, the client application must call the function **eCLD\_PPEnergyPhasesScheduleNotificationSend\(\)**. On receiving the notification, the server automatically starts the schedule.

The possible states of a power profile are fully detailed in [Section 21.9.2](power_profile_state_enumerations.md#id_661944ca-6f1d-45f9-abfa-d84e7d80de5d) but, generally, it moves through the following principal states before, during and after execution:

-   E\_CLD\_PP\_STATE\_PROGRAMMED: The power profile is defined in the local power profile table but a schedule has not been received from the client. Even without a schedule from the client, a schedule of energy phases that was defined when the power profile was introduced using the function **eCLD\_PPAddPowerProfileEntry\(\)** can be started from this state \(see below\).

-   E\_CLD\_PP\_STATE\_WAITING\_TO\_START: The power profile remains in this state before the first energy phase starts and between energy phases \(provided there is a gap between the end of one phase and the beginning of the next\).

-   E\_CLD\_PP\_STATE\_RUNNING: An energy phase is running.

-   E\_CLD\_PP\_STATE\_ENDED: The final energy phase has completed.


Once a schedule has started, the server application must progress execution through the different states of the schedule by periodically calling the function **eCLD\_PPSchedule\(\)** once per second. This function moves the power profile to the next state, if it is due to start, and update the relevant state and timing parameters.

**Note:** The server application can also use the function **eCLD\_PPSetPowerProfileState\(\)** to ‘manually’ move execution of the schedule to a particular \(valid\) state, irrespective of whether the target state is scheduled. This function can be used by the server application to locally start a schedule from the ‘programmed’ state.

Whenever there is a change of state of a power profile, the cluster server automatically sends a Power Profile State Notification to the client. The server application can also send such a notification ‘manually’ by calling the function **eCLD\_PPPowerProfileStateNotificationSend\(\)**. The notification contains a power profile record that specifies the active power profile, the energy phase that is currently running \(or due to run next\) and the current state of the power profile. These notifications allow the controller to monitor the appliance. On receiving a notification on the client, an E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_NOTIFICATION event is generated, containing the sent power profile state information in a `tsCLD_PP_PowerProfileStatePayload` structure \(see [Section 21.10.5](tscld_pp_powerprofilestatepayload.md#id_f342d466-8058-4515-977d-10b00eecb718)\).

**Parent topic:**[Power profile operations](../../power_profile_cluster/topics/power_profile_operations.md)

