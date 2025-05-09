# tsCLD\_PP\_EnergyPhaseDelay

This structure contains the start-time for a particular energy phase of a power profile.

```
typedef struct
{
     zuint8   u8EnergyPhaseId;
     zuint16  u16ScheduleTime;
}tsCLD_PP_EnergyPhaseDelay;

```

where:

-   `u8EnergyPhaseId` is the identifier of the energy phase

-   `u16ScheduleTime` is the start-time of the energy phase expressed as a delay, in minutes, from the end of the previous energy phase \(for the first energy phase of a power profile schedule, this delay is measured from the start of the schedule\)


**Note:** A delayed start-time for the energy phase can only be set through this structure if the field `u16MaxActivationDelay` of the structure `tsCLD_PP_EnergyPhaseInfo` for this energy phase is non-zero \(see [Section 21.10.11](tscld_pp_energyphaseinfo.md#id_69a8a2a9-cbb0-4338-a129-ef02e810d0f8)\).

**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

