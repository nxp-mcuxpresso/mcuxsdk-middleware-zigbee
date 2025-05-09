# eZCL\_Initialise

```
teZCL_Status eZCL_Initialise(
     tfpZCL_ZCLCallBackFunction cbCallBack,
    PDUM_thAPdu hAPdu);

```

## Description 

This function initializes the ZCL. It should be called before registering any endpoints \(using one of the device-specific endpoint registration functions\) and before starting the ZigBee PRO stack.

As part of this function call, you must specify a user-defined callback function that is invoked when a ZigBee PRO stack event occurs that is not associated with an endpoint \(the callback function for events associated with an endpoint is specified when the endpoint is registered using one of the registration functions\). This callback function is defined according to the typedef:

```
typedef void (* tfpZCL_ZCLCallBackFunction)
         (tsZCL_CallBackEvent *pCallBackEvent);  

```

You must also provide a pointer to a local pool of Application Protocol Data Units \(APDUs\) that would be used by the ZCL to hold messages to be sent and received.

## Parameters 

-   *cbCallBack*: Pointer to a callback function to handle stack events that are not associated with a registered endpoint
-   *hAPdu*: Pointer to a pool of APDUs for holding messages to be sent and received

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_HEAP\_FAIL
-   E\_ZCL\_ERR\_PARAMETER\_NULL

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

