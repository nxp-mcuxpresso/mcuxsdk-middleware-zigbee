# Endpoint callback functions

A user-defined callback function must be provided for each endpoint used. The callback function is invoked when an event occurs \(such as an incoming message\) relating to the endpoint. The callback function is registered when the endpoint is registered using the registration function for the device type that the endpoint supports \(see [Device initialization](device_initialisation.md#ID_8FA1D63D-261F-4C44-9E5F-FD43FFBC000B)\) - for example, using the function **eZLO\_RegisterOnOffLightEndPoint\(\)** for an On/Off Light device \(see [On/Off light](on_off_light.md)\).

The endpoint callback function has the type definition given below:

```
typedef void (* tfpZCL_ZCLCallBackFunction)
(tsZCL_CallBackEvent *pCallBackEvent);
```
Here, *pCallBackEvent* is a pointer to the *pCallBackEvent* event.

**Note:** Events that do not have an associated endpoint are delivered via the general stack-supplied callback function **APP\_vGenCallback\(\)**. For example, stack leave and join events can be received by the application through this callback function. Stack events are described in the *ZigBee 3.0 Stack User Guide* *\(JNUG3130\)*.

**Parent topic:** [Introduction](../topics/introduction.md)

