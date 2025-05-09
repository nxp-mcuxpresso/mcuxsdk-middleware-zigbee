# eCLD\_LevelControlSetLevel

```
teZCL_Status eCLD_LevelControlSetLevel(
    uint8 u8SourceEndPointId,
    uint8 u8Level,
    uint16 u16TransitionTime);

```

## Description 

This function sets the level on the device on the specified \(local\) endpoint by writing the specified value to the ‘current level’ attribute. The new level is implemented over the specified transition time by gradually changing the level.

The specified target level must be within the range 0x01 to 0xFE or a more restricted range imposed by the device manufacturer and/or user/installer \(see [Section 16.6.1](setting_level.md#id_35234a21-e26f-4f38-80d5-8ee2421350ab)\).

This operation is performed with the On/Off cluster \(if enabled\), in which case:

-   If the operation is to increase the current level, the OnOff attribute of the On/Off cluster is set to ‘on’.

-   If the operation is to decrease the current level to the minimum permissible level for the device, the OnOff attribute of the On/Off cluster is set to ‘off’.


## Parameters 

-   *u8SourceEndPointId*: Number of the local endpoint on which level is to be changed
-   *u8Level*: New level to be set, within the range 0x01 to 0xFE or within a more restricted range \(see above\)
-   *u16TransitionTime*: Time to be taken, in units of tenths of a second, to reach the target level \(0xFFFF means move to the level as fast as possible\)

## Returns 

-   E\_ZCL\_SUCCESS
-   E\_ZCL\_ERR\_PARAMETER\_NULL
-   E\_ZCL\_ERR\_EP\_RANGE
-   E\_ZCL\_ERR\_EP\_UNKNOWN
-   E\_ZCL\_ERR\_CLUSTER\_NOT\_FOUND
-   E\_ZCL\_ERR\_ZBUFFER\_FAIL
-   E\_ZCL\_ERR\_ZTRANSMIT\_FAIL

If an error is returned by the ZigBee PRO stack function which is invoked by this function to transmit the data, this error may be obtained by calling **eZCL\_GetLastZpsError\(\)**.

**Parent topic:**[Functions](../../Level_Control_cluster/topics/functions.md)

