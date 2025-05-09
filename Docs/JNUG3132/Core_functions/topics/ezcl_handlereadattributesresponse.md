# eZCL\_HandleReadAttributesResponse

```
teZCL_Status eZCL_HandleReadAttributesResponse(
    tsZCL_CallBackEvent *psEvent,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used to examine the response to a 'read attributes' request for a remote cluster and determine whether the response is complete - that is, whether the 'read attributes' response contains all the relevant attribute values \(it may be incomplete if the returned data is too large to fit into a single APDU\).

**eZCL\_HandleReadAttributesResponse\(\)** should normally be included in the user-defined callback function that is invoked on generation of the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE. The callback function must pass the generated event into **eZCL\_HandleReadAttributesResponse\(\)**.

If the 'read attributes' response is not complete, the function will re-send 'read attributes' requests until all relevant attribute values have been received.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameters 

-   *psEvent*        Pointer to generated event of the type E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE
-   *pu8TransactionSequenceNumber*        Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_ATTRIBUTE\_WO
-   E\_ZCL\_ERR\_ATTRIBUTES\_ACCESS
-   E\_ZCL\_ERR\_ATTRIBUTE\_NOT\_FOUND
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_PARAMETER\_RANGE

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

