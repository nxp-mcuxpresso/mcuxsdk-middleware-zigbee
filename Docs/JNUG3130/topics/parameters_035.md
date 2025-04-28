# Parameters

-   *pu8TimerIndex* Pointer to location containing the index number of the timer in the list of timers initialized using **ZTIMER\_eInit\(\)**
-   *pfCallback* Pointer to the user-defined callback function for the timer
-   *pvParams* Pointer to a list of parameter values for the timer *u8Flags* Flag indicating whether the timer should allow or prevent sleep, one of:
    -   ZTIMER\_FLAG\_ALLOW\_SLEEP
    -   ZTIMER\_FLAG\_PREVENT\_SLEEP

**Parent topic:**[ZTIMER\_eOpen](../topics/ztimer_eopen.md)

