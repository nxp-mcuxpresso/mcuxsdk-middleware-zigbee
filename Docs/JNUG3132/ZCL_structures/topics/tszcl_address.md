# tsZCL\_Address

This structure is used to specify the addressing mode and address for a communication with a remote node:

```
typedef struct PACK
{
  teZCL_AddressMode           eAddressMode;
  union {
        zuint16               u16GroupAddress;
        zuint16               u16DestinationAddress;
        zuint64               u64DestinationAddress;
        teAplAfBroadcastMode  eBroadcastMode;
    } uAddress;
} tsZCL_Address;

```

Where:

-   `eAddressMode` is the addressing mode to be used \(see [Section 7.1.1](../../ZCL_enums_codes/topics/addressing_modes_tezcl_addressmode.md#id_770cb165-bfc2-4129-9db1-c205a6fe2fa9)\).

-   `uAddress` is a union containing the necessary address information \(only one of the following must be set, depending on the addressing mode selected\):

    -   `u16GroupAddress` is the 16-bit group address for the target nodes.

    -   `u16DestinationAddress` is the 16-bit network address of the target.

    -   `u64DestinationAddress` is the 64-bit IEEE/MAC address of the target.

    -   `eBroadcastMode` is the required broadcast mode \(see [Section 7.1.2](../../ZCL_enums_codes/topics/broadcast_modes_zps_teaplafbroadcastmode.md#id_4278bab1-e8b6-4519-81e8-7dcbd243dddd)\).


**Parent topic:**[General Structures](../../ZCL_structures/topics/general_structures.md)

