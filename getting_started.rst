Hardware requirement
====================
All you need is:

**One** Attiny85-20PU

**Two** 3.6V Zener Diode

**Three** resistors 
 *One* 1.5K ohm
 *TWO* 68 ohm
 
*Broken USB-A cable*


Pre-requisite packages
======================

* `arduinoIDE <http://arduino.cc/en/Main/Software>`_ Arduino IDE to use arduino-UNO as ISP to program ATtiny85 chip.

* **avrdude**: To burn the BOOTLOADER on raw ATtiny85-20PU and set fuses of ATtiny85

* `Bootloader <https://github.com/Bluebie/micronucleus-t85/>`_ Burn the latest version

* `DigisparkIDE <http://digistump.com/wiki/digispark/tutorials/connecting>`_ ArduinoIDE integrated with Digispark libraries required to run programs on your home-made Digispark.

* `Fritzing <http://fritzing.org/download/>`_ Optional


Arduino as ISP
==============
#. `Arduino IDE 1.04 <http://arduino.cc/en/Main/Software>`_ Download arduino 1.04
#. Plug in your arduino board 
#. File-->Examples-->ArduinoISP
#. Tools-->Board-->Arduino UNO 
#. Tools-->Serial Port-->/dev/ttyACM0
#. `ArduinoISP Tutorial <http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`_


Programming ATTiny85 with Arduino
=================================
#. To know more about SPI protocol clike `here <http://www.google.com/url?q=http%3A%2F%2Fpdp11.byethost12.com%2FAVR%2FArduinoAsProgrammer.htm&sa=D&sntz=1&usg=AFQjCNE7KJzWFBbjRhLtpMYrmUypxO8VHQ>`_

**CAUTION**
  If you are programming with Arduino UNO then use a **10uF** capacitor between RESET and GND of arduino UNO.

#. `Why do you need a capacitor <http://forum.arduino.cc/index.php/topic,104435.0.html>`_

#. To check if connections are proper before burning hex file ,run this command and see that the signature match that of Attiny85 (**0x1e930b**)

	**NOTE** change the port to your port /dev/ttyACM* or /dev/ttyUSB*	

	avrdude -p attiny85 -c arduino -b 19200 -P /dev/ttyACM0 

	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85

	avrdude: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.02s

	avrdude: Device signature = 0x1e930b

	avrdude: safemode: Fuses OK

	avrdude done.  Thank you.


Burning micronucleus.hex and setting fuses
==========================================
**Command to burn the BOOTLOADER**

Go to directory where exists micronucleus-t85 folder and run the following

:command:  avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U  flash:w:"micronucleus-t85-master/firmware/releases/micronucleus-1.06.hex"

	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85

	avrdude: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.02s

	avrdude: Device signature = 0x1e930b

	avrdude: NOTE: FLASH memory has been specified, an erase cycle will be performed
	To disable this feature, specify the -D option.

	avrdude: erasing chip
	
	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85

	avrdude: reading input file "firmware/releases/micronucleus-1.06.hex"

	avrdude: input file firmware/releases/micronucleus-1.06.hex auto detected as Intel Hex

	avrdude: writing flash (8162 bytes):

	Writing | ################################################## | 100% 3.59s

	avrdude: 8162 bytes of flash written

	avrdude: verifying flash memory against firmware/releases/micronucleus-1.06.hex:

	avrdude: load data flash data from input file firmware/releases/micronucleus-1.06.hex:

	avrdude: input file firmware/releases/micronucleus-1.06.hex auto detected as Intel Hex

	avrdude: input file firmware/releases/micronucleus-1.06.hex contains 8162 bytes

	avrdude: reading on-chip flash data:

	Reading | ################################################## | 100% 8.12s

	avrdude: verifying ...

	avrdude: 8162 bytes of flash verified

	avrdude: safemode: Fuses OK

	avrdude done.  Thank you.



**Command to set fuses of the attiny85-20PU**

  avrdude -P /dev/ttyACM0 -b 19200 -c arduino -p t85 -U lfuse:w:0xe1:m -U hfuse:w:0xdd:m -U efuse:w:0xfe:m



	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85

	avrdude: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.02s

	avrdude: Device signature = 0x1e930b

	avrdude: reading input file "0xe1"

	avrdude: writing lfuse (1 bytes):

	Writing | ################################################## | 100% 0.06s

	avrdude: 1 bytes of lfuse written

	avrdude: verifying lfuse memory against 0xe1:

	avrdude: load data lfuse data from input file 0xe1:

	avrdude: input file 0xe1 contains 1 bytes

	avrdude: reading on-chip lfuse data:

	Reading | ################################################## | 100% 0.02s

	avrdude: verifying ...

	avrdude: 1 bytes of lfuse verified

	avrdude: reading input file "0xdd"

	avrdude: writing hfuse (1 bytes):

	Writing | ################################################## | 100% 0.06s

	avrdude: 1 bytes of hfuse written

	avrdude: verifying hfuse memory against 0xdd:

	avrdude: load data hfuse data from input file 0xdd:

	avrdude: input file 0xdd contains 1 bytes

	avrdude: reading on-chip hfuse data:

	Reading | ################################################## | 100% 0.02s

	avrdude: verifying ...

	avrdude: 1 bytes of hfuse verified

	avrdude: reading input file "0xfe"

	avrdude: writing efuse (1 bytes):

	Writing | ################################################## | 100% 0.06s

	avrdude: 1 bytes of efuse written

	avrdude: verifying efuse memory against 0xfe:

	avrdude: load data efuse data from input file 0xfe:

	avrdude: input file 0xfe contains 1 bytes

	avrdude: reading on-chip efuse data:

	Reading | ################################################## | 100% 0.02s

	avrdude: verifying ...

	avrdude: 1 bytes of efuse verified

	avrdude: safemode: Fuses OK

	avrdude done.  Thank you.


**Please Note**
These fuses setting will not enable reset pin (ATTINY85 pin 1) as I/O, so you only have 5 I/O instead of 6 I/O.


After the above two steps are accomplished ,make all the USB connections and follow the next step.
`USB connections <https://github.com/mehtajaghvi/Digispark-on-breadboard/blob/master/Images/digispark_breadboard_bb.jpg>`_



Burn cdc232.hex 
===============
#. Go to micronucleus-t85-master folder downloaded from `here <https://github.com/Bluebie/micronucleus-t85/>`_
#. In /micronucleus-t85-master/commandline/ folder run **make**
#. A **micronucleus** binary is formed 
#. To enumerate digispark as USB device run this command

 sudo ./micronucleus micronucleus-t85-master/commandline/cdc232.hex

**dmesg**

[27858.906553] usb 2-1.2: >new low-speed USB device number 87 using ehci_hcd

[27859.004058] usb 2-1.2: >New USB device found, idVendor=16d0, idProduct=0753

[27859.004068] usb 2-1.2: >New USB device strings: Mfr=0, Product=0, SerialNumber=0


Setting rules in udev to avoid errors
=====================================
#. /etc/udev/rules/49-micronucelus.rules
#. /etc/udec/rules/90-digispark.rules

`Udev Rules<https://github.com/Bluebie/micronucleus-t85/wiki/Ubuntu-Linux>`_ 


ERRORS encountered
==================

#. **Error**
	avrdude: please define PAGEL and BS2 signals in the configuration file for part ATtiny85
	avrdude: AVR device initialized and ready to accept instructions

	Reading | ################################################## | 100% 0.02s

	avrdude: Device signature = 0x000000
	avrdude: Yikes!  Invalid device signature.
		 Double check connections and try again, or use -F to override
		 this check.
#. **Error**
	avrdude: stk500_getparm(): (a) protocol error, expect=0x14, resp=0x14

	avrdude: stk500_getparm(): (a) protocol error, expect=0x14, resp=0x01
	avrdude: stk500_initialize(): (a) protocol error, expect=0x14, resp=0x10
	avrdude: initialization failed, rc=-1
		 Double check connections and try again, or use -F to override
		 this check.
#. **Error**
	If 90-digispark.rules not found in /etc/udev/rules.d/

	Abort mission! -1 error has occured ...
	>> Please unplug the device and restart the program.
#. **Error**
	avrdude: stk500_getsync(): not in sync: resp=0xe0

	avrdude done.  Thank you.

**Caution**
This error occurs if baud rate is not set properly.

#. **Error**
> Please plug in the device ... 
> Press CTRL+C to terminate the program.
If you try to burn cdc232.hex or any other hex file  via arduinoISP or any other ISP programmer the above error occurs.This is because once the bootloader is burn on chip ,the fuses disable the reset pin thus preventing any other hex file to be programmed on chip by an ISP programmer.



===============
Burning Program
===============

#. Board--->Digispark(TinyCore)
#. Programmer--->Digispark
#. Upload 
IDE will ask to plug int the device within sixty seconds	
#. Plug Digispark


==============
Serial Monitor
==============

#. `Digiterm: <http://digistump.com/wiki/digispark/tutorials/digiusb>`_ Digispark Serial Monitor

#. The Digispark integrated arduinoIDE has DigiUSB libraries which has the DigiUSB monitor working like digiterm.



Help LINKS
==========
#.  `Digispark Forum <http://digistump.com/board/index.php>`_

#. `SPI Protocol <http://en.wikipedia.org/wiki/Serial_Peripheral_Interface_Bus>`_

#.
