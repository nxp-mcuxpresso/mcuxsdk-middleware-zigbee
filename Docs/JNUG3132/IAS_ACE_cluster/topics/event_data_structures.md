# Event Data Structures

The following structures hold the data contained in certain IAS ACE cluster events.

## E\_CLD\_IASACE\_CMD\_ARM\_RESP Data 

```
typedef struct
{
    zenum8         eArmNotification;   
} tsCLD_IASACE_ArmRespPayload;

```

where `eArmNotification` is an enumeration indicating the outcome of the Arm command, one of:

-   E\_CLD\_IASACE\_ARM\_NOTIF\_ALL\_ZONES\_DISARMED
-   E\_CLD\_IASACE\_ARM\_NOTIF\_ONLY\_DAY\_HOME\_ZONES\_ARMED
-   E\_CLD\_IASACE\_ARM\_NOTIF\_ONLY\_NIGHT\_SLEEP\_ZONES\_ARMED
-   E\_CLD\_IASACE\_ARM\_NOTIF\_ALL\_ZONES\_ARMED
-   E\_CLD\_IASACE\_ARM\_NOTIF\_INVALID\_ARM\_DISARM\_CODE
-   E\_CLD\_IASACE\_ARM\_NOTIF\_NOT\_READY\_TO\_ARM
-   E\_CLD\_IASACE\_ARM\_NOTIF\_ALREADY\_DISARMED

## E\_CLD\_IASACE\_CMD\_GET\_ZONE\_ID\_MAP\_RESP Data 

```
typedef struct
{
    zbmap16  au16ZoneIDMap[CLD_IASACE_MAX_BYTES_FOR_NUM_OF_ZONES]; 
} tsCLD_IASACE_GetZoneIDMapRespPayload;

```

where `au16ZoneIDMap[``]` is an array, each element being a 16-bit bitmap indicating whether each of a set of zone identifiers is allocated - a Zone ID is represented by a single bit which is set to ‘1’ if the identifier value has been allocated and ‘0’ otherwise.

| Array Element    | Bit                         | Zone ID                                              |
| ---------------- | --------------------------- | ---------------------------------------------------- |
| au16ZoneIDMap[0] | 0<br>1<br>: 15              | 0x00<br>0x01<br>: 0x0F                               |
| au16ZoneIDMap[1] | 0<br>1<br>: 15              | 0x10<br>0x11<br>: 0x1F                               |
| :                | :                           | :                                                    |
| au16ZoneIDMap[N] | 0<br>1<br>:<br>n<br>:<br>15 | 16N<br>16N + 0x1<br>:<br>16N + 0xn<br>:<br>16N + 0xF |

## E\_CLD\_IASACE\_CMD\_GET\_ZONE\_INFO\_RESP Data 

```
typedef struct
{
    zuint8                    u8ZoneID;
    zbmap16                   u16ZoneType;
    zieeeaddress              u64IeeeAddress;
    tsZCL_CharacterString     sZoneLabel; 
} tsCLD_IASACE_GetZoneInfoRespPayload;

```

where:

-   `u8ZoneID` is the identifier of the zone

-   `u16ZoneType` is a value indicating the type of zone \(for the possible values, refer to the description of the attribute `e``16ZoneType` of the IAS Zone cluster in [Section 37.2](../../IAS_Zone_cluster/topics/ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

-   `u64IeeeAddress` is the IEEE/MAC address of the device which hosts the zone

-   `sZoneLabel` is a character string representing a name/label for the zone


## E\_CLD\_IASACE\_CMD\_ZONE\_STATUS\_CHANGED Data 

```
typedef struct
{
    zuint8                    u8ZoneID;
    zenum16                   eZoneStatus;
    zenum8                    eAudibleNotification;
    tsZCL_CharacterString     sZoneLabel;
} tsCLD_IASACE_ZoneStatusChangedPayload;

```

where:

-   `u8ZoneID` is the identifier of the zone

-   `u16ZoneType` is a value indicating the type of zone \(for the possible values, refer to the description of the attribute `e``16ZoneType` of the IAS Zone cluster in [Section 37.2](../../IAS_Zone_cluster/topics/ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

-   `eAudibleNotification` is a value specifying whether an audible notification

    \(e.g. a chime\) to signal the change is required \(enumerations are available in `teCLD_IASACE_AudibleNotification` - see [Section 38.8.4](tecld_iasace_audiblenotification.md#id_3be77966-a0dd-4c6d-8068-4b85a3d9a4ee)\):


|**Value**|**Status**|
|---------|----------|
|0x00|Audible notification to be muted|
|0x01|Audible notification to be sounded|
|0x02 - 0xFF|Reserved|

-   `sZoneLabel` is a character string representing a name/label for the zone


## E\_CLD\_IASACE\_CMD\_PANEL\_STATUS\_CHANGED Data                          

```
tsCLD_IASACE_PanelStatusChangedOrGetPanelStatusRespPayload

```

For details of this structure, see [Section 38.7.5](custom_command_payloads.md#id_becec8e4-bbfa-4204-8937-a7f52c960d70).

## E\_CLD\_IASACE\_CMD\_GET\_PANEL\_STATUS\_RESP Data 

```
tsCLD_IASACE_PanelStatusChangedOrGetPanelStatusRespPayload

```

For details of this structure, see [Section 38.7.5](custom_command_payloads.md#id_becec8e4-bbfa-4204-8937-a7f52c960d70).

## E\_CLD\_IASACE\_CMD\_BYPASS\_RESP Data 


```
typedef struct
{
    zuint8          u8NumofZones;
    zuint8         *pu8BypassResult;           
} tsCLD_IASACE_BypassRespPayload;

```

where:

-   `u8NumOfZones` is the number of zones ‘bypassed’ \(taken out of the system\)

-   `pu8BypassResult` is a pointer to a list of identifiers specifying the zones bypassed \(the number of zones in the list is specified in `u8NumOfZones`\)


## E\_CLD\_IASACE\_CMD\_GET\_ZONE\_STATUS\_RESP Data 

```
typedef struct
{
    zbool           bZoneStatusComplete;
    zuint8          u8NumofZones;
    zuint8         *pu8ZoneStatus;         
} tsCLD_IASACE_GetZoneStatusRespPayload;

```

where:

-   `bZoneStatusComplete` is a Boolean indicating whether the current response completes the set of zones for which status information can be returned \(if not, the client should send another Get Zone Status command to the server\):

    -   TRUE - no more zone status information to be returned

    -   FALSE - status information for more zones available to be queried

-   `u8NumofZones` is the number of zones for which status information was returned in this response

-   `pu8ZoneStatus` is a pointer to a list of status values for the reported zones \(the number of values in the list is indicated by `u8NumofZones` above\) - each is a 24-bit value containing the following information:


|**Bits**|**Description**|
|--------|---------------|
|0-7|Zone ID|
|8-23|Value of `b16ZoneStatus` attribute of the IAS Zone cluster for the zone|

**Parent topic:**[Structures](../../IAS_ACE_cluster/topics/structures.md)

