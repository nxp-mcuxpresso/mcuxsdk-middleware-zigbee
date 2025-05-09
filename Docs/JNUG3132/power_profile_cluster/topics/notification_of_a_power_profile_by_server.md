# Notification of a power profile \(by server\)

The cluster server may send unsolicited notifications of the power profiles that it supports to the client. To do this, the server application must call the function **eCLD\_PPPowerProfileNotificationSend\(\)** which sends a Power Profile Notification containing the essential details of one supported power profile \(such as the energy phases within the profile\). This information is supplied to the function in a `tsCLD_PP_PowerProfilePayload` structure \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\). If the server supports multiple power profiles, a separate notification must be sent for each profile.

On receiving the notification on the client, the event E\_CLD\_PP\_CMD\_POWER\_PROFILE\_NOTIFICATION is generated on the client for each energy phase within the power profile. The reported information is contained in a `tsCLD_PP_PowerProfilePayload` structure \(see [Section 21.10.4](tscld_pp_powerprofilepayload.md#id_c895e2f5-5dde-4408-b3c5-72cc084ddd73)\). The application may store or discard this information, as required. By receiving the energy phase information in individual events, the application only needs to use as much memory as is required to store the relevant energy phase data.

**Parent topic:**[Communicating power profiles](../../power_profile_cluster/topics/communicating_power_profiles.md)

