# Custom Command Payloads

## Off With Effect Request Payload 

```
typedef struct
{
    zuint8                 u8EffectId;
    zuint8                 u8EffectVariant;
} tsCLD_OnOff_OffWithEffectRequestPayload;

```

where:

-   `u8EffectId` indicates the required ‘off effect’:

    -   0x00 - Fade

    -   0x01 - Rise and fall

        -   All other values are reserved.
-   `u8EffectVariant` indicates the required variant of the specified ‘off effect’ - the interpretation of this field depends on the value of `u8EffectId`, as indicated in the table below.


| u8EffectId              | u8EffectVariant | Description                                                                                     |
| ----------------------- | --------------- | ----------------------------------------------------------------------------------------------- |
| 0x00<br>(Fade)          | 0x00            | Fade to off in 0.8 seconds (default)                                                            |
|                         | 0x01            | No fade                                                                                         |
|                         | 0x02            | Reduce brightness by 50 % in 0.8 seconds then fade to off in 4 seconds                          |
|                         | 0x03-0xFF       | Reserved                                                                                        |
| 0x01<br>(Rise and fall) | 0x00            | Increase brightness by 20 % (if possible) in 0.5 seconds then fade to off in 1 second (default) |
|                         | 0x01-0xFF       | Reserved                                                                                        |
| 0x02-0xFF               | 0x00-0xFF       | Reserved                                                                                        |                                                     |
 

## On With Timed Off Request Payload 

```
typedef struct
{
    zuint8                 u8OnOff;
    zuint16                u16OnTime;
    zuint16                u16OffTime;
} tsCLD_OnOff_OnWithTimedOffRequestPayload;

```

where:

-   `u8OnOff` indicates when the command can be accepted:

    -   0x00 - at all times \(apart from in waiting time, if implemented\)

    -   0x01 - only when light is on

        -   All other values are reserved.
-   `u16OnTime` is the ‘on time’, expressed in tenths of a second in the range 0x0000 to 0xFFFE.

-   `u16OffTime` is the ‘off waiting time’, expressed in tenths of a second in the range 0x0000 to 0xFFFE


**Parent topic:**[Structures](../../OnOff_cluster/topics/structures.md)

