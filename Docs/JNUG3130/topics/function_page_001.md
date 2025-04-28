# Function page

1.  [ZTIMER\_eInit](ztimer_einit.md)
2.  [ZTIMER\_eOpen](ztimer_eopen.md)
3.  [ZTIMER\_eClose](ztimer_eclose.md)
4.  [ZTIMER\_eStart](ztimer_estart.md)
5.  [ZTIMER\_eStop](ztimer_estop.md)
6.  [ZTIMER\_eGetState](ztimer_egetstate.md)

To use the software timers, the while loop of your application must include a call to the following function:
<strong>
```
void ZTIMER\_vTask\(void\);
```
</strong>
This allows the stack software to automatically update the ZTIMER\_tsTimer structure for each timer as the timer runs.

**Parent topic:**[ZigBee Timer functions](../topics/zigbee_timer_functions.md)

