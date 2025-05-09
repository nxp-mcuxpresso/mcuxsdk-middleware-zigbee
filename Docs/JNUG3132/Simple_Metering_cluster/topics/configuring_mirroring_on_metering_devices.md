# Configuring Mirroring on Metering Devices

Configuration of a Metering Device for mirroring is carried out both within the application that runs on the device and as a compile-time option - refer to [Section](compile-time_options.md#id_25334628-dcfd-426f-af0c-8d34a10f08a1)42.12 for the relevant compile-time options.

It is the responsibility of the Metering Device to request a mirror on the ESP, but first it must establish whether the ESP is accepting mirror requests. To do this, the application should use the function **eZCL\_SendReadAttributesRequest\(\)** to obtain the value of the `u8PhysicalEnvironment` attribute of the Basic cluster on the ESP - if this value is non-zero then the ESP is open to receiving mirror requests.

Provided that the ESP is accepting mirror requests, a Metering Device application can request a mirror using the function **eSM\_ServerRequestMirrorCommand\(\)**. This function sends a mirror request to the ESP with the aim of being allocated a mirror endpoint. The handling of this request on the ESP is described in [Section 42.5.1](configuring_mirroring_on_esp.md#id_56382dc2-f3cb-45d7-b933-601ecbbcede8).

The Metering Device application must then wait for a response from the ESP. This response is indicated by the event E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_REQUEST\_MIRROR\_RESPONSE, causing the callback function for the receiving endpoint to be invoked.

If the request has resulted in the successful allocation of a mirror endpoint on the ESP, the `tsSM_RequestMirrorResponseCommand` structure \(see [Section 42.11.6](tssm_requestmirrorresponsecommand.md#id_f0a8bde1-a77f-4d19-81d9-dd153d2af499)\) in this event will contain the allocated endpoint number. In this case:

-   The callback function should write the allocated endpoint number and mirroring server \(ESP\) IEEE address to non-volatile memory for persistent data storage using the NVM module.

-   The Metering Device application can now send metering data for storage on the ESP whenever required, as described in [Section 42.5.3](mirroring_data.md#id_5c81e91a-7d4a-4e82-8247-d180d955c57a).


**Note:** If the Metering Device subsequently requests another mirror on the same ESP, the same mirror endpoint number will be returned - a Metering Device cannot have more than one mirror on the same ESP.

If the request did not result in an allocated mirror endpoint on the ESP, the endpoint number returned in the above structure will be 0xFFFF and no action needs to be taken by the callback function.

**Parent topic:**[Mirroring Metering Data](../../Simple_Metering_cluster/topics/mirroring_metering_data.md)

