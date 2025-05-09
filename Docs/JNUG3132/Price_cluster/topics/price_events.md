# Price events

The Price cluster has its own events that are handled through the callback mechanism described in [Chapter 3](../../ZCL_event_handling/topics/event_handling.md#id_dc3930f1-d872-41b9-9d62-e68af6bf28ee). If a device uses the Price cluster then Price event handling must be included in the callback function for the associated endpoint, where this callback function is registered through the relevant endpoint registration function \(for example, through **eSE\_RegisterEspEndPoint\(\)** for a standalone ESP\). The relevant callback function will then be invoked when a Price event occurs.

For a Price event, the `eEventType` field of the `tsZCL_CallBackEvent` structure is set to E\_ZCL\_CBET\_CLUSTER\_CUSTOM. This event structure also contains an element `sClusterCustomMessage`, which is itself a structure containing a field `pvCustomData`. This field is a pointer to a `tsSE_PriceCallBackMessage` structure which contains the Price parameters:

```
typedef struct
{
 teSE_PriceCallBackEventType      eEventType;
 uint32             u32CurrentTime;
 union {
  tsSE_PriceTableCommand        sPriceTableCommand;
  tsSE_PriceTableTimeEvent        sPriceTableTimeEvent;
  teSE_PriceCommandOptions        ePriceCommandOptions;
  tsSE_PriceAckCmdPayload        *psAckCmdPayload;
  tsSE_PriceAttrReadInput        sReadAttrInfo;
  tsSE_BlockPeriodTableTimeEvent      sBlockPeriodTableTimeEvent;
  tsSE_ConversionFactorTableTimeEvent    sConversionFactorTableTimeEvent;
  tsSE_CalorificValueTableTimeEvent     sCalorificValueTableTimeEvent;
  } uMessage;
} tsSE_PriceCallBackMessage;

```

The `eEventType` field of the above structure specifies the type of Price event that has been generated - these event types are listed and described below \(also refer to [Section 40.12.2](price_event_enumerations.md#id_fecac6e4-2d88-4c3b-8edc-d12a805548c5) for a summary of the Price events\).

**Note:** The field `sReadAttrInfo` is reserved for future use \(for Block mode\).

## E\_SE\_PRICE\_TABLE\_ADD 

The E\_SE\_PRICE\_TABLE\_ADD event is generated on a Price cluster client when an attempt has been made to add a scheduled price \(received in a Publish Price command\) to the local price list. In the `tsSE_PriceCallBackMessage` structure, the `u32CurrentTime` field is set to the current time from the Publish Price command and the `sPriceTableCommand` field is used as follows:

```
typedef struct {
   teSE_PriceStatus ePriceStatus;
} tsSE_PriceTableCommand;

```

`ePriceStatus` contains E\_SE\_PRICE\_SUCCESS if a new price has been successfully added to the price list. Otherwise, the addition was rejected for the reason specified by `ePriceStatus`. If the addition was successful but the new price information overlapped \(in time\) any existing price information in the list, this previous price information may have been deleted from the list according to the rules in the ZigBee SE Profile specification.

## E\_SE\_PRICE\_TABLE\_ACTIVE 

The E\_SE\_PRICE\_TABLE\_ACTIVE event is generated when there is a new active price or the active price expires. This event can occur due to a time update or the reception of a Publish Price command from the server. In the `tsSE_PriceCallBackMessage` structure, the `u32CurrentTime` field is set to the current ZCL time and the `sPriceTableTimeEvent` field is used as follows:

```
typedef struct {
   teSE_PriceStatus  ePriceStatus;
   uint8     u8NumberOfEntriesFree;
} tsSE_PriceTableTimeEvent;

```

`ePriceStatus` contains E\_SE\_PRICE\_SUCCESS if there is a new active price or E\_SE\_PRICE\_TABLE\_NOT\_YET\_ACTIVE if the price at the head of the list is scheduled for a time in the future.

`u8NumberOfEntriesFree` contains the number of free entries in the client's price list. This number can be used to determine whether the client should issue a new Get Scheduled Prices command, in order to obtain more price entries to fill the free space in the list.

## E\_SE\_PRICE\_GET\_CURRENT\_PRICE\_RECEIVED 

The E\_SE\_PRICE\_GET\_CURRENT\_PRICE\_RECEIVED event is generated on a Price cluster server when a Get Current Price command is received from a client. In the `tsSE_PriceCallBackMessage` structure, the `ePriceCommandOptions` field is used as follows:

```
typedef enum PACK
{
    E_SE_PRICE_REQUESTOR_RX_ON_IDLE = 0x01 // LSB set
} teSE_PriceCommandOptions;

```

This field indicates whether the client that sent the request has its radio receiver enabled when idle \(e.g. sleeping\), and is used as described in [Section 40.5.1](unsolicited_price_updates.md#id_8a77360e-56a4-4ea8-8248-f0a4215f6789) and [Section 40.5.2](get_current_price.md#id_4b60492f-41f6-4573-bede-13bf7f20e978).

## E\_SE\_PRICE\_TIME\_UPDATE 

The E\_SE\_PRICE\_TIME\_UPDATE event is generated on a Price cluster client when a Publish Price command is received from the server. In the `tsSE_PriceCallBackMessage` structure, the `u32CurrentTime` field is set to the current time from the Publish Price command. The application may then use this information to time-synchronise the device, as described in [Section 40.6](time-synchronisation_via_publish_price_commands.md#id_6eb258c6-6fc6-43f5-ac4a-b7c68cde7f12).

## E\_SE\_PRICE\_ACK\_RECEIVED 

The E\_SE\_PRICE\_ACK\_RECEIVED event is generated on a Price cluster server when a Price Acknowledgment command is received from a client. In the `tsSE_PriceCallBackMessage` structure, the `psAckCmdPayload` field is a pointer to the structure `tsSE_PriceAckCmdPayload` defined as follows:

```
typedef struct {
   uint32              u32ProviderId;
   uint32              u32IssuerEventId;
   uint32              u32PriceAckTime;
   uint8               u8Control;
} tsSE_PriceAckCmdPayload;

```

This structure contains the Price Acknowledgement command payload.

## E\_SE\_PRICE\_NO\_PRICE\_TABLES 

The E\_SE\_PRICE\_NO\_PRICE\_TABLES event is generated when an active price expires, is deleted from the price list and the price list becomes empty. In the `tsSE_PriceCallBackMessage` structure the `sPriceTableTimeEvent` field is used as follows:

```
typedef struct {
   teSE_PriceStatus ePriceStatus;
   uint8 u8NumberOfEntriesFree;
} tsSE_PriceTableTimeEvent;

```

`ePriceStatus` contains E\_SE\_PRICE\_NO\_TABLES.

`u8NumberOfEntriesFree` contains the number of free entries in the client's price list. This number can be used to determine whether the client should issue a new Get Scheduled Prices command, in order to obtain more price entries to fill the free space in the list.

## E\_SE\_PRICE\_CONVERSION\_FACTOR\_TABLE\_ACTIVE 

The E\_SE\_PRICE\_CONVERSION\_FACTOR\_TABLE\_ACTIVE event is generated when a new conversion factor value becomes active - that is, when the start-time of the conversion factor entry becomes less than or equal to the present time. This event can occur due to a time update or the reception of a Publish Conversion Factor command from the server.

In the `tsSE_PriceCallBackMessage` structure, the `u32CurrentTime` field is set to the current ZCL time and the field `tsSE_PriceConversionFactorTableTimeEvent` is used as follows:

```
typedef struct {
   teSE_PriceStatus     eConversionFactorStatus;
   uint8         u8NumberOfEntriesFree;
} tsSE_ConversionFactorTableTimeEvent;

```

`eConversionFactorStatus` takes the value E\_ZCL\_SUCCESS when a new conversion factor becomes active.

`u8NumberOfEntriesFree` contains the present number of free entries in the conversion factor list. This value should be checked by the client before issuing a Get Conversion Factor command to obtain a new conversion factor value - the command should be issued only if there is free space in the list for a new entry to be added.

## E\_SE\_PRICE\_CONVERSION\_FACTOR\_ADD 

The E\_SE\_PRICE\_CONVERSION\_FACTOR\_ADD event is generated when a new conversion factor entry is advertised by the ESP to the client application using the Publish Conversion Factor command. Note that the event is generated even when the new entry is not successfully added to the internal conversion factor list maintained by the cluster.

The status of the command is passed back to the user application in the `ePriceStatus` field of the `tsSE_PriceTableCommand` structure \(see above\) within the `tsSE_PriceCallBackMessage` structure.

## E\_SE\_PRICE\_CALORIFIC\_VALUE\_TABLE\_ACTIVE 

The E\_SE\_PRICE\_CALORIFIC\_VALUE\_TABLE\_ACTIVE event is generated when a new calorific value becomes active - that is, when the start-time of the calorific value entry becomes less than or equal to the present time. This event can occur due to a time update or the reception of a Publish Calorific Value command from the server.

In the `tsSE_PriceCallBackMessage` structure, the `u32CurrentTime` field is set to the current ZCL time and the field `tsSE_PriceCalorificValueTableTimeEvent` is used as follows:

```
typedef struct {
   teSE_PriceStatus   eCalorificValueStatus;
   uint8       u8NumberOfEntriesFree;
} tsSE_CalorificValueTableTimeEvent;

```

`eCalorificValueStatus` takes the value E\_ZCL\_SUCCESS when a new calorific value becomes active.

`u8NumberOfEntriesFree` contains the present number of free entries in the calorific value list. This value should be checked by the client before issuing a Get Calorific Value command to obtain a new calorific value - the command should be issued only if there is free space in the list for a new entry to be added.

## E\_SE\_PRICE\_CALORIFIC\_VALUE\_ADD 

The E\_SE\_PRICE\_CALORIFIC\_VALUE\_ADD event is generated when a new calorific value entry is advertised by the ESP to the client application using the Publish Calorific Value command. Note that this event is generated even when the new entry is not successfully added to the internal calorific value list maintained by the cluster.

The status of the command is passed back to the user application in the `ePriceStatus` field of the `tsSE_PriceTableCommand` structure \(see above\) within the `tsSE_PriceCallBackMessage` structure.

**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

