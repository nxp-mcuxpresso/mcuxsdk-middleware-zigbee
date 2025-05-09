# Load Control Events \(LCEs\)

The Load Control Event \(LCE\) is an instruction, which originates from the utility company, to schedule a temporary adjustment of consumption in devices that support the DRLC cluster. The contents of an LCE are outlined in [Section 41.4.1](lce_contents.md#id_653a1246-6562-4421-bb31-02570c934c77).

An LCE is sent from the utility company to the DRLC server \(ESP\) of a ZigBee network, from where it is passed to DRLC clients. The LCEs are held in lists on the server and clients, as described in [Section 41.4.2](lce_lists_.md#id_fc0eb412-d0ca-4bb8-a714-063c0e887c11).

LCE handling is described in [Section 41.5](lce_handling.md#id_1445f62d-33bb-44a9-874e-ee4266d9d37b).


```{include} ../../DRLC_cluster/topics/lce_contents.md
:heading-offset: 2
```

```{include} ../../DRLC_cluster/topics/lce_lists_.md
:heading-offset: 2
```

**Parent topic:**[Demand-Response and Load Control Cluster](../../DRLC_cluster/topics/demand-response_and_load_control_cluster.md)

