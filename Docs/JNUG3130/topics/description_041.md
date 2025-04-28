# Description

This function can be used by an End Device to poll its parent for pending data.

Since an End Device is able to sleep, messages addressed to the End Device are buffered by the parent for delivery when the child is ready. This function requests this buffered data and should normally be called immediately after waking from sleep.

This function call will trigger a confirmation event, ZPS\_EVENT\_NWK\_POLL\_CONFIRM, if the poll request is successfully sent to the parent. The subsequent arrival of data from the parent is indicated by a ZPS\_EVENT\_APS\_DATA\_INDICATION event. Any messages forwarded from the parent should then be collected using the function **ZQ\_bZQueueReceive\(\)**.

**Parent topic:**[ZPS\_eAplZdoPoll](../topics/zps_eaplzdopoll.md)

