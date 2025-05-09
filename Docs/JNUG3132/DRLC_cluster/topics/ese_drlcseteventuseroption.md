# eSE\_DRLCSetEventUserOption

```
teSE_DRLCStatus eSE_DRLCSetEventUserOption(
    uint32 u32IssuerId,
    uint8 u8SourceEndPointId,
    teSE_DRLCUserEventOption eEventOption);

```

## Description 

This function can be used on a DRLC cluster client to choose to participate or not participate in an individual LCE. By default, a client participates in an LCE, so normally this function only needs to be called if the client is to opt out of the LCE.

The function could be called following a button-press which results from a user decision to opt out of the LCE \(for which information is displayed on the IPD screen\).

When this function is called, a Report Event Status message is sent to the cluster server in order to indicate that the local client has opted out of the LCE. Once the LCE end-time has been reached, another Report Event Status message is sent to the server in order to confirm that the LCE has completed without the participation of the local client.

## Parameters 

-   *u32IssuerId*: Identifier of the LCE \(as issued by the utility company\)
-   *u8SourceEndPointId*: Number of the local endpoint where the LCE is located \(endpoint corresponding to the DRLC cluster\)
-   *eEventOption*: Required option, one of:
    -   E\_SE\_DRLC\_EVENT\_USER\_OPT\_IN \(participate\)
    -   E\_SE\_DRLC\_EVENT\_USER\_OPT\_OUT \(do not participate\)

## Returns 

Any relevant DRLC return code listed in [Section 41.9](return_codes.md#id_21b0e681-dbf2-4755-b6be-3cd79a1704f9) or ZCL return code listed in [Section 7.2](../../ZCL_enums_codes/topics/general_return_codes_zcl_status.md#id_b4a2f8bb-7568-4982-8fa7-78a992e3c541)

**Parent topic:**[Functions](../../DRLC_cluster/topics/functions.md)

