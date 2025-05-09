# tsCLD\_PP\_PowerProfiIeRecord

This structure contains information about the current state of a power profile.

```
typedef struct
{
     zuint8   u8PowerProfileId;
     zuint8   u8EnergyPhaseId;
     zbool    bPowerProfileRemoteControl;
     zenum8   u8PowerProfileState;
} tsCLD_PP_PowerProfileRecord;

```

where:

-   `u8PowerProfileId` is the identifier of the power profile

-   `u8EnergyPhaseId` is the identifier of the currently running energy phase or, if currently between energy phases, the next energy phase to be run

-   `bPowerProfileRemoteControl` is a boolean indicating whether the power profile can be remotely controlled \(from a client device\): TRUE if it can be remotely controlled, FALSE otherwise

-   `u8PowerProfileState` is an enumeration indicating the current state of the power profile \(see [Section 21.9.2](power_profile_state_enumerations.md#id_661944ca-6f1d-45f9-abfa-d84e7d80de5d)\)


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

