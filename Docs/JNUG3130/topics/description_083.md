# Description

This function can be used to apply a mutex at the start of a section of application code that is to be protected from re-entrancy. The function **ZPS\_u8ReleaseMutexLock\(\)**must be called at the end of the mutex-protected section to release the mutex.

A pointer must be provided to a user-defined mutex function with the following prototype:

**\(\(bool\_t\*\) \(\*\) \(void\)\)**

This function must define and maintain a Boolean flag which indicates whether the corresponding mutex is active \(TRUE\) or inactive \(FALSE\). This flag is used by **ZPS\_u8GrabMutexLock\(\)** to determine whether the mutex is available. If this flag reads as FALSE, the mutex is applied and the above mutex function must set the flag to TRUE, but if the flag is already TRUE then the mutex cannot be applied - in the latter case, **ZPS\_u8GrabMutexLock\(\)** returns a failure.

A pointer to a ‘priority level’ value must be provided, which contains the current priority level of the main application thread \(when mutex protection is not being implemented\). When a mutex is applied, the priority level of the main thread is increased such that interrupts with a priority of 11 or less cannot preempt the main thread. When the mutex is released, the priority level of the main thread will be returned to its value from before the mutex was applied.

Mutexes are further described in [Section 6.9.3](critical_sections_and_mutual_exclusion_mutex.md).

**Parent topic:**[ZPS\_u8GrabMutexLock](../topics/zps_u8grabmutexlock.md)

