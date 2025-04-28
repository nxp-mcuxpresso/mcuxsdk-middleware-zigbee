# ZPS\_tsAfZdoLinkKeyEvent

This structure is used in the ZPS\_EVENT\_ZDO\_LINK\_KEY event, which indicates that a new application link key has been received and installed, and is ready for use.

The `ZPS_tsAfZdoLinkKeyEvent`structure is defined as:

```
typedef struct {
    uint64 u64IeeeLinkAddr;
} ZPS_tsAfZdoLinkKeyEvent;
```

where `u64IeeeLinkAddr`is the IEEE/MAC address of the remote device with which the installed link key is valid.

**Parent topic:**[Event structures](../topics/event_structures.md)

