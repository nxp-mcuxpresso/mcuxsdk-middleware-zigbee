# eSM\_ServerUpdateConsumption

```
teZCL_Status eSM_ServerUpdateConsumption(
    uint8 u8SourceEndPointId,
    uint32 u32UtcTime);

```

## Description 

This function can be used on a Simple Metering cluster server \(with the ‘Get Profile’ feature enabled\) to add a new entry to the circular buffer used to store historical consumption data. The buffer stores a sequence of entries containing consumption data for consecutive time intervals, identified by their end-times.

Before this function is called, the application must update one or both of the following Simple Metering cluster attributes with the relevant consumption\(s\) over the last time interval \(since the last readings were made\):

```
u24CurrentPartialProfileIntervalValueDelivered
u24CurrentPartialProfileIntervalValueReceived

```

An attribute only needs to be updated if the corresponding consumption has been implemented.

The function takes the current time \(UTC time\) as an input and adds a buffer entry containing the consumption measurements together with the supplied UTC time, which is saved as the end-time of the interval

The entry is stored as a `tsSEGetProfile` structure, described in [Section 42.11.5](tssegetprofile.md#id_79efff42-e795-48cb-bd39-538b74d8bf56).

The buffer can contain a limited number of entries, determined at compile-time \(see [Section 42.12](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1)\), and operates on a FIFO basis so that a new entry added to a full buffer will over-write the oldest entry.

The function should be called periodically by the application. The period must match the value to which the Simple Metering `eProfileIntervalPeriod` attribute has been set \(see [Section 42.2](simple_metering_cluster_structure_and_attributes.md#id_1c898ead-e5b8-46b9-9117-d5b84c56d269)\). Standard periods, ranging from 2.5 minutes to one day, are provided as a set of enumerations \(see [Section 42.10.10](consumption_interval_enumerations.md#id_1958ed12-0a48-4347-92a2-df4dc7b1efd1)\).

## Parameters 

-   *u8SourceEndPointId*: Number of local endpoint on which the Simple Metering cluster server operates
-   *u32UtcTime*: Current time \(as UTC time which can be obtained using **u32ZCL\_GetUTCTime\(\)**\)

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

