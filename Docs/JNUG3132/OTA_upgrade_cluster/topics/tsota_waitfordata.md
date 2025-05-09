# tsOTA\_WaitForData

The following structure contains time information for an Image Block Response. It can be used by a response which reports ‘failure’, to instruct the client to re-request the data block after a certain waiting time \(see [Section 49.11.10](tsota_imageblockresponsepayload.md#id_51ded850-0671-42aa-aeef-4ee5317fba37)\). It can also be used in ‘rate limiting’ to specify a new value for the ‘block request delay’ attribute on the client.

```
typedef struct
{
    uint32 u32CurrentTime;
    uint32 u32RequestTime;
    uint16 u16BlockRequestDelayMs;
}tsOTA_WaitForData;

```

where:

-   `u32CurrentTime` is the current UTC time, in seconds, on the server. If UTC time is not supported by the server, this value should be set to zero

-           `u32RequestTime` is the UTC time, in seconds, at which the client should re-issue an Image Block Request. If the server does not support UTC time \(indicated by a zero value for `u32CurrentTime`\), the client should interpret this value as a time delay before re-issuing an Image Block Request


**Note:** If the client does not support UTC time but both of the above values are non-zero, the client will take the difference between the two times as a time delay before re-issuing an Image Block Request.

-   `u16BlockRequestDelayMs` is used in ‘rate limiting’ to specify the value of the ‘block request delay’ attribute for the client - this is minimum time, in milliseconds, that the client must wait between consecutive block requests \(the client will update the local attribute with this value\). If the server does not support rate limiting or does not need to limit the download rate to the client, this field must be set to 0


**Parent topic:**[Structures](../../OTA_upgrade_cluster/topics/structures.md)

