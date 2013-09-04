#include <DigiUSB.h>
#define TEMP 1         //using PB2 as analog INPUT

void setup() {
  DigiUSB.begin();
  pinMode(2, INPUT);
  
}

void returnTemp( int degree ){
  //int readValue = analogRead(TEMP);
  float celsius;
 int sample;
 int ten_samples;
 
   for (sample = 0; sample < 29; sample++) {
        // convert A0 value to temperature
        celsius = ((float)analogRead(TEMP) * 5.0 / 1024.0);
        celsius = celsius / 0.01;
        // sample every .102 seconds
        delay(100);
        // sum of all samples
        ten_samples = ten_samples + celsius;
        DigiUSB.refresh();
       
    }

    celsius = ten_samples / 30.0;
 
  if ( degree == 1 ){
    DigiUSB.print(celsius);
    DigiUSB.println("C");
    DigiUSB.delay(10);
  
}
  }
  

void loop() {
  
returnTemp(1);
 DigiUSB.delay(990);

}
