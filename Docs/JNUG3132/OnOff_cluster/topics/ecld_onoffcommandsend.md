# eCLD\_OnOffCommandSend

```
teZCL_Status eCLD_OnOffCommandSend(
    uint8 u8SourceEndPointId,
    uint8 u8DestinationEndPointId,
    tsZCL_Address *psDestinationAddress,
    uint8 *pu8TransactionSequenceNumber,
    teCLD_OnOff_Command eCommand);

```

## Description 

This function sends a custom command instructing the target device to perform the specified operation on itself: switch off, switch on, toggle \(on-to-off or off-to-on\), or switch on with settings retrieved from the global scene, This last option \(On with Recall Global Scene\) is described in [Section 14.6](saving_light_settings.md#id_3cd235e7-bcd7-411a-8914-56f7163653a0) and, if used, must be enabled in the compile-time options on the server \(target\), as indicated in [Section 14.10](compile-time_options.md#id_bfec7b3c-d152-4003-ac21-999c7d5ad203).

The device receiving this message generates a callback event on the endpoint on which the On/Off cluster was registered.

If the Level Control cluster \(see [Chapter 16](../../Level_Control_cluster/topics/level_control_cluster.md#id_492efae6-d88d-4203-be53-0039b6fe8f2d)\) is also used on the target device, an ‘On’ or ‘Off’ command can be implemented with a transition effect, as follows:

-   If the optional Level Control ‘On Transition Time’ attribute is enabled, an ‘On’ command results in a gradual transition. This transition is from the ‘off’ level to the ‘on’ level over the time-interval specified in the attribute.

-   If the optional Level Control ‘Off Transition Time’ attribute is enabled, an ‘Off’ command results in a gradual transition from the ‘on’ level to the ‘off’ level over the time-interval specified in the attribute.


## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint through which to send the request. This parameter is used both to send the message and to identify the instance of the shared structure holding the required attribute values.
-   *u8DestinationEndPointId*: Number of the endpoint on the remote node to which the request is sent. This parameter is ignored when sending to address types eZCL\_AMBOUND and eZCL\_AMGROUP
-   *psDestinationAddress*: Pointer to a structure holding the address of the node to which the request is sent
-   *pu8TransactionSequenceNumber*: Pointer to a location to receive the Transaction Sequence Number \(TSN\) of the request
-   *eCommand*: Command code, one of the following:
    -   E\_CLD\_ONOFF\_CMD\_OFF
    -   E\_CLD\_ONOFF\_CMD\_ON

    -   E\_CLD\_ONOFF\_CMD\_TOGGLE

    -   E\_CLD\_ONOFF\_CMD\_ON\_RECALL\_GLOBAL\_SCENE

    -   E\_CLD\_ONOFF\_CMD\_TOGGLE


## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../OnOff_cluster/topics/functions.md)

