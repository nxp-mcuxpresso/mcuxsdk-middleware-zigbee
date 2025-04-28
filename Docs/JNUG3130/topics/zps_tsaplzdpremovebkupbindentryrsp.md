# ZPS\_tsAplZdpRemoveBkupBindEntryRsp

This structure is used to store Remove\_Bkup\_Bind\_Entry\_rsp message data - a response to a call to the function **ZPS\_eAplZdpRemoveBkupBindEntryRequest\(\)**. This response indicates the status of the remove request.

The `ZPS_tsAplZdpRemoveBkupBindEntryRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpRemoveBkupBindEntryRsp;
```

where `u8Status`is the return status for the function **ZPS\_eAplZdpRemoveBkupBindEntryRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

