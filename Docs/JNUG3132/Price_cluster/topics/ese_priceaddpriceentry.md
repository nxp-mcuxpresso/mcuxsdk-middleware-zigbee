# eSE\_PriceAddPriceEntry

```
teSE_PriceStatus eSE_PriceAddPriceEntry(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    bool_t bOverwritePrevious,
    tsSE_PricePublishPriceCmdPayload *psPricePayload,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on the Price cluster server to add a price to the local price list. The function also sends an unsolicited Publish Price command containing the new price information to one or more remote endpoints. The function should be called on the ESP when a new price is received from the utility company.

On receiving the Publish Price command, a remote client will automatically add the new price to the local price list. However, you must specify the action to be taken if the time-period of the new price overlaps with the time-period of a price that is already in the client’s price list. You can choose to delete the existing price and add the new price, or leave the existing price in place and not add the new price. The rules on overlapping prices are defined in the ZigBee Smart Energy Profile specification.

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId* Number of the remote endpoint to which the request is sent
-   *psDestinationAddress* Pointer to a structure containing the address of the remote node to which the Publish Price command is sent. It is recommended that the command is sent to all bound clients using a ZCL address mode of E\_ZCL\_AM\_BOUND. If the stack has not been started, the E\_ZCL\_AM\_NO\_TRANSMIT address mode should be used
-   *bOverwritePrevious* Action to be taken if the new price overlaps \(in time\) a price which is already in the price list:
    -   TRUE - existing price deleted, new price added
    -   FALSE - new price not added and error returned
-   *psPricePayload* Pointer to a structure containing the price information to be added \(see [Section 40.11.1](tsse_pricepublishpricecmdpayload.md#id_33de0832-fd7e-46e1-b6e3-7d58ef09b32a)\). This parameter only needs to remain in scope for the duration of this function call
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the command

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_INVALID\_VALUE
-   E\_ZCL\_ERR\_TIME\_NOT\_SYNCHRONISED
-   E\_ZCL\_ERR\_INSUFFICIENT\_SPACE
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_SE\_PRICE\_OVERFLOW
-   E\_SE\_PRICE\_DUPLICATE
-   E\_SE\_PRICE\_DATA\_OLD

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

