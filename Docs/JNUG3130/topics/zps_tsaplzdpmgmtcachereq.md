# ZPS\_tsAplZdpMgmtCacheReq

This structure is used by the function **ZPS\_eAplZdpMgmtCacheRequest\(\)**. It requests a remote node to provide a list of the End Devices registered in its primary discovery cache.

The `ZPS_tsAplZdpMgmtCacheReq`structure is detailed below.

`typedef struct {`

`uint8 u8StartIndex;`

`} ZPS_tsAplZdpMgmtCacheReq;`

where `u8StartIndex`is the discovery cache index of the first entry to be included in the response to this request.

**Parent topic:**[ZDP Request structures](../topics/zdp_request_structures.md)

