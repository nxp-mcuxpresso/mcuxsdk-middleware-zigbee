# eSE\_PriceGetConversionFactorSend

```
teZCL_Status eSE_PriceGetConversionFactorSend(
        uint8 u8SourceEndPointId,
        uint8 u8DestinationEndPointId,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        uint32 u32StartTime,
        uint8 u8NumberOfEvents);

```

## Description 

The function can be used on a Price cluster client to send a Get Conversion Factor request to the Price cluster server. Therefore, it is used by a device \(such as an IPD\) to obtain scheduled conversion factor values from the ESP. The function allows scheduled conversion factors to be obtained with start-times greater than or equal to a specified time, *u32StartTime*.

The ESP should respond with a Publish Conversion Factor command containing up to *u8NumberOfEvent* scheduled conversion factor values. The Price cluster on the receiving client processes the response by updating the local conversion factor list, as follows. For each conversion factor received in the response, the event E\_SE\_PRICE\_CONVERSION\_FACTOR\_ADD is generated.

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId* Number of the remote endpoint to which the request is sent
-   *psDestinationAddress* Pointer to a structure containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u32StartTime* Earliest start-time of scheduled conversion factors to be returned - a setting of 0 returns the factor that is currently active and factors with start-times in the future
-   *u8NumberOfEvents* Maximum number of conversion factors to be returned as a result of this request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

