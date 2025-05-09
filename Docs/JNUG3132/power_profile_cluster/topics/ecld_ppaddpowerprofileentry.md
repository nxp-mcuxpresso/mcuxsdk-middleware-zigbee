# eCLD\_PPAddPowerProfileEntry

```
teZCL_Status eCLD_PPAddPowerProfileEntry(
    uint8 u8SourceEndPointId,
    tsCLD_PPEntry *psPowerProfileEntry);

```

## Description 

This function can be used on a cluster server to introduce a new power profile by adding an entry to the local power profile table.

The function checks whether there is sufficient space in the table for the new power profile entry \(if not, the function returns with the status E\_ZCL\_ERR\_INSUFFICIENT\_SPACE\).

An existing power profile entry can be over-written with a new profile by specifying the same Power Profile ID \(in the new entry structure\).

The function also updates two of the cluster attributes \(if needed\), as follows.

-   If a power profile is introduced which has multiple energy phases \(as indicated by the `u8NumOfScheduledEnergyPhases` field of the `tsCLD_PPEntry` structure\), the attribute `bMultipleScheduling` is set to TRUE \(if not already TRUE\)

-   If a power profile is introduced which allows remote control for energy management \(as indicated by the `bPowerProfileRemoteControl` field of the `tsCLD_PPEntry` structure\), the attribute `bEnergyRemote` is set to TRUE \(if not already TRUE\)


## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster resides:
-   *psPowerProfileEntry* : Structure containing the power profile to add \(see [Section 21.10.2](tscld_ppentry.md#id_0b02e806-25f8-4e82-a2ef-394f596c0691)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INSUFFICIENT\_SPACE

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

