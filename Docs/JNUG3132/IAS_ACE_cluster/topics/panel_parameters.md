# Panel Parameters

The following structure is used to store the ‘panel parameters’ on the IAS ACE cluster server.

```
typedef struct
{
    zenum8    ePanelStatus;
    zuint8    u8SecondsRemaining;
    zenum8    eAudibleNotification;
    zenum8    eAlarmStatus;
}tsCLD_IASACE_PanelParameter;

```

where:

-   `ePanelStatus` is a value indicating the status to be displayed on the panel, as follows \(enumerations are available in `teCLD_IASACE_PanelStatus` - see [Section 38.8.2](tecld_iasace_panelstatus.md#id_54442dcb-4435-4539-9846-4840a403eadf)\):


|**Value**|**Status**|
|---------|----------|
|0x00|Disarmed \(all zones\) and ready to be armed|
|0x01|Armed stay|
|0x02|Armed night|
|0x03|Armed away|
|0x04|Exit delay|
|0x05|Entry delay|
|0x06|Not ready to be armed|
|0x07|In alarm|
|0x08|Arming stay|
|0x09|Arming night|
|0x0A|Arming away|
|0x0B - 0xFF|Reserved|

-   `u8SecondsRemaining` represents the time, in seconds, that the server will remain in the displayed state when the latter is ‘Exit delay’ or ‘Entry delay’ \(for other states, this field should be set to 0x00\).

-   `eAudibleNotification` is a value specifying whether an audible notification \(e.g. a chime\) is required to signal a zone status change \(enumerations are available in `teCLD_IASACE_AudibleNotification` - see [Section 38.8.4](tecld_iasace_audiblenotification.md#id_3be77966-a0dd-4c6d-8068-4b85a3d9a4ee)\):


|**Value**|**Status**|
|---------|----------|
|0x00|Audible notification muted|
|0x01|Audible notification sounded|
|0x02 - 0xFF|Reserved|

-   `eAlarmStatus` is a value indicating the alarm status/type when the panel’s state is ‘In Alarm’, as follows \(enumerations are available in `teCLD_IASACE_AlarmStatus` - see [Section 38.8.3](tecld_iasace_alarmstatus.md#id_2a7a360b-e97c-428e-991f-e24113781296)\):


|**Value**|**Status**|
|---------|----------|
|0x00|No alarm|
|0x01|Burglar|
|0x02|Fire|
|0x03|Emergency|
|0x04|Police panic|
|0x05|Fire panic|
|0x06|Emergency panic|
|0x07 - 0xFF|Reserved|

**Parent topic:**[Structures](../../IAS_ACE_cluster/topics/structures.md)

