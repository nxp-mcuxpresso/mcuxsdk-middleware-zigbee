# Compile-time options

-   To enable the On/Off cluster in the code to be built, it is necessary to add the following to the **zcl\_options.h** file:

    ```
    #define CLD_ONOFF
    
    ```

-   In addition, to include the software for a cluster client or server or both, it is necessary to add one or both of the following to the same file:

    ```
    #define ONOFF_CLIENT
    #define ONOFF_SERVER
    
    ```

-   The On/Off cluster contains macros that may be optionally specified at compile time by adding some or all of the following lines to the **zcl\_options.h** file.

## Optional Attributes 

1.  To enable the optional On Configurable Duration attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_ID_ON_CONFIGURABLE_DURATION
    ```

2.  To enable the optional Duration Unit of Measure attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_ID_DURATION_UNIT_OF_MEASUREMENT
    
    ```

3.  To enable the optional Maximum Duration attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_ID_MAX_DURATION
    
    ```

4.  To enable the optional Global Scene Control attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_GLOBAL_SCENE_CONTROL
    
    ```

5.  To enable the optional On Time attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_ON_TIME
    
    ```

6.  To enable the optional Off Wait Time attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_OFF_WAIT_TIME
    
    ```

7.  To enable the optional Start-up On/Off attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_STARTUP_ONOFF
    
    ```

8.  To enable the optional Attribute Reporting Status attribute, add this line:

    ```
    #define CLD_ONOFF_ATTR_ID_ATTRIBUTE_REPORTING_STATUS
    
    ```


## Optional Commands 

1.  Add this line to enable processing of the On With Recall Global Scene command on the server:

    ```
    #define CLD_ONOFF_CMD_ON_WITH_RECALL_GLOBAL_SCENE
    ```

2.  Add this line to enable the optional On With Timed Off command on the client and server:

    ```
    #define CLD_ONOFF_CMD_ON_WITH_TIMED_OFF
    ```

3.  Add this line to enable the optional Off With Effect command on the client and server:

    ```
    #define CLD_ONOFF_CMD_OFF_WITH_EFFECT
    ```


## Cluster Revision 

To define the value \(n\) of the Cluster Revision attribute, add this line:

```
#define CLD_ONOFF_CLUSTER_REVISION <n>

```

The default value is 1, which corresponds to the revision of the cluster in the ZCL r6 specification \(see [Section 2.4](../../ZCL_fundamentals/topics/global_attributes.md#id_8f80e769-8ccd-4b4f-8609-579f4457d527)\).

**Parent topic:**[On/Off Cluster](../../OnOff_cluster/topics/onoff_cluster.md)

