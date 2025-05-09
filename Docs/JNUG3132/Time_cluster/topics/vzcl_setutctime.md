# vZCL\_SetUTCTime

```
void vZCL_SetUTCTime(uint32 u32UTCTime);

```

## Description 

This function sets the current time \(UTC\) that is stored in the ZCL \(‘ZCL time’\).

The application may call this function, for example, when a time update has been received \(e.g. via the Time or Price cluster\).

Note that this function does not update the time in the Timer cluster - if required, the application must do this by writing to the `tsCLD_Time` structure \(see [Section 18.2](time_cluster_structure_and_attributes.md#id_0641e5fe-7531-4a59-8378-862128710a31)\).

## Parameters 

-   *u32UTCTime*        The current time \(UTC\) to be set, in seconds

## Returns 

-   None

**Parent topic:**[Functions](../../Time_cluster/topics/functions.md)

