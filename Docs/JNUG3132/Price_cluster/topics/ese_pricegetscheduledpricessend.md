# eSE\_PriceGetScheduledPricesSend

```
teZCL_Status eSE_PriceGetScheduledPricesSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        uint32 u32StartTime,
        int8 u8NumberOfEvents);

```

## Description 

This function can be used on a Price cluster client to send a Get Scheduled Prices command to the Price cluster server. Therefore, it is used by a device \(such as an IPD\) to obtain the current price schedule from the ESP, either to check that its own price schedule is up-to-date or to recover the price schedule following a device reset.

You must specify the earliest start-time for the scheduled prices to be included in the results. This is normally set to zero or the current time \(UTC\). Note that you are not advised to specify the last time in the client price list, since the server may contain updates for prices covering an earlier time-period that are already in the client price list. You must also specify the maximum number of scheduled prices to be returned in the results.

The ESP should respond with multiple Publish Price commands containing the scheduled prices. Each response is processed by the Price cluster. The obtained price is checked against the prices currently in the price list on the client. If the price is not currently in the list, it is added to the list and an E\_SE\_PRICE\_TABLE\_ADD event is generated to indicate that a price has been added.

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId* Number of the remote endpoint to which the request is sent
-   *psDestinationAddress* Pointer to a structure containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u32StartTime* The earliest start-time of any prices to be returned - this is normally set to zero or the current time \(UTC\)
-   *u8NumberOfEvents* The maximum number of scheduled prices to be returned in the results - this should normally be set to: SE\_PRICE\_NUMBER\_OF\_CLIENT\_PRICE\_RECORD\_ENTRIES

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

