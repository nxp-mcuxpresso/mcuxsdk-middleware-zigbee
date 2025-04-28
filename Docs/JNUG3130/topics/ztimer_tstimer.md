# ZTIMER\_tsTimer

The ZigBee timer structure is shown below. It is used to represent a single software timer that may be used by the application.

```
typedef struct
{
     ZTIMER_teState      eState;
     uint32             u32Time;
     void               *pvParameters;
     ZTIMER_tpfCallback pfCallback;
} ZTIMER_tsTimer;

```

where:

-   `eState`represents the current state of the timer, as one of:
    -   E\_ZTIMER\_STATE\_CLOSED
    -   E\_ZTIMER\_STATE\_STOPPED
    -   E\_ZTIMER\_STATE\_RUNNING
    -   E\_ZTIMER\_STATE\_EXPIRED
-   `u32Time`is the remaining time, in milliseconds, that the timer still has to run
-   `pvParameters`is a pointer to a set of parameters used by the timer
-   `pfCallback`is a pointer to the user-defined callback function that will be called when the timer expires - this function has the prototype:

    ```
    typedef void \(\*ZTIMER\_tpfCallback\)\(void \pvParam*\);
    ```

    where `pvParam` is a pointer to the timer parameters.


**Parent topic:**[ZigBee timer structures](../topics/zigbee_timer_structures.md)

