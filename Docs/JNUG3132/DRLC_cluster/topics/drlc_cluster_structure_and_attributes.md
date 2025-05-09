# DRLC Cluster structure and attributes

The DRLC cluster has no server attributes but has client attributes that are contained in the following `tsCLD_DRLC` structure:

```
typedef struct
{
    uint8               u8UtilityEnrolmentGroup;
    uint8               u8StartRandomizeMinutes;
    uint8               u8StopRandomizeMinutes;
    uint16              u16DeviceClassValue;
} tsCLD_DRLC;

```

where:

-   `u8UtilityEnrolmentGroup` identifies the ‘enrolment’ group to which the device belongs, where a group of devices is defined by the utility company in order to aid load management in a large system. The default value of 0x00 is used to indicate membership of all groups.

-   `u8StartRandomizeMinutes` specifies the largest random delay, in minutes, that can be applied to the start of a Load Control Event \(so a random delay, no greater than this value, will be applied to an individual event\). The valid range of values is 0x00 to 0x3C \(0 to 60 mins\), where 0x00 indicates that no delay is to be applied.

-   `u8StopRandomizeMinutes` specifies the largest random delay, in minutes, that can be applied to the end of a Load Control Event \(so a random delay, no greater than this value, will be applied to an individual event\). The valid range of values is 0x00 to 0x3C, where 0x00 indicates that no delay is to be applied.

-   `u16DeviceClassValue` is a bitmap specifying the relevant device classes \(for example, water heater and pool pump\). Enumerations are provided for the device classes and are detailed in [Section 41.10.1](device_class_enumerations.md#id_e306426a-097c-4efe-b3ed-71042120ef0d). If more than one device class is required, the relevant enumerations can be bitwise-ORed.


**Note:** It may be desirable to refuse write access to the `u16DeviceClassValue` attribute on a device. To do this, when a ‘write attributes’ request is received and an E\_ZCL\_CBET\_CHECK\_ATTRIBUTE\_RANGE event is generated for this attribute, the application should set the `eAttributeStatus` field of the event to E\_ZCL\_DENY\_ATTRIBUTE\_ACCESS.

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

