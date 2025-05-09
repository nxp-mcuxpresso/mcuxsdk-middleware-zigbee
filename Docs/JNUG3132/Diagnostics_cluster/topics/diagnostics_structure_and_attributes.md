# Diagnostics Structure and Attributes

The structure definition for the Diagnostics cluster is:

```
typedef struct
{
#ifdef DIAGNOSTICS_SERVER
 /* Hardware Information attribute set */
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NUMBER_OF_RESETS
  uint16 u16NumberOfResets;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_PERSISTENT_MEMORY_WRITES
  uint16 u16PersistentMemoryWrites;
 #endif
 /* Stack/Network Information attribute set */
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_RX_BCAST
  uint32 u32MacRxBcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_TX_BCAST
  uint32 u32MacTxBcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_RX_UCAST
  uint32 u32MacRxUcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_TX_UCAST
  uint32 u32MacTxUcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_TX_UCAST_RETRY
  uint16 u16MacTxUcastRetry;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_MAC_TX_UCAST_FAIL
  uint16 u16MacTxUcastFail;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_RX_BCAST
  uint16 u16ApsRxBcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_TX_BCAST
  uint16 u16ApsTxBcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_RX_UCAST
  uint16 u16ApsRxUcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_TX_UCAST_SUCCESS
  uint16 u16ApsTxUcastSuccess;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_TX_UCAST_RETRY
  uint16 u16ApsTxUcastRetry;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_TX_UCAST_FAIL
  uint16 u16ApsTxUcastFail;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_ROUTE_DISC_INITIATED
  uint16 u16RouteDiscInitiated;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NEIGHBOR_ADDED
  uint16 u16NeighborAdded;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NEIGHBOR_REMOVED
  uint16 u16NeighborRemoved;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NEIGHBOR_STALE
  uint16 u16NeighborStale;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_JOIN_INDICATION
  uint16 u16JoinIndication;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_CHILD_MOVED
  uint16 u16ChildMoved;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NWK_FC_FAILURE
  uint16 u16NWKFCFailure;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_FC_FAILURE
  uint16 u16APSFCFailure;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_UNAUTHORIZED_KEY
  uint16 u16APSUnauthorizedKey;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_NWK_DECRYPT_FAILURE
  uint16 u16NWKDecryptFailure;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_APS_DECRYPT_FAILURE
  uint16 u16APSDecryptFailure;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_PACKET_BUFFER_ALLOCATE_FAILURE
  uint16 u16PacketBufferAllocateFailure;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_RELAYED_UCAST
  uint16 u16RelayedUcast;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_PHY_TO_MAC_QUEUE_LIMIT_REACHED
  uint16 u16PhyToMACQueueLimitReached;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_PACKET_VALIDATE_DROP_COUNT
  uint16 u16PacketValidateDropCount;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_AVERAGE_MAC_RETRY_PER_APS_MESSAGE_SENT
  uint16 u16AverageMACRetryPerAPSMessageSent;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_LAST_MESSAGE_LQI
  uint8 u8LastMessageLQI;
 #endif
 #ifdef CLD_DIAGNOSTICS_ATTR_ID_LAST_MESSAGE_RSSI
  int8 i8LastMessageRSSI;
 #endif
#endif 
 zuint16 u16ClusterRevision;
} tsCLD_Diagnostics;

```

where:

## ‘Hardware Information’ Attribute Set 

The following two attributes can be maintained by the application using the Attribute Access functions detailed in [Section 5.2](../../Core_functions/topics/attribute_access_functions.md#id_4affd45c-30c4-4380-b0e4-54535096b0ee).

-   `u16NumberOfResets` is an optional attribute which acts as a counter of device resets/restarts \(note that a factory reset clears this attribute\) - thus, the attribute value must be incremented on each restart.

-   `u16PersistentMemoryWrites` is an optional attribute which acts as a counter of the number of writes to persistent memory - thus, the attribute value must be incremented on each write.


## ‘Stack/Network Information’ Attribute Set 

The following attributes must be updated by the application by calling the function **eCLD\_DiagnosticsUpdate\(\)** \(see [Section 22.3](functions.md#id_fb90e2cf-e141-493d-a369-55c3db57cbdb)\) either periodically \(at the highest rate possible\) or on receiving an appropriate event from the stack.

```
u32MacRxBcast is reserved for future use
u32MacTxBcast is reserved for future use
u32MacRxUcast is reserved for future use
u32MacTxUcast is reserved for future use
u16MacTxUcastRetry is reserved for future use
u16MacTxUcastFail is reserved for future use
u16ApsRxBcast is reserved for future use
u16ApsTxBcast is reserved for future use
u16ApsRxUcast is reserved for future use
u16ApsTxUcastSuccess is reserved for future use
u16ApsTxUcastRetry is reserved for future use
u16ApsTxUcastFail is reserved for future use
u16RouteDiscInitiated is reserved for future use
u16NeighborAdded is reserved for future use
u16NeighborRemoved is reserved for future use
u16NeighborStale is reserved for future use
u16JoinIndication is reserved for future use
u16ChildMoved is reserved for future use
u16NWKFCFailure is reserved for future use
u16APSFCFailure is reserved for future use
u16APSUnauthorizedKey is reserved for future use
u16NWKDecryptFailure is reserved for future use
u16APSDecryptFailure is reserved for future use
u16PacketBufferAllocateFailure is reserved for future use
u16RelayedUcast is reserved for future use
u16PhyToMACQueueLimitReached is reserved for future use
u16PacketValidateDropCount is reserved for future use

```

-   `u16AverageMACRetryPerAPSMessageSent` is an optional attribute which is used to maintain a record of the average number of IEEE802.15.4 MAC-level retries needed to send a message from the APS layer of the stack.

-   `u8LastMessageLQI` is an optional attribute containing the LQI \(Link Quality Indicator\) value for the last message received, as a value in the range 0 to 255 where 0 indicates the worst link quality and 255 indicates the best link quality.

-   `i8LastMessageRSSI` is an optional attribute containing the RSSI \(Receive Signal Strength Indication\) value of the last message received.


**Note:** If the value of `u8LastMessageLQI` or `i8LastMessageRSSI` is read remotely, the returned value will relate to the received message that contained the instruction to read the attribute.

## Global Attributes 

-   `u16ClusterRevision` is a mandatory attribute that specifies the revision of the cluster specification on which this cluster instance is based. The cluster specification in the ZCL r6 corresponds to a cluster revision of 1. The value is incremented by one for each subsequent revision of the cluster specification. This attribute is also described in [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527).


**Parent topic:**[Diagnostics Cluster](../../Diagnostics_cluster/topics/diagnostics_cluster.md)

