# Page Requests

An OTA Upgrade client normally requests image data from the server one block at a time, by sending an Image Block Request when it is ready for the next block. The number of requests can be reduced by requesting the image data one page at a time, where a page may contain many blocks of data. Requesting data by pages reduces the OTA traffic and, in the case of battery-powered client device, extends battery life.

A page of data is requested by sending an Image Page Request to the server. This request contains a page size, which indicates the number of data bytes that should be returned by the server following the request \(and before the next request is sent, if any\). The server still sends the data one block at a time in Image Block Responses. The Image Page Request also specifies the maximum number of bytes that the client device can receive in any one OTA message and the block size must therefore not exceed this limit \(in general, the page size should be a multiple of this limit\).

It is the responsibility of the client to keep track of the amount of data so far received since the last Image Page Request was issued - this count is updated after each Image Block Response received. Once this count reaches the page size in the request, the client will issue the next Image Page Request \(if the download is not yet complete\).

During a download that uses page requests:

-   If the client fails to receive one or more of the requested blocks then the next Image Page Request will request data starting from the offset which corresponds to the first missing block.

-   If the client fails to receive all the blocks requested in an Image Page Request then the same request will be repeated up to two more times - if the requested data still fails to arrive, the client will switch to using Image Block Requests to download the remaining image data.


An Image Page Request also contains a ‘response spacing’ value. This indicates the minimum time-interval, in milliseconds, that the server should insert between consecutive Image Block Responses. If the client is a sleepy End Device, it may specify a long response spacing so that it can sleep between consecutive Image Block Responses, or it may specify a short response spacing so that it can quickly receive all blocks requested in a page and sleep between consecutive Image Page Requests.

The implementation of the above page requests in an application is described below. The OTA image download process using page requests is similar to the one described in [Section 49.7](implementing_ota_upgrade_mechanism_.md#id_dd5d3237-7c2e-4a47-ad47-9815f483cd62), except the client submits Image Page Requests to the server instead of Image Block Requests.

## Enabling the Page Requests Feature 


In order to use page requests, the macro OTA\_PAGE\_REQUEST\_SUPPORT must be defined in the **zcl\_options.h** file for the server and client.

In addition, values for the page size and response spacing can also be defined in this file for the client \(if non-default values are required\) - see below and [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31).

## Implementation in the Server Application 

The application on the OTA Upgrade server device must control a millisecond timer \(a timer with a resolution of one millisecond\) to support page requests. This timer is used to implement the ‘response spacing’ specified in an Image Page Request - that is, to time the interval between the transmissions of consecutive Image Block Responses \(sent out in response to the Image Page Request\).

When the server receives an Image Page Request, it will generate the event E\_ZCL\_CBET\_ENABLE\_MS\_TIMER to prompt the application to start the millisecond timer for a timed interval equal in value to the ‘response spacing’ in the request. The application can obtain this value \(in milliseconds\) from the event via:

```
sZCL_CallBackEvent.uMessage.u32TimerPeriodMs

```

The millisecond timer is started for a particular timed interval. The expiry of this timer is indicated by an E\_ZCL\_CBET\_TIMER\_MS event, which is handled as described in [Section 3.2](../../ZCL_event_handling/topics/processing_events.md#id_330793fd-a49c-4aa2-8637-b6fa2de34c38). The server will then send the next Image Block Response.

After sending an Image Block Response:

-   If the server now generates an E\_ZCL\_CBET\_DISABLE\_MS\_TIMER event, this indicates that the last of the Image Block Responses \(for the Image Page Request\) has been sent and the application should disable the millisecond timer.

-   Otherwise, the application must start the next timed interval \(until the next response\).


## Implementation in the Client Application 

There is nothing specific to do in the client application to implement page requests. Provided that page requests have been enabled in the **zcl\_options.h** file for the client \(see above\), page requests will be automatically implemented by the stack instead of block requests for OTA image downloads. The page size \(in bytes\) and response spacing \(in milliseconds\) for these requests can be specified through the following macros in the **zcl\_options.h** file \(see [Section 49.13](compile-time_options.md#id_97b3e8ab-ab41-4c8b-9817-fc21181c7e31)\):

-   OTA\_PAGE\_REQ\_PAGE\_SIZE

-   OTA\_PAGE\_REQ\_RESPONSE\_SPACING


The default values are 512 bytes and 300 ms, respectively.

However, the client application can itself submit an Image Page Request to the server by calling the function **eOTA\_ClientImagePageRequest\(\)**. In this case, the page size and response spacing are specified in the Image Page Request payload structure as part of this function call.

The client handles the resulting Image Block Responses as described in [Section 49.7](implementing_ota_upgrade_mechanism_.md#id_dd5d3237-7c2e-4a47-ad47-9815f483cd62) for standard OTA downloads.

**Parent topic:**[Ancillary Features and Resources for OTA Upgrade](../../OTA_upgrade_cluster/topics/ancillary_features_and_resources_for_ota_upgrade.md)

