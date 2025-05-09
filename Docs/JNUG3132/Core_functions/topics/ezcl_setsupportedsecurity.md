# eZCL\_SetSupportedSecurity

```
teZCL_Status eZCL_SetSupportedSecurity(
    teZCL_ZCLSendSecurity eSecuritySupported);

```

## Description 

This function can be used to set the security level for future transmissions from the local device. The possible levels are:

-   Application-level security, which uses an application link key that is unique to the pair of nodes in communication

-   Network-level security, which uses a network key that is shared by the whole network


By default, application-level security is enabled. In practice, this function can be used to disable application-level security on the local device so that the device sends all future communications with only network-level security. This is useful when transmitted packets need to be easily accessed. For example, it can be used during over-air tests performed using a packet sniffer.

## Parameters 

-   eSecuritySupportedRequired level of security, one of:
    -   E\_ZCL\_SECURITY\_NETWORK - network-level security
    -   E\_ZCL\_SECURITY\_APPLINK - application-level security

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_RANGE

**Parent topic:**[Attribute Access Functions](../../Core_functions/topics/attribute_access_functions.md)

