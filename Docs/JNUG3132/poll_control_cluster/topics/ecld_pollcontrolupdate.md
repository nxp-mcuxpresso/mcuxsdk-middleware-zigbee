# eCLD\_PollControlUpdate

```
teZCL_Status eCLD_PollControlUpdate(void);

```

## Description 

This function can be used on a cluster server to update the timing status for the following periodic activities:

-   polling of the parent for a data packet

-   ‘check-ins’ with the client to check for a required change in the poll mode


The function should be called once per quarter-second and the application should provide a 250-ms timer to prompt these function calls.

Any poll or check-in that is due when this function is called are automatically performed by the cluster server.

## Parameters 

-   None

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../poll_control_cluster/topics/server_functions.md)

