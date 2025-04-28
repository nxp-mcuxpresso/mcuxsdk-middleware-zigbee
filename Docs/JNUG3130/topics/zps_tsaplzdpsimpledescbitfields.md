# ZPS\_tsAplZdpSimpleDescBitFields

The `ZPS_tsAplZdpSimpleDescBitFields`structure is used by the `sBitFields` element in the Simple descriptor structure \(see above\), and is shown below:

```
typedef struct
{
unsigned eDeviceVersion :4;
unsigned eReserved :4;
}ZPS_tsAplZdpSimpleDescBitFields;
```

where:

-   `eDeviceVersion`is a 4-bit value identifying the version of the device description supported by the endpoint.
-   `eReserved`is a 4-bit reserved value.

**Parent topic:**[ZPS\_tsAplZdpSimpleDescType](../topics/zps_tsaplzdpsimpledesctype.md)

