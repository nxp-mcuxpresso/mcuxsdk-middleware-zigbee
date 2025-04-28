# ZPS\_tsAplZdpStoreBkupBindEntryRsp

This structure is used to store Store\_Bkup\_Bind\_Entry\_rsp message data - a response to a call to the function **ZPS\_eAplZdpStoreBkupBindEntryRequest\(\)**. This response indicates the status of the back-up request.

The `ZPS_tsAplZdpStoreBkupBindEntryRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpStoreBkupBindEntryRsp;
```

where `u8Status`is the return status for the function **ZPS\_eAplZdpStoreBkupBindEntryRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

