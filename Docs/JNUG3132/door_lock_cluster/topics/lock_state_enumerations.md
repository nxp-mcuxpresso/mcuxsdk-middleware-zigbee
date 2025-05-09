# ‘Lock State’ Enumerations

The following enumerations are used to set the `eLockState` element in the Door Lock cluster structure `tsCLD_DoorLock`.

```
typedef enum 
{
    E_CLD_DOORLOCK_LOCK_STATE_NOT_FULLY_LOCKED  = 0x00,
    E_CLD_DOORLOCK_LOCK_STATE_LOCKED,
    E_CLD_DOORLOCK_LOCK_STATE_UNLOCKED,
    E_CLD_DOORLOCK_LOCK_STATE_UNDEFINED         = 0xFF
} teCLD_DoorLock_LockState;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_DOORLOCK\_LOCK\_STATE\_NOT\_FULLY\_LOCKED|Not fully locked|
|E\_CLD\_DOORLOCK\_LOCK\_STATE\_LOCK|Locked|
|E\_CLD\_DOORLOCK\_LOCK\_STATE\_UNLOCK|Unlocked|

**Parent topic:**[Enumerations](../../door_lock_cluster/topics/enumerations.md)

