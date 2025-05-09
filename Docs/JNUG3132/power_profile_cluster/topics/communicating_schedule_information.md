# Communicating schedule information

A power profile schedule comprises a sequence of energy phases and their relative start-times \(the energy phases may have gaps between them\):

-   An energy phase is identified by its Energy Phase Identifier, in the range 1 to 255 \(inclusive\).

-   The start-time of an energy phase is expressed as a delay, in minutes, from the end of the previous energy phase. For the first energy phase of a power profile schedule, this delay is measured from the time that the schedule was started.


**Note:** The normal duration of an energy phase, in minutes, is fixed and is specified in the energy phase information in the power profile.

Although a power profile on the cluster server may support multiple energy phases, the schedule for the power profile may possibly incorporate only a sub-set of these phases. The client \(controller\) selects the set of energy phases in a schedule and communicates this schedule to the server \(appliance\). This may be done through a request or notification, as described in [Section 21.5.4.1](requesting_a_schedule_by_server.md#id_cd6274b7-0366-4883-9612-b48405b2c9e6) and [Section 21.5.4.2](notification_of_a_schedule_by_client.md#id_b545b6d7-cc27-4a0e-bfca-dd8b143c2a3b) below.


```{include} ../../power_profile_cluster/topics/requesting_a_schedule_by_server.md
:heading-offset: 3
```

```{include} ../../power_profile_cluster/topics/notification_of_a_schedule_by_client.md
:heading-offset: 3
```

```{include} ../../power_profile_cluster/topics/notification_of_energy_phases_in_power_profile_sch.md
:heading-offset: 3
```

```{include} ../../power_profile_cluster/topics/requesting_the_scheduled_energy_phases_by_client.md
:heading-offset: 3
```

**Parent topic:**[Power profile operations](../../power_profile_cluster/topics/power_profile_operations.md)

