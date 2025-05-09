# Addressing Modes \(teZCL\_AddressMode\)

The following enumerations are used to specify the addressing mode to be used in a communication with a remote node:

```
typedef enum
{
    E_ZCL_AM_BOUND,
    E_ZCL_AM_GROUP,
    E_ZCL_AM_SHORT,
    E_ZCL_AM_IEEE,
    E_ZCL_AM_BROADCAST,
    E_ZCL_AM_NO_TRANSMIT,
    E_ZCL_AM_BOUND_NO_ACK,
    E_ZCL_AM_SHORT_NO_ACK,
    E_ZCL_AM_IEEE_NO_ACK,
    E_ZCL_AM_BOUND_NON_BLOCKING,
    E_ZCL_AM_BOUND_NON_BLOCKING_NO_ACK,
    E_ZCL_AM_ENUM_END, /* enum End */
} teZCL_AddressMode;

```

The above enumerations are described in the table below.

|**Enumeration**|**Description**|
|---------------|---------------|
|E\_ZCL\_AM\_BOUND|Use one or more bound nodes/endpoints, with acknowledgments|
|E\_ZCL\_AM\_GROUP|Use a pre-defined group address, with acknowledgments|
|E\_ZCL\_AM\_SHORT|Use a 16-bit network address, with acknowledgments|
|E\_ZCL\_AM\_IEEE|Use a 64-bit IEEE/MAC address, with acknowledgments|
|E\_ZCL\_AM\_BROADCAST|Perform a broadcast \(see [Section 7.1.2](broadcast_modes_zps_teaplafbroadcastmode.md#id_4278bab1-e8b6-4519-81e8-7dcbd243dddd)\)|
|E\_ZCL\_AM\_NO\_TRANSMIT|Do not transmit|
|E\_ZCL\_AM\_BOUND\_NO\_ACK|Perform a bound transmission, with no acknowledgments|
|E\_ZCL\_AM\_SHORT\_NO\_ACK|Perform a transmission using a 16-bit network address, with no acknowledgments|
|E\_ZCL\_AM\_IEEE\_NO\_ACK|Perform a transmission using a 64-bit IEEE/MAC address, with no acknowledgments|
|E\_ZCL\_AM\_BOUND\_NON\_BLOCKING|Perform a non-blocking bound transmission, with acknowledgments|
|E\_ZCL\_AM\_BOUND\_NON\_BLOCKING\_NO\_ACK|Perform a non-blocking bound transmission, with no acknowledgments|

The required addressing mode is specified in the structure `tsZCL_Address` \(see [Section 6.1.4](../../ZCL_structures/topics/tszcl_address.md#id_5358d9e4-dd01-4dd1-8f62-8358c0150c98)\).

**Parent topic:**[General Enumerations](../../ZCL_enums_codes/topics/general_enumerations.md)

