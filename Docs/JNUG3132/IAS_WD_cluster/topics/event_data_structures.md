# Event Data Structures

The following structures hold the data contained in certain IAS WD cluster events.

## E\_CLD\_IASWD\_CLUSTER\_UPDATE\_STROBE Data 

```
typedef struct
{
 bool_t   bStrobe;
 uint8    u8StrobeDutyCycle;
 zenum8   eStrobeLevel;
}tsCLD_IASWD_StrobeUpdate;

```

where:

```
bStrobe is the current (new) status of the strobe:

```

-   TRUE - Strobe ‘on’

-   FALSE - Strobe ‘off’

    -   `uStrobeDutyCycle` is the duty-cycle of the strobe pulse, expressed as a percentage in 10% steps \(example, 0x1E represents 30%\) - invalid values is rounded to the nearest multiple of 10%

    -   `eStrobeLevel` is the level \(brightness\) of the strobe pulse:

-   0 - Low level

-   1 - Medium level

-   2 - High level

-   3 - Very high level

    -   All other values are reserved

## E\_CLD\_IASWD\_CLUSTER\_UPDATE\_WARNING Data 

```
typedef struct
{
 uint8    u8WarningMode;
 uint16   u16WarningDurationRemaining;
 zenum8   eStrobeLevel;
}tsCLD_IASWD_WarningUpdate;

```

where:

-   `u8WarningMode` is a value indicating the current warning mode:

    -   0 - No warning

    -   1 - Burglar

    -   2 - Fire

    -   3 - Emergency

    -   4 - Police panic

    -   5 - Fire panic

    -   6 - Emergency \(medical\) panic

        -   All other values are reserved
-   `u16WarningDurationRemaining` is the time, in seconds, during which the device remains in warning mode

-   `eStrobeLevel` is the level of the strobe \(pulse\)


**Parent topic:**[Structures](../../IAS_WD_cluster/topics/structures.md)

