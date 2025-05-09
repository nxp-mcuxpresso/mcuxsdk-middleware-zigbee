# Removing a Mirror

The removal of a mirror on the ESP is initiated by the application on the corresponding Metering Device using the function **eSM\_ServerRemoveMirrorCommand\(\)**. This function sends a ‘remove mirror’ request to the relevant mirror endpoint on the ESP.

**Note:** A mirror can be removed from an endpoint on the ESP but the endpoint will remain reserved for mirroring - it may later be re-assigned to another mirror.

On receiving this request, the ESP processes the request as follows:

1. The ZCL first verifies the source address of the request to ensure that it has come from the Metering Device which corresponds to the mirror to be removed. If the source address is not valid then a ZCL default response is automatically sent to the requesting Metering Device to indicate that the request was not authorised \(E\_ZCL\_CMDS\_NOT\_AUTHORIZED\) - otherwise, the ESP continues to process the request as described in the steps below.

2. The ZCL then removes the mirror from the specified endpoint, thus freeing the endpoint for future use by another mirror.

3. The event E\_CLD\_SM\_CLIENT\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_REMOVE\_MIRROR is generated on the ESP, causing the callback function on the ESP to be invoked.

4. The callback function must set the `u8PhysicalEnvironment` attribute of the Basic cluster to 0x01 in order to indicate that the ESP has the capacity to accept mirror requests \(since the removal of the mirror leaves at least one mirror endpoint free\).

5. The callback function must copy the IEEE addresses from the `tsSE_Mirror`         structures \(which are automatically kept up-to-date\) to the application’s array of IEEE addresses for mirrored devices, and this array should be re-saved in non-volatile memory using the NVM module. This step is illustrated in the code fragment under "[Writing and Preserving Array of IEEE Addresses](configuring_mirroring_on_esp.md#id_1fd8cd4d-cf13-4c2b-a3ef-7cb535ea8dba)" on page [1011](configuring_mirroring_on_esp.md#id_1fd8cd4d-cf13-4c2b-a3ef-7cb535ea8dba).

6. A response is automatically sent to the requesting Metering Device to confirm the mirror removal.

The response \(reporting successful mirror removal\) results in the generation of the event E\_CLD\_SM\_SERVER\_RECEIVED\_COMMAND containing the command E\_CLD\_SM\_MIRROR\_REMOVED on the Metering Device.

**Note:** The function **eSM\_RemoveMirror\(\)** is also provided, which allows the ESP application to directly remove a mirror.

**Parent topic:**[Mirroring Metering Data](../../Simple_Metering_cluster/topics/mirroring_metering_data.md)

