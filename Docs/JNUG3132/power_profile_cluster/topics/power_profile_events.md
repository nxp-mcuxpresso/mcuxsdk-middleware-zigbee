# Power Profile Events

The Power Profile cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). The cluster contains its own event handler. However, if a device uses this cluster then application-specific Power Profile event handling must be included in the user-defined callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function. This callback function is then invoked when a Power Profile event occurs and needs the attention of the application.

For a Power Profile event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to the following `tsCLD_PPCallBackMessage` structure:

```
typedef struct
{
 uint8  u8CommandId;
#ifdef PP_CLIENT
  bool  bIsInfoAvailable;    
#endif    
  union
   {
   tsCLD_PP_PowerProfileReqPayload 
                    *psPowerProfileReqPayload;
   tsCLD_PP_GetPowerProfilePriceExtendedPayload          
        *psGetPowerProfilePriceExtendedPayload;
   } uReqMessage;
   union
   {
   tsCLD_PP_GetPowerProfilePriceRspPayload 
                    *psGetPowerProfilePriceRspPayload;
   tsCLD_PP_GetOverallSchedulePriceRspPayload              
       *psGetOverallSchedulePriceRspPayload;
    tsCLD_PP_EnergyPhasesSchedulePayload       
                    *psEnergyPhasesSchedulePayload;
    tsCLD_PP_PowerProfileScheduleConstraintsPayload
       *psPowerProfileScheduleConstraintsPayload;
    tsCLD_PP_PowerProfilePayload   
                    *psPowerProfilePayload;
        tsCLD_PP_PowerProfileStatePayload    
                    *psPowerProfileStatePayload;
    }uRespMessage;
} tsCLD_PPCallBackMessage; 

```

The above structure is fully described in [Section 21.10.1](tscld_ppcallbackmessage.md#id_2565cf7f-6f12-4055-856f-93223e42149b).

When a Power Profile event occurs, one of the command types listed in [Table 30](#id_a80128e4-4b34-4c06-979e-ebe4a1fdd7a2) and [Table 31](#id_a38fa960-f25e-4ce7-bc53-cb9a80dd9f3b) is specified through the `u8CommandId` field of the `tsCLD_PPCallBackMessage` structure. This command type determines which command payload is used from the unions `uReqMessage` \(for request commands\) and `uRespMessage` \(for response and notification commands\).

|**u8CommandId Enumeration**|**Description/Payload Type**|
|---------------------------|----------------------------|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_REQ|The server \(appliance\) receives a Power Profile Request. **tsCLD\_PP\_PowerProfileReqPayload**|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_REQ|The server \(appliance\) receives a Power Profile State Request.|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_RSP|The server \(appliance\) receives a Get Power Profile Price Response, following a previously sent Get Power Profile Price Request. **tsCLD\_PP\_GetPowerProfilePriceRspPayload**|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_EXTENDED\_RSP|The server \(appliance\) receives a Get Power Profile Price Extended Response, following a previously sent Get Power Profile Price Extended Request.**tsCLD\_PP\_GetPowerProfilePriceRspPayload**

|
|E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE\_RSP|The server \(appliance\) receives a Get Overall Schedule Price Response, following a previously sent Get Overall Schedule Price Request.

 **tsCLD\_PP\_GetOverallSchedulePriceRspPayload**

|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_NOTIFICATION|The server \(appliance\) receives an Energy Phases Schedule Notification.

 **tsCLD\_PP\_EnergyPhasesSchedulePayload**

|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_RSP|The server \(appliance\) receives an Energy Phases Schedule Response, following a previously sent Energy Phases Schedule Request.

 **tsCLD\_PP\_EnergyPhasesSchedulePayload**

|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_RSP|The server \(appliance\) receives an Energy Phases Schedule State Response, following a previously sent Energy Phases Schedule State Request.

 **tsCLD\_PP\_EnergyPhasesSchedulePayload**

|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_SCHEDULE\_CONSTRAINTS\_REQ|The server \(appliance\) receives a Get Power Profile Schedule Constraints Request.

 **tsCLD\_PP\_PowerProfileReqPayload**

|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_REQ|The server \(appliance\) receives an Energy Phases Schedule State Request.

 **tsCLD\_PP\_PowerProfileReqPayload**

|

|**u8CommandId Enumeration**|**Description/Payload Type**|
|---------------------------|----------------------------|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_NOTIFICATION|The client \(controller\) receives a Power Profile Notification.

 **tsCLD\_PP\_PowerProfilePayload**

|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_NOTIFICATION|The client \(controller\) receives a Power Profile State Notification.

 **tsCLD\_PP\_PowerProfileStatePayload**

|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_RSP|The client \(controller\) receives a Power Profile Response, following a previously sent Power Pro-file Request.

 **tsCLD\_PP\_PowerProfilePayload**

|
|E\_CLD\_PP\_CMD\_POWER\_PROFILE\_STATE\_RSP|The client \(controller\) receives a Power Profile State Response, following a previously sent Power Profile State Request.

 **tsCLD\_PP\_PowerProfileStatePayload**

|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE|The client \(controller\) receives a Get Power Profile Price Request.

 **tsCLD\_PP\_PowerProfileReqPayload**

|
|E\_CLD\_PP\_CMD\_GET\_OVERALL\_SCHEDULE\_PRICE|The client \(controller\) receives a Get Overall Schedule Price Request.|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_REQ|The client \(controller\) receives an Energy Phases Schedule Request .

 **tsCLD\_PP\_PowerProfileReqPayload**

|
|E\_CLD\_PP\_CMD\_ENERGY\_PHASES\_SCHEDULE\_STATE\_NOTIFICATION|The client \(controller\) receives an Energy Phases Schedule State Notification.

 **tsCLD\_PP\_EnergyPhasesSchedulePayload**

|
|E\_CLD\_PP\_CMD\_SCHEDULE\_CONSTRAINTS\_NOTIFICATION|The client \(controller\) receives a Power Profile Schedule Constraints Notification.

 **tsCLD\_PP\_PowerProfileScheduleConstraintsPayload**

|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_SCHEDULE\_CONSTRAINTS\_RSP|The client \(controller\) receives a Power Profile Schedule Constraints Response.

 **tsCLD\_PP\_PowerProfileScheduleConstraintsPayload**

|
|E\_CLD\_PP\_CMD\_GET\_POWER\_PROFILE\_PRICE\_EXTENDED|The client \(controller\) receives a Get Power Profile Price Extended Request.

 **tsCLD\_PP\_GetPowerProfilePriceExtendedPayload**

|

**Parent topic:**[Power Profile Cluster](../../power_profile_cluster/topics/power_profile_cluster.md)

