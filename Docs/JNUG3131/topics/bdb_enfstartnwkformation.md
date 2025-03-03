# BDB\_eNfStartNwkFormation

```
BDB_teStatus BDB_eNfStartNwkFormation(void);
```

## Description 

This function starts the Network Formation process and, if necessary, must be called after **BDB\_vStart\(\)**. If it is potentially required on a node, Network Formation must be enabled via the attribute `u8bdbCommissioningMode`.

The function can be called only on a Coordinator or Router:

-   If called on a Coordinator, a centralized security network is formed.

-   If called on a Router, a distributed security network is formed.


The above network types are described in [Network security](network_security.md#).

Once Network Formation starts, the function returns and the eventual outcome of the Network Formation process is indicated by an asynchronous event - one of the following:

-   BDB\_EVENT\_NWK\_FORMATION\_SUCCESS if a centralized or distributed network has been successfully formed.

-   BDB\_EVENT\_NWK\_FORMATION\_FAILURE if a network has not been successfully formed.


Network Formation is described in more detail in [Network Formation](network_formation.md#ID_FF746201-046E-48EF-82F0-608A6E5D4F33).

## Parameters 

-   None

## Returns 

-   BDB\_E\_SUCCESS

    \(Network Formation has been successfully started\)\*.

-   BDB\_E\_ERROR\_INVALID\_PARAMETER

    \(End Device has attempted Network Formation\).

-   BDB\_E\_ERROR\_NODE\_IS\_ON\_A\_NWK

    \(node is already in a network\).


The eventual outcome is indicated by a BDB\_EVENT\_NWK\_FORMATION\_SUCCESS or BDB\_EVENT\_NWK\_FORMATION\_FAILURE event, as described above.

**Parent topic:**[Functions](../topics/functions.md)

