# eZCL\_Update100mS

```
teZCL_Status eZCL_Update100mS(void);

```

## Description 

This function is used to service all the timing needs of the clusters used by the application and should be called every 100 ms. This can be achieved by using a 100 ms software timer to periodically prompt execution of this function.

The function calls the external user-defined function **vIdEffectTick\(\)**, which can be used to implement an identify effect on the node. This function must be defined in the application, irrespective of whether identify effects are needed \(and therefore, may be empty\). The function prototype is:

```
void vIdEffectTick(void)

```

## Parameters 

-   None

## Returns 

-   E\_ZCL\_SUCCESS

**Parent topic:**[General Functions](../../Core_functions/topics/general_functions_.md)

