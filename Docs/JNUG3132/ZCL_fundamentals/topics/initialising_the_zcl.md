# Initializing the ZCL

The ZCL can be initialized using the function **eZCL\_Initialise\(\)**, which must be called before registering any endpoints. The initialization is done using the device-specific endpoint registration functions and before starting the ZigBee PRO stack. As part of this initialization, you must specify a user-defined callback function that would be invoked when a ZigBee PRO stack event occurs that is not associated with an endpoint. Also provide a local pool of Application Protocol Data Units \(APDUs\) that are used by the ZCL to hold messages that are to be sent and received.

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

