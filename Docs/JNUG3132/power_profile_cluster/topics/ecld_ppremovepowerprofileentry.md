# eCLD\_PPRemovePowerProfileEntry

```
teZCL_Status eCLD_PPRemovePowerProfileEntry(
    uint8 u8SourceEndPointId,
    uint8 u8PowerProfileId);

```

## Description 

This function can be used on a cluster server to remove a power profile by deleting the relevant entry in the local power profile table.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster resides:
-   *u8PowerProfileId* : Identifier of power profile to be removed

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

