# eCLD\_PPSetPowerProfileState

```
teZCL_CommandStatus eCLD_PPSetPowerProfileState(
    uint8 u8SourceEndPointId,
    uint8 u8PowerProfileId,
    teCLD_PP_PowerProfileState sPowerProfileState);

```

## Description 

This function can be used on a cluster server to move the specified power profile to the specified target state. Enumerations for the possible states are provided, and are listed and described in [Section 21.9.2](power_profile_state_enumerations.md#id_661944ca-6f1d-45f9-abfa-d84e7d80de5d).

The function performs the following checks:

-   Checks whether the specified Power Profile ID exists \(if not, the function returns with the status E\_ZCL\_CMDS\_NOT\_FOUND\)

-   Checks whether the specified target state is a valid state \(if not, the function returns with the status E\_ZCL\_CMDS\_INVALID\_VALUE\)

-   Checks whether the power profile is currently able move to the target state \(if not, the function returns with the status E\_ZCL\_CMDS\_INVALID\_FIELD\)


**Note:** The power profile state can be changed by this function only if the move from the existing state to the target state is a valid change.

If all the checks are successful, the move is implemented \(and the function returns with the status E\_ZCL\_CMD\_SUCCESS\).

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster resides
-   *u8PowerProfileId* : Identifier of the power profile
-   *sPowerProfileState*: Target state to which power profile is to be moved - enumerations are provided \(see [Section 21.9.2](power_profile_state_enumerations.md#id_661944ca-6f1d-45f9-abfa-d84e7d80de5d)\)

## Returns 

-   E\_ZCL\_CMD\_SUCCESS
-   E\_ZCL\_CMDS\_NOT\_FOUND
-   E\_ZCL\_CMDS\_INVALID\_VALUE
-   E\_ZCL\_CMDS\_INVALID\_FIELD

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

