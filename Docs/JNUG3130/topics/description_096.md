# Description

This function is used to open the specified software timer. A list of parameter values for the timer must be provided as well as a user-defined callback function that will be used to perform any operations required on expiration of the timer.

The callback function has the following prototype:

**typedef void \(\*ZTIMER\_tpfCallback\)\(void \*** *pvParam* **\);**

where *pvParam* is a pointer to the timer parameters.

The function also includes a parameter *u8Flags*, which specifies whether the timer should allow or prevent sleep. When activity checks are made to decide whether the device can enter sleep mode, the value of this flag determines if the \(running\) timer will stop the device from going to sleep.

Before a timer is opened, it must have been initialized in a call to **ZTIMER\_eInit\(\)**.

**Parent topic:**[ZTIMER\_eOpen](../topics/ztimer_eopen.md)

