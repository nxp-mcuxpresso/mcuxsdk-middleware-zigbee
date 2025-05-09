# eSM\_ClientGetProfileCommand

```
teZCL_Status eSM_ClientGetProfileCommand(
    uint8 u8SourceEndpoint,
    uint8 u8DestinationEndpoint,
    tsZCL_Address *psDestinationAddress,
    uint8 u8IntervalChannel,
    uint32 u32EndTime,
    uint8 u8NumberOfPeriods);

```

## Description 

This function can be used on a Simple Metering cluster client \(with the ‘Get Profile’ feature enabled\) to send a ‘Get Profile’ request to the Simple Metering cluster server in order to retrieve historical consumption data.

The server contains a circular buffer which stores a sequence of data entries containing consumption data for consecutive time intervals, identified by their end-times. This function can request a number of entries from the buffer, containing the consumption data over multiple intervals.

The function parameters include:

-   The number of buffer entries \(corresponding to consumption intervals\) requested

-   The most recent end-time for which a buffer entry will be reported - the most recent consumption data will be reported which has an end-time equal to or earlier than this end-time \(a specified end-time of zero will result in the most recent consumption data\)

-   A value indicating whether the units delivered or units received are being requested


This is a non-blocking function and so returns immediately after the request has been sent. The application must then wait for a response, which is accessed using the function **u32SM\_GetReceivedProfileData\(\)**.

## Parameters 

-   *u8SourceEndpoint*: Number of local endpoint through which request is sent
-   *u8DestinationEndpoint*: Number of endpoint to which request is sent on the destination device
-   *psDestinationAddress*: : Pointer to a structure containing the address of the destination device
-   *u8IntervalChannel*: Required consumption data - received or delivered:
-   E\_CLD\_SM\_CONSUMPTION\_RECEIVED
-   E\_CLD\_SM\_CONSUMPTION\_DELIVERED
-   *u32EndTime*: A UTC time representing the most recent interval end-time for which data will be reported \(a zero value means report data for the most recent interval\)
-   *u8NumberOfPeriods*: Number of consumption intervals to be reported

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_EP\_RANGE

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

