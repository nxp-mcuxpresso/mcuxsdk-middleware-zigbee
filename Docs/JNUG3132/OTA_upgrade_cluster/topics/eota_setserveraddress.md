# eOTA\_SetServerAddress

```
teZCL_Status eOTA_SetServerAddress(
    uint8 u8Endpoint,
    uint64 u64IeeeAddress,
    uint16 u16ShortAddress);

```

## Description 

This function sets the addresses \(64-bit IEEE/MAC address and 16-bit network address\) of the OTA Upgrade cluster server that will be used to provide application upgrade images to the local client.

The function should be called after a server discovery has been performed to find a suitable server - this is done by sending out a Match Descriptor Request using the function **ZPS\_eAplZdpMatchDescRequest\(\)** described in the*ZigBee 3.0 Stack User Guide \(JNUG3130\)*. The server discovery must be completed and a server address set before any OTA-related message exchanges can occur \(e.g. image request\).

## Parameters 

-   *u8Endpoint*: Number of endpoint corresponding to application
-   *u64IeeeAddress*: IEEE/MAC address of server
-   *u16ShortAddress*: Network address of server

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Client Functions](../../OTA_upgrade_cluster/topics/client_functions.md)

