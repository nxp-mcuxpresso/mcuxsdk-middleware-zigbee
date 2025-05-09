# tsSM\_GetProfileResponseCommand

This stucture contains the details of a ‘Get Profile’ response \(from the cluster server\). It is included in the structure `tsSM_CallBackMessage` when an E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND event containing the command E\_CLD\_SM\_GET\_PROFILE\_RESPONSE is generated on the cluster server.

```
typedef struct
{
    uint32         u32Endtime;
    teSM_Status    eStatus;
    teSM_TimeFrame u8ProfileIntervalPeriod;
    uint8          u8NumberOfPeriodsDelivered;
    zuint24       *pau24Intervals;
}tsSM_GetProfileResponseCommand;

```

where:

-   `u32Endtime` is the end-time of the consumption data that is being reported, as a UTC time

-   `eStatus` is the status of the response, represented by one of the enumerated values listed in [Section 42.10.11](simple_metering_status_enumerations.md#id_847cf6a7-2924-402a-8250-0a03979d9f57)

-   `u8ProfileIntervalPeriod` is the time-interval \(consumption interval\) over which each set of consumption data is collected - one of the standard enumerated values listed in [Section 42.10.10](consumption_interval_enumerations.md#id_1958ed12-0a48-4347-92a2-df4dc7b1efd1)

-   `u8NumberOfPeriodsDelivered` is the number of consumption intervals being reported

-   `pau24Intervals` is a pointer to the consumption data being reported


**Parent topic:**[Structures](../../Simple_Metering_cluster/topics/structures.md)

