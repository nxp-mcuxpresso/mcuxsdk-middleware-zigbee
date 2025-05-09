# LCE Handling on Server

When a new LCE is received from the utility company, it is the responsibility of the application on the ESP \(DRLC cluster server\) to add this LCE to the local ‘Scheduled’ list \(or to the ‘Active’ list, if the LCE has a ‘start-time of now’\). This addition is performed using the function **eSE\_DRLCAddLoadControlEvent\(\)**, which also sends the LCE \(unsolicited\) to the cluster clients. The LCE should normally be sent to all client endpoints with which the cluster server has been bound \(see [Section 41.3](initialisation.md#id_a8e57ff7-a370-4a13-9603-75097ed384a2)\).

**Note:**

1.  **Note 1:**Following the initial reception of LCEs from the utility company, the addition of these LCEs to the list\(s\) through **eSE\_DRLCAddLoadControlEvent\(\)**can be done after calling **eSE\_RegisterEspMeterEndPoint\(\)** or **eSE\_RegisterEspEndPoint\(\)** but before calling **ZPS\_eAplZdoStartStack\(\)**.
2.  **Note 2:** On receiving an LCE, the client checks the device class and enrollment group specified within the LCE, and only accepts the LCE if these values match the corresponding DRLC cluster attributes held locally \(see [Section 41.2](drlc_cluster_structure_and_attributes.md#id_7bc64896-4d9e-47c4-87c2-0bc3e3957607)\).

The cluster server also automatically responds to Get Scheduled Events messages from cluster clients that need current and future LCEs \(see [Section 41.5.2.2](getting_scheduled_events.md#id_f2887a5e-7cc6-46e8-bb28-92b73262e8a0)\).

**Parent topic:**[LCE Handling](../../DRLC_cluster/topics/lce_handling.md)

