# Custom Command Payloads

The following structures contain the payloads for the IAS WD cluster custom commands.

## ‘Start Warning’ Payload 

The following structure contains the payload of a Start Warning command.

```
typedef struct
{
 uint8   u8WarningModeStrobeAndSirenLevel;
 uint16  u16WarningDuration;
 uint8   uStrobeDutyCycle;
 enum8       eStrobeLevel;
}tsCLD_IASWD_StartWarningReqPayload;

```

where:

-   `u8WarningModeStrobeAndSirenLevel` is an 8-bit bitmap containing the requirements for the warning alarm, as follows:

| Bits | Description                                                                                                                                                                                                                              |
| ---- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 0-3  | Warning Mode - indicates the meaning of the requested warning:<br>0 - Stop (no warning)<br>1 - Burglar<br>2 - Fire<br>3 - Emergency<br>4 - Police panic<br>5 - Fire panic<br>6 - Emergency (medical) panic All other values are reserved |
| 4-5  | Strobe\* - indicates whether a visual strobe indication of the warning is required:<br>0 - No strobe<br>1 - Use strobe<br>Other values are reserved                                                                                      |
| 6-7  | Siren Level - indicates the requested level of an audible siren (if enabled):<br>0 - Low level<br>1 - Medium level<br>2 - High level<br>3 - Very high level                                                                              |

\* If ‘Strobe’ is 1 and ‘Warning Mode’ is 0, only the strobe is activated

-   `u16WarningDuration` is the requested time-duration of the warning, in seconds, which must be less than or equal to the value of the `u16MaxDuration` attribute

-   `uStrobeDutyCycle` is the duty-cycle of the strobe pulse, expressed as a percentage in 10% steps \(example, 0x1E represents 30%\) - invalid values are rounded to the nearest multiple of 10%

-   `eStrobeLevel` is the level of the strobe \(pulse\)


## ‘Squawk’ Payload 

The following structure contains the payload of a Squawk command.

```
typedef struct
{
  uint8  u8SquawkModeStrobeAndLevel;  
}tsCLD_IASWD_SquawkReqPayload;

```

Where `u8SquawkModeStrobeAndLevel` is an 8-bit bitmap containing the requirements for the ‘squawk’, as follows.

| Bits | Description                                                                                                                                             |
| ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 0-3  | Squawk Mode - indicates the meaning of the required ‘squawk’:<br>0 - System is armed<br>1 - System is disarmed<br>All other values are reserved         |
| 4    | Strobe - indicates whether a visual strobe indication of the ‘squawk’ is required:<br>0 - No strobe<br>1 - Use strobe                                   |
| 5    | Reserved                                                                                                                                                |
| 6-7  | Squawk Level - indicates the requested level of the audible squawk sound:<br>0 - Low level<br>1 - Medium level<br>2 - High level<br>3 - Very high level |

**Parent topic:**[Structures](../../IAS_WD_cluster/topics/structures.md)

