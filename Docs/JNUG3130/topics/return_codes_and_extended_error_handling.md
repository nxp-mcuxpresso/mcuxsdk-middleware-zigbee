# Return codes and extended error handling

When a ZigBee PRO API function is called, a code is normally returned on completion of the function to indicate the outcome. This code is taken from one of the following:

-   zps\_E\_SUCCESS
-   APS return codes, listed and described in [Section 11.2.2](aps_codes.md)
-   NWK return codes, listed and described in [Section 11.2.3](nwk_codes.md)
-   MAC return codes, listed and described in [Section 11.2.4](mac_codes.md)

An extended error handling mechanism can be optionally implemented which allows more detail to be obtained about certain errors that can occur during function execution. The particular errors are:

-   0xA3: zps\_APL\_APS\_E\_ILLEGAL\_REQUEST
-   0xA6: zps\_APL\_APS\_E\_INVALID\_PARAMETER
-   0xC2: zps\_NWK\_ENUM\_INVALID\_REQUEST

The extended error codes are listed and described in [Section 11.2.5](extended_error_codes.md).

In order to implement the extended error handling mechanism, you must register a callback function using the function **zps\_vExtendedStatusSetCallback\(\)**. This registration function must be called before invoking the first API function for which extended error handling is required. The registered callback function will then be invoked during execution of the API function if one of the above errors occurs. The callback function will return an extended error code \(from those listed in [Section](extended_error_codes.md)[11.2.5](extended_error_codes.md)\) but the API function will return only the basic error code.

**Parent topic:**[Application coding with ZigBee PRO APIs](../topics/application_coding_with_zigbee_pro_apis.md)

