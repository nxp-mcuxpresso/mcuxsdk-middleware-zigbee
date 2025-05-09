# ‘Power Profile State’ Enumerations

The following enumerations represent the possible states of a power profile.

```
typedef enum PACK
{
   E_CLD_PP_STATE_IDLE   = 0x00,
   E_CLD_PP_STATE_PROGRAMMED,
   E_CLD_PP_STATE_RUNNING   = 0x02,
   E_CLD_PP_STATE_PAUSED,
   E_CLD_PP_STATE_WAITING_TO_START,
   E_CLD_PP_STATE_WAITING_PAUSED,
   E_CLD_PP_STATE_ENDED,
} teCLD_PP_PowerProfileState;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_CLD\_PP\_STATE\_IDLE|Not all parameters of the power profile have yet been defined|
|E\_CLD\_PP\_STATE\_PROGRAMMED|In the programmed state, as all the parameters of the power pro-file have been defined but there is no schedule or a schedule exists but has not been started|
|E\_CLD\_PP\_STATE\_RUNNING|The power profile is active and an energy phase is running|
|E\_CLD\_PP\_STATE\_PAUSED|The power profile is active but the current energy phase is paused|
|E\_CLD\_PP\_STATE\_WAITING\_TO\_START|The power profile is between two energy phases - one has ended and the next one has not yet started. If the next energy phase is the first energy phase of the schedule, this state indicates that schedule has been started but the first energy has not yet started|
|E\_CLD\_PP\_STATE\_WAITING\_PAUSED|The power profile has been paused while in the ‘waiting to start’ state \(described above\)|
|E\_CLD\_PP\_STATE\_ENDED|The power profile schedule has finished|

**Parent topic:**[Enumerations](../../power_profile_cluster/topics/enumerations.md)

