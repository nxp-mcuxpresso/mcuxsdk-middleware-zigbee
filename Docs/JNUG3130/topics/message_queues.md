# Message queues

Communications between application tasks on a node are implemented via message queues. The application can create a dedicated message queue for a particular communication channel. A set of functions are provided to implement message queues, as indicated in [Section 6.9.1.1](general_queue_management.md)below \(these functions are detailed in [Section](zigbee_queue_resources.md)[10.1](zigbee_queue_resources.md)\). The stack requires certain standard queues, as indicated in [Section 6.9.1.2](standard_stack_queues.md) below.

Note: To allow the device to enter sleep mode, the message queues must not contain any messages. All message queues must first be emptied.


```{include} ../topics/general_queue_management.md
:heading-offset: 3
```

```{include} ../topics/standard_stack_queues.md
:heading-offset: 3
```

**Parent topic:**[Using support software features](../topics/using_support_software_features.md)

