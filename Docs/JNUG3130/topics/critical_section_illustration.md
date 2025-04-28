# Critical section illustration

**Time**

A critical section of code must be delimited by the following two functions:

-   **zps\_eEnterCriticalSection\(\)** must be called at the start of the critical section.
-   **zps\_eExitCriticalSection\(\)** must be called at the end of the critical section.

A mutex can also be optionally associated with a critical section, to protect the section from re-entrancy. If required, the mutex can be specified in a parameter of **zps\_eEnterCriticalSection\(\)**. Mutexes are described in [Section 5.9.3.2](implementing_a_mutex.md).

To implement critical sections, the application must maintain a ‘priority level’ value `u8Level`\(see [Section 9.3.2.1](u32microintstorage.md)\) which contains the current priority level of the main application thread \(when critical sections are not being executed\). When a critical section is entered, the priority level of the main thread is increased such that interrupts with a priority of 11 or less cannot preempt the main thread. At the end of the critical section, the priority level of the main thread is returned to the value that was contained in `u8Level`before the critical section was entered.

**Parent topic:**[Implementing a critical section](../topics/implementing_a_critical_section.md)

