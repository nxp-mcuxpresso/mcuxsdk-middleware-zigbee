# tsCLD\_PP\_EnergyPhaseInfo

This structure contains various pieces of information about a specific energy phase of a power profile.

```
typedef struct
{
    zuint8  u8EnergyPhaseId;
    zuint8  u8MacroPhaseId;
    zuint16  u16ExpectedDuration;
    zuint16  u16PeakPower;
    zuint16  u16Energy;
    zuint16  u16MaxActivationDelay;        
}tsCLD_PP_EnergyPhaseInfo;

```

where:

-   `u8EnergyPhaseId` is the identifier of the energy phase

-   `u8MacroPhaseId` is a value that may be used to obtain a name/label for the energy phase for display purposes - for example, it may be the index of an entry in a table of ASCII strings

-   `u16ExpectedDuration` is the expected duration of the energy phase, in minutes

-   `u16PeakPower` is the estimated peak power of the energy phase, in Watts

-   `u16Energy` is the estimated total energy consumption, in Joules, during the energy phase \(≤ `u16PeakPower` x `u16ExpectedDuration` x `60`\)

-   `u16MaxActivationDelay` is the maximum delay, in minutes, between the end of the previous energy phase and the start of this energy phase - special values are as follows: 0x0000 if no delay possible, 0xFFFF if first energy phase


**Note:** If `u16MaxActivationDelay` is non-zero, a delayed start-time for the energy phase can be set through the structure `tsCLD_PP_EnergyPhaseDelay` \(see [Section 21.10.12](tscld_pp_energyphasedelay.md#id_f35a9742-8103-4549-ac3c-8e862fb0a6eb)\).

**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

