# Software timers

The ZigBee 3.0 SDK provides resources that allow an application to implement and interact with software timers on the local node. Multiple software timers can be used concurrently and they are all derived from the same source counter, which is the ZigBee Tick Timer.

Note: To allow the device to enter sleep mode, no software timers should be active. Any running software timers must first be stopped and all timers must be closed.


```{include} ../topics/setting_up_timers.md
:heading-offset: 3
```

```{include} ../topics/operating_timers.md
:heading-offset: 3
```

**Parent topic:**[Using support software features](../topics/using_support_software_features.md)

