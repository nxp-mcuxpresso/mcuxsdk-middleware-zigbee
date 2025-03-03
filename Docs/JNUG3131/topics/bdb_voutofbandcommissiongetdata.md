# BDB\_vOutOfBandCommissionGetData

```
void BDB_vOutOfBandCommissionGetData(
BDB_tsOobReadDataToAuthenticate
*psReturnedCommissioningData);
```

## Description 

This function is used to obtain locally stored commissioning data. The obtained data is received in a structure described in [BDB_tsOobReadDataToAuthenticate](bdb_tsoobreaddatatoauthenticate.md#) and includes the network key. The data is then passed to higher layers which may encrypt it before sending it by out-of-band means to the other device involved in the commissioning.

A similar set of data but with the network key encrypted can be obtained using the function **BDB\_eOutOfBandCommissionGetDataEncrypted\(\)**.

For an overview of out-of-band commissioning, refer to [Out-Of-Band Commissioning](out-of-band_commissioning.md#).

## Parameters 

-   *psReturnedCommissioningData*: Pointer to a structure to receive the obtained commissioning data \(see [BDB_tsOobReadDataToAuthenticate](bdb_tsoobreaddatatoauthenticate.md#ID_6EE299CB-AD7C-49E8-8E19-9266FA9389EF)\)

## Returns 
-   None

**Parent topic:**[Functions](../topics/functions.md)

