# B.3.4: General \(Server and Client\) Options

If attribute reporting is to report any attributes of the ‘floating point’ type, the following macro must also be enabled in **zcl\_options.h** on both the server and client:

```
#define ZCL_ENABLE_FLOAT

```

This enables the use of the floating point library to calculate differences in attribute values. If this library is not already used by the application code, enabling it in this way increases the build size of the application by approximately 5 Kbytes.

**Parent topic:**[Appendix B.3: Configuring attribute reporting](../../appendix/topics/configuring_attribute_reporting.md)

