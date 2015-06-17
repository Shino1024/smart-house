# smart-house
<br>
Link to the project: <a href="http://www.rpsdusu-sh.wix.com/homepage">RPSDUSU-SH</a>
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
The project consists of the main_ino.ino Arduino sketch which should be loaded to this device and 2 Python scripts:
- visualizer - creates the graphs, basing on the LOG.LOG file from Arduino,
- serialscript - an application that shows a sample usage of the data sent to the computer, this
application is a real data monitor.
</font>
