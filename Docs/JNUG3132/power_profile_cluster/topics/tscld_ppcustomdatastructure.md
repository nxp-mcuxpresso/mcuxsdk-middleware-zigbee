# tsCLD\_PPCustomDataStructure

The Power Profile cluster requires extra storage space to be allocated to be used by internal functions. The structure definition for this storage is shown below:

```
typedef struct
{
#ifdef (CLD_PP) && (PP_SERVER)  
   bool    bOverrideRunning;
   uint8    u8ActSchPhaseIndex;
   tsCLD_PPEntryasPowerProfileEntry[CLD_PP_NUM_OF_POWER_PROFILES];
#endif
  tsZCL_ReceiveEventAddress    sReceiveEventAddress;
  tsZCL_CallBackEvent      sCustomCallBackEvent;
  tsCLD_PPCallBackMessage    sCallBackMessage;
} tsCLD_PPCustomDataStructure;

```

The fields are for internal use and no knowledge of them is required.

**Parent topic:**[Structures](../../power_profile_cluster/topics/structures.md)

