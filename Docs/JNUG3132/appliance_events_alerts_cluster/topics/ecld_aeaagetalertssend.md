# eCLD\_AEAAGetAlertsSend

```
teZCL_Status eCLD_AEAAGetAlertsSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

This function can be used on an Appliance Events and Alerts cluster client to send a ‘Get Alerts’ message to a cluster server \(appliance\).

You are required to provide a pointer to a location to receive a Transaction Sequence Number \(TSN\) for the message. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request. This is useful when sending more than one request to the same destination endpoint.

## Parameter 


## Returns 


**Parent topic:**[Functions](../../appliance_events_alerts_cluster/topics/functions.md)

