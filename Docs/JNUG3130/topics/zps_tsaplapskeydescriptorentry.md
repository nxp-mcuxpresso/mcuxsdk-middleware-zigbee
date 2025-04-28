# ZPS\_tsAplApsKeyDescriptorEntry

This structure contains a link key for secured communications with another node.

```
typedef struct
{
    uint32     u32OutgoingFrameCounter;
    uint16     u16ExtAddrLkup;
    uint8      au8LinkKey[ZPS_SEC_KEY_LENGTH];
} ZPS_tsAplApsKeyDescriptorEntry;
```

where:

-   `u32OutgoingFrameCounter`is the outgoing frame counter value which is incremented on each transmission to a destination address below.
-   `u16ExtAddrLkup`is the index of the local look-up table entry that contains the IEEE/MAC address of either the Trust Centre or the target node.
-   `au8LinkKey[]`is an array containing the link key.

**Parent topic:**[Other structures](../topics/other_structures.md)

