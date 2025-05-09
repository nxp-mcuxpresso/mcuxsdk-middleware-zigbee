# eCLD\_ZllUtilityCommandGetGroupIdReqCommandSend

```
teZCL_Status eCLD_ZllUtilityCommandGetGroupIdReqCommandSend(
        uint8 u8Srcendpoint,
        uint8 u8DstEndpoint,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        uint8 u8StartIndex);

```

## Description 

This function is used to send a Get Group Identifiers Request command to obtain information about the groups \(of lights\) that have been configured on a remote endpoint. The function would typically be used on a ‘learner’ node to request the groups that have been configured on a ‘teacher’ node.

The first group from the groups list to be included in the returned information must be specified in terms of an index.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *u8SrcEndpoint* Number of local endpoint \(1-240\)
-   *u8DstEndpoint* Number of destination endpoint \(1-240\)
-   *psDestinationAddress* Pointer to stucture containing address information for target node
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *u8StartIndex* Index in group list of the first group to include in the returned information

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

