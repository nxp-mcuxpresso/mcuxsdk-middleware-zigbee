# tsSE\_DRLCLoadControlEvent

The structure of type `tsSE_DRLCLoadControlEvent` contains the parameters of a Load Control Event \(LCE\), as shown and described below.

```
typedef struct {
 uint8    u8UtilityEnrolmentGroup;
 uint8    u8CriticalityLevel;
 uint8    u8CoolingTemperatureOffset;
 uint8    u8HeatingTemperatureOffset;
 uint8    u8AverageLoadAdjustmentSetPoint;
 uint8    u8DutyCycle;
 uint8    u8EventControl;
 uint16   u16DeviceClass;
 uint16   u16DurationInMinutes;
 uint16   u16CoolingTemperatureSetPoint;
 uint16   u16HeatingTemperatureSetPoint;
 uint32   u32IssuerId;
 uint32   u32StartTime;
}tsSE_DRLCLoadControlEvent;

```

where:

-   `u8UtilityEnrolmentGroup` identifies the group of devices to which the LCE applies - an ‘enrolment group’ is defined by the utility company. The identifier 0x00 is reserved to indicate ‘all groups’.

-   `u8CriticalityLevel` is a value representing the level of criticality of the LCE. Enumerations are provided for the different levels and are detailed in [Section 41.10.3](criticality_level_enumerations.md#id_107a83ae-db5f-4158-8fd5-e4fa9d5557fb).

-   `u8CoolingTemperatureOffset` \(optional\) specifies the required temperature offset, in units of 0.1oC, above the current temperature set-point of a cooling device \(example, 0x5 represents a temperature offset of 0.5oC\). The setting 0xFF is used to indicate that no offset is required.

-   `u8HeatingTemperatureOffset` \(optional\) specifies the required temperature offset, in units of 0.1oC, below the current temperature set-point of a heating device \(example, 0x14 represents a temperature offset of 2.0oC\). The setting 0xFF is used to indicate that no offset is required.

-   `u8AverageLoadAdjustmentSetPoint` \(optional\) specifies the maximum permissible load as an offset from the consumer’s average load, where this offset is expressed as a positive or negative percentage in units of 1% \(e.g. 20% allows loads of up to 120% of the average while -10% allows loads of up to 90% of the average\). The offset has a valid range of -100% to +100% and is represented in two’s complement form \(e.g. 15% is represented by 0x0F and

    -5% is represented by 0xFB\). The value 0x80 is used to indicate that no such limit is required.

-   `u8DutyCycle` \(optional\) specifies the percentage duty cycle for the load supplied to the device - that is, the percentage of the LCE duration for which the load will be supplied \(e.g. for a duty cycle of 80%, the supplied device will be ‘on’ for 80% of the duration of the LCE\). The manner in which the duty cycle is implemented \(e.g. periodicity\) is device-specific. The valid range of duty cycle values is 0 to 100. The setting 0xFF indicates that no duty cycling is required.

-   `u8EventControl` specifies whether a randomised start-time and/or randomised end-time are required for the LCE. The following bit-masks are provided to allow the start-time and end-time of an LCE to be individually randomised \(they can be bitwise-ORed to randomize both times\):


```
#define SE_DRLC_CONTROL_RANDOMISATION_START_TIME_MASK   (0x01)
#define SE_DRLC_CONTROL_RANDOMISATION_STOP_TIME_MASK (0x02)

```

-   `u``16DeviceClass` identifies the class\(es\) of device to which the LCE applies. Enumerations are provided for the various device classes, which may be combined in a bitwise-OR operation, and are detailed in [Section 41.10.1](device_class_enumerations.md#id_e306426a-097c-4efe-b3ed-71042120ef0d).

-   `u16DurationInMinutes` specifies the duration, in minutes, of the LCE \(although the actual duration will be longer than the specified duration if a randomized end-time is required\). The maximum possible duration that can be specified is 1440 minutes \(one day\).

-   `u16CoolingTemperatureSetPoint` \(optional\) specifies the required temperature set-point, in units of 0.01oC, for a cooling device, where a negative temperature is represented in two’s complement form \(e.g. a temperature of 20oC is represented by 0x07D0 and -40oC is represented by 0xF060\). The valid temperature range is -273.15°C to 327.67°C. The setting 0x8000 is used to indicate that no temperature set-point is required.

-   `u16HeatingTemperatureSetPoint` \(optional\) specifies the required temperature set-point, in units of 0.01oC, for a heating device, where a negative temperature is represented in two’s complement form \(for example, a temperature of 25oC is represented by 0x09C4 and -1oC is represented by 0xFFFF\). The valid temperature range is -273.15°C to 327.67°C. The setting 0x8000 is used to indicate that no temperature set-point is required.

-   `u32IssuerId` is a unique identifier for the LCE, issued by the utility company \(the value could be based on the time-stamp of when the LCE was issued\).

-   `u``32StartTime` represents the start-time \(UTC\) of the LCE \(although the actual start-time is later if a randomized start-time is required\). The value 0x000000000 is used to indicate a ‘start-time of now’.


**Parent topic:**[Structures](../../DRLC_cluster/topics/structures.md)

