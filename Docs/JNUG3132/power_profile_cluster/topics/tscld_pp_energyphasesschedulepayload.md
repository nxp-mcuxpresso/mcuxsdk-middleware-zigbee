# tsCLD\_PP\_EnergyPhasesSchedulePayload

This structure contains the payload of an Energy Phases Schedule Response, of an Energy Phases Schedule State Response or of an Energy Phases Schedule State Notification.

```
typedef struct
{
  zuint8   u8PowerProfileId;
  zuint8   u8NumOfScheduledPhases;
  tsCLD_PP_EnergyPhaseDelay 
                    *psEnergyPhaseDelay;
}tsCLD_PP_EnergyPhasesSchedulePayload;

```

where:

-   `u8PowerProfileId` is the identifier of the power profile being reported

-   `u8NumOfScheduledPhases` is the number of energy phases within the power profile schedule

-   `psEnergyPhaseDelay` is a pointer to an array containing timing information on the scheduled energy phases, where each array element corresponds to one energy phase of the schedule \(see [Section 21.10.12](tscld_pp_energyphasedelay.md#id_f35a9742-8103-4549-ac3c-8e862fb0a6eb)\)


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

