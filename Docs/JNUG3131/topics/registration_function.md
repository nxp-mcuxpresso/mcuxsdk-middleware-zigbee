# Registration Function

The following **eZLO\_RegisterNonColourSceneControllerEndPoint\(\)** function is the endpoint registration function for a Non-Colour Scene Controller device.

```
teZCL_Status eZLO_RegisterNonColourSceneControllerEndPoint(
uint8 u8EndPointIdentifier,
tfpZCL_ZCLCallBackFunction cbCallBack,
tsZLO_NonColourSceneControllerDevice *psDeviceInfo);
```

## Description 

This function is used to register an endpoint which supports a Non-Colour Scene Controller device. The function must be called after **eZCL\_Initialise\(\)**.

The specified identifier for the endpoint is a number in the range 1 to 240 \(endpoint 0 is reserved for ZigBee use\). Application endpoints are normally numbered consecutively starting at 1. The specified number must be less than or equal to the value of ZLO\_NUMBER\_OF\_ENDPOINTS defined in the **zcl\_options.h** file, which represents the highest endpoint number used for applications.

While invoking this function, specify a user-defined callback function, which is invoked when an event associated with the endpoint occurs. This callback function is defined according to the typedef:

```
typedef void(* tfpZCL_ZCLCallBackFunction)
(tsZCL_CallBackEvent *pCallBackEvent);

```

Also provide a pointer to a `tsZLO_NonColourSceneControllerDevice` structure, described in [Device Structure](device_structure_015.md#ID_488CC64B-2F8A-48CA-A2AF-2F8E1D7DCC2B). This structure stores all variables relating to the color Controller device associated with the endpoint. The `sEndPoint` and `sClusterInstance` fields of this structure are set by this function and must not be directly written to by the application.

The function is called multiple times if more than one endpoint is being used - for example, if more than one Non-Colour Scene Controller device is housed in the same hardware, sharing the same module.

## Parameters 

-   *u8EndPointIdentifier*: Endpoint that is to be associated with the registered structure and callback function.
-   *cbCallBack*: Pointer to the function that is used to indicate events to the application for this endpoint.
-   *psDeviceInfo*: Pointer to the structure that acts as storage for all variables related to the device being registered on this endpoint \(see [Device Structure](device_structure_015.md#ID_488CC64B-2F8A-48CA-A2AF-2F8E1D7DCC2B)\). The `sEndPoint` and `sClusterInstance` fields are set by this register function for internal use and must not be written to by the application.

## Returns 

1.  E\_ZCL\_SUCCESS
2.  E\_ZCL\_FAIL
3.  E\_ZCL\_ERR\_PARAMETER\_NULL
4.  E\_ZCL\_ERR\_PARAMETER\_RANGE
5.  E\_ZCL\_ERR\_EP\_RANGE
6.  E\_ZCL\_ERR\_CLUSTER\_0
7.  E\_ZCL\_ERR\_CALLBACK\_NULL
8.  E\_ZCL\_ERR\_CLUSTER\_NULL
9.  E\_ZCL\_ERR\_SECURITY\_RANGE
10. E\_ZCL\_ERR\_CLUSTER\_ID\_RANGE
11. E\_ZCL\_ERR\_MANUFACTURER\_SPECIFIC
12. E\_ZCL\_ERR\_ATTRIBUTE\_TYPE\_UNSUPPORTED
13. E\_ZCL\_ERR\_ATTRIBUTE\_ID\_ORDER
14. E\_ZCL\_ERR\_ATTRIBUTES\_ACCESS

The above codes are described in the *ZCL User Guide \(JNUG3132\)*.

**Parent topic:**[Non-Colour Scene Controller](../topics/non-colour_scene_controller.md)

