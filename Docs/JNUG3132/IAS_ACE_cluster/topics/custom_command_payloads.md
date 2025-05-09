# Custom Command Payloads

The following structures contain the payloads for the IAS ACE cluster custom commands.

## ‘Arm’ Command Payload 

The following structure contains the payload of a Arm command.

```
typedef struct
{
    zenum8                     eArmMode;   
    tsZCL_CharacterString      sArmDisarmCode;
    zuint8                     u8ZoneID;
} tsCLD_IASACE_ArmPayload;

```

where:

-   `eArmMode` is a value indicating the state of armament in which to put the zone \(enumerations are available in `teCLD_IASACE_ArmMode` - see [Section](tecld_iasace_armmode.md#id_d31bfeb6-f47f-4633-a94c-7dfa2fc303ed)38.8.1\):


|**Value**|**Status**|
|---------|----------|
|0x00|Disarm|
|0x01|Arm day/home zones only|
|0x02|Arm night/sleep zones only|
|0x03|Arm all zones|
|0x04 - 0xFF|Reserved|

-   `sArmDisarmCode` is an 8-character string containing the arm/disarm code \(if a code is not required, set to "00000000"\)

-   `u8ZoneID` is the identifier of the zone to arm/disarm


## ‘Bypass’ Command Payload 

The following structure contains the payload of a Bypass command.

```
typedef struct
{   
    zuint8                     u8NumOfZones;
    zuint8                    *pu8ZoneID;
    tsZCL_CharacterString      sArmDisarmCode;
} tsCLD_IASACE_BypassPayload;

```

where:

-   `u8NumOfZones` is the number of zones to be ‘bypassed’ \(taken out of the system\)

-   `pu8ZoneID` is a pointer to a list of identifiers specifying the zones to be bypassed \(the number of zones in the list is specified in `u8NumOfZones`\)

-   `sArmDisarmCode` is an 8-character string containing the arm/disarm code \(if a code is not required, set to "00000000"\)


## ‘Get Zone Information’ Command Payload 

The following structure contains the payload of a Get Zone Information command.

```
typedef struct
{
    zuint8          u8ZoneID;
} tsCLD_IASACE_GetZoneInfoPayload;

```

where `u8ZoneID` is the identifier of the zone on which information is required.

## ‘Set Bypassed Zone List’ Command Payload 

The following structure contains the payload of a Set Bypassed Zone List command.

```
typedef struct
{
    zuint8          u8NumofZones;
    zuint8         *pu8ZoneID;         
} tsCLD_IASACE_SetBypassedZoneListPayload;

```

where:

-   `u8NumofZones` is the number of zones in the new bypassed zone list

-   `pu8ZoneID` is a pointer to the new bypassed zone list \(the number of zones in the list is specified in `u8NumOfZones`\)


## ‘Get Zone Status’ Command Payload 

The following structure contains the payload of a Get Zone Status command.

```
typedef struct
{
    zuint8         u8StartingZoneID;
    zuint8         u8MaxNumOfZoneID;
    zbool          bZoneStatusMaskFlag;
    zbmap16        u16ZoneStatusMask;
} tsCLD_IASACE_GetZoneStatusPayload;

```

where:

-   `u8StartingZoneID` is the identifier of the first zone for which status information is required

-   `u8MaxNumOfZoneID` is the maximum number of zones for which status information should be returned

-   `bZoneStatusMaskFlag` is a Boolean indicating whether status information should be returned for all zones or only for those zones with particular status values \(specified through `u16ZoneStatusMask` below\):

    -   TRUE - only zones with specific status values

    -   FALSE - all zones

-   `u16ZoneStatusMask` is a 16-bit bitmap indicating the zone status values of interest \(used when `bZoneStatusMaskFlag` is set to TRUE\) - the response to the request will contain information only for those zones with a status value indicated in this bitmap:


|**Bit**|**Description**|
|-------|---------------|
|0|Alarm1:

 1 - Opened or alarmed

 0 - Closed or not alarned

|
|1|Alarm2:

 1 - Opened or alarmed

 0 - Closed or not alarned

|
|2|Tamper:

 1 - Tampered with

 0 - Not tampered with

|
|3|Battery:

 1 - Low

 0 - OK

|
|4|Supervision reports:

 1 - Reports

 0 - No reports

|
|5|Restore reports:

 1 - Reports

 0 - No reports

|
|6|Trouble:

 1 - Trouble/failure

 0 - OK

|
|7|AC \(mains\):

 1 - Fault

 0 - OK

|
|8|Test mode:

 1 - Sensor in test mode

 0 - Sensor in operational mode

|
|9|Battery defect:

 1 - Defective battery detected

 0 - Battery OK

|
|10-15|Reserved|

## ‘Panel Status Changed or Get Panel Status Response’ 
The following structure contains the payload of a Panel Status Changed command or Get Panel Status Response.

```
typedef struct
{
    zenum8        ePanelStatus;
    zuint8        u8SecondsRemaining;
    zenum8        eAudibleNotification;
    zenum8        eAlarmStatus;
} tsCLD_IASACE_PanelStatusChangedOrGetPanelStatusRespPayload;

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

