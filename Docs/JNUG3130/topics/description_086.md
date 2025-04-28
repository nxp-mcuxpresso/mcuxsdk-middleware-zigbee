# Description

This function can be used to mark the end of a critical section of application code. The function **ZPS\_eEnterCriticalSection\(\)** should be called at the start of the critical section.

A pointer to the ‘priority level’ value must be provided. If a mutex was used in the critical section, a pointer to the relevant mutex function must be provided in order to release the mutex.

Critical sections and mutexes are further described in [Section 6.9.3](critical_sections_and_mutual_exclusion_mutex.md).

**Parent topic:**[ZPS\_eExitCriticalSection](../topics/zps_eexitcriticalsection.md)

