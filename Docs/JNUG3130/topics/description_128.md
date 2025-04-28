# Description

This function sends a binding or unbinding request \(as specified\) to a remote node which hosts a binding table. The function requests a modification of the binding table in order to bind or unbind two endpoints of nodes in the network. The nodes to be bound/unbound may be different from the node sending the request and the node receiving the request. The latter must be either a node with a primary binding table cache or the source node for the binding. This function could typically be used in a commissioning application to configure bindings between nodes during system set- up.

The function sends a Bind\_req or Unbind\_req request to the remote node which hosts the binding table to be modified. This request includes details of the source node and endpoint, and the target node and endpoint for the binding. The request is represented by the structure below \(further detailed in [Section 9.2.2.24](zps_tsaplzdpbindunbindreq.md)\).

```
typedef struct {
        uint64 u64SrcAddress;
        uint8 u8SrcEndpoint;
        uint16 u16ClusterId;
        uint8 u8DstAddrMode;
        union {
            struct {
                uint16 u16DstAddress;
            } sShort;
            struct {
                uint64 u64DstAddress;
                uint8 u8DstEndPoint;
            } sExtended;
    } uAddressField;
} ZPS_tsAplZdpBindUnbindReq;
```

On receiving the request, the remote node adds or removes the relevant entry in its binding table and locally generates the event ZPS\_EVENT\_ZDO\_BIND or ZPS\_EVENT\_ZDO\_UNBIND, as appropriate, to signal the relevant update.

If the remote node holds a primary binding table cache, it checks whether the source node for the binding holds a table of its own source bindings \(see the description of **ZPS\_eAplZdpBindRegisterRequest\(\)**\). If it is so, it automatically requests an update of this table. A node with a primary binding table cache also requests an update of the back-up cache, if one exists.

The remote node replies with a Bind\_rsp or Unbind\_rsp response, which should be collected using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpBindRsp`\(detailed in [Section 9.2.3.23](zps_tsaplzdpbindrsp.md)\) or `ZPS_tsAplZdpUnbindRsp`\(detailed in [Section 9.2.3.24](zps_tsaplzdpunbindrsp.md)\).

**Parent topic:**[ZPS\_eAplZdpBindUnbindRequest](../topics/zps_eaplzdpbindunbindrequest.md)

