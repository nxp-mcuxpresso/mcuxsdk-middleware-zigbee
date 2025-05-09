# tsSEGetProfile

This structure is used to store historical consumption data when the ‘Get Profile’ feature is enabled. The data within the structure corresponds to a single consumption interval.

```
typedef struct
{
           uint32 u32UtcTime;
           zuint24 u24ConsumptionReceived;
           zuint24 u24ConsumptionDelivered;
}tsSEGetProfile;

```

where:

-   `u32UtcTime` is the end-time of the consumption interval \(as a UTC time\)

-   `u24ConsumptionReceived` is the number of units received from the customer during the interval \(for customers who generate and sell their own units\)

-   `u24ConsumptionDelivered` is the number of units delivered to the customer during the interval


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

