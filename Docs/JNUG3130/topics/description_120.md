# Description

This function can be used to register a callback function for extended error handling \(see \([Section 6](managing_group_addresses.md)[.7](return_codes_and_extended_error_handling.md)\)

The prototype of the callback function is:

**ZPS\_teExtendedStatus vExtendedStatusCb\(\);**

The registered callback function is invoked if a subsequent API function call results in one of the following errors:

-   0xA3: ZPS\_APL\_APS\_E\_ILLEGAL\_REQUEST
-   0xA6: ZPS\_APL\_APS\_E\_INVALID\_PARAMETER
-   0xC2: ZPS\_NWK\_ENUM\_INVALID\_REQUEST

The callback function returns another error code \(from those listed and described in [Section 11.2.5](extended_error_codes.md)\), which provides a more specific reason for the error.

**Parent topic:**[ZPS\_vExtendedStatusSetCallback](../topics/zps_vextendedstatussetcallback.md)

