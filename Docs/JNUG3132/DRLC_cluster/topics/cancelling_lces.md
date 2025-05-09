# Canceling LCEs

An LCE can be canceled, in which case it is moved to the ‘Deallocated’ list \(possibly via the ‘Cancelled’ list - see below\). A cancellation can only be performed from the DRLC cluster server and is normally sent to all client endpoints that have been bound to the server. Two functions are provided which can be called on the cluster server to perform LCE cancelations:

-   **eSE\_DRLCCancelLoadControlEvent\(\)** is used to cancel a particular LCE

-   **eSE\_DRLCCancelAllLoadControlEvents\(\)** is used to cancel all LCEs


Cancellation involves removing the LCE\(s\) from the ‘Scheduled’ or ‘Active’ lists on the cluster server and clients, which is done automatically by the cluster. As a result, the callback event E\_SE\_DRLC\_EVENT\_COMMAND is generated, containing a LOAD\_CONTROL\_EVENT\_CANCEL or LOAD\_CONTROL\_EVENT\_CANCEL\_ALL command, as appropriate. This indicates whether the cancellation with immediate effect or a random delay is applied:

-   If the cancellation is with immediate effect, the application should stop load control for the relevant device\(s\).

-   If a random delay is to be applied to the cancellation, the cluster puts the LCE in the ‘Cancelled’ list until the delay has expired, when the LCE is moved to the ‘Deallocated’ list. Another E\_SE\_DRLC\_EVENT\_COMMAND callback event containing the command LOAD\_CONTROL\_EVENT\_CANCEL or LOAD\_CONTROL\_EVENT\_CANCEL\_ALL is then generated, this time indicating immediate cancellation. The application should now stop load control for the relevant device\(s\).


**Parent topic:**[LCE Handling](../../DRLC_cluster/topics/lce_handling.md)

