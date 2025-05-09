# eCLD\_PollControlUpdateSleepInterval

```
teZCL_Status eCLD_PollControlUpdateSleepInterval(
    uint32 u32QuarterSecondsAsleep);

```

## Description 
This function can be used on a cluster server to provide the updated ticks back into PollControl cluster for the time the device was sleeping in terms of quarter second.

This function updates the Checkin period based on the ticks provided.

## Parameters 

-   *u32QuarterSecondsAsleep*: Number of Quarter seconds the device has slept for

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND

**Parent topic:**[Server Functions](../../poll_control_cluster/topics/server_functions.md)

