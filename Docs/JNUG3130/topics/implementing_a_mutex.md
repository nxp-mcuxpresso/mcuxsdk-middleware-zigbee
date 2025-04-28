# Implementing a Mutex

A mutex can be associated with a section of application code to prevent the section from being re-entered before the current execution of the section has finished. The section of code to which the mutex will be applied must be delimited by the following two functions:

-   **zps\_u8GrabMutexLock\(\)** must be called at the start of the code section.
-   **zps\_u8ReleaseMutexLock\(\)** must be called at the end of the code section.

It is also possible to apply a mutex to a critical section, as described in [Section 5.9.3.1](implementing_a_critical_section.md).

When applying a mutex, a pointer must be provided to a user-defined mutex function with the following prototype:

**\(\(bool\_t\*\) \(\*\) \(void\)\)**

This function must define and maintain a Boolean flag which indicates whether the corresponding mutex is active \(TRUE\) or inactive \(FALSE\). This flag is used by the API functions to determine whether the specified mutex is available. If this flag reads as FALSE at the start of the relevant code section, the mutex is applied and the above mutex function must set the flag to TRUE, but if the flag is already TRUE then the mutex cannot be applied \(and the API function returns with a failure\).

To implement mutex protection, the application must maintain a ‘priority level’ value `u8Level`\(see [Section 9.3.2.1](u32microintstorage.md)\) which contains the current priority level of the main application thread \(when mutex-protected sections are not being executed\). When a mutex is applied, the priority level of the main thread is increased such that interrupts with a priority of 11 or less cannot preempt the main thread. When the mutex is released, the priority level of the main thread is returned to the value that was contained in `u8Level`before the mutex was applied.

**Parent topic:**[Critical sections and Mutual Exclusion \(Mutex\)](../topics/critical_sections_and_mutual_exclusion_mutex.md)

