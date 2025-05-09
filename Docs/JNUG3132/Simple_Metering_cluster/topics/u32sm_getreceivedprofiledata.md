# u32SM\_GetReceivedProfileData

```
uint32 u32SM_GetReceivedProfileData(
    tsSM_GetProfileResponseCommand
    *psSMGetProfileResponseCommand);

```

## Description 

This function is used on a Simple Metering cluster client to obtain the consumption data received in a ‘Get Profile’ response. The response is obtained from the Simple Metering cluster server \(and previously requested by the client through a call to **eSM\_ClientGetProfileCommand\(\)**\).

When a ‘Get Profile’ response from the server arrives, the event E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_GET\_PROFILE\_RESPONSE is generated on the client. This response causes the callback function on the device to be invoked \(for an IPD, this is the callback function registered through **eSE\_RegisterIPDEndPoint\(\)**\). The callback function should deal with the response.

This function can be called within the callback function to extract consumption data from the event. It is necessary to provide the function with a pointer to the response within the event. The function returns the data corresponding to one consumption interval on each call. Therefore, if the response contains data for multiple intervals, the function must be called multiple times to extract all of this data. The number of intervals contained in the response is also included in the response:

```
sSMCallBackMessage.uMessage.sGetProfileResponseCommand.u8NumberOfPeriodsDelivered 

```

When there is no more data to be extracted from the event, the function returns 0xFFFFFFFF.

## Parameters 

-   *psSMGetProfileResponseCommand*: Pointer to `sGetProfileResponseCommand` element of the event

## Returns 

-   32-bit value corresponding to consumption data for one interval

0xFFFFFFFF indicates that there is no more data to be read from the event.

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

