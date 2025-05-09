# Appendix B.1: Automatic attribute reporting

Automatic attribute reporting involves two mechanisms:

-   A report is triggered by a change in the attribute value of at least a configured minimum amount

-   Reports are issued for the attribute periodically at a configured frequency


These mechanisms can operate at the same time. In this case, reports will be issued periodically and additional reports will be issued between periodic reports if triggered by changes in the attribute value.

If reports are triggered by frequent changes in the attribute value, they may add significantly to the network traffic. To manage this traffic, the production of reports for an attribute can be ‘throttled’. This involves defining a minimum time-interval between consecutive reports for the attribute. If the attribute value changes within this time-interval since the last report, a new report will not be generated.

**Note:** If triggered reports are throttled, periodic reports will still be produced as scheduled.

Periodic reporting can be disabled, leaving only triggered reports to be automatically generated. Automatic reporting can also be disabled altogether \(both mechanisms\). For information on the configuration of automatic reporting, refer to [Appendix B.3](configuring_attribute_reporting.md#id_8f4a2099-2cfd-4173-ae40-941bc28e2989).

**Parent topic:**[Appendix B: Attribute reporting](../../appendix/topics/attribute_reporting.md)

