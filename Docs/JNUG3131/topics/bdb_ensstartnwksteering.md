# BDB\_eNsStartNwkSteering

```
BDB_teStatus BDB_eNsStartNwkSteering(void);
```

## Description 

This function starts the Network Steering process and, if necessary, must be called after **BDB\_vStart\(\)**. If it is potentially required on a node, enable Network Steering via the attribute `u8bdbCommissioningMode`.

The actions performed by this function depend on whether the local node is already a member of a network:

-   When the node is already in a network and is a Coordinator or Router, it opens up the network for other nodes to join. This action is for a fixed time-interval of 180 seconds by default, but this interval can be configured \(in seconds\) using the macro BDBC\_MIN\_COMMISSIONING\_TIME in the **bdb\_options.h** file.

-   When the node is not already in a network, it searches for a suitable network to join. If it finds one, attempts to join the network. Once a node has joined the network, the node is authenticated and receives the network key from its parent. If the network has a Trust Centre, the node may then replace its pre-configured link key with one generated and supplied by the Trust Centre.


Once Network Steering starts, the function returns and the eventual outcome of the Network Steering process is indicated by an asynchronous event - one of the following:

-   BDB\_EVENT\_NWK\_STEERING\_SUCCESS if Network Steering has been completed successfully.

-   BDB\_EVENT\_NO\_NETWORK if no open network was discovered for joining.

-   BDB\_EVENT\_NWK\_JOIN\_FAILURE if the node attempted to join a network but failed.


Network Steering is described in more detail in [Network steering](network_steering.md#ID_DB53F959-3956-49EA-844E-D27462676BEB).

## Parameters 

-   None

## Returns 

-   BDB\_E\_SUCCESS

    \(Network Steering has been successfully started\)\*.

-   BDB\_E\_ERROR\_IMPROPER\_COMMISSIONING\_MODE

    \(Network Steering is not enabled\).

-   BDB\_E\_ERROR\_COMMISSIONING\_IN\_PROGRESS

    \(node is already in a commissioning mode\).

-   BDB\_E\_ERROR\_INVALID\_DEVICE

    \(joining node is a Coordinator\).


The eventual outcome is indicated by a *BDB\_EVENT\_NWK\_STEERING\_SUCCESS*, *BDB\_EVENT\_NO\_NETWORK*, or *BDB\_EVENT\_NWK\_JOIN\_FAILURE* event, as described above.

**Parent topic:**[Functions](../topics/functions.md)

