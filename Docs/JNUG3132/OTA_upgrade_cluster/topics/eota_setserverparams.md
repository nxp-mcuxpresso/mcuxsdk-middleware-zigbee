# eOTA\_SetServerParams

```
teZCL_Status eOTA_SetServerParams(
    uint8 u8Endpoint,
    uint8 u8ImageIndex,
    tsCLD_PR_Ota *psOTAData);

```

## Description 

This function can be used to set server parameter values \(including query jitter, data size, image data, current time and upgrade time\) for a particular image stored on the server. The parameter values to be set are specified in a structure, described in [Section 49.11.22](tscld_pr_ota.md#id_35f086d8-664d-4c2a-99d1-305472248fe8). For detailed descriptions of these parameters, refer to the *ZigBee Over-the-Air Upgrading Cluster Specification \(095264\)*from the ZigBee Alliance.

If this function is not called, default values are used for these parameters.

The current values of these parameters can be obtained using the function **eOTA\_GetServerData\(\)**.

The index of the image for which server parameter values are to be set must be specified. For an image stored in Flash memory, this index will take a value in the range 0 to \(OTA\_MAX\_IMAGES\_PER\_ENDPOINT - 1\).

## Parameters 

-   *u8Endpoint*: Number of endpoint \(on server\) on which cluster operates
-   *u8ImageIndex*: Index number of image
-   *psOTAData*: Pointer to structure containing parameter values to be set \(see [Section 49.11.22](tscld_pr_ota.md#id_35f086d8-664d-4c2a-99d1-305472248fe8)\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_FAIL

**Parent topic:**[Server Functions](../../OTA_upgrade_cluster/topics/server_functions.md)

