# Description

This function can be used to add the addresses of a remote node to the local Address Map table. Each entry in this table stores a remote node’s 16-bit network address and an index to its 64-bit IEEE \(MAC\) address in the MAC Address table \(see [Section](network_addressing.md)[3.2.4](network_addressing.md)\). Thus, the function adds the IEEE address to the MAC Address table and then the index of this entry to the Address Map table.

**Note:** You should only modify the Address Map table using the supplied API functions and never write to it directly.

**Parent topic:**[ZPS\_eAplZdoAddAddrMapEntry](../topics/zps_eaplzdoaddaddrmapentry.md)

