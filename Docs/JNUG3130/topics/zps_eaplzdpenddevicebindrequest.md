# ZPS\_eAplZdpEndDeviceBindRequest

```
ZPS\_teStatus ZPS\_eAplZdpEndDeviceBindRequest\(
        PDUM\_thAPduInstance hAPduInst,
        uint8 *pu8SeqNumber,
        ZPS\_tsAplZdpEndDeviceBindReq
                    *psZdpEndDeviceBindReq);
```

**Description**

This function sends a binding request to the Coordinator in order to bind an endpoint on the local node to an endpoint on a remote node \(these nodes can be End Devices or Routers\). The function should normally be invoked as the result of a user action on the local node, such as pressing a button. The function sends an End\_Device\_Bind\_req request to the Coordinator.

This request includes details of the source node, endpoint and clusters. The request is represented by the structure below \(further detailed in [Section 9.2.2.23](zps_tsaplzdpenddevicebindreq.md)\).

```
typedef struct {
  uint16 u16BindingTarget;
  uint64 u64SrcIeeeAddress;
  uint8 u8SrcEndpoint;
  uint16 u16ProfileId;
  /* Rest of message is variable length */
  uint8 u8NumInClusters;
  uint16 *pu16InClusterList;
  uint8 u8NumOutClusters;
  uint16 *pu16OutClusterList;
} ZPS_tsAplZdpEndDeviceBindReq;
```

On receiving the request, the Coordinator waits \(for a pre-defined timeout period\) for another binding request, from a different node, so that it can pair the requests and bind the endpoints. In order to bind the endpoints, their application profile IDs must match, and they must have compatible clusters in their input and output cluster lists.

The Coordinator replies to a binding request with an End\_Device\_Bind\_rsp response, which should be collected on the requesting node using the function **ZQ\_bZQueueReceive\(\)** and stored in a structure of type `ZPS_tsAplZdpEndDeviceBindRsp`\(detailed in [Section 9.2.3.22](zps_tsaplzdpenddevicebindrsp.md)\).

The stack will automatically update the Binding tables on the two End Devices \(following further bind requests from the Coordinator\) and an ZPS\_EVENT\_ZDO\_BIND event will be generated on the End Devices to signal these updates.


```{include} ../topics/description_141.md
:heading-offset: 4
```

```{include} ../topics/parameters_123.md
:heading-offset: 4
```

```{include} ../topics/returns_024.md
:heading-offset: 4
```

**Parent topic:**[Binding functions](../topics/binding_functions.md)

