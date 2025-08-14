# ADS125H_Driver
Driver for ADS125H

Programmable data rate 133KSPS-> How fast the ADC samples the input signal.
                              -> Up to 133 ksps = The highest rate it can sample is 133 thousand samples per second.
                              -> At 133 ksps, the ADC takes 1 sample every ~7.52 µs: 1/133,000
                              -> "Programmable” means you can reduce this rate (e.g., 1 ksps, 10 ksps, etc.) depending on your needs, usually via register settings or prescalers.
                              -> Higher sample rate = faster measurement but more noise and higher power use.
                              -> Lower sample rate = slower measurement but often better resolution and lower power.

Analog MUX-> The ADC front-end has a multiplexer that can select one input channel at a time from multiple analog sources.
          -> Can program a register to choose which channel the ADC samples.

17 independently selected inputs-> There are 17 possible MUX selections.
                                -> These selections cover both single-ended and differential configurations.
                                -> Each selection is independent can pick any channel without needing to scan in a fixed sequence.
                               

8 fully differential inputs-> Fully differential means the ADC measures the voltage difference between two pins: Vdiff​=Vpos​−Vneg​
                           -> 8 fully differential inputs means the MUX supports 8 pairs of pins in differential mode.
                           -> This uses 16 physical pins (2 per differential channel).
                           -> Differential inputs help reject common-mode noise.
                           -> Differential: (CH0–CH1), (CH2–CH3), …, (CH14–CH15) = 8 combos.
                        

16 single-ended inputs-> Single-ended means the ADC measures the voltage of one pin with respect to a common reference(Ground).
                      -> Single-ended uses fewer pins per channel, so you can measure more signals.
                      -> Single-ended: CH0, CH1, …, CH15 = 16 options.


Application differential inputs-> Bridge Sensors (e.g., load cells, strain gauges, pressure sensors).
                               -> Audio and Communication Signals.
                               -> Battery Cell Voltage Measurement.
                               -> Instrumentation and Medical Equipment etc.
                               -> To measure +ve and -ve voltages.
                               -> Long distance eg PLC etc.
KeyPoints-> The signal is low amplitude (microvolts to millivolts).
         -> There’s a lot of common-mode noise.
         -> The sensor or source is not referenced to system ground.
         
Application single-ended inputs-> Simple Sensor Measurements.
                               -> Internal System Monitoring.
                               -> Audio and Analog Signals with Common Ground.
                               -> Knobs, Sliders, and Joystick Inputs etc.
KeyPoints-> simpler, more channels, cheaper wiring.

Internal Reference->The internal reference in an ADC is basically a built-in, factory-calibrated voltage source that the ADC uses as its measurement baseline instead of relying on an external voltage reference pin.
                  -> If the reference voltage changes, your ADC readings change even if the input signal stays the same.
                  -> A stable and accurate reference is essential for accurate measurements.
                  -> That output stays stable even if your system supply moves from 3.3 V to 3.0 V, because the internal reference didn’t change.


         
