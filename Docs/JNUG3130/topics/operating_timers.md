# Operating timers

Once an individual software timer has been opened, it can be run one or more times before it is closed. A timer can be run by calling the function **ZTIMER\_eStart\(\)**. The timed period must be specified in milliseconds. On expiration of the timer, the user-defined callback function **ZTIMER\_tpfCallback\(\)** is called to perform any operations required by the application.

A running timer can be stopped before it expires by calling the function **ZTIMER\_eStop\(\)**. The status of an individual timer can be obtained at any time using the function **ZTIMER\_eGetState\(\)**. The possible reported states are Running, Stopped, Expired and Closed.

**Parent topic:**[Software timers](../topics/software_timers.md)

