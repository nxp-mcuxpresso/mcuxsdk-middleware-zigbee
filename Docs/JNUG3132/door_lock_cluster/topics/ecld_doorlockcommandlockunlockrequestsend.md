# eCLD\_DoorLockCommandLockUnlockRequestSend

```
teZCL_Status eCLD_DoorLockCommandLockUnlockRequestSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    teCLD_DoorLock_CommandID eCommand);

```

## Description 

This function can be used on a Door Lock cluster client to send a lock or unlock command to the Door Lock cluster server.

A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId*                Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId*                Number of the remote endpoint to which the request is sent
-   *psDestinationAddress*                Pointer to a structure containing the address of the remote node to which the request is sent
-   *pu8TransactionSequenceNumber*                Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request
-   *eCommand*        The         command to be sent, one of:
-           E\_CLD\_DOOR\_LOCK\_CMD\_LOCK
-           E\_CLD\_DOOR\_LOCK\_CMD\_UNLOCK

## Returns

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

**Parent topic:**[Functions](../../door_lock_cluster/topics/functions.md)

