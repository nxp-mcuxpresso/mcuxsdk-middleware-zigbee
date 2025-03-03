# BDB\_bOutOfBandCommissionGetKey

```
bool_tBDB_bOutOfBandCommissionGetKey(
uint8* pu8InstallCode,
uint8* pu8EncKey,
uint64 u64ExtAddress,
uint8* pu8DecKey,
uint8* pu8Mic);

```

## Description 

This function is used to decrypt an encrypted security key. It may be used to decrypt the network key received from another device during out-of-band commissioning.

The function requires the install code that was used to generate the pre-configured link key used to encrypt the key.

For an overview of out-of-band commissioning, refer to [Out-Of-Band Commissioning](../topics/out-of-band_commissioning.md).

## Parameters 

-   *pu8InstallCode*: Pointer to install code used to generate the pre-configured link key used in the encryption.
-   *pu8EncKey*: Pointer to encrypted key.
-   *u64ExtAddress*: Pointer to IEEE/MAC address of originating device.
-   *pu8DecKey*: Pointer to location to receive the decrypted key.
-   *pu8Mic*: Pointer to the MIC value to be used to validate the decryption.

## Returns

-   TRUE if key successfully decrypted, otherwise FALSE

**Parent topic:**[Functions](../topics/functions.md)

