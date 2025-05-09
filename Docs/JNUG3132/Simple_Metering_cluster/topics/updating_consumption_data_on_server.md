# Updating Consumption Data on Server

The consumption archive is held on the Smart Metering cluster server in a circular buffer operating on a FIFO basis. This buffer provides storage space for a sequence of entries containing consumption data for consecutive time intervals, where each buffer entry is a structure of the type `tsSEGetProfile` consisting of:

-   End-time of consumption interval \(as UTC time\)

-   Units delivered to the customer

-   Units received from the customer \(when customer sells units to utility company\)


The maximum number of entries that can be stored in the buffer is determined at compile-time \(see [Section 42.12](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1)\). When a new entry is added to a full buffer, this entry replaces the oldest entry currently in the buffer.

The application must keep the buffer up-to-date by adding a new entry using the function **eSM\_ServerUpdateConsumption\(\)**. Before this function is called, the relevant consumption data must be updated in one or both of the following Simple Metering cluster attributes:

```
u24CurrentPartialProfileIntervalValueDelivered

```

-   Contains the number of units delivered to the customer over the last interval

```
u24CurrentPartialProfileIntervalValueReceived

```

-   Contains the number of units received from the customer over the last interval

An attribute only needs to be updated if the corresponding consumption has been implemented \(for example, the utility company often only delivers units to the customer and does not receive any from the customer\).

**eSM\_ServerUpdateConsumption\(\)** takes the current time as an input and then adds an entry containing the consumption data \(in the above attributes\) to the buffer, where the supplied current time becomes the end-time in the entry \(thus, the duration of the consumption intervals is dictated by the frequency at which this function is called - see below\).

**Note:** The current time can be obtained by the application using the function **u32ZCL\_GetUTCTime\(\)**, described in [Section 18.7](../../Time_cluster/topics/functions.md#id_9907cf73-7425-485c-bcc3-cbea97dae2a4).

**eSM\_ServerUpdateConsumption\(\)** must be called periodically by the application. The period must match the value to which the Simple Metering `eProfileIntervalPeriod` attribute has been set \(see [Section 42.2](simple_metering_cluster_structure_and_attributes.md#id_1c898ead-e5b8-46b9-9117-d5b84c56d269)\). Standard periods, ranging from 2.5 minutes to one day, are provided as a set of enumerations \(see [Section 42.10.10](consumption_interval_enumerations.md#id_1958ed12-0a48-4347-92a2-df4dc7b1efd1)\).

**Parent topic:**[Consumption Data Archive \(‘Get Profile’\)](../../Simple_Metering_cluster/topics/consumption_data_archive_get_profile.md)

