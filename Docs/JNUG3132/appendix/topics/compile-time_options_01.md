# Appendix C.1: Compile-time options

If required, the extended attribute discovery feature must be explicitly enabled on the cluster server and client at compile-time by respectively including the following defines in the **zcl\_options.h** files:

```
#define ZCL_ATTRIBUTE_DISCOVERY_EXTENDED_SERVER_SUPPORTED
#define ZCL_ATTRIBUTE_DISCOVERY_EXTENDED_CLIENT_SUPPORTED

```

**Parent topic:**[Appendix C: Extended attribute discovery](../../appendix/topics/extended_attribute_discovery.md)

