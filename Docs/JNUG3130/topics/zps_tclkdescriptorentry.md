# ZPS\_TclkDescriptorEntry

This structure is used on the Trust Centre to hold information in RAM about a link key for a node, where this link key is held in persistent storage in devices Flash memory, as enabled by the function **ZPS\_vTcInitFlash\(\)**. If this feature is used, the application must allocate space for an array of these structures in RAM, with one structure for each potential node in the network.

```
typedef struct
{
    uint16   u16CredOffset;
    uint16   u16TclkRetries;
} ZPS_TclkDescriptorEntry;
```

where:

-   `u16CredOffset`is the offset, in bytes, of the storage location for the node’s link key in the relevant Flash memory sector.
-   `u16TclkRetries`is the number of retries that were attempted to negotiate the link key between the Trust Centre and the node.

**Parent topic:**[Other structures](../topics/other_structures.md)

