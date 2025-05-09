# eCLD\_DoorLockSetLockState

```
teZCL_Status eCLD_DoorLockSetLockState(
    uint8 u8SourceEndPointId,
    teCLD_DoorLock_LockState eLock);

```

## Description 

This function can be used on a Door Lock cluster server to set the value of the `eLockState` attribute which represents the current state of the door lock \(locked, unlocked or not fully locked\).

Depending on the specified value of *eLock*, the attribute will be set to one of the following:

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK

-   E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK


This function generates an update event to inform the application when the change has been made.

## Parameters 

-   *u8SourceEndPointId*        Number of the endpoint on which the Door Lock cluster resides
-   *eLock*         State in which to put the door lock, one of:
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK
-           E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Functions](../../door_lock_cluster/topics/functions.md)

