# Critical sections and Mutual Exclusion \(Mutex\)

The ZigBee 3.0 stack software provides features to prevent sections of application code from being preempted and/or re-entered. For example, when the application is writing data to memory, it may not be desirable for this operation to be interrupted and for an interrupt service routine to start writing to the same memory block.

Two features are provided to protect sections of application code:

-   **Critical Section:** A section of application code can be designated as a ‘critical section’, which means that the execution of this code section cannot be preempted by an interrupt with a priority level less than 12. A critical section should be short in order to avoid suspending interrupts for a long period of time.

-   **Mutual Exclusion \(Mutex\):** It may be desirable for a section of code not to be re-entrant. A ‘mutex’ can be associated with a code section to prevent it from being entered again before the current execution of the section has completed.

These features are described in more detail in the sub-sections below. The API resources to implement these features are detailed in [Section 9.3](critical_section_and_mutex_resources.md).


```{include} ../topics/implementing_a_critical_section.md
:heading-offset: 3
```

```{include} ../topics/implementing_a_mutex.md
:heading-offset: 3
```

**Parent topic:**[Using support software features](../topics/using_support_software_features.md)

