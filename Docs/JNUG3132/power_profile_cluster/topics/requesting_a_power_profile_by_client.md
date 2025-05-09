# Requesting a power profile \(by client\)

A client application can request a power profile supported by the server by calling the **eCLD\_PPPowerProfileReqSend\(\)** function, which sends a Power Profile Request to the server. The function can be used to request a specific power profile \(specified using its Power Profile ID\) or all the power profiles supported by the server.

On receiving a response from the server, an E\_CLD\_PP\_CMD\_POWER\_PROFILE\_RSP event is generated on the client for each energy phase within the power profile. The reported information is contained in a `tsCLD_PP_PowerProfilePayload` structure \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\). The application may store or discard this information, as required. By receiving the energy phase information in individual events, the application only needs to use as much memory as is required to store the relevant energy phase data.

**Note:** The client application may first use the function **eCLD\_PPPowerProfileStateReqSend\(\)** to request the identifiers of the power profiles that are currently supported on the server.

**Parent topic:**[Communicating power profiles](../../power_profile_cluster/topics/communicating_power_profiles.md)

