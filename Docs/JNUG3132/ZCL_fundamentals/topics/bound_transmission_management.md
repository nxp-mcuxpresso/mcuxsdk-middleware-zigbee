# Bound Transmission Management

ZigBee PRO provides the facility for bound transfers/transmissions. In this case, a source endpoint on one node is bound to one or more destination endpoints on other nodes. Data sent from the source endpoint is then automatically transmitted to all the bound endpoints \(without the need to specify destination addresses\). The bound transmission is handled by a Bind Request Server on the source node. Binding, bound transfers, and the Bind Request Server are fully described in the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

Congestion may occur if a new bound transmission is requested while the Bind Request Server is still busy completing the previous bound transmission \(still sending packets to bound nodes\). This causes the new bound transmission to fail. The ZCL software incorporates a feature for managing bound transmission requests, so not to overload the Bind Request Server and cause transmissions to fail.

**Note:** The alternative to using this feature is for the application to re-attempt bound transmissions that fail.

If this feature is enabled and a bound transmission request submitted to the Bind Request Server fails, the bound transmission APDU is automatically put into a queue. A one-second scheduler periodically takes the APDU at the head of the queue and submits it to the Bind Request Server for transmission. If this bound transmission also fails, the APDU is returned to the bound transmission queue.

The bound transmission queue has the following properties:

-   Number of buffers in the queue

-   Size of each buffer, in bytes


The feature is enabled and the above properties are defined at compile-time, as described below.

**Note:** If a single APDU does not fit into a single buffer in the queue, it is stored in multiple buffers \(provided that enough buffers are available\).

## Compile-time Options 

In order to use the bound transmission management feature, the following definitions are required in the **zcl\_options.h** file.

Add this line to enable the bound transmission management feature:

```
#define CLD_BIND_SERVER 

```

Add this line to define the number of buffers in the bound transmission queue \(in this example, the queue will contain four buffers\):

```
#define MAX_NUM_BIND_QUEUE_BUFFERS  4

```

Add this line to define the size, in bytes, of a buffer in the bound transmission queue \(in this example, the buffer size is 60 bytes\):

```
#define MAX_PDU_BIND_QUEUE_PAYLOAD_SIZE   60 

```

Certain clusters and the ‘attribute reporting’ feature allow APS acknowledgements to be disabled for bound transmissions. The required definitions are detailed in the cluster-specific compile-time options.

**Parent topic:**[ZCL Fundamentals and Features](../../ZCL_fundamentals/topics/zcl_fundamentals_and_features.md)

