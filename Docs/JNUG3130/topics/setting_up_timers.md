# Setting up timers

To set up software timers in your application code, you must:

-   Declare an array of `ZTIMER_tsTimer` structures \(see [Section 10.2.2.1](ztimer_tstimer.md)\), where each element/structure contains information on one timer
-   Call the function **ZTIMER\_vTask\(\)** in the while loop of your application - this allows the stack software to automatically update the structure for each timer as the timer runs

For each timer, a user-defined callback function must be provided, which is referenced from the timer’s structure. This callback function, **ZTIMER\_tpfCallback\(\)**, is called when the timer expires \(reaches its timed period\) in order to perform any operations that the application requires as a result of the timer expiration.

Before any of the software timers can be used, they must be collectively initialized by calling the function **ZTIMER\_eInit\(\)**. This function takes the array of timer structures as an input.

Before an individual timer can be used, it must be opened using the function **ZTIMER\_eOpen\(\)**. Similarly, when the timer is no longer required, it should be closed using the function **ZTIMER\_eClose\(\)**. A timer is specified in these functions by means of its index in the array of timer structures.

**Parent topic:**[Software timers](../topics/software_timers.md)

