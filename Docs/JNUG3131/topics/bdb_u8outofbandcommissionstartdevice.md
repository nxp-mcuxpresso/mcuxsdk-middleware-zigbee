# BDB\_u8OutOfBandCommissionStartDevice

```
uint8 BDB_u8OutOfBandCommissionStartDevice(
BDB_tsOobWriteDataToCommission *psStartupData);
```

## Description 

This function initiates out-of-band commissioning which allows the local device to form a network as a Coordinator or to join an existing network as a Router or End Device. The function should be called after **ZPS\_eAplAfInit\(\)**. It is called when commissioning data is received from another device via out-of-band means. This commissioning data must be supplied to the function in a `BDB_tsOobWriteDataToCommission` structure, described in [Section 2.7.5](bdb_tsoobwritedatatocommission.md#ID_40AA20CC-B50E-4012-AC92-16437AB3A3FB).

Not all the data values are mandatory.

The out-of-band commissioning interface makes sensible assumptions about data values and does not allow certain values already in the node to be over-ridden by the commissioning data. For example:

-   It does not allow the network address of a Coordinator to set to a non-zero value \(since the network address of the Coordinator must be zero\)

-   It does not allow the rejoin flag to set on a Coordinator \(since the Coordinator cannot leave and then rejoin the network\)

-   In a centralized network, it does not allow the IEEE/MAC address of Trust Centre to set to any value other than the IEEE/MAC address of Coordinator \(since the Coordinator is always the Trust Centre\)


For an overview of out-of-band commissioning, refer to [Out-Of-Band Commissioning](out-of-band_commissioning.md#).

## Parameters 

-   *psStartupData*: Pointer to a structure containing commissioning data \(see [BDB_tsOobWriteDataToCommission](bdb_tsoobwritedatatocommission.md#ID_40AA20CC-B50E-4012-AC92-16437AB3A3FB)\)

## Returns 

-   BDB\_E\_SUCCESS

    \(The device has successfully formed or joined a network\).

-   BDB\_E\_FAILURE

    \(The request to form or join a network has not been accepted\).

-   ZPS\_NWK\_ENUM\_INVALID\_REQUEST

    \(The request contained invalid data\).

-   ZPS\_APL\_APS\_E\_ILLEGAL\_REQUEST

    \(The stack is not in the correct state to accept the request\).


**Parent topic:**[Functions](../topics/functions.md)

