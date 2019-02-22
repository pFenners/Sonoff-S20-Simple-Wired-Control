# Sonoff-S20-Simple-Wired-Control
Turns the Sonoff S20 in to a simple on/off relay controlled by a external switch/input. 
Allows for manual override using the push button on the front of the S20.
No wifi functionality is enabled.

# Flashing the Sonoff S20

How to flash the S20 with custon firmware is covered in many places. The two guides here go in to detail:

https://github.com/arendst/Sonoff-Tasmota/wiki/Sonoff-S20-Smart-Socket
https://github.com/arendst/Sonoff-Tasmota/wiki/Arduino-IDE

In short this involves:

1. UNPLUG and open the S20
2. Solder a pin header to connect a FTDI USB converter
3. Hold down the push button while connecting the FTDI USB converter to a computer
4. Flash the firmware (the .ino file from this repository) using the Arduino IDE

# Connecting the S20 to an external switch or input

Solder tail wires to the pin's previously used to flash the S20, the pins differ depending on your use. Normally only two wires are needed.
When looking at the S20 with the push button at the top and the plug pins at the bottom:
- The top pin is VCC 
- The X pin in PIN 3 (input pin)
- The bottom pin is GND

*To use an external input e.g another microcontroller*
- Wire GND to the GND of the other device
- Wire the input put to an output pin of the other device

*To use an external push button*
- Wire one side of the push button to the input pin
- Wire the other side of the switch to VCC

Pulling the input pin high will activate the S20's relay
Pulling the input pin low will de-activate the relay

# Using the manual override feaure

Sometimes you may want to turn on or off the relay regardless of the state of the external switch/input. When override mode is enabled the state of the relay can be changed by pressing the push button on the S20. This can be toggle as many times as required until you disable override mode.

*OVERRIDE mode will ignore the external switch/input until turned off*

- Enable override
There are two ways to enable override mode. When enabled the switch will be illuminated green.
1. Non-toggle method - Hold down the push button on the S20 for over 2 seconds. This will not toggle the relay state.
2. Toggle method - Simply push the button on the S20, the relay state will toggle and override mode will be enabled.

- Disable override
Hold the push button on the S20 for over 2 seconds, the switch will no longer be illuminated green. The relay will now continue to be toggled by the external switch/input

