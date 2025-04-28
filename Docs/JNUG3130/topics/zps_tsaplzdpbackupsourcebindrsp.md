# ZPS\_tsAplZdpBackupSourceBindRsp

This structure is used to store Backup\_Source\_Bind\_rsp message data - a response to a call to the function **ZPS\_eAplZdpBackupSourceBindRequest\(\)**. This response indicates the status of the back-up request.

The `ZPS_tsAplZdpBackupSourceBindRsp`structure is detailed below.

```
typedef struct {
    uint8 u8Status;
} ZPS_tsAplZdpBackupSourceBindRsp;
```

where `u8Status`is the return status for the function **ZPS\_eAplZdpBackupSourceBindRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

