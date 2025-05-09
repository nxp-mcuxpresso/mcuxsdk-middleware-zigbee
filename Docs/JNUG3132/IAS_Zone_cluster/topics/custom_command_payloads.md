# Custom Command Payloads

The following structures contain the payloads for the IAS Zone cluster custom commands.

## ‘Enroll Request’ Payload 

The following structure contains the payload of an Enroll Request command.

```
typedef struct
{
    zenum16    e16ZoneType;          
    uint16     u16ManufacturerCode;
}tsCLD_IASZone_EnrollRequestPayload;

```

where:

-   `e16ZoneType` is the zone type of the local \(sending\) node, as specified in the `e``16ZoneType` attribute \(see [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)

-   `u16ManufacturerCode` is the manufacturer ID code that is held in the Node Descriptor of the local \(sending\) node


## ‘Enroll Response’ Payload 

The following structure contains the payload of an Enroll Response command.

```
typedef struct
{
   teCLD_IASZoneZoneEnrollRspCode   e8EnrollResponseCode;          
   uint8                            u8ZoneID;
}tsCLD_IASZone_EnrollResponsePayload;

```

where:

-   `e8EnrollResponseCode` is a code indicating the outcome of the corresponding Enroll Request, one of:


|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_IASZONE\_ENROLL\_RESP\_SUCCESS|Requested enrollment successful|
|E\_CLD\_IASZONE\_ENROLL\_RESP\_NOT\_SUPPORTED|Zone type of requesting device is not known/sup-ported by the CIE device|
|E\_CLD\_IASZONE\_ENROLL\_RESP\_NO\_ENROLL\_PERMIT|CIE device is not allowing new zones to be enrolled at the present time|
|E\_CLD\_IASZONE\_ENROLL\_RESP\_TOO\_MANY\_ZONES|CIE device has reached its limit for the number of zones that it can enroll|

-   `u8ZoneID` is the index of the entry for the enrollment which has been added to the Zone table on the CIE device \(only valid for a successful enrollment\)


## ‘Zone Status Change Notification’ Payload 

The following structure contains the payload of a Zone Status Change Notification command.

```
typedef struct
{
   zbmap16    b16ZoneStatus;            
   zbmap8     b8ExtendedStatus;
   zuint8     u8ZoneId;
   zuint16    u16Delay;
}tsCLD_IASZone_StatusChangeNotificationPayload;

```

where:

-   `b16ZoneStatus` contains the new/current status of the \(sending\) zone device, as indicated in the `e``8ZoneState` attribute - one of:

    -   E\_CLD\_IASZONE\_STATE\_NOT\_ENROLLED \(0x01\)

    -   E\_CLD\_IASZONE\_STATE\_ENROLLED \(0x02\)

-   `b8ExtendedStatus` can be optionally used to indicate further status information, but otherwise should be set to zero

-   `u8ZoneId` is the index of the entry for the \(sending\) device in the Zone table on the CIE device

-   `u16Delay` is is the time-delay, in quarter-seconds, between the status change taking place in the `e``8ZoneState` attribute and the successful transmission of the Zone Status Change Notification \(this value can be used in assessing network traffic congestion\)


## ‘Initiate Test Mode Request’ Payload 

The following structure contains the payload of an Initiate Test Mode Request command.

```
typedef struct
{
    uint8    u8TestModeDuration;          
    uint8    u8CurrentZoneSensitivityLevel;
}tsCLD_IASZone_InitiateTestModeRequestPayload;

```

where:

-   `u8TestModeDuration` is the duration, in seconds, for which the device should remain in test mode

-   `u8CurrentZoneSensitivityLevel` is the current sensitivity level for the zone, as indicated in the `u8CurrentZoneSensitivityLevel` attribute \(see [Section 37.2](ias_zone_structure_and_attributes.md#id_83321b14-3ef5-49b3-aebd-b6ba63ef42e1)\)


**Parent topic:**[Structures](../../IAS_Zone_cluster/topics/structures.md)

