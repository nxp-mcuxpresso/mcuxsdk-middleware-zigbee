# tsCLD\_PPEntry

This structure contains the data for a power profile table entry.

```
typedef struct
{
  zuint8  u8PowerProfileId;
  zuint8  u8NumOfTransferredEnergyPhases;
  zuint8  u8NumOfScheduledEnergyPhases;
  zuint8  u8ActiveEnergyPhaseId;
  tsCLD_PP_EnergyPhaseDelay        
       asEnergyPhaseDelay[CLD_PP_NUM_OF_ENERGY_PHASES];
   tsCLD_PP_EnergyPhaseInfo        
       asEnergyPhaseInfo[CLD_PP_NUM_OF_ENERGY_PHASES];
   zbool   bPowerProfileRemoteControl;
   zenum8   u8PowerProfileState;
   zuint16  u16StartAfter;
   zuint16  u16StopBefore; 
} tsCLD_PPEntry;

```

where:

-   `u8PowerProfileId` is the identifier of the power profile in the range 1 to 255 \(0 is reserved\)

-   `u8NumOfTransferredEnergyPhases` is the number of energy phases supported within the power profile

-   `u8NumOfScheduledEnergyPhases` is the number of energy phases actually scheduled within the power profile \(must be less than or equal to the value of `u8NumOfTransferredEnergyPhases`\)

-   `u8ActiveEnergyPhaseId` is the identifier of the energy phase that is currently active or will be active next \(if currently between energy phases\)

-   `asEnergyPhaseDelay[]` is an array containing timing information on the scheduled energy phases, where each array element corresponds to one energy phase of the schedule \(see [Section 21.10.12](tscld_pp_energyphasedelay.md#id_f35a9742-8103-4549-ac3c-8e862fb0a6eb)\)

-   `asEnergyPhaseInfo[]` is an array containing various information on the supported energy phases, where each array element corresponds to one energy phase of the profile \(see [Section 21.10.11](tscld_pp_energyphaseinfo.md#id_69a8a2a9-cbb0-4338-a129-ef02e810d0f8)\)

-   `bPowerProfileRemoteControl` is a boolean indicating whether the power profile can be remotely controlled: TRUE if it can be remotely controlled, FALSE otherwise \(this property directly affects the attribute `bEnergyRemote`\)

-   `u8PowerProfileState` is a value indicating the current state of the power profile \(enumerations are provided - see [Section 21.9.2](power_profile_state_enumerations.md#id_661944ca-6f1d-45f9-abfa-d84e7d80de5d)\)

-   `u16StartAfter` is the minimum time-delay, in minutes, to be implemented between an instruction to start the power profile schedule and actually starting the schedule

-   `u16StopBefore` is the maximum time-delay, in minutes, to be implemented between an instruction to stop the power profile schedule and actually stopping the schedule


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

