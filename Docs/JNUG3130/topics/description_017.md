# Description

This function can be used to register a user-defined callback function that will be invoked when a leave request, a management leave request or a remove device request \(from a remote node, normally the Trust Centre\) is received by the local node. The callback function must determine whether the request must be obeyed or ignored by the stack - this decision may depend on the originator of the request.

The prototype of the callback function is as follows:

**bool\_t ZPS\_bPerformLeaveActionDecider\(uint8** _u8Value_ **,**

**uint64** _u64Address_, **uint8** _u8Flags_\);

where:

-   *u8Value* is an enumerated value indicating the type of request - one of: ZPS\_LEAVE\_ORIGIN\_NLME \(NLME-LEAVE.request from NWK layer\) ZPS\_LEAVE\_ORIGIN\_MGMT\_LEAVE \(management leave request\) ZPS\_LEAVE\_ORIGIN\_REMOVE\_DEVICE \(remove request from remote node\)
-   *u64Address* is the IEEE/MAC address of the node that issued the request
-   *u8Flags* is a user-defined bitmap containing flagged information

The callback function must return TRUE to allow or FALSE to disallow the requested leave.

**Parent topic:**[ZPS\_eAplZdoRegisterZdoLeaveActionCallback](../topics/zps_eaplzdoregisterzdoleaveactioncallback.md)

