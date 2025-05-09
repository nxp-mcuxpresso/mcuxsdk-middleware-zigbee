# eZLL\_RegisterCommissionEndPoint

```
teZCL_Status eZLL_RegisterCommissionEndPoint(
    uint8 u8EndPointIdentifier,
    tfpZCL_ZCLCallBackFunction cbCallBack,
    tsZLL_CommissionEndpoint *psDeviceInfo);

```

## Description 

This function registers a ‘commissioning’ endpoint for Touchlink and creates a Touchlink Commissioning cluster instance on the endpoint.

Touchlink must have its own application \(separate from the main application\) on its own endpoint.

This function uses **eCLD\_ZllCommissionCreateCommission\(\)** to create the cluster instance. The type of cluster instance to be created \(server or client, or both\) is determined using the compile-time options in the header file **zcl\_options.h** \(refer to [Section 44.10](compile-time_options.md#id_b35eeb86-3074-417e-8aae-7184fa911842)\).

## Parameters 

-   *u8EndPointIdentifier*        Identifier of endpoint to be registered - this is an endpoint number in the range 1 to 240
-   *cbCallBack*        Pointer to a callback function to handle events associated with the registered endpoint
-   *psDeviceInfo*        Pointer to structure to be used to hold Touchlink endpoint information \(see [Section 44.8.1](tszll_commissionendpoint.md#id_2edc3bf3-dfd3-4a57-ae73-119073a7cdda)\)

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[Touchlink functions](../../touchlink_cluster/topics/touchlink_functions.md)

