# ZPS\_tsAftsStartParamsDistributed

This structure contains the start parameter values for a node in a distributed security network.

```
typedef struct
{
    uint64     u64ExtPanId;
    uint8      *pu8NwkKey;
    uint16     u16PanId;
    uint16     u16NwkAddr;
    uint8      u8KeyIndex;
    uint8      u8LogicalChannel;
    uint8      u8NwkupdateId;
} ZPS_tsAftsStartParamsDistributed;
```

where:

-   `u64ExtPanId`is the Extended PAN ID of the distributed security network.
-   `pu8NwkKey`is a pointer to a location to receive the network key.
-   `u16PanId`is the PAN ID of the network.
-   `u16NwkAddr`is the network address of the local node.
-   `u8KeyIndex`is the sequence number required to identify the network key in the security set.
-   `u8LogicalChannel`is the number of the radio channel on which the network operates.
-   `u8NwkupdateId`is a unique byte value which is incremented when the network parameters are updated \(and is therefore used to determine whether a receiving node has missed an update\).

**Parent topic:**[Other structures](../topics/other_structures.md)

