# eCLD\_ZllUtilityCommandEndpointInformationCommandSend

```
teZCL_Status eCLD_ZllUtilityCommandEndpointInformationCommandSend(
        uint8 u8SrcEndpoint,
        uint8 u8DstEndpoint,
        tsZCL_Address *psDestinationAddress,
        uint8 *pu8TransactionSequenceNumber,
        tsCLD_ZllUtility_EndpointInformationCommandPayload
*psPayload);

```

## Description 

This function is used to send an Endpoint Information command to provide a remote endpoint with general information about the local endpoint \(this may prompt the remote endpoint to request further information about the local endpoint\). The function would typically be used to send local endpoint information from a ‘teacher’ node to a ‘learner’ node, in order to facilitate two-way communication between the Commissioning Utilities on the two nodes.

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the command. The TSN in the response is set to match the specified TSN, allowing an incoming response to be paired with the original command. This is useful when sending more than one command to the same destination endpoint.

## Parameters 

-   *u8SrcEndpoint* Number of local endpoint \(1-240\)
-   *u8DstEndpoint* Number of destination endpoint \(1-240\)
-   *psDestinationAddress* Pointer to stucture containing address information for target node
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the command
-   *psPayload* Pointer to structure to contain payload data for the Endpoint Information command \(see [Section 44.8.20](tscld_zllutility_endpointinformationcommandpayload.md#id_6f261fcd-1151-4138-9efb-328ec99b1269)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Commissioning Utility functions](../../touchlink_cluster/topics/commissioning_utility_functions.md)

