# Link cost configuration

The mappings between LQI values and link costs can be modified from the default mappings detailed in [Section 6.10.3.1](link_cost.md). To modify the mappings, the following function must be user-defined, which translates an LQI value \(input\) into a link cost \(output\):

```
uint8 APP\_u8LinkCost\(uint8 u8Lqi\);
```
An example function that implements the default mapping is shown below:

```
PRIVATE uint8 APP_u8LinkCost ( uint8 u8Lqi )
            {
            uint8 u8Lc;
            if (u8Lqi > 50)
            {
            u8Lc = 1;
            }
            else if ((u8Lqi <= 50) && (u8Lqi > 45))
            {
            u8Lc = 2;
            }
            else if ((u8Lqi <= 45) && (u8Lqi > 40))
            {
            u8Lc = 3;
            }
            else if ((u8Lqi <= 40) && (u8Lqi > 38))
            {
            u8Lc = 4;
            }
            else if ((u8Lqi <= 38) && (u8Lqi > 35))
            {
            u8Lc = 5;
            }
            else if ((u8Lqi <= 35) && (u8Lqi > 24))
            {
            u8Lc = 6;
            }
            else
            {
            u8Lc = 7;
            }
            return u8Lc;
            }
```

The above function must be registered as a callback function using the following callback registration function **zps\_vNwkLinkCostCallbackRegister\(\)**, which is detailed in [Section 8.1.1](initialization_functions.md). This function takes a pointer to the **APP\_u8LinkCost\(\)** function to be registered. If required, the registration function must be called before **zps\_eAplAfInit\(\)**, and on both cold and warm starts.

**Parent topic:**[Packet filtering configuration](../topics/packet_filtering_configuration.md)

