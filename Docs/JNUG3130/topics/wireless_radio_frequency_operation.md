# Wireless radio frequency operation

The IEEE 802.15.4 protocol, on which ZigBee is built, provides radio-based network connectivity operating in one of three possible RF \(Radio Frequency\) bands: 868 MHz, 915 MHz, or 2400 MHz. These bands are available for unlicensed use, depending on the geographical area \(check your local radio communication regulations\).

The characteristics of these RF bands are shown in the table below.

**Total number of channels**

|**RF Band**|**Number of Channels**|
|-----------|----------------------|
|863 MHz - 876 MHz|63|
|915 MHz - 921 MHz|27|
|**Total**|90|

**Channel distribution across pages**

|**Channel Page**|**Description**|
|----------------|---------------|
|863-876 MHz|63|
|915-921 MHz|27|
|**Total**|90|

The internal representation of the channels in our stack is as follows:

-   A 32-bit mask is used to represent the channel mask.
-   The top 5 bits are used for page number and the lower 27 bits are the channel masks.

In 2.4G, page number is 0 channel range 11-26. Thus, it will be 0x00000800 \(page 0, Channel 11\). In Sub Gig Page 28 channel 0, is 0xE0000001. The 868 MHz and 915 MHz bands offer certain advantages such as fewer users, less interference, and less absorption and reflection, but the 2400 MHz band is far more widely adopted for a number of reasons:

-   Worldwide availability for unlicensed use
-   Higher data rate \(250 kbit/s\) and more channels
-   Lower power \(transmit/receive are on for shorter time due to higher data rate\)
-   Band more commonly understood and accepted by the marketplace

Therefore, the ZigBee standard assumes operation in the 2400-MHz band, although it is possible to implement ZigBee networks in the other IEEE 802.15.4 bands. ZigBee includes measures to avoid interference between radio communications. One is its ability to automatically select the best frequency channel at initialization. It is also possible to adapt to a changing RF environment by moving the network to another channel, if the current channel proves problematic - this ‘frequency agility’ is a core feature of ZigBee PRO. Other measures are described in [Highly reliable operation](highly_reliable_operation.md). The range of a radio transmission is dependent on the operating environment - for example, indoors or outdoors. Using an NXP JN518x or K32W041/K32W061/K32W1/MCXW71/MCXW72/RW612 standard module fitted with an external dipole antenna, a range of over 1 km can typically be achieved in an open area, but inside a building this can be reduced due to absorption, reflection, diffraction and standing wave effects caused by walls and other solid objects. A high-power module \(greater than 15 dBm output power\) can achieve a range which is a factor of five greater than that of a standard module. In addition, the range between devices can be extended in a ZigBee network since the network topology \(see [Network topology](network_topology.md)\) can use intermediate nodes \(Routers\) as stepping stones when passing data to destinations.

**Parent topic:**[ZigBee overview](../topics/zigbee_overview.md)

