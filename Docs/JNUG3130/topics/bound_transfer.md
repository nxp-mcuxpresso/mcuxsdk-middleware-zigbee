# Bound transfer

A data packet can be sent from an endpoint to all the remote endpoints with which the source endpoint has been previously bound \(see [Section 5.4](binding_001.md)\). The function **zps\_eAplAfBoundDataReq\(\)** is used to implement this type of data transfer. This method provides an alternative to a group multicast \(see [Section 5.5.1.3](group_multicast.md)\) for sending data to selected endpoints.

An equivalent to the above function is provided which also requests an ‘end-to-end’ acknowledgment from the destination - **zps\_eAplAfBoundAckDataReq\(\)**. If an acknowledgment has not been received within approximately 1600 ms of the initial request, the data is re-sent, with up to 3 more subsequent re-tries before the data transfer is abandoned completely.

**zps\_eAplAfBoundAckDataReq\(\)** also allows a large data packet to be sent that may need to be fragmented into multiple messages during transmission. Application design issues concerned with fragmented data transfers are outlined in [Fragmented data transfers](fragmented_data_transfers.md).

Following a call to one of the above bound transfer functions, a deferred zps\_EVENT\_BIND\_REQUEST\_SERVER event is generated on the sending node. This event summarizes the status of the transmission \(see [Section 7.2.2.21](zps_tsafbindrequestserverevent.md)\), including the number of bound endpoints for which the transmission failed. The event is generated only after receiving MAC-level acknowledgments from the ‘next hop’ nodes or, if requested, after receiving end-to-end acknowledgments from the destination nodes.

**Note:** In the case of a bound transfer, the ‘next hop’ zps\_EVENT\_APS\_DATA\_CONFIRM events and ‘end-to-end’ zps\_EVENT\_APS\_DATA\_ACK events are consumed and do not reach the application.

**Parent topic:**[Sending data](../topics/sending_data.md)

