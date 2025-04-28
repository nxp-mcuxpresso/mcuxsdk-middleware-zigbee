# Summary of API functionality

This section summarizes the roles of the NXP ZigBee PRO and JCU APIs in an application. The table below indicates the APIs needed for the different functionality that might be required in your code:

**Use of ZigBee PRO and JCU APIs**

|**Functionality**|**ZigBee PRO APIs**|**JCU APIs**|
|-----------------|-------------------|------------|
|Essential functionality, including network formation and management|**ZDO API:** Network formation and local network management **ZDP API:** Network discovery and remote network management|-|
|Basic data transfer|**AF API:** Sending and receiving data messages|**PDUM API:** Assembling and disassembling data messages|
|Binding endpoints for data transfers between them|**ZDO API:** Basic binding **ZDP API:** Manipulation of remote Binding tables|-|
|Low-power modes \(Sleep and Doze\)|-|**Low-Power API:** Managing low-power modes|
|Preserving context data \(for example, for resuming operation after sleep without memory held\)|-|**NVM API:** Saving and restoring context data|
|Network security|**ZDO API:** Managing security|-|

**Important points to note:**

-   ZigBee PRO API function names are prefixed with ‘ZPS’ \(for ‘ZigBee PRO Stack’ function\). The function names also incorporate ‘Apl’ \(for ‘Application’ function\) and the acronym for the API to which the function belongs:
    -   ZDO function names include ‘Zdo’ \(for example, **ZPS\_eAplZdoPoll\(\)**\).
    -   ZDP function names include ‘Zdp’ \(for example, **eAplZdpActiveEpRequest\(\)**\).
    -   AF function names include ‘Af’ \(for example, **ZPS\_eAplAfUnicastDataReq\(\)**\).
-   JCU API function names are prefixed with the acronym for the JCU module to which the function belongs:
    -   ‘NVM’ for NVM functions.
    -   ‘PWR’ for Low-Power functions.
    -   ‘PDUM’ for PDUM functions.

A similar naming convention is used in structures and enumerations.

**Parent topic:**[ZigBee Stack Software](../topics/zigbee_stack_software.md)

