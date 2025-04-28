# Description

This function can be used to add the 64-bit IEEE \(MAC\) address of a node to the local MAC Address table. The function first searches the table to determine whether the address already exists in the table. If there is no entry for this address, a new entry for it is added to the table. The number of the entry where the address was found or added is returned in a specified location.

**Note:** You should modify the MAC Address table only using the supplied API functions and never write to it directly.

**Parent topic:**[ZPS\_bNwkFindAddIeeeAddr](../topics/zps_bnwkfindaddieeeaddr.md)

