# Compile-time options

This section describes the compile-time options that may be enabled in the **zcl\_options.h** file of an application that uses the DRLC cluster.

The DRLC cluster is enabled by defining CLD\_DRLC.

Client and server versions of the cluster are defined by DRLC\_CLIENT and DRLC\_SERVER, respectively.

## Length of LCE Lists 

The number of LCEs that may be stored in an LCE list \(see [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11)\) is, by default, three. This default can be over-ridden on the cluster server and a cluster client by assigning the desired values to the macros:

SE\_DRLC\_NUMBER\_OF\_SERVER\_LOAD\_CONTROL\_ENTRIES \(server\)

SE\_DRLC\_NUMBER\_OF\_CLIENT\_LOAD\_CONTROL\_ENTRIES \(client\)

## LCE Re-sends 

The DRLC cluster server may re-send an LCE when it becomes active in order to support clients that do not have a clock. This facility should not be enabled unless explicitly required. To enable this functionality, define:

DRLC\_SEND\_LCE\_AGAIN\_AT\_ACTIVE\_TIME

## Message Signing \(Security\) 

On DRLC cluster clients that need to implement message signing \(see [Section 41.6](message_signing_security.md#id_a36618a8-7914-49df-a2e2-8a45929c7dc0)\), the following must be defined:

```
#define SE_MESSAGE_SIGNING

```

For a DRLC cluster server to check a message signature, it is necessary to locally store the certificates of any nodes that perform key establishment. The maximum number of certificates that can be stored is configured by defining the following on the server:

```
#define KEC_NUM_CERTIFICATES <        n>

```

where `n` is the number of certificates that can be stored.

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

