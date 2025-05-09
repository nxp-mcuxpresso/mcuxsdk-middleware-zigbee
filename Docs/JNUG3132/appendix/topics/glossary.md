# Appendix G: Glossary

|**Term**|**Description**|
|--------|---------------|
|Address|A numeric value that is used to identify a network node. In ZigBee, the device’s 64-bit IEEE/MAC address or 16-bit network address is used.|
|AIB|APS Information Base: A database for the Application Support \(APS\) layer of the ZigBee stack, containing attributes concerned with system security.|
|APDU|Application Protocol Data Unit: Part of a wireless network message that is handled by the application and contains user data.|
|API|Application Programming Interface: A set of programming functions that can be incorporated in application code to provide an easy-to-use interface to underlying functionality and resources.|
|APS|Application Support: A sub-layer of the Application layer of the ZigBee stack, relating to communications with applications, binding and security.|
|Application|The program that deals with the input/output/processing requirements of the node, as well as high-level interfacing to the network.|
|Application Profile|A collection of device descriptors that characterise an application for a par-ticular market sector. An application profile can be public or private. A pub-lic profile is identified by a 16-bit number, assigned by the ZigBee Alliance.|
|Attribute|A data entity used by an application, e.g. a temperature measurement. It is part of a ‘cluster’ along with a set of commands which can be used to pass attribute values between applications or modify attributes.|
|Binding|The process of associating an endpoint on one node with an endpoint on another node, so that communications from the source endpoint are auto-matically routed to the destination endpoint without specifying addresses.|
|Channel|A narrow frequency range within the designated radio band - for example, the IEEE 802.15.4 2400-MHz band is divided into 16 channels. A wireless network operates in a single channel which is determined at network initial-isation.|
|Child|A node which is connected directly to a parent node and for which the par-ent node provides routing functionality. A child can be an End Device or Router. Also see Parent.|
|Cluster|A collection of attributes and commands that define a functional building block for a ZigBee device. The commands are used to communicate or modify attribute values. A cluster has input/server and output/client sides - a cluster client issues a command which is received and acted on by a cluster server.|
|Context Data|Data which reflects the current state of the node. The context data must be preserved during sleep \(of an End Device\).|
|Co-ordinator|The node through which a network is started, initialised and formed - the Co-ordinator acts as the seed from which the network grows, as it is joined by other nodes. The Co-ordinator also usually provides a routing function. All networks must have one and only one Co-ordinator.|
|End Device|A node which has no networking role \(such as routing\) and is only con-cerned with data input/output/processing. As such, an End Device cannot be a parent but can sleep to conserve power.|
|Endpoint|A software entity that acts as a communications port for an application on a ZigBee node. A node can support up to 240 endpoints, numbered 1 to 240. Two special endpoints are also supported - endpoint 0 is used by the ZDO and endpoint 255 is used for a broadcast to all endpoints on the node.|
|Extended PAN ID \(EPID\)|A 64-bit identifier for a ZigBee PRO network that is assigned when the net-work is started. A value can be pre-set or, alternatively, the IEEE/MAC address of the Co-ordinator can be used as the EPID.|
|IEEE 802.15.4|A standard network protocol that is used as the lowest level of the ZigBee software stack. Among other functionality, it provides the physical interface to the network’s transmission medium \(radio\).|
|IEEE/MAC Address|A unique 64-bit address that is allocated to a device at the time of manufac-ture and is retained by the device for its lifetime. No two devices in the world can have the same IEEE/MAC address.|
|Joining|The process by which a device becomes a node of a network. The device transmits a joining request. If this is received and accepted by a parent node \(Co-ordinator or Router\), the device becomes a child of the parent. Note that the parent must have "permit joining" enabled.|
|Mesh Network|A wireless network topology in which all routing nodes \(Routers and the Co-ordinator\) can communicate directly with each other, provided that they are within radio range. This allows optimal and flexible routing, with alterna-tive routes if the most direct route is not available.|
|Network Address|A 16-bit address that is allocated to a ZigBee node when it joins a network. The Co-ordinator always has the network address 0x0000. In IEEE 802.15.4 terminology, it is called the short address.|
|NIB|NWK Information Base: A database containing attributes needed in the management of the Network \(NWK\) layer of the ZigBee stack.|
|Node Descriptor|A set of information about the capabilities of a node.|
|Node Power Descriptor|A set of information about a node’s current and potential power supply.|
|NPDU|Network Protocol Data Unit: The transmitted form of a wireless network message \(incorporates APDU and header/footer information from stack\).|
|PAN ID|Personal Area Network Identifier: This is a 16-bit value that uniquely identi-fies the network - all neighbouring networks must have different PAN IDs.|
|Parent|A node which allows other nodes \(children\) to join the network through it and provides a routing function for these child nodes. A parent can be a Router or the Co-ordinator. Also see Child.|
|Router|A node which provides routing functionality \(in addition to input/output/pro-cessing\) if used as a parent node. Also see Routing.|
|Routing|The ability of a node to pass messages from one node to another, acting as a stepping stone from the source node to the target node. Routing function-ality is provided by Routers and the Co-ordinator. Routing is handled by the network level software and is transparent to the application on the node.|
|Simple Descriptor|A set of assorted information about a particular application/endpoint.|
|Sleep Mode|An operating state of a node in which the device consumes minimal power. During sleep, the only activity of the node may be to time the sleep duration to determine when to wake up and resume normal operation. Only End Devices can sleep.|
|Stack|The hierarchical set of software layers used to operate a system. The high-level user application is at the top of the stack and the low-level interface to the transmission medium is at the bottom of the stack.|
|Stack Profile|The set of features implemented from the ZigBee specification - that is, all the mandatory features together with a subset of the optional features. The ZigBee Alliance define two Stack Profiles for use with public Application Profiles - ZigBee and ZigBee PRO.|
|UART|Universal Asynchronous Receiver Transmitter: A standard interface used for cabled serial communications between two devices \(each device must have a UART\).|
|User Descriptor|A user-defined description of a node \(e.g. "KitchenLight"\).|
|ZigBee Base Device|A framework for the use of ZigBee device types that provides basic func-tionality such as commissioning. Its functionality is defined in the ZigBee Base Device Behaviour \(BDB\) specification from the ZigBee Alliance.|
|ZigBee Certified Product|An end-product that uses ZigBee Compliant Platforms and public Applica-tion Profiles, and which has been tested for ZigBee compliance and subse-quently authorised to carry the ZigBee Alliance logo.|
|ZigBee Cluster Library \(ZCL\)|A collection of clusters that can be individually employed in ZigBee devices, as required, to implement the functionality of a device.|
|ZigBee Compliant Platform|A component \(such as a module\) that has been tested for ZigBee compli-ance and authorised to be used as a building block for a ZigBee end-prod-uct.|
|ZigBee Device Objects \(ZDO\)|A special application which resides in the Application Layer on all nodes and performs various standard tasks \(e.g. device discovery, binding\). The ZDO communicates via endpoint 0.|

