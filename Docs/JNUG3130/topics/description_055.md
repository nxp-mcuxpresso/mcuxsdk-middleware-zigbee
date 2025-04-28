# Description

This function requests a binding to be created between an endpoint on the local node and an endpoint on a remote node. The source endpoint and cluster must be specified, as well as the destination node and endpoint. The destination node is specified using both its 64-bit IEEE \(MAC\) address and its 16-bit network address.

The binding is added to the binding table on the local node.

A binding to multiple remote endpoints \(collected into a group\) can be created using the function **ZPS\_eAplZdoBindGroup\(\)**.

**Parent topic:**[ZPS\_eAplZdoBind](../topics/zps_eaplzdobind.md)

