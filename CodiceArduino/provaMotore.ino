#include <Stepper.h>
Stepper myStepper(2048, 11, 10, 9, 8);
void setup() {
  myStepper.setSpeed(10);
}
void loop() {
  float gradi = 90;
  gradi = map(gradi, 0, 360, 0, 2048);
  myStepper.step(gradi);
  delay(1000);
  myStepper.step(-gradi);
  delay(1000);
}
