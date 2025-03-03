# Events

The ZigBee Base Device has a number of associated events. Some API functions \(described in [Functions](functions.md#ID_06E94677-E32C-41DA-8F48-1B4AE5ABCD48)\) return immediately and the outcome of the process they invoke is later indicated with the generation of an asynchronous event. A user-defined callback function must be defined in the application to handle these events. The prototype of this callback function is as follows:

**void APP\_vBdbCallback\(BDB\_tsBdbEvent \****psBdbEvent***\)**

where *psBdbEvent* is a pointer to a `BDB_tsBdbEvent` event structure containing the event information to be passed to the function \(for this structure, see [BDB_tsBdbEvent](bdb_tsbdbevent.md#ID_B31805B4-8616-4043-A157-C672A1244E29)\).

The enumerations for the ZigBee Base Device events are listed below.

```
typedef enum
 {
    BDB_EVENT_NONE,
    BDB_EVENT_ZPSAF,
    BDB_EVENT_INIT_SUCCESS,
    BDB_EVENT_REJOIN_SUCCESS,
    BDB_EVENT_REJOIN_FAILURE,
    BDB_EVENT_NWK_STEERING_SUCCESS,
    BDB_EVENT_NO_NETWORK,
    BDB_EVENT_NWK_JOIN_SUCCESS,
    BDB_EVENT_NWK_JOIN_FAILURE,
    BDB_EVENT_APP_START_POLLING,
    BDB_EVENT_NWK_FORMATION_SUCCESS,
    BDB_EVENT_NWK_FORMATION_FAILURE,
    BDB_EVENT_FB_HANDLE_SIMPLE_DESC_RESP_OF_TARGET,
    BDB_EVENT_FB_CHECK_BEFORE_BINDING_CLUSTER_FOR_TARGET,
    BDB_EVENT_FB_CLUSTER_BIND_CREATED_FOR_TARGET,
    BDB_EVENT_FB_BIND_CREATED_FOR_TARGET,
    BDB_EVENT_FB_GROUP_ADDED_TO_TARGET,
    BDB_EVENT_FB_ERR_BINDING_FAILED,
    BDB_EVENT_FB_ERR_BINDING_TABLE_FULL,
    BDB_EVENT_FB_ERR_GROUPING_FAILED,
    BDB_EVENT_FB_NO_QUERY_RESPONSE,
    BDB_EVENT_FB_TIMEOUT,
    BDB_EVENT_FB_OVER_AT_TARGET,
    BDB_EVENT_LEAVE_WITHOUT_REJOIN,
 }
 BDB_teBdbEventType;

```

These events are described below.

The events with ‘FB’ in their names are used in the ‘Finding and Binding’ process and the event data is contained in the structure `BDB_tsFindAndBindEvent` \(see [BDB_tsFindAndBindEvent](bdb_tsfindandbindevent.md#ID_3BA20764-40D8-4B2D-B8E5-A4BEDA95411C)\).

**Note:** In addition, certain ZCL events are generated during the Finding and Binding process. These events are passed to the callback function **BDB\_vZclEventHandler\(\)**, which is supplied with the ZigBee Base Device. For these events, refer to [Finding and Binding](finding_and_binding.md#).

1.  **BDB\_EVENT\_ZPSAF**

    This event indicates that a ZigBee stack event has occurred. In this case, the `uEventData` field \(of the `BDB_tsBdbEvent` structure\) contains a `BDB_tsZpsAfEvent` structure, which itself includes the `ZPS_tsAfEvent` stack event structure.

2.  **BDB\_EVENT\_INIT\_SUCCESS**

    This event is generated when the ZigBee Base Device has been successfully initialized.

3.  **BDB\_EVENT\_REJOIN\_SUCCESS**

    This event is generated when the node has successfully rejoined its previous network.

4.  **BDB\_EVENT\_REJOIN\_FAILURE**

    This event is generated when the node attempts to rejoin its previous network has failed.

5.  **BDB\_EVENT\_NWK\_STEERING\_SUCCESS**

    This event is generated when the Network Steering process has successfully completed and the local node has broadcast either of the following messages:

    -   Management Permit Joining message to request the network to be opened for other devices to join \(this message is broadcast when the local node was already in the network before Network Steering\).

    -   Device Announce message to announce that the local node has joined the network \(this message is broadcast when the local node was not in the network before Network Steering\).

6.  **BDB\_EVENT\_NO\_NETWORK**

    This event is generated when no open network open was discovered in a channel scan performed by a device attempting to join a network.

7.  **BDB\_EVENT\_NWK\_JOIN\_SUCCESS**

    This event is generated when the node has successfully joined a network.

8.  **BDB\_EVENT\_NWK\_JOIN\_FAILURE**

    This event is generated when the node attempted to join a network but failed.

9.  **BDB\_EVENT\_APP\_START\_POLLING**

    This event is generated on an End Device during the Trust Centre link key exchange procedure to instruct the application to start fast polling of its parent, in order to retrieve packets received as part of the exchange procedure.

10. **BDB\_EVENT\_NWK\_FORMATION\_SUCCESS**

    This event is generated at the end of the Network Formation process when a centralized or distributed has been successfully formed by the local node.

11. **BDB\_EVENT\_NWK\_FORMATION\_FAILURE**

    This event is generated at the end of the Network Formation process if the local node failed to form a network.

12. **BDB\_EVENT\_FB\_HANDLE\_SIMPLE\_DESC\_RESP\_OF\_TARGET**

    This event indicates that the initiator has received a Simple Descriptor response from a target. This event can be used by the application to determine which type of device \(for example: Dimmable Light, On/Off Light\) the initiator is binding to. The information provided to the application is:

    ```
    u8InitiatorEp
    u8TargetEp
    u16TargetAddress
    u16ProfileId
    u16DeviceId
    u8DeviceVersion
    psAfZdpEvent \(points to received Simple Descriptor\)
    ```

 

13. **BDB\_EVENT\_FB\_CHECK\_BEFORE\_BINDING\_CLUSTER\_FOR\_TARGET**

    This event is generated just before creating a Binding table entry for a cluster. It allows the application to exclude clusters from binding by setting the `bAllowBindOrGroup` flag to FALSE \(by default it is TRUE\). This event can also be used when the application must perform a group binding by setting the attribute *u16bdbCommissioningGroupID* to a value other than 0xFFFF. Moreover, this event also allows the application to decide whether to broadcast an 'Add Group If Identifying' or unicast an 'Add Group' command. An 'Add Group If Identifying' is broadcast to all the identifying targets by setting `bGroupCast` to TRUE. By default, this parameter is set to FALSE and allows unicasting an 'Add Group' request individually to all the identifying targets. The information provided to the application is:

    ```
    u8InitiatorEp
    u8TargetEp
    u16TargetAddress
    u16ClusterId
    bAllowBindOrGroup
    bGroupCast
    psAfZdpEvent \(points to received Simple Descriptor\)
    ```

 

14. **BDB\_EVENT\_FB\_CLUSTER\_BIND\_CREATED\_FOR\_TARGET**

    This event is generated per cluster for every binding or grouping created. The event may be generated more than once for the same target device. For example, when binding a color Dimmer Switch to a Dimmable Light, the event is generated twice: once for the On/Off cluster and once for the Level Control Cluster. The information provided to the application is:


    ```
    u8InitiatorEp
    u8TargetEp
    u16TargetAddress
    u16ClusterId
    ```

15. **BDB\_EVENT\_FB\_BIND\_CREATED\_FOR\_TARGET**

    This event is generated once all address bindings have been completed. The application can then send a ‘Stop Identifying’ command to the bound target. The information provided to the application is:

    ```
    u8InitiatorEp
    u8TargetEp
    u16TargetAddress
    ```

16. **BDB\_EVENT\_FB\_GROUP\_ADDED\_TO\_TARGET**

    This event is generated once the ‘Add Group’ or ‘Add Group If Identifying’ has been sent, in order to inform the application that grouping has been completed from the perspective of the initiator. The application can then groupcast a ‘Stop Identifying’ command to the grouped targets. The information provided to the application is:

    ```
    u8InitiatorEp
    u8TargetEp
    u16GroupId
    u16TargetAddress
    psAfZdpEvent
    ```

17. **BDB\_EVENT\_FB\_ERR\_BINDING\_FAILED**

    This event is generated to indicate that an unexpected error has occurred while creating a Binding table entry.

18. **BDB\_EVENT\_FB\_ERR\_BINDING\_TABLE\_FULL**

    This event is generated to inform the application that the Binding table is full and therefore the Finding and Binding process has failed. As a result, the ZigBee Base Device exits the Finding and Binding process.

19. **BDB\_EVENT\_FB\_ERR\_GROUPING\_FAILED**

    This event is generated to indicate that a grouping has failed, since the initiator was not able to send an ‘Add Group’ or ‘Add Group If Identifying’ request.

20. **BDB\_EVENT\_FB\_NO\_QUERY\_RESPONSE**

    This event indicates that the initiator did not receive an Identify Query response within BDB\_FB\_RESEND\_IDENTIFY\_QUERY\_TIME \(default value is 10\) seconds. The information provided to the application is:


    ```
    u8InitiatorEp
    ```

21. **BDB\_EVENT\_FB\_TIMEOUT**

    This event indicates that the commissioning timer expired after a period defined by the constant BDBC\_MIN\_COMMISSIONING\_TIME \(180 seconds by default\). The information provided to the application is:

    ```
    u8InitiatorEp
    ```

22. **BDB\_EVENT\_FB\_OVER\_AT\_TARGET**

    This event indicates that the Finding and Binding process has ended on the target node because the identify time reached zero or a remote node forced it to go to zero.

23. **BDB\_EVENT\_LEAVE\_WITHOUT\_REJOIN**

    This event is generated when the node has been instructed to leave the network without attempting to rejoin the network.


**Parent topic:**[ZigBee Base Device](../topics/zigbee_base_device.md)

