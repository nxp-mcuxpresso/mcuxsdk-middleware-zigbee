# Description

This function can be used to release a mutex that has been applied to a section of application code. The function **ZPS\_u8GrabMutexLock\(\)** must have been called at the start of the mutex-protected section.

A pointer to the relevant mutex function must be provided in order to release the mutex. A pointer to the ‘priority level’ value must also be provided.

Mutexes are further described in [Section 6.9.3](critical_sections_and_mutual_exclusion_mutex.md).

**Parent topic:**[ZPS\_u8ReleaseMutexLock](../topics/zps_u8releasemutexlock.md)

