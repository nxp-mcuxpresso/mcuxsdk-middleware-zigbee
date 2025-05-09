# eCLD\_DoorLockGetLockState

```
teZCL_Status eCLD_DoorLockGetLockState(
    uint8 u8SourceEndPointId,
    teCLD_DoorLock_LockState *peLock);

```

## Description 

This function can be used on a Door Lock cluster server to obtain the value of the `eLockState` attribute which represents the current state of the door lock \(locked, unlocked or not fully locked\).

The value of the attribute is returned through the location pointed to by `peLock` and can be any one of the following:

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK


## Parameters 

-   *u8SourceEndPointId*        Number of the endpoint on which the Door Lock cluster resides
-   *peLock*         Pointer to location to receive the obtained state of the door lock, which will be one of:
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../door_lock_cluster/topics/functions.md)

