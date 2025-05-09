# tsCLD\_PP\_PowerProfilePayload

This structure contains the payload of a Power Profile Response or of a Power Profile Notification, which reports the details of a power profile.

```
typedef struct
{
   zuint8       u8TotalProfileNum;
   zuint8       u8PowerProfileId;
   zuint8       u8NumOfTransferredPhases;
   tsCLD_PP_EnergyPhaseInfo *psEnergyPhaseInfo;
}tsCLD_PP_PowerProfilePayload;

```

where:

-   `u8TotalProfileNum` is the total number of power profiles supported on the originating device

-   `u8PowerProfileId` is the identifier of the power profile being reported

-   `u8NumOfTransferredPhases` is the number of energy phases supported within the power profile

-   `psEnergyPhaseInfo` is a pointer to a structure or an array of structures \(see [Section 21.10.11](tscld_pp_energyphaseinfo.md#id_69a8a2a9-cbb0-4338-a129-ef02e810d0f8)\) containing information on the supported energy phases, where each array element corresponds to one energy phase of the profile


**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

