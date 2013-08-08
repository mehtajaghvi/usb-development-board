#include <DigiUSB.h>
#define TEMP 1   //using PB2 as analog INPUT
#define SENSE 0 //using PB5 as analog INPUT

void setup() {
  DigiUSB.begin();
  pinMode(2, INPUT);
  pinMode(5,INPUT);  
}

void returnTemp( int degree ){
  int readValue = analogRead(TEMP);
  float celsius;
  float fahrenheit;

celsius=readValue*(5.0/1024.0); //converting voltage to corresponding temp value
  celsius=celsius*100;//
 fahrenheit = (1.8 * celsius) + 32;  

  if ( degree == 1 ){
    DigiUSB.print(celsius);
    DigiUSB.println("C");
  }
  if ( degree == 2 ){
    DigiUSB.print(fahrenheit);
    DigiUSB.println("F");
  }
 
}
void returnDist(int sense){
   int sensorValue=analogRead(SENSE);
 sense=3;
  if(sensorValue>=400)
  { DigiUSB.print(sesnorValue);
    DigiUSB.println("whitesurface");
    }
    else 
    
  { DigiUSB.print(sesnorValue); 
    DigiUSB.println("blacksurface");
  }
  



}

void get_input() {
  int lastRead;
  while (true) { // loop forever
    if (DigiUSB.available()) {
      // something to read
      lastRead = DigiUSB.read();
      if (lastRead == '1'){
        // Return temperature in celsius
        returnTemp(1);
      }
      if (lastRead == '2'){
        // Return temperature in fahrenheit
        returnTemp(2);
      }
            if (lastRead == '3'){
        // Return temperature in fahrenheit
        returnDist(3);
      }
            if (lastRead == '4'){
        // Return temperature in fahrenheit
        returnTemp(4);
      }
      if (lastRead == '\n') {
        break; // when we get a newline, break out of loop
      }
    }
    
    // refresh the usb port for 10 milliseconds
    DigiUSB.delay(10);
  }
}


void loop() {
  DigiUSB.refresh();
  get_input();
}
