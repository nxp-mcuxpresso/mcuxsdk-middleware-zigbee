# Description

This function can be used to register a user-defined callback function which handles messages received for an unsupported cluster which resides on the ZDO endpoint \(0\), such as the cluster for an optional descriptor \(for example, a user descriptor\).

The prototype of the user-defined callback function is: **bool fn\(uint16** clusterid **\);**

where *clusterid*is the ID of the cluster that the function handles.

Normally, a message arriving for an unsupported ZDO cluster is not handled and the stack automatically returns an ‘unsupported’ message to the originating node. If this function is used to register a callback function for an unsupported ZDO cluster then on receiving a message for the cluster, the stack will invoke the callback function. The stack will not respond with an ‘unsupported message’ provided that the callback function returns TRUE, otherwise the normal stack behavior will continue.

The callback function allows the received message to be passed to the application for servicing.

**Parent topic:**[ZPS\_eAplZdoRegisterZdoFilterCallback](../topics/zps_eaplzdoregisterzdofiltercallback.md)

