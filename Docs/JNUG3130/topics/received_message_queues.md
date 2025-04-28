# Received message queues

All messages received ZPS\_msgMcpsInd on a network node are pushed into one of the following two queues:

-   `ZPS_msgMcpsDcfm`
-   `ZPS_msgMcpsInd`

These queues must be created by the application using the function **ZQ\_vZQueueCreate\(\)**. An example code is described in [Section 6.9.1.2](standard_stack_queues.md).


```{include} ../topics/zps_msgmcpsdcfm.md
:heading-offset: 2
```

```{include} ../topics/zps_msgmcpsind.md
:heading-offset: 2
```

**Parent topic:**[Appendix B: Application design notes](../topics/application_design_notes.md)

