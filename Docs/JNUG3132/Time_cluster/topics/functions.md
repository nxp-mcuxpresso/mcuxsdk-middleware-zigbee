# Functions

The following time-related functions are provided in the NXP implementation of the ZCL:

1.  [eCLD\_TimeCreateTime](ecld_timecreatetime.md#id_69db1f5b-a213-477e-8a71-6ce45aaca196)
2.  [vZCL\_SetUTCTime](vzcl_setutctime.md#id_9a687ca3-48eb-471d-87ed-c74d92d477b6)
3.  [u32ZCL\_GetUTCTime](u32zcl_getutctime.md#id_14409d9d-8764-46c0-9969-2714c4aea5d2)
4.  [bZCL\_GetTimeHasBeenSynchronised](bzcl_gettimehasbeensynchronised.md#id_07e6959f-8b96-4c12-9ddf-f13c7ab9ef28)
5.  [vZCL\_ClearTimeHasBeenSynchronised](vzcl_cleartimehasbeensynchronised.md#id_0bbc6f3f-be36-4e37-be1b-8e09b773e232)

**Note:** The time used in the Time cluster and in the ZCL is a UTC \(Co-ordinated Universal Time\) type **UTCTime**, which is defined in the ZigBee Specification as follows: *"UTCTime is an unsigned 32 bit value representing the number of seconds since 0 hours, 0 minutes, 0 seconds, on the 1st of January, 2000 UTC"*


```{include} ../../Time_cluster/topics/ecld_timecreatetime.md
:heading-offset: 2
```

```{include} ../../Time_cluster/topics/vzcl_setutctime.md
:heading-offset: 2
```

```{include} ../../Time_cluster/topics/u32zcl_getutctime.md
:heading-offset: 2
```

```{include} ../../Time_cluster/topics/bzcl_gettimehasbeensynchronised.md
:heading-offset: 2
```

```{include} ../../Time_cluster/topics/vzcl_cleartimehasbeensynchronised.md
:heading-offset: 2
```

**Parent topic:**[Time Cluster and ZCL Time](../../Time_cluster/topics/time_cluster_and_zcl_time.md)

