# ZPS\_tsAplZdpBackupBindTableRsp

This structure is used to store Backup\_Bind\_Table\_rsp message data - a response to a call to the function **ZPS\_eAplZdpBackupBindTableRequest\(\)**. This response indicates the status of the back-up request.

The `ZPS_tsAplZdpBackupBindTableRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
    uint16 u16EntryCount;
} ZPS_tsAplZdpBackupBindTableRsp;
```

where:

-   `u8Status`is the return status for **ZPS\_eAplZdpBackupBindTableRequest\(\)**
-   `u16EntryCount`is the number of binding table entries that have been backed up

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

