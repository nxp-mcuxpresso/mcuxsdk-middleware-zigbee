# bZCL\_GetTimeHasBeenSynchronised

```
bool_t bZCL_GetTimeHasBeenSynchronised(void);

```

## Description 

This function queries whether the ZCL time on the device has been synchronized.

The clock is considered to be unsynchronized at start-up and is synchronized following a call to **vZCL\_SetUTCtime\(\)**. The ZCL time must be synchronized before using the time-related functions of other clusters.

## Parameters 

-   None

## Returns

-   TRUE if the local ZCL time has been synchronized, otherwise FALSE

**Parent topic:**[Functions](../../Time_cluster/topics/functions.md)

