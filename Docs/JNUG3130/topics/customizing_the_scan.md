# Customizing the scan

You can implement network formation based on the noise level threshold, as described above, by setting `u8VsFormEdThreshold`to an appropriate value in the range 0 to 254. In the following code fragment, a noise level threshold of 100 is set:

`ZPS_psNwkNibGetHandle(ZPS_pvAplZdoGetNwkHandle())->u8VsFormEdThreshold = 100`

Thus, in the above case, all channels with a noise level above 100 will be rejected.

If no suitable channel is found and no network formed, the application can dynamically increase the value of `u8VsFormEdThreshold`and initiate another scan.

**Parent topic:**[Noise threshold for forming a network](../topics/noise_threshold_for_forming_a_network.md)

