# tsCLD\_Commissioning\_RestartDevicePayload

The following structure contains the payload of a Restart Device command.

```
typedef struct
{
    zbmap8                  u8Options;
    uint8                   u8Delay;
    uint8                   u8Jitter;
} tsCLD_Commissioning_RestartDevicePayload;

```

where:

```
u8Options is a 8-bit bitmap specifying the required start-up options:

```

|**Bits**|**Option**|**Description**|
|--------|----------|---------------|
|0-2|Start-up Mode|Determines the starting state of the device restart:

 -   0b000: Restart with current Start-up Parameter values

-   0b001: Restart from existing stack state


 All other values are reserved.

|
|3|Immediate|Determines how quickly the start-up procedure will begin follow-ing receipt of the command or the specified delay/jitter:

 -   1: Immediately

-   0: At a convenient moment \(e.g. following any pending actions\)


|
|4-7|-|Reserved|

```
u8Delay specifies the time-delay, in seconds, before the start-up procedure should be executed. 
u8Jitter is a value which determines the possible range of values of the jitter that is added to the delay u8Delay - the jitter, in milliseconds, is a random value in the range 0 to u8Jitter x 80.

```

**Parent topic:**[Structures](../../Commissioning_cluster/topics/structures.md)

