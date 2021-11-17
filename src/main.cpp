#include <Arduino.h>
#include <Stepper.h>

Stepper focus(2,4,3,5,10);
Stepper zoom(15,16,14,10,10);

void setup() {
  Serial.begin(115200);

}


void loop() {
  // put your main code here, to run repeatedly:
  int read = Serial.read();
  if (read == '1') {
    focus.step(false);
  } else if (read == '2') {
    focus.step(true);
  } else if (read == '3') {
    zoom.step(false);
  } else if (read == '4') {
    zoom.step(true);
  }

   
}