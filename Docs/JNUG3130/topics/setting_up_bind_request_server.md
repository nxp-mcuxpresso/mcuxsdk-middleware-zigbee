# Setting up bind request server

A Bind Request Server must be set up on each device that will be the source node of a bound data transfer. This server manages a bound data transfer so that application processing is not blocked by concurrent requests for transmissions to the multiple destinations of the transfer. It does this by limiting the number of destinations and inserting a time delay between consecutive transmissions of a bound transfer.

**Note:** The bound server can only handle one bound request at a time. The application must wait for the confirmation from the first bound request before attempting to send a second bound request.

The server is configured in the ZPS Configuration Editor \(introduced in [Chapter 13](zps_configuration_editor.md)\). Two parameter values must be set:


```{include} ../topics/simultaneous_requests.md
:heading-offset: 3
```

```{include} ../topics/time_interval.md
:heading-offset: 3
```

**Parent topic:**[Binding](../topics/binding_001.md)

