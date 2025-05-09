# tsSE\_DRLCCancelLoadControlEvent

The structure of type `tsSE_DRLCCancelLoadControlEvent` contains the parameters of a Cancel LCE command, as shown and described below.

```
typedef struct {
    uint32   u32IssuerId;
    uint16   u16DeviceClass;
    uint8    u8UtilityEnrolmentGroup;
    teSE_DRLCCancelControl  eCancelControl;
    uint32   u32effectiveTime;
} tsSE_DRLCCancelLoadControlEvent;

```

where:

-   `u32IssuerId` is the identifier \(provided by the utility company\) of the LCE to be canceled

-   `u16DeviceClass` is a bitmap indicating the device class\(es\) to which the LCE cancelation applies - enumerations for the device classes are provided, as described in [Section 41.10.1](device_class_enumerations.md#id_e306426a-097c-4efe-b3ed-71042120ef0d)

-   `u8UtilityEnrolmentGroup` is the enrolment group of the devices to which the LCE cancelation applies

-   `eCancelControl` indicates whether to honour a randomised end that has been configured in the LCE - enumerations are provided, as described in [Section 41.10.4](lce_cancellation_enumerations.md#id_a8a2405b-dc1c-405c-829e-b4e989614dc7)

-   `u32effectiveTime` is the time \(UTC\) from which the LCE cancelation is effective


**Parent topic:**[Structures](../../DRLC_cluster/topics/structures.md)

