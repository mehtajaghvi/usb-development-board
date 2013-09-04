===============
Anuduino Kicad 
===============

Kicad libraries
---------------

The .lib file contains the schematic symbols and the .mod file contains footprints.You can extract the file to wherever you like. Just remember to tell eeschema and cvpcb where those files are.These two files have been added for USB-A-PCB module to be directly etched on PCB.
 #. To copy the files to /use/share/kicad/ you need root permissions.

 #. Copy the Sparkfun.lib from kicad_lib_mod folder to /usr/share/kicad/library

 #. Copy the Sparkfun.mod from kicad_lib_mod folder to /use/share/kicad/modules

 #. Now to add the library file in your project go to Eeschema-->Preferences-->Library-->Add-->Sparkfun.lib

 #. Now to add the module file to project go to Cvpcb-->Preferences-->library-->Add-->Sparkfun.mod


Desgin your PCB
---------------

* Anuduino is single layer PCB board.All its connections are on **front** side.It has been possible because most of the components are placed at back and few in front. 

.. warning :: your circuit needs to be printed on FRONT side.If by mistake you print it back all your efforts will be wasted as when you insert a USB GND has to match to GND ,VCC to VCC and so on... Printing on the back will reverse the GND and VCC and the PCB will be rendered useless.
* You just need tp print the anuduino-Front.ps 

* Or if you are generating your own ps files ,remember to plot **negative** plot for printing.

  .. image:: images/cad.png
      :scale: 250%	
      :height: 50 	
      :width: 50

* Once you have the PCB. Open the getting_started.rst in doc folder.It contains detailed explanation of what all you need and how you have to proceed further.



