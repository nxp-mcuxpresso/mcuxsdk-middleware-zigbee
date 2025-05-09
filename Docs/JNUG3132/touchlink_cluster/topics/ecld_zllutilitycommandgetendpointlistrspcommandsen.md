# eCLD\_ZllUtilityCommandGetEndpointListRspCommandSend

```
PUBLIC teZCL_Status eCLD_ZllUtilityCommandGetEndpointListRspCommandSend(
        uint8 u8SrcEndpoint,
        uint8 u8DstEndpoint,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        uint8 u8StartIndex);

```

## Description 

This function is used to send a Get Endpoint List Response command containing information about controlled endpoints. The function would typically be used on a ‘teacher’ node to respond to a Get Endpoint List Request from a ‘learner’ node.

The first endpoint from the endpoints list to be included in the returned information must be specified in terms of an index. The returned information will include this index, the number of \(consecutive\) endpoints included and the information about each endpoint \(including endpoint number, identifier of resident ZigBee device and version of this device\).

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *u8SrcEndpoint* Number of local endpoint \(1-240\)
-   *u8DstEndpoint* Number of destination endpoint \(1-240\)
-   *psDestinationAddress* Pointer to stucture containing address information for target node
-   *pu8TransactionSequenceNumber* Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *u8StartIndex* Index in endpoint list of the first endpoint to include in the returned information

## Returns

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

