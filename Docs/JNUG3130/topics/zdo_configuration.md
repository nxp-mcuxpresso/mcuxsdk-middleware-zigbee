# ZDO configuration

Specifies the ZigBee Device Object \(ZDO\) servers that are present on the device. Most of these are mandatory for a ZCP.

The ZDO configuration parameters are detailed in the following categories:

-   **Category** **Page**
-   [Default Server](#ID_14EFFD51-F1D0-4250-BB25-48FBB8429F56)
-   [ZDO Client](#ID_B2360F5C-F17C-4AFE-9119-64AEDCE1F9D5)
-   [Device Annce Server](#ID_509FD194-BA5D-4E5A-AB40-DD571199E741)
-   [Active Ep Server](#ID_37CFF3C2-B99D-4D0B-81EC-66AD8000890F)
-   [Nwk Addr Server](#ID_F0B241C3-0293-42EE-8B58-90F5B0E3FD46)
-   [IEEE Address Server](#ID_16B6213B-347A-4139-93BD-355344145F3B)
-   [System Server Discovery Server](#ID_F2066BAA-F7BE-44E2-815A-E6EC0B004FDD)
-   [Permit Joining Server](#ID_162852A6-80C7-4392-8586-14B74C1A2919)
-   [Node Descriptor Server](#ID_54CF717B-EEB8-4C77-8525-3CD1AA24BC12)
-   [Power Descriptor Server](#ID_B9D659E3-8FB0-436F-8A89-48B618B23910)
-   [Match Descriptor Server](#ID_8CEAFAA7-A70D-4401-8ED8-04168AF0A17E)
-   [Simple Descriptor Server](#ID_945FE874-190D-4BA1-88EE-846D6567CAED)
-   [Mgmt Lqi Server](#ID_919DD051-5E3D-4073-BADA-BA8451B70A47)
-   [Mgmt Rtg Server](#ID_20878DFB-CDD2-43FE-91DB-3852D55FA846)
-   [Mgmt Leave Server](#ID_6EED1ADA-AA0D-44EB-9A5F-123A951CAA2E)
-   [Mgmt NWK Update Server](#ID_AB388215-17A1-4AA3-AB55-65D5FFFA314F)
-   [Bind Unbind Server](#ID_2E2949AA-E192-40ED-BC65-852AAB649231)
-   [Extended Active Ep Server](#ID_9B9934BB-5CEA-4A67-A7C8-672E3DBC2FF5)
-   [Extended Simple Descriptor Server](#ID_655C7CEE-78E8-4B20-AF88-1C371456088E)
-   [End Device Bind Server](#ID_7A7FA2E4-1097-47D8-A038-FA34D47D874A)
-   [Parent Announcement Server](#ID_D5BEE08C-2695-4773-85AD-B6F326B8EDB5)
-   [Management Enhanced Network Update Server](#ID_BB97210B-0BAA-4838-8959-98654918A3B3)
-   [MIB IEEE List Server](#ID_7AED0435-125B-4871-B873-1BFC41584F09)

## Default Server 
<a id="ID_14EFFD51-F1D0-4250-BB25-48FBB8429F56"></a>

Mandatory. Replies to any unimplemented server requests.

**Default Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to unimplemented server request mes​sages.​|apduZDP|-|

## ZDO Client
<a id="ID_B2360F5C-F17C-4AFE-9119-64AEDCE1F9D5"></a>
Mandatory. Processes ZDO client messages.

**ZDO Client Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to ZDO client messages.​|apduZDP|-|

## Device Annce Server 
<a id="ID_509FD194-BA5D-4E5A-AB40-DD571199E741"></a>
Mandatory. Processes device announcements.

**Default Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to device announcement messages.​|apduZDP|-|

## Active Ep Server 
<a id="ID_37CFF3C2-B99D-4D0B-81EC-66AD8000890F"></a>
Mandatory. Processes active endpoint requests.

**Active Ep Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to active endpoint request messages.​|apduZDP| |

## Nwk Addr Server 
<a id="ID_F0B241C3-0293-42EE-8B58-90F5B0E3FD46"></a>
Mandatory. Processes network address discovery requests.

**Nwk Addr Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to net-​work address discovery request messages.​|apduZDP| |

## IEEE Address Server 
<a id="ID_16B6213B-347A-4139-93BD-355344145F3B"></a>
Mandatory. Processes IEEE address discovery requests.

**IEEE Address Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to IEEE address discovery request messages.​|apduZDP| |

## System Server Discovery Server 
<a id="ID_F2066BAA-F7BE-44E2-815A-E6EC0B004FDD"></a>
Mandatory. Processes system server discovery requests.

**System Server Discovery Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to sys​tem server discovery request mes​sages.​|apduZDP| |

## Permit Joining Server 
<a id="ID_162852A6-80C7-4392-8586-14B74C1A2919"></a>
Mandatory. Processes 'permit joining' requests.

**Permit Joining Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to per​mit joining request messages.​|apduZDP| |

## Node Descriptor Server 
<a id="ID_54CF717B-EEB8-4C77-8525-3CD1AA24BC12"></a>
Mandatory. Processes Node descriptor requests.

**Node Descriptor Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to node descriptor request messages.​|apduZDP| |

## Power Descriptor Server 
<a id="ID_B9D659E3-8FB0-436F-8A89-48B618B23910"></a>
Mandatory. Processes Node Power descriptor requests.

**Power Descriptor Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to power descriptor request messages.​|apduZDP| |

## Match Descriptor Server 
<a id="ID_8CEAFAA7-A70D-4401-8ED8-04168AF0A17E"></a>
Mandatory. Processes Match descriptor requests.

**Match Descriptor Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to Match descriptor request messages.​|apduZDP| |

## Simple Descriptor Server 
<a id="ID_945FE874-190D-4BA1-88EE-846D6567CAED"></a>
Mandatory. Processes simple descriptor requests.

**Simple Descriptor Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to Sim​ple descriptor request messages.​|apduZDP| |

## Mgmt Lqi Server 
<a id="ID_919DD051-5E3D-4073-BADA-BA8451B70A47"></a>
Mandatory. Processes management LQI requests.

**Mgmt Lqi Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to Link Quality Indicator \(LQI\) request mes​sages.​|apduZDP| |

## Mgmt Rtg Server 
<a id="ID_20878DFB-CDD2-43FE-91DB-3852D55FA846"></a>
Mandatory. Processes management routing requests.

**Mgmt Rtg Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to management routing request mes​sages.​|apduZDP| |

## Mgmt Leave Server 
<a id="ID_6EED1ADA-AA0D-44EB-9A5F-123A951CAA2E"></a>
Mandatory. Processes management leave requests.

**Mgmt Leave Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to management leave request messages.​|apduZDP| |

## Mgmt NWK Update Server 
<a id="ID_AB388215-17A1-4AA3-AB55-65D5FFFA314F"></a>
Mandatory. Processes management network update requests.

**Mgmt NWK Update Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to management network update request messages.​|apduZDP| |

## Bind Unbind Server 
<a id="ID_2E2949AA-E192-40ED-BC65-852AAB649231"></a>
Mandatory. Processes both bind and unbind requests.

**Bind Unbind Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to bind and unbind request messages.​|apduZDP| |

## Extended Active Ep Server 
<a id="ID_9B9934BB-5CEA-4A67-A7C8-672E3DBC2FF5"></a>
Mandatory. Processes extended active endpoint discovery requests.

**Active Ep Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to extended active endpoint discovery request messages.​|apduZDP| |

## Extended Simple Descriptor Server 
<a id="ID_655C7CEE-78E8-4B20-AF88-1C371456088E"></a>
**Extended Simple Descriptor Server Parameters**

Mandatory. Processes extended Simple descriptor discovery requests.

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to extended Simple descriptor discovery request messages.​|apduZDP| |

## End Device Bind Server 
<a id="ID_7A7FA2E4-1097-47D8-A038-FA34D47D874A"></a>
Mandatory \(Coordinator only\). Processes End Device bind requests.

**End Device Bind Server Parameters**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to end device bind request messages.​|apduZDP| |
|*Timeout*|Number of seconds before timing out an End Device bind request.​|5|1 or higher|
|*Bind Num Retries*|Number of binding retries attempted if a binding request \(zdo\_​bind\_​req or end\_​device\_​bind\_​req\) fails.​| | |

## Parent Announcement Server 
<a id="ID_D5BEE08C-2695-4773-85AD-B6F326B8EDB5"></a>
Mandatory on the coordinator and router devices.

**End Parent Announcement Server**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to parent announce broadcast messages.​| | |

## Management Enhanced Network Update Server 
<a id="ID_BB97210B-0BAA-4838-8959-98654918A3B3"></a>
Mandatory for Sub Gig; optional for 2.4G.

**Management Enhanced Network Update Server**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to management enhanced network update request messages.​|apduZDP| |

## MIB IEEE List Server 
<a id="ID_7AED0435-125B-4871-B873-1BFC41584F09"></a>
Mandatory on routers in Sub Gig; optional on 2.4G.

**MIB IEEE List Server**

|**Parameter Name**|**Description**|**Default Value**|**Range**|
|--|--|--|--|
|*Output APDU*|The APDU to use when replying to MIB IEEE request messages.​|apduZDP| |

**Parent topic:**[ZigBee network parameters](../topics/zigbee_network_parameters.md)

