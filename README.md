# smart-house
<br>
<font size="20"> A smart house system for the "Regionalny program stypendialny dla uczniów szczególnie
uzdolnionych" Masovia project.</font>
<br>
<font size="16">The system's core is the Arduino MEGA2560 chip. The Arduino IDE was used to burn
the sketches on the microcontroller, which is ATmega2560 with 256 KB of RAM.
<br>
The system consists of several sensors that, once turned on, measure, process and send the data to
the ATmega microcontroller. There is a serial communication set between the device and the computer.
It's possible for user to observe the data in the especial computer application. What's more, the
PCD8544 LCD screen with the resolution of 84 x 48 pixels is connected and programmed to display the
data as well, but also to let the user operate on the system to a certain extent.
<br>
The project's homepage is <a href="http://www.rpsdusu-sh.wix.com/homepage">http://www.rpsdusu-sh.wix.com/homepage</a>.
<br><br>
# Python scripts
- serialscript - makes use of the data sent to the PC from the system. It shows the devices' states, as well as the readout from the sensors in both of the rooms.
- visualizer - creates the graphs, basing on the LOG.LOG files located in the same folder as this script.
</font>
