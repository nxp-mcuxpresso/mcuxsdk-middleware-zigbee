# ZPS\_tsAplZdpMatchDescReq

This structure is used by the function **ZPS\_eAplZdpMatchDescRequest\(\)**. It represents a request for nodes with endpoints that match certain criteria in their Simple descriptors.

The `ZPS_tsAplZdpMatchDescReq`structure is detailed below.

`typedef struct {`

`uint16 u16NwkAddrOfInterest; uint16 u16ProfileId;`

`/* rest of message is variable length */ uint8 u8NumInClusters;`

`uint16* pu16InClusterList; uint8 u8NumOutClusters; uint16* pu16OutClusterList;`

`} ZPS_tsAplZdpMatchDescReq;`

where:

-   `u16NwkAddrOfInterest`is the network address of the node of interest
-   `u16ProfileId`is the identifier of the ZigBee application profile used
-   `u8NumInClusters`is the number of input clusters to be matched
-   `pu16InClusterList`is a pointer to the list of input clusters to be matched - this is a variable-length list of input cluster IDs, two bytes for each cluster
-   `u8NumOutClusters`is the number of output clusters to be matched
-   `pu16OutClusterList`is a pointer to the list of output clusters to be matched - this is a variable-length list of output cluster IDs, two bytes for each cluster

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

