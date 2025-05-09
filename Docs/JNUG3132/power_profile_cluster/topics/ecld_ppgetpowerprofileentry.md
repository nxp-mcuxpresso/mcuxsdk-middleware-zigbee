# eCLD\_PPGetPowerProfileEntry

```
teZCL_Status eCLD_PPGetPowerProfileEntry(
    uint8 u8SourceEndPointId,
    uint8 u8PowerProfileId,
    tsCLD_PPEntry **ppsPowerProfileEntry);

```

## Description 

This function can be used on a cluster server to obtain an entry from the local power profile table. The required entry is specified using the relevant Power Profile ID. The function obtains a pointer to the relevant entry, if it exists - a pointer must be provided to a location to receive the pointer to the entry.

If no entry with the specified Power Profile ID is found, the function returns E\_ZCL\_ERR\_INVALID\_VALUE.

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which cluster resides
-   *u8PowerProfileId*: Identifier of power profile to be obtained
-   *ppsPowerProfileEntry*: Pointer to a location to receive a pointer to the required power profile table entry \(see [Section 21.10.2](tscld_ppentry.md#id_0b02e806-25f8-4e82-a2ef-394f596c0691)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_INVALID\_VALUE

**Parent topic:**[Server Functions](../../power_profile_cluster/topics/server_functions.md)

