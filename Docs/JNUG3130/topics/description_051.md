# Description

This function can be used \(normally by the Coordinator/Trust Centre\) to request another node \(such as a Router\) to remove one of its children from the network \(for example, if the child node does not satisfy security requirements\).

The Router receiving this request ignores the request unless it has originated from the Trust Centre or is a request to remove itself. If the request was sent without APS layer encryption, the device ignores the request. If APS layer security is not in use, the alternative function **ZPS\_eAplZdoLeaveNetwork\(\)** should be used.

**Parent topic:**[ZPS\_eAplZdoRemoveDeviceReq](../topics/zps_eaplzdoremovedevicereq.md)

