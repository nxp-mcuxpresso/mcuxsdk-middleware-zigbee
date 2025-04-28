# ZPS\_tsAplZdpUserDescSet

This structure is used by the function **ZPS\_eAplZdpUserDescSetRequest\(\)**. It represents a request used to configure the User descriptor on a remote node.

The `ZPS_tsAplZdpUserDescSet`structure is detailed below.

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint8 u8Length;`

`char szUserDescriptor[ZPS_ZDP_LENGTH_OF_USER_DESC];`

`} ZPS_tsAplZdpUserDescSet;`

where:

-   `u16NwkAddrOfInterest`is the network address of the node of interest
-   `u8Length`is the length of the User descriptor
-   `szUserDescriptor`is the new User descriptor for the remote node as a character array.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

