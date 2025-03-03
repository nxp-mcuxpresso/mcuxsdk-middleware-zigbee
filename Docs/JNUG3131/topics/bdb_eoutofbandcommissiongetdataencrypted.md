# BDB\_eOutOfBandCommissionGetDataEncrypted

```
BDB_teStatus BDB_eOutOfBandCommissionGetDataEncrypted(
BDB_tsOobWriteDataToAuthenticate *psSrcCredentials,
uint8 *pu8ReturnAuthData,
uint16 *puSize);

```

## Description 

This function is used to obtain locally stored commissioning data, including the network key which returns encrypted. Authentication data \(including an install code\) must be provided which is used to encrypt the network key.

The obtained data is received as a byte stream - the size of the byte stream is also returned. The byte stream contains the following data:

-   IEEE/MAC address of the local node as `u64address` \(8 bytes\)

-   Network key encrypted with the data passed via *psSrcCredentials* \(16 bytes\)

-   MIC value generated to validate encryption \(4 bytes\)

-   Key sequence number of active network key \(1 byte\)

-   Active channel number \(1 byte\)

-   PAN ID \(2 bytes\)

-   Extended PAN ID \(8 bytes\)


The encrypted network key and other obtained data are then sent by out-of-band means to the other device involved in the commissioning. The receiving device may decrypt the key using the **BDB\_bOutOfBandCommissionGetKey\(\)** function.

A similar set of data without encryption of the network key is obtained using the function **BDB\_u8OutOfBandCommissionStartDevice\(\)**.

For an overview of out-of-band commissioning, refer to [Out-Of-Band Commissioning](out-of-band_commissioning.md#).

## Parameters

-   *psSrcCredentials*: Pointer to a structure containing authentication data to be used to encrypt the network key \(see [BDB_tsOobWriteDataToAuthenticate](bdb_tsoobwritedatatoauthenticate.md#)\).
-   *pu8ReturnAuthData*: Pointer to the start of the returned byte stream containing the obtained data.
-   *puSize*: Pointer to a location to receive the size of the obtained byte stream.

## Returns

-   None

**Parent topic:**[Functions](../topics/functions.md)

