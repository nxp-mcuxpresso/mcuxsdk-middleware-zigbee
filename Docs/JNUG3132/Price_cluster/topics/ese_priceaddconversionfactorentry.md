# eSE\_PriceAddConversionFactorEntry

```
teZCL_Status eSE_PriceAddConversionFactorEntry(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    bool_t bOverwritePrevious,
    tsSE_PricePublishConversionCmdPayload
    *psPublishConversionCmdPayload,
    uint8 *pu8TransactionSequenceNumber);

```

## Description 

The function can be used on a Price cluster server to add a new conversion factor entry to the internal list of scheduled conversion factors maintained by the cluster. The function also sends an unsolicited Publish Conversion Factor command to the Price cluster client nodes in the network, to advertise the new conversion factor. Therefore, the function should be called on the ESP when a new conversion factor is received from the utility company.

On receiving the Publish Conversion Factor command, a remote client automatically adds the new conversion factor to the local conversion factor list. However, if the new entry has the same start-time as an existing entry in the list, the outcome depends on the setting of the boolean parameter *bOverwritePrevious* in this function:

-   If this parameter is set to TRUE then the existing entry is removed and the new entry is added

-   If this parameter is set to FALSE then the Issuer Event IDs of the two conversion factor entries are compared:

    -   If the Event ID of the new entry is the greater, the existing entry is removed and the new entry is added

    -   If the Event ID of the existing entry is the greater, E\_ZCL\_FAIL is returned and the list is not modified


A pointer must be specified to a location to receive a Transaction Sequence Number \(TSN\) for the request. The TSN in the response is set to match the TSN in the request, allowing an incoming response to be paired with a request.

## Parameters 

-   *u8SourceEndPointId* Number of the local endpoint through which the request is sent
-   *u8DestinationEndPointId* Number of the remote endpoint to which the request is sent
-   *psDestinationAddress* Pointer to a structure containing the address of the remote node to which the request is sent
-   *bOverwritePrevious* Determines whether an existing conversion factor with the same start-time on the clients will be over-written without comparing Event IDs \(see above\):
    -   TRUE - over-write existing entry
    -   FALSE - compare Event IDs first
-   *psPublishConversionCmdPayload* Pointer to conversion factor entry to be added to list on server and advertised to clients
-   *pu8TransactionSequenceNumber* Pointer to a location to store the Transaction Sequence Number \(TSN\) of the request

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_TIME\_NOT\_SYNCHRONISED

**Parent topic:**[Functions](../../Price_cluster/topics/functions.md)

