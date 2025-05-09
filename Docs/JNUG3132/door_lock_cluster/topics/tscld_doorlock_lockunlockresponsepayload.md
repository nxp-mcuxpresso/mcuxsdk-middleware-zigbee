# tsCLD\_DoorLock\_LockUnlockResponsePayload

This stucture contains the payload of a lock/unlock command response \(from the cluster server\).

```
typedef struct
{
    zenum8     eStatus;
}tsCLD_DoorLock_LockUnlockResponsePayload;

```

where `e``Status` indicates whether the command was received:

0x00 - SUCCESS, 0x01 - FAILURE \(all other values are reserved\).

**Parent topic:**[Structures](../../door_lock_cluster/topics/structures.md)

