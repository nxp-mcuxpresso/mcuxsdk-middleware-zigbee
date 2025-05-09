# tsZCL\_ClusterCustomMessage

This structure contains a cluster custom message:

```
typedef struct {
     uint16                     u16ClusterId;
     void                       *pvCustomData;
} tsZCL_ClusterCustomMessage;

```

Where:

-   `u16ClusterId` is the Cluster ID.

-   `pvCustomData` is a pointer to the start of the data contained in the message.


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

