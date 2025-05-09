# Adding a power profile entry

The server application can introduce a new power profile by adding a corresponding entry to the power profile table using the function **eCLD\_PPAddPowerProfileEntry\(\)**. The new power profile table entry is specified in a `tsCLD_PPEntry` structure \(see [Section 21.10.2](tscld_ppentry.md#id_0b02e806-25f8-4e82-a2ef-394f596c0691)\) supplied to this function. This structure includes the Power Profile ID - these identifiers should be numbered consecutively from 1 to 255.

The function **eCLD\_PPAddPowerProfileEntry\(\)** can also be used to replace \(over-write\) an existing power profile table entry, in which case the new entry should have the same Power Profile ID as the existing entry to be replaced.

**Parent topic:**[Adding and removing a power profile \(server only\)](../../power_profile_cluster/topics/adding_and_removing_a_power_profile_server_only.md)

