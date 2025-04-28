# Description

This function requests a remote node with a primary binding table cache to modify binding table entries with new data - more specifically, binding table entries can be modified by replacing an IEEE address and/or associated endpoint number. This function could typically be used in a commissioning application to modify bindings between nodes. The function sends a Replace\_Device\_req request to the remote node.

This request must include the old IEEE address and its replacement, as well as the corresponding endpoint number and its replacement \(if any\). The request is represented by the structure below \(further detailed in [Section 9.2.2.26](zps_tsaplzdpreplacedevicereq.md)\).

`typedef struct {`

`uint64 u64OldAddress;`

`uint8 u8OldEndPoint;`

`uint64 u64NewAddress;`

`uint8 u8NewEndPoint;`

`} ZPS_tsAplZdpReplaceDeviceReq;`

On receiving this request, the remote node will search its binding table for entries containing the old IEEE address and old endpoint number from the request - this pair of values may make up the source or destination data of the binding table entry.

These values will be replaced by the new IEEE address and endpoint number from the request. Note that if the endpoint number in the request is zero, only the address will be included in the ‘search and replace’ \(the endpoint number in the modified binding table entries will be left unchanged\).

The remote node will check whether a node affected by a binding table change holds a table of its own source bindings \(see **ZPS\_eAplZdpBindRegisterRequest\(\)**\) and, if so, automatically requests an update of this table. The remote node will also request an update of the back-up of the primary binding table cache, if one exists.

The remote node will reply with a Replace\_Device\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpReplaceDeviceRsp`\(detailed in [Section 9.2.3.26](zps_tsaplzdpreplacedevicersp.md)\).

**Parent topic:**[ZPS\_eAplZdpReplaceDeviceRequest](../topics/zps_eaplzdpreplacedevicerequest.md)

