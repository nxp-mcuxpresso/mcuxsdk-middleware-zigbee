# Description

This function can be used to mark the end of a critical section of application code. The function **ZPS\_eEnterCriticalSection\(\)** must have been called at the start of the critical section.

This function can be used to mark the start of a critical section of application code - this is a code section that cannot be preempted by an interrupt with priority level less than 12. The function **ZPS\_eExitCriticalSection\(\)** must be called at the end of the critical section.

A pointer to a ‘priority level’ value must be provided, which contains the current priority level of the main application thread \(when critical sections are not being executed\). When a critical section is entered, the priority level of the main thread is increased such that interrupts with a priority of 11 or less cannot preempt the main thread. At the end of the critical section, the priority level of the main thread is returned to its value from before the critical section was entered.

Optionally, a mutex can also be applied during the critical section to protect the section from re-entrancy. If a mutex is required, a pointer must be provided to a user- defined mutex function with the following prototype:

**\(\(bool\_t\*\) \(\*\) \(void\)\)**

This function must define and maintain a Boolean flag that indicates whether the corresponding mutex is active \(TRUE\) or inactive \(FALSE\). This flag is used by **ZPS\_eEnterCriticalSection\(\)** to determine whether the mutex is available.

-   If this flag reads as FALSE, the mutex is applied and the above mutex function must set the flag to TRUE.

-   If the flag is already TRUE, then the mutex cannot be applied - in this case, **ZPS\_eEnterCriticalSection\(\)** returns a failure.


Critical sections and mutexes are further described in [Section 6.9.3](critical_sections_and_mutual_exclusion_mutex.md).

**Parent topic:**[ZPS\_eEnterCriticalSection](../topics/zps_eentercriticalsection.md)

