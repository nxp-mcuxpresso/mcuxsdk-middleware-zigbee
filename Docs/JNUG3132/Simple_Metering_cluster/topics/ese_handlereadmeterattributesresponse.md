# eSE\_HandleReadMeterAttributesResponse

```
teSE_Status eSE_HandleReadAttributesResponse(
    tsZCL_CallBackEvent *psEvent,
    uint8 *puTransactionSequenceNumber);

```

## Description 

This function should be called after **eSE\_ReadMeterAttributes\(\)**. The function examines the response to a ‘read attributes’ request for the Simple Metering cluster and determines whether the response is complete - that is, whether it contains all the Simple Metering attributes \(the response may be incomplete if the returned data is too large to fit into a single APDU\). If the response is not complete, the function will re-send ‘read attributes’ requests until all attribute values have been obtained. Any further attribute values obtained are written to the local shared device structure containing the attributes.

This function call should normally be included in the user-defined callback function that is invoked when the event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE is generated. This is the callback function which is specified when the \(requesting\) endpoint is registered using the appropriate endpoint registration function. The callback function must pass the generated event into **eSE\_HandleReadAttributesResponse\(\)**.

You are also required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the request/response.

## Parameters 

-   *psEvent*: Pointer to the generated event E\_ZCL\_CBET\_READ\_ATTRIBUTES\_RESPONSE
-   *pu8TransactionSequenceNumber*: Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request/response

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

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

