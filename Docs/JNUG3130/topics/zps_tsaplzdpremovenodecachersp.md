# ZPS\_tsAplZdpRemoveNodeCacheRsp

This structure is used to store Remove\_node\_cache\_rsp message data - a response to a call to the function **ZPS\_eAplZdpRemoveNodeCacheRequest\(\)**. This response indicates whether the sending node has successfully removed from its primary discovery cache all ‘discovery information’ relating to a given End Device node.

The `ZPS_tsAplZdpRemoveNodeCacheRsp`structure is detailed below.

```
typedef struct {
     uint8 u8Status;
} ZPS_tsAplZdpRemoveNodeCacheRsp;
```

where `u8Status`is the return status for the function **ZPS\_eAplZdpRemoveNodeCacheRequest\(\)**.

**Parent topic:**[ZDP response structures](../topics/zdp_response_structures.md)

