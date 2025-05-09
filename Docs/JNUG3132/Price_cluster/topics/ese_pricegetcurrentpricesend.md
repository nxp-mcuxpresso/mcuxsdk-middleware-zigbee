# eSE\_PriceGetCurrentPriceSend

```
teZCL_Status eSE_PriceGetCurrentPriceSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    teSE_PriceCommandOptions ePriceCommandOptions);

```

## Description 

This function can be used on a Price cluster client to send a Get Current Price command to the Price cluster server. Therefore, it is used by a device \(such as an IPD\) to obtain the currently active price from the ESP.

The ESP should respond with a Publish Price command containing the active price. This response is processed by the Price cluster. The obtained price is checked against the prices currently in the price list on the client. If the price is not currently in the list, it is added to the list and an E\_SE\_PRICE\_TABLE\_ADD event is generated to indicate that a price has been added.

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId* Number of the remote endpoint to which the request is sent
-   *psDestinationAddress* Pointer to a structure containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *ePriceCommandOptions* Indicates whether the radio receiver on client remains on when the device is idle \(for example, asleep\):
    -   0x01 - receiver on when idle
    -   0x00 - receiver off when idle
-   An enumeration is provided for the ‘on’ case:
-   E\_SE\_PRICE\_REQUESTOR\_RX\_ON\_IDLE

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

