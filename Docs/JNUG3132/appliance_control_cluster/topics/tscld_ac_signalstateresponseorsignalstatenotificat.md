# tsCLD\_AC\_SignalStateResponseORSignalStateNotificationPayload

This structure contains the payload for a "Signal State" response or notification message.

```
typedef struct
{
           zenum8   eApplianceStatus;
           zuint8                   u8RemoteEnableFlagAndDeviceStatus;
           zuint24                          u24ApplianceStatusTwo;
} tsCLD_AC_SignalStateResponseORSignalStateNotificationPayload;

```

where:

-   `eApplianceStatus` is a value indicating the reported appliance status \(the relevant status values depend on the appliance\):


|**Status Value**|**Description**|
|----------------|---------------|
|0x00|Reserved|
|0x01|Appliance in off state|
|0x02|Appliance in stand-by|
|0x03|Appliance already programmed|
|0x04|Appliance already programmed and ready to start|
|0x05|Appliance is running|
|0x06|Appliance is in pause state|
|0x07|Appliance end programmed tasks|
|0x08|Appliance is in a failure state|
|0x09|Appliance programmed tasks have been interrupted|
|0x0A|Appliance in idle state|
|0x0B|Appliance rinse hold|
|0x0C|Appliance in service state|
|0x0D|Appliance in superfreezing state|
|0x0E|Appliance in supercooling state|
|0x0F|Appliance in superheating state|
|0x10-0x3F|Reserved|
|0x40-0x7F|Non-standardised|
|0x80-0xFF|Proprietary|

-   `u8RemoteEnableFlagAndDeviceStatus` is a bitmap value indicating the status of the relationship between the appliance and the remote control unit as well as the type of additional status information reported in `u24ApplianceStatusTwo`:


|**Bits**|**Field**|**Values/Description**|
|--------|---------|----------------------|
|0-3|Remote Enable Flags|Status of remote control link:

 -   0x0: Disabled

-   0x1: Enabled remote and energy control

-   0x2-0x06: Reserved

-   0x7: Temporarily locked/disabled

-   0x8-0xE: Reserved

-   0xF: Enabled remote control


|
|4-7|Device Status 2|Type of information in `u24ApplianceStatusTwo`:

 -   0x0: Proprietary

-   0x1: Proprietary

-   0x2: IRIS symptom code

-   0x3-0xF: Reserved


|

-   `u24ApplianceStatusTwo` is a value indicating non-standard or proprietary status information about the appliance. The type of status information represented by this value is indicated in the ‘Device Status 2’ field of `u8RemoteEnableFlagAndDeviceStatus`. In the case of an IRIS symptom code, the three bytes of this value represent a 3-digit code.


**Parent topic:**[Structures](../../appliance_control_cluster/topics/structures.md)

