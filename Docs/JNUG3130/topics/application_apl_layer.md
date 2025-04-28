# Application \(APL\) Layer

This includes:

-   <strong>Applications:</strong> Up to 240 application instances can be supported on a single ZigBee node. Each application instance communicates via an endpoint, where endpoints are numbered between 1 and 240 \(note that endpoint 0 is reserved for the ZDO of the node - see below\).
-   <strong>Application Framework \(AF\):</strong> The AF facilitates interaction between the applications and the APS layer \(see below\) through an interface known as a Service Access Point or SAP.
-   <strong>ZigBee Device Objects \(ZDO\):</strong> The ZDO represents the ZigBee node type of the device \(Coordinator, Router, or End Device\) and has a number of communication roles. The ZDO communicates via endpoint 0. For more information, refer to "[Section 3.4.7](zigbee_device_objects_zdo.md)".
-   <strong>ZigBee Base Device:</strong> This device is required for all ZigBee 3.0 nodes and deals with essential tasks for the whole node, such as commissioning. It does not occupy an endpoint.
-   <strong>ZigBee Cluster Library \(ZCL\):</strong> The ZCL provides the standard ZigBee clusters used by the device applications that run on the endpoints.
-   <strong>Application Support sub-layer \(APS\):</strong> The APS layer is responsible for:
    -   Communicating with the relevant application - for example, when a message arrives to illuminate an LED, the APS layer relays this instruction to the responsible application using the endpoint information in the message.
    -   Maintaining binding tables \(see "[Section 3.6.2](binding.md)"\) and sending messages between bound nodes.
    -   Providing communication with the Trust Centre to obtain authorization.

The APS layer has an associated database, called the APS Information Base \(AIB\). This contains attributes that mainly relate to system security.

**Parent topic:**[Software levels](../topics/software_levels.md)

