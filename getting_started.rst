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
    Burn the latest version

#. `http://digistump.com/wiki/digispark/tutorials/connecting
   <http://digistump.com/wiki/digispark/tutorials/connecting>`_
   ArduinoIDE integrated with Digispark libraries required to run programs on your
   home-made Digi.
   Download the apt package for your system.


==============
Arduino as ISP
==============
#. Arduino IDE 1.04
#. Examples-->Arduino as ISp
#. Board-->Arduini UNO 
#. `ArduinoISP Tutorial <http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`


================================
Programming ATTiny85 with Arduino
================================
 It uses SPI protocol
`<http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`
**CAUTION**
  If you are programming with Arduino UNO then use a 10uF capacitor between RESET and GND of arduino UNO.
`Why Capacitor <http://forum.arduino.cc/index.php/topic,104435.0.html>`
==========================================
Burning micronucleus.hex and setting fuses
==========================================
**Command to burn the BOOTLOADER**
avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U  flash:w:"micronucleus-t85-master/firmware/releases/micronucleus-1.06.hex"

avr initialized.....the device signature should match that of attiny85...safemode..fuses ok 

**Command to set fuses of the attiny85-20PU**
avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m


After the above two steps are accomplished ,make all the USB connections and follow the next step.

============
Burn cdc.hex 
============
To enumerate digispark as USB device 

sudo ./micronucleus micronucleus-t85-master/commandline/cdc232.hex

=====================================
setting rules in udev to avoid errors
=====================================
/etc/udev/rules/49-micronucelus.rules
/etc/udec/rules/90-digispark.rules

`<https://github.com/Bluebie/micronucleus-t85/wiki/Ubuntu-Linux>`_Content of the rules

=================
ERROR encountered
=================
#. *Error*
	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85
	avrdude: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.02s

	avrdude: Device signature = 0x000000
	avrdude: Yikes!  Invalid device signature.
		 Double check connections and try again, or use -F to override
		 this check.
#. *Error*
	avrdude: stk500_getparm(): (a) protocol error, expect=0x14, resp=0x14

	avrdude: stk500_getparm(): (a) protocol error, expect=0x14, resp=0x01
	avrdude: stk500_initialize(): (a) protocol error, expect=0x14, resp=0x10
	avrdude: initialization failed, rc=-1
		 Double check connections and try again, or use -F to override
		 this check.
#. *Error*
	error if 90-digispark.rules not included

	Abort mission! -1 error has occured ...
	>> Please unplug the device and restart the program.

===============
Burning Program
===============

#. Board--->Digispark(TinyCore)
#. Programmer--->Digispark
#. Upload

	IDE will ask to plug int the device within sixty seconds	

#. Plug Digispark

==========
Help LINKS
==========
#.  `Digispark Forum <http://digistump.com/board/index.php>`

#. `SPI Protocol<http://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus>`

#.
