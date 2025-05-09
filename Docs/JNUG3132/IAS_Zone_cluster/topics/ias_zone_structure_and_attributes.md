# IAS Zone Structure and Attributes

The structure definition for the IAS Zone cluster is:

```
typedef struct
{
#ifdef IASZONE_SERVER    
    zenum8     e8ZoneState; 
    zenum16    e16ZoneType;
    zbmap16    b16ZoneStatus; 
    zuint64    u64IASCIEAddress; 
    zuint8     u8ZoneId;
#ifdef CLD_IASZONE_ATTR_ID_NUMBER_OF_ZONE_SENSITIVITY_LEVELS
    zuint8     u8NumberOfZoneSensitivityLevels;
#endif
#ifdef CLD_IASZONE_ATTR_ID_CURRENT_ZONE_SENSITIVITY_LEVEL
    zuint8     u8CurrentZoneSensitivityLevel;
#endif   
#endif
    zuint16    u16ClusterRevision;
} tsCLD_IASZone;

```

where:

## ‘Zone Information’ Attribute Set 

-   `e8ZoneState` is a mandatory attribute which indicates the membership status of the device in an IAS system \(enrolled or not enrolled\) - one of:
    -   E\_CLD\_IASZONE\_STATE\_NOT\_ENROLLED \(0x00\)

    -   E\_CLD\_IASZONE\_STATE\_ENROLLED \(0x01\)

        -   ‘Enrolled’ means that the cluster client will react to Zone State Change Notification commands from the cluster server.
-   `e16ZoneType` is a mandatory attribute which indicates the zone type and the types of security detectors that can trigger the alarms, Alarm1 and Alarm2:

| Enumeration                                     | Value  | Type                      | Alarm1                     | Alarm2                   |
| ----------------------------------------------- | ------ | ------------------------- | -------------------------- | ------------------------ |
| E_CLD_IASZONE_TYPE_STANDARD_CIE                 | 0x0000 | Standard CIE              | System alarm               | \-                       |
| E_CLD_IASZONE_TYPE_MOTION \_ SENSOR             | 0x000D | Motion sensor             | Intrusion indication       | Presence indica- tion    |
| E_CLD_IASZONE_TYPE_CONTACT \_ SWITCH            | 0x0015 | Contact switch            | First portal open close    | Second portal open-close |
| E_CLD_IASZONE_TYPE_FIRE_SENSOR                  | 0x0028 | Fire sensor               | Fire indication            | \-                       |
| E_CLD_IASZONE_TYPE_WATER_SENSOR                 | 0x002A | Water sensor              | Water overflow indication  | \-                       |
| E_CLD_IASZONE_TYPE_GAS_SENSOR                   | 0x002B | Gas sensor                | Carbon monoxide indication | Cooking indica- tion     |
| E_CLD_IASZONE_TYPE_PERSONAL \_ EMERGENCY_DEVICE | 0x002C | Personal emergency device | Fall/concussion            | Emergency but- ton       |
| E_CLD_IASZONE_TYPE_VIBRATION \_ MOVEMENT_SENSOR | 0x002D | Vibration movement sensor | Movement indication        | Vibration                |
| E_CLD_IASZONE_TYPE_REMOTE \_ CONTROL            | 0x010F | Remote control            | Panic                      | Emergency                |
| E_CLD_IASZONE_TYPE_KEY_FOB                      | 0x0115 | Key fob                   | Panic                      | Emergency                |
| E_CLD_IASZONE_TYPE_KEYPAD                       | 0x021D | Keypad                    | Panic                      | Emergency                |
| E_CLD_IASZONE_TYPE_STANDARD \_ WARNING_DEVICE   | 0x0225 | Standard warning device   | \-                         | \-                       |
| E_CLD_IASZONE_TYPE_INVALID_ZONE                 | 0xFFFF | Invalid zone type         | \-                         | \-                       |

-   `b``16ZoneStatus` is a mandatory attribute which is a 16-bit bitmap indicating the status of each of the possible notification triggers from the device:


| Bit   | Description                                                             |
| ----- | ----------------------------------------------------------------------- |
| 0     | Alarm1:<br>1 - Opened or alarmed<br>0 - Closed or not alarned           |
| 1     | Alarm2:<br>1 - Opened or alarmed<br>0 - Closed or not alarned           |
| 2     | Tamper:<br>1 - Tampered with<br>0 - Not tampered with                   |
| 3     | Battery:<br>1 - Low<br>0 - OK                                           |
| 4     | Supervision reports:<br> 1 - Reports<br>0 - No reports (See the note below)                   |
| 5     | Restore reports:<br> 1 - Reports<br>0 - No reports   (See the note below)                        |
| 6     | Trouble:<br>1 - Trouble/failure<br>0 - OK                               |
| 7     | AC (mains): 1 - Fault<br>0 - OK                                         |
| 8     | Test mode:<br>1 - Sensor in test mode<br>0 - Sensor in operational mode |
| 9     | Battery defect:  <br>1 - Defective battery detected<br>0 - Battery OK   |
| 10-15 | Reserved                                                                |

- Bit 4 indicates whether the Zone device issues periodic Zone Status Change Notification commands that may be used by the CIE device as evidence that the Zone device is operational.

- Bit 5 indicates whether the Zone device issues a Zone Status Change Notification command to notify when an alarm is no longer present \(some Zone devices do not have the ability to detect when the alarm condition has disappeared\).

## ‘Zone Settings’ Attribute Set 

-   `u64IASCIEAddress` is a mandatory attribute containing the 64-bit IEEE/MAC address of the CIE device to which the cluster server must send commands/ notifications

-   `u8ZoneId` is a mandatory attribute containing the 8-bit identifier for the zone allocated by the CIE device at the time of enrollment

-   `u8NumberOfZoneSensitivityLevels` is an optional attribute containing the number of sensitivity levels \(for the detectable quantity\) for the zone - for devices that have only one sensitivity level, this attribute need not be enabled or can be set to 0x00 or 0x01

    **Note:** The definition of a sensitivity level is manufacturer-specific but detector ‘sensitivity’ should increase with higher values of this attribute.

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)


**Parent topic:**[IAS Zone Cluster](../../IAS_Zone_cluster/topics/ias_zone_cluster.md)

