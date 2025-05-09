# tsSE\_DRLCGetScheduledEvents

The structure of type `tsSE_DRLCGetScheduledEvents` contains the parameters of a **Get Scheduled Event** message, as shown and described below.

```
typedef struct {
   uint32 u32StartTime;
   uint8 u8numberOfEvents;
} tsSE_DRLCGetScheduledEvents;

```

where:

-   `u32StartTime` is the earliest start-time \(UTC\) of the requested LCEs

-   `u8numberOfEvents` is the maximum number of LCEs to report


**Parent topic:**[Structures](../../DRLC_cluster/topics/structures.md)

