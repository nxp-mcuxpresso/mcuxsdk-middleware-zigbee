# tsCLD\_AEAA\_GetAlertsResponseORAlertsNotificationPayload

This structure contains the payload for a ‘Get Alerts Response’ message or an ‘Alerts Notification’ message.

```
typedef struct
{
   zuint8  u8AlertsCount;
   zuint24 au24AlertStructure[
              CLD_APPLIANCE_EVENTS_AND_ALERTS_MAXIMUM_NUM_OF_ALERTS];
} tsCLD_AEAA_GetAlertsResponseORAlertsNotificationPayload;

```

where:

-   `u8AlertsCount` is an 8-bit bitmap containing the following alerts information:


|**Bits**|**Description**|
|--------|---------------|
|0-3|Number of reported alerts|
|4-7|Type of alert:

 -   0x0: Unstructured

-   0x1-0xF: Reserved


|

-   `au24AlertStructure[``]` is an array of 24-bit bitmaps, with one bitmap for each reported alert, containing the following information:


|**Bits**|**Description**|
|--------|---------------|
|0-7|Alert ID:

 -   0x0: Reserved

-   0x01-0x3F: Standardized

-   0x40-0x7F: Non-standardized

-   0x80-0xFF: Proprietary


|
|8-11|Category:

 -   0x0: Reserved

-   0x1: Warning

-   0x2: Danger

-   0x3: Failure

-   0x4–0xF: Reserved


|
|12-13|Presence or recovery:

 -   0x0: Presence \(alert detected\)

-   0x1: Recovery \(alert recovered\)

-   0x2–0x3: Reserved


|
|14-15|Reserved \(set to 0x0\)|
|16-23|Non-standardized or proprietary|

**Parent topic:**[Structures](../../appliance_events_alerts_cluster/topics/structures.md)

