# eCLD\_ZllUtilityCommandGetGroupIdRspCommandSend

```
PUBLIC teZCL_Status   eCLD_ZllUtilityCommandGetGroupIdRspCommandSend(
        uint8 u8SrcEndpoint,
        uint8 u8DstEndpoint,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        uint8 u8StartIndex);

```

## Description 

This function is used to send a Get Group Identifiers Response command containing information about the groups \(of lights\) that have been configured on the local endpoint. The function would typically be used on a ‘teacher’ node to respond to a Get Group Identifiers Request from a ‘learner’ node.

The first group from the groups list to be included in the returned information must be specified in terms of an index. The returned information includes this index, the number of \(consecutive\) groups included and the identifier of each group.

The specified Transaction Sequence Number \(TSN\) of the response must match the TSN of the corresponding request, as this will allow the response to be paired with the request at the destination.

## Parameters 

-   *u8SrcEndpoint* Number of local endpoint \(1-240\)
-   *u8DstEndpoint* Number of destination endpoint \(1-240\)
-   *psDestinationAddress* Pointer to stucture containing address information for target node
-   *pu8TransactionSequenceNumber* Pointer to location containing the Transaction Sequence Number \(TSN\) of the response
-   *u8StartIndex* Index in group list of the first group to include in the returned information

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

