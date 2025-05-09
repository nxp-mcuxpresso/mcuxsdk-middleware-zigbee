# Compile-time options

To enable the OTA Upgrade cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

```
#define CLD_OTA

```

In addition, to enable the cluster as a client or server or both, it is also necessary to add one or both of the following to the same file:

```
#define OTA_CLIENT
#define OTA_SERVER

```

**Note:** The OTA Upgrade cluster must be enabled as a client or server, as appropriate, in the application images to be downloaded using the cluster. The relevant cluster options \(see below\) should also be enabled for the image.

The following may also be defined in the **zcl\_options.h** file.

## Optional Attributes \(Client only\) 

The OTA Upgrade cluster has attributes on the client side only. The optional attributes may be specified by defining some or all of the following.

Add this line to enable the optional File Offset attribute:

```
#define OTA_CLD_ATTR_FILE_OFFSET

```

Add this line to enable the optional Current File Version attribute:

```
#define OTA_CLD_ATTR_CURRENT_FILE_VERSION

```

Add this line to enable the optional Current ZigBee Stack Version attribute:

```
#define OTA_CLD_ATTR_CURRENT_ZIGBEE_STACK_VERSION

```

Add this line to enable the optional Downloaded File Version attribute:

```
#define OTA_CLD_ATTR_DOWNLOADED_FILE_VERSION

```

Add this line to enable the optional Downloaded ZigBee Stack Version attribute:

```
#define OTA_CLD_ATTR_DOWNLOADED_ZIGBEE_STACK_VERSION

```

Add this line to enable the optional Manufacturer ID attribute:

```
#define         OTA_CLD_MANF_ID

```

Add this line to enable the optional Image Type attribute:

```
#define OTA_CLD_IMAGE_TYPE

```

Add this line to enable the optional Minimum Block Request Delay attribute:

```
#define OTA_CLD_ATTR_REQUEST_DELAY

```

## Global Attributes 

Add this line to define the value \(n\) of the Cluster Revision attribute:

```
#define CLD_THERMOSTAT_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

## Number of Images 

The maximum number of images that can be stored in the Flash memory of the device of a server or client node must be specified as follows, where in this example the maximum is two images:

```
#define OTA_MAX_IMAGES_PER_ENDPOINT              2

```

Note that the active image should not be included.

## OTA Block Size 

The maximum size of a block of image data to be transferred over the air is defined, in bytes, as follows:

```
#define OTA_MAX_BLOCK_SIZE                       100

```

If a large maximum block size is configured, it is recommended to enable fragmentation for data transfers between nodes. Fragmentation is enabled and configured on the sending and receiving nodes as described in the ‘Application Design Notes’ appendix of the *ZigBee 3.0 Stack User Guide \(JNUG3130\)*.

## Page Requests 

The ‘page request’ feature can be enabled on the server and client by adding the line:

```
#define OTA_PAGE_REQUEST_SUPPORT

```

If the page request feature is enabled then the page size \(in bytes\) and ‘response spacing’ \(in milliseconds\) to be inserted into the Image Page Requests can be configured by defining the following macros on the client:

```
#define OTA_PAGE_REQ_PAGE_SIZE                    512 
#define OTA_PAGE_REQ_RESPONSE_SPACING             300 

```

The above example definitions contain the default values of 512 bytes and 300 ms.

## Hardware Versions in OTA Header 

If hardware versions will be present in the OTA header then in order to enable checks of the hardware versions on the OTA server and client, add:

```
#define OTA_CLD_HARDWARE_VERSIONS_PRESENT

```

## Custom Serialization Data 

To maintain custom serialization data associated with binary images during upgrades on the server or client, add:

```
#define         OTA_MAINTAIN_CUSTOM_SERIALISATION_DATA 

```

## OTA Command Acks 

To disable APS acknowledgements for OTA commands on the server or client, add:

```
 #define         OTA_ACKS_ON   FALSE

```

If the above define is not included, APS acknowledgements are enabled by default. **They must be enabled for ZigBee certification**, but for increased download speed it may be convenient to disable them during application development. However, they must not be disabled if using fragmentation.

## Frequency of Requests \(Client only\) 

To avoid flooding the network with continuous packet exchanges, the request messages from the client can be throttled by defining a time interval, in seconds, between consecutive requests. For example, a one-second interval is defined as follows:

```
#define OTA_TIME_INTERVAL_BETWEEN_REQUESTS       1

```

If this time interval is not defined then the time interval, in seconds, between consecutive retries of an unthrottled message request should be defined. For example, a ten-second retry interval is defined as follows:

```
#define OTA_TIME_INTERVAL_BETWEEN_RETRIES        10

```

\(valid only if OTA\_TIME\_INTERVAL\_BETWEEN\_REQUESTS is not defined\)

## Upper Limit on Minimum Block Request Delay 

An upper limit on the value of the Minimum Block Request Delay attribute is defined, in seconds, as follows:

```
#define OTA_BLOCK_REQUEST_DELAY_MAX_VALUE        2

```

In the above example, the limit is set to 2 seconds. If no value is defined, the default value of this limit is 5 seconds.

## Device Address Copying 

On a device whose application image is to be upgraded \(client or server\), the OTA Upgrade cluster must copy the IEEE/MAC address of the device from the old image to the new image. This copy must be enabled on the device by adding the line:

```
#define OTA_COPY_MAC_ADDRESS

```

## No Security Certificate 

If no security certificate is to be used, it is necessary to remove references to the Certicom security certificate by including the following definition:

```
#define OTA_NO_CERTIFICATE

```

## Internal Storage of OTA Upgrade Image on Client 

An OTA upgrade image can be stored in the devices internal Flash memory on an OTA Upgrade cluster client by including the following definition:

```
#define OTA_INTERNAL_STORAGE

```

In addition, if the OTA upgrade image is encrypted then it needs to be decrypted before being stored in internal Flash memory. This decryption can be enabled by including the following definition:

```
#define INTERNAL_ENCRYPTED   

```

**Parent topic:**[OTA Upgrade cluster](../../OTA_upgrade_cluster/topics/ota_upgrade_cluster.md)

