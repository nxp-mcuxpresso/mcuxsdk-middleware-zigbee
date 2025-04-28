# ZPS\_tsAplZdpEndDeviceBindReq

This structure is used by the function **ZPS\_eAplZdpEndDeviceBindRequest\(\)**. It represents a request to the Coordinator to bind an endpoint on the local node to an endpoint on a remote node \(the Coordinator must match two such binding requests, from the local node and remote node\).

The `ZPS_tsAplZdpEndDeviceBindReq`structure is detailed below.

```
typedef struct {
uint16 u16BindingTarget;
uint64 u64SrcIeeeAddress;
uint8 u8SrcEndpoint;
uint16 u16ProfileId;
/* Rest of the message is variable length */
uint8 u8NumInClusters;
uint16 *pu16InClusterList;
uint8 u8NumOutClusters;
uint16 *pu16OutClusterList;
} ZPS_tsAplZdpEndDeviceBindReq;
```

where:

-   `u16BindingTarget`is the network address of the node to hold the binding \(either a node with primary binding table cache or the local node\).
-   `u64SrcIeeeAddress`is the IEEE address of the local node.
-   `u8SrcEndpoint`is the number of the local endpoint to be bound \(1-240\).
-   `u16ProfileId`is the application profile ID to be matched for the binding.
-   `u8NumInClusters`is the number of input clusters of the local endpoint \(available for matching with output clusters of remote node to be bound\).
-   `pu16InClusterList`is a pointer to the input cluster list of the local endpoint \(containing clusters for matching with output clusters of remote node\).
-   `u8NumOutClusters`is the number of output clusters of the local endpoint \(available for matching with input clusters of remote node to be bound\).
-   `pu16OutClusterList`is a pointer to the output cluster list of the local endpoint \(containing clusters for matching with input clusters of remote node\).

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

