# eSM\_IsMirrorSourceAddressValid

```
eSM_IsMirrorSourceAddressValid(
tsZCL_ReportAttributeMirror *psZCL_ReportAttributeMirror);

```

## Description 

This function can be used on the ESP to handle mirroring data reported from a Metering Device. If mirroring is enabled, the function should be included in the callback function on the ESP.

When the ESP receives mirroring data from a Metering Device, the event E\_ZCL\_CBET\_ATTRIBUTE\_REPORT\_MIRROR is generated, causing the callback function to be invoked. The callback function should call this function to deal with the event.

The function first checks that the data comes from a Metering Device which has a mirror on the ESP \(the source IEEE address of the data is used for this check\) and then updates the event status accordingly:

```
sZCL_CallBackEvent.uMessage.sReportAttributeMirror.eStatus

```

If the source device is valid then this status is set to E\_ZCL\_ATTR\_REPORT\_OK and the metering data is automatically stored on the relevant mirror endpoint. Otherwise, a ZCL default response is returned to the Metering Device to indicate that mirroring is not authorised for this device \(E\_ZCL\_CMDS\_NOT\_AUTHORIZED\).

The mirroring of metering data is fully described in [Section 42.5.3](mirroring_data.md#id_5c81e91a-7d4a-4e82-8247-d180d955c57a).

## Parameters 

-   *psZCL\_ReportAttributeMirror*: Pointer to `sReportAttributeMirror` element of the event

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Functions](../../Simple_Metering_cluster/topics/functions.md)

