# Appendix F.1: Application Upgrades for Different Target Processors

In a ZigBee PRO network containing dual-processor nodes \(with a JN518x, K32W041, or K32W061 Wireless microcontroller and a co-processor\), an application upgrade can be targeted at any of the following processors:

-   OTA server node processors:

    -   Wireless Microcontroller \(JN518x, K32W041, or K32W061\)

    -   Co-processor

-   OTA client node processors:

    -   Wireless Microcontroller \(JN518x, K32W041, or K32W061\)

    -   Co-processor


Only application upgrades for the OTA client node processors need the new software image to be distributed over-the-air.

The following table describes the roles of the different processors \(and their associated memory devices\) during the different application upgrades.
<html>
<table class="table frame-all table--pgwide-1" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24"><caption><span class="table--title-label">Table 1. </span><span id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__tableTitle_24497ec3-52d6-4cc0-8ae2-29f0df3fdb95" class="title">Processor Roles in Application Upgrade</span></caption><colgroup><col style="width:19.999987888227718%"><col style="width:19.999987888227718%"><col style="width:19.999987888227718%"><col style="width:19.999987888227718%"><col style="width:20.000048447089117%"></colgroup><thead class="thead">
<tr class="row">
<th class="entry valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__1" rowspan="3">
<p class="p"><strong class="ph b">Target Processor for Application Upgrade</strong></p>
</th>
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2" colspan="4">
<p class="p"><strong class="ph b">Intermediate Processors during Application Upgrade</strong></p>
</th>
</tr>
<tr class="row">
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3" colspan="2">
<p class="p"><strong class="ph b">OTA Server</strong></p>
</th>
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4" colspan="2">
<p class="p"><strong class="ph b">OTA Client</strong></p>
</th>
</tr>
<tr class="row">
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__5">
<p class="p"><strong class="ph b">Co-processor</strong></p>
</th>
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__6">
<p class="p"><strong class="ph b">JN518x/K32W041/K32W061</strong></p>
</th>
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__7">
<p class="p"><strong class="ph b">JN518x/K32W041/K32W061</strong></p>
</th>
<th class="entry align-center valign-middle" id="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__8">
<p class="p"><strong class="ph b">Co-processor</strong></p>
</th>
</tr>
</thead><tbody class="tbody">
<tr class="row">
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__1">
<p class="p"><strong class="ph b">OTA Server </strong></p>
<p class="p"><strong class="ph b">Co-processor</strong></p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__5">
<p class="p">Co-processor saves new image to its internal storage and performs update</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__6">
<p class="p">-</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__7">
<p class="p">-</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__8">
<p class="p">-</p>
</td>
</tr>
<tr class="row">
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__1">
<p class="p"><strong class="ph b">OTA Server </strong></p>
<p class="p"><strong class="ph b">Wireless Micro</strong>-<strong class="ph b">controller</strong></p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__5">
<p class="p">Co-processor passes new image to server Wireless Microcontroller device *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__6">
<p class="p">Wireless Microcon-troller saves image to Flash memory and performs update *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__7">
<p class="p">-</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__8">
<p class="p">-</p>
</td>
</tr>
<tr class="row">
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__1">
<p class="p"><strong class="ph b">OTA Client </strong></p>
<p class="p"><strong class="ph b">Wireless Micro</strong>-<strong class="ph b">controller</strong></p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__5">
<p class="p">Co-processor passes new image to server Wireless Microcontroller device *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__6">
<p class="p">Wireless Microcon-troller saves image to Flash memory and then sends it over-the-air to client *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__7">
<p class="p">Wireless Microcon-troller receives image, saves it to Flash memory and performs update</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__8">
<p class="p">-</p>
</td>
</tr>
<tr class="row">
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__1">
<p class="p"><strong class="ph b">OTA Client </strong></p>
<p class="p"><strong class="ph b">Co-processor</strong></p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__5">
<p class="p">Co-processor passes new image to server Wireless Microcontroller *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__3 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__6">
<p class="p">Wireless Microcon-troller saves image to Flash memory and then sends it over-the-air to client *</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__7">
<p class="p">Wireless Microcon-troller receives image and saves it to Flash memory or to co-processor storage device</p>
</td>
<td class="entry" headers="topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__2 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__4 topic_91eb2ac9-2a51-4666-9be3-754ec0cd8443__table_bf03cef6-6381-4506-b70a-127006d18d24__entry__8">
<p class="p">Co-processor per-forms update</p>
</td>
</tr>
</tbody></table>
</html>

\* If insufficient space in Flash memory, image may be stored in co-processor storage - see [Appendix F.2](storing_upgrade_images_in_co-processor_storage_on_.md#id_1da077b9-d126-4c31-a319-80c30738d774)

The case of the co-processor on the OTA server node updating its own application is not described any further in this manual, as this upgrade mechanism is specific to the co-processor. The other three application upgrade scenarios are described in [Appendix F.2](storing_upgrade_images_in_co-processor_storage_on_.md#id_1da077b9-d126-4c31-a319-80c30738d774).

**Parent topic:**[Appendix F: OTA extension for dual-processor nodes](../../appendix/topics/ota_extension_for_dual-processor_nodes.md)

