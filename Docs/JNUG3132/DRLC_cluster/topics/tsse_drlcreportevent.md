# tsSE\_DRLCReportEvent

The structure of type `tsSE_DRLCReportEvent` contains the parameters of a Report Event Status message, as shown and described below.

```
typedef struct {
    uint8   u8EventStatus;
    uint8   u8AverageLoadAdjustmentPercentageApplied;
    uint8   u8DutyCycleApplied;
    uint8   u8EventControl;
    uint8   u8SignatureType;
    uint8   u8CriticalityLevelApplied;
    bool_t  bSignatureVerified;
    uint16  u16CoolingTemperatureSetPointApplied;
    uint16  u16HeatingTemperatureSetPointApplied;
    uint32  u32IssuerId;
    uint32  u32EventStatusTime;
    tsSE_DRLCOctets     sSignature;
} tsSE_DRLCReportEvent;

```

where:

-   `u8EventStatus` is the reported LCE status - enumerations are provided and described in [Section 41.10.8](lce_status_enumerations.md#id_a042c90e-cd3d-45f8-8472-9845f41ecca4)

-   `u8AverageLoadAdjustmentPercentageApplied` is an optional field containing the load adjustment percentage applied by the sending client \(if the user has chosen to over-ride the original setting in the LCE\) - for the format of this setting, refer to the equivalent field description in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1) \(0x80 indicates that the field is not used\)

-   `u8DutyCycleApplied` is an optional field containing the percentage duty cycle applied by the sending client \(if the user has chosen to over-ride the original setting in the LCE\) - for the format of this setting, refer to the equivalent field description in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1) \(0xFF indicates that the field is not used\)

-   `u8EventControl` is a bitmap which specifies whether a randomised start-time and/or randomised end-time are configured for the LCE:


|**Bit**|**Description**|
|-------|---------------|
|0|1 = randomised start-time, 0 = immediate start-time|
|1|1 = randomised end-time, 0 = immediate end-time|
|2-7|Not used|

-   `u8SignatureType` is the type of algorithm, if any, used to create the signature for the Report Event Status message \(only one algorithm, ECDSA, is currently supported\):


```
#define SE_DRLC_NO_SIGNATURE (0x00)
#define SE_DRLC_SIGNATURE_TYPE_ECDSA     (0x01)

```

-   `u8CriticalityLevelApplied` is the criticality level of the LCE - enumerations are provided and described in [Section 41.10.3](criticality_level_enumerations.md#id_107a83ae-db5f-4158-8fd5-e4fa9d5557fb)

-   `bSignatureVerified` is filled in by the recipient of the Report Event Status message \(therefore, the DRLC cluster server\) to indicate whether the signature of the message has been verified and is valid:

    TRUE - verified and valid

    FALSE - verified and not valid, or not verified

-   `u16CoolingTemperatureSetPointApplied` is an optional field containing the cooling temperature applied by the sending client \(if the user has chosen to over-ride the original setting in the LCE\) - for the format of this setting, refer to the equivalent field description in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1) \(0x8000 indicates that the field is not used\)

-   `u16HeatingTemperatureSetPointApplied` is an optional field containing the heating temperature applied by the sending client \(if the user has chosen to over-ride the original setting in the LCE\) - for the format of this setting, refer to the equivalent field description in [Section 41.11.1](tsse_drlcloadcontrolevent.md#id_beb5b077-259a-4c2d-a863-11cc8d38d3e1) \(0x8000 indicates that the field is not used\)

-   `u32IssuerId` is the unique identifier for the LCE, as issued by the utility company

-   `u``32EventStatusTime` is the time \(UTC\) at which the Report Event Status message was issued

-   `s``Signature` is the signature for the Report Event Status message - this is the concatenation of two ECDSA signature components \(r,s\)


**Note:** It is recommended that signatures are supported by your application for backward compatibility.

**Parent topic:**[Structures](../../DRLC_cluster/topics/structures.md)

