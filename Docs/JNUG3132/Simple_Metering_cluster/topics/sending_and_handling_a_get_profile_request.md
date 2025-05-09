# Sending and Handling a ‘Get Profile’ Request

The application on a device which supports the Simple Metering cluster as a client, such as an IPD, can send a ‘Get Profile’ request to the cluster server by calling the function **eSM\_ClientGetProfileCommand\(\)**. This function allows consumption data to be requested from the archive for one or more intervals.

The inputs for this function include:

-   A value indicating whether the units delivered or units received \(by the utility company\) are being requested \(see [Section 42.6.1](updating_consumption_data_on_server.md#id_11566dd9-de95-4802-a999-1d80c3a6abd6)\)

-   An end-time \(as a UTC time\) - the most recent consumption data will be reported which has an end-time equal to or earlier than this end-time \(a specified end-time of zero will result in the most recent consumption data\)

-   The number of consumption intervals to report \(this number will be reported only if data for sufficient intervals is available\) - the end-time rule, specified above, will be applied to all the reported intervals


On receiving the request, the event E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_GET\_PROFILE is generated on the server, causing the callback function on the device to be invoked \(for a Metering Device, this is the callback function registered through **eSE\_RegisterEspMeterEndPoint\(\)** or **eSE\_RegisterMeterEndPoint\(\)**\). The callback function only needs to be concerned with this event if the archive data needs to be modified before the ZCL automatically sends the requested data in a ‘Get Profile’ response. The response indicates the number of consumption intervals reported and contains the consumption data for these intervals, as well as the end-time of the most recent interval reported.

On receiving the response, the event E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_GET\_PROFILE\_RESPONSE is generated on the requesting client, causing the callback function on the device to be invoked \(for an IPD, this is the callback function registered through **eSE\_RegisterIPDEndPoint\(\)**\). The callback function should extract the requested data from the event using the function **u32SM\_GetReceivedProfileData\(\)** in order to process or store the data. This function should be called for each consumption interval reported in the event - the code fragment below illustrates repeated calls to the function until all the reported data has been obtained:

```
for (i =0 ;i < sGetProfileResponseCommand.u8NumberOfPeriodsDelivered; i
++)
{
    //Read data from event
X(i)= u32SM_GetReceivedProfileData(tsSM_GetProfileResponseCommand *psSMGetProfileResponseCommand)
}

```

Alternatively, the function can be called repeatedly until it returns 0xFFFFFFFF, which indicates that there is no more data to be extracted from the event.

**Parent topic:**[Consumption Data Archive \(‘Get Profile’\)](../../Simple_Metering_cluster/topics/consumption_data_archive_get_profile.md)

