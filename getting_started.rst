======================
Pre-requisite packages
======================

#. `arduinoIDE <http://arduino.cc/en/Main/Software>`_ Arduino IDE to use
   arduino-UNO as ISP to program ATtiny85 chip.

#. *avrdude*: To burn the BOOTLOADER on raw ATtiny85-20PU and set
   fuses of ATtiny85

#. `https://github.com/Bluebie/micronucleus-t85
   <https://github.com/Bluebie/micronucleus-t85/>`_ It contains the
   micronucelus.hex file (bootloader).

#. `http://digistump.com/wiki/digispark/tutorials/connecting
   <http://digistump.com/wiki/digispark/tutorials/connecting>`_
   Arduino integrated with digispark required to run programs on your
   home-made Digi.Download the apt package for your system.


==============
Arduino as ISP
==============
#. Arduino IDE 
#. Examples--Arduino as ISp
#. Board--Arduini UNO
#. `ArduinoISP Tutorial <http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`


================================
Programming ATTiny85 with Arduino
================================
SPI protocol
`<http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`

==========================================
Burning micronucleus.hex and setting fuses
==========================================
:Command to burn the BOOTLOADER:
avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U  flash:w:"micronucleus-t85-master/firmware/releases/micronucleus-1.06.hex"

avr initialized.....the device signature should match that of attiny85...safemode..fuses ok 

:Command to set fuses of the attiny:
avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m






