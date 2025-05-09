# Conversion factor and calorific value \(gas only\)

The Price cluster provides attributes related to conversion factor and calorific value for use with gas \(only\):

-   **Conversion factor:** Accounts for the variation of gas volume with temperature and pressure

-   **Calorific value:** Indicates the quantity of energy in MJ that is generated per unit volume or unit mass of gas burned


The attributes associated with the above properties are part of the ‘Commodity’ set - refer to [Section 40.2](price_cluster_structure_and_attributes.md#id_040fd477-8263-48cc-9679-a5e34621e8f9).

If required, conversion factor and/or calorific value must be enabled in the compile-time options, as described in [Section 40.13](compile-time_options.md#id_d7c0b485-9cb7-41c2-b7ba-4c8aff1d72fe).

Conversion factors and calorific values can be independently scheduled with associated start-times. The Price cluster server \(ESP\) and clients each maintain a list of the scheduled conversion factors and a list of the scheduled calorific values \(along with their start-times\). The maximum number of entries in each list is by default 2 \(allowing the present one and the next one to be stored\), but this maximum can be re-defined in the compile-time options.

The ESP \(Price cluster server\) receives a scheduled conversion factor or calorific value from the utility company. A received value and its associated start-time are added as an entry to the relevant list on the server by the ESP application as follows:

-   A new entry is added to the conversion factor list by calling the function **eSE\_PriceAddConversionFactorEntry\(\)**

-   A new entry is added to the calorific value list by calling the function **eSE\_PriceAddCalorificValueEntry\(\)**


The entries are maintained in the list in increasing order of start-times. If an existing entry in the list has the same start-time as the new entry, the entry with the greater value of the Issuer Event ID is included in the list \(and the other entry is discarded\).

Once a new entry is added to a list on the server, a Publish Conversion Factor or Publish Calorific Value command is automatically sent to the cluster clients to inform them that a new value is available, allowing them to update their lists with the new information.

## Initializing Conversion Factors and Calorific Values at Network Startup 

Note the following issues at network startup:

-   When the ESP node first starts, there may be no other active nodes in the network to receive a new conversion factor and/or calorific value. Thus, the Price cluster clients should request this information from the ESP when they start. They can do this using **eSE\_PriceGetConversionFactorSend\(\)** or **eSE\_PriceGetCalorificValueSend\(\)**, as appropriate.

-   When initializing the conversion factor or calorific value at ESP startup, the ESP application should call **eSE\_PriceAddConversionFactorEntry\(\)** or **eSE\_PriceAddCalorificValueEntry\(\)** with the address mode parameter set to E\_ZCL\_AM\_NO\_TRANSMIT. This prevents the new value from being transmitted to a network with no other active nodes.

-   Any clients that are active during ESP initialization should not request a conversion factor or calorific value from the ESP before the values are received from the utility company. To avoid this problem, the ESP application should obtain the values from the utility company before calling the ZigBee PRO function **ZPS\_eAplZdoStartStack\(\)** and after calling the relevant endpoint register function \(example, **eSE\_RegisterEspMeterEndPoint\(\)**\).


**Parent topic:**[Price Cluster](../../Price_cluster/topics/price_cluster.md)

