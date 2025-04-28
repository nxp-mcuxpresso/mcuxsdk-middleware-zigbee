# ZPS\_eAplZdoDirectJoinNetwork

```
ZPS_teStatus ZPS_eAplZdoDirectJoinNetwork( uint64 u64Addr, uint16 u16Addr, uint8 u8Capability);
```

**Description**

This function can be used on a Router and on the Coordinator to pre-determine the child nodes that will directly join it. The function is called to register each child node separately, and the IEEE/MAC and network addresses of the child node must be specified. The function adds the registered node to its Neighbor table \(it actually adds the node’s IEEE/MAC address to the MAC Address table and then includes the index of this address in a Neighbor table entry for the node\).

The function must be called only when the parent node is fully up and running in the network. Since the child node has not yet joined the network but is in the Neighbor table, it will be perceived by the parent as having been orphaned. Therefore, when the child node attempts to join the network, it must perform a rejoin as an orphan by calling the function **`ZPS\_eAplZdoOrphanRejoinNetwork\(\)`**.

**Note:** You should only modify the Neighbor table using this function and never write to it directly.

**Parameters**

-   *u64Addr* IEEE/MAC address of child node to be registered

-   *u16Addr* Network address of child node to be registered

-   *u8Capability* A bitmap indicating the operational capabilities of the child node - this bitmap is detailed in [Table](zps_tsafnwkjoinindevent.md#TABLE_026A2BDC-B736-4A72-8700-BD9FF0F39F3E) in section [ZPS\_tsAfNwkJoinIndEvent](zps_tsafnwkjoinindevent.md).


**Returns**

-   `ZPS_E_SUCCESS` \(child node successfully registered\)
-   `ZPS_APL_APS_E_ILLEGAL_REQUEST` \(address 0x0, address 0xFFFFFFFFFFFFFFFF, own address, ZDO busy\)
-   `ZPS_NWK_ENUM_ALREADY_PRESENT`
-   `ZPS_NWK_ENUM_NEIGHBOR_TABLE_FULL`

**Parent topic:**[Network deployment functions](../topics/network_deployment_functions.md)

