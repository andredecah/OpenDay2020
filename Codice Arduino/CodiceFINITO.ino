#include <Servo.h>
#define PINSERVO 6

Servo motorino;

int differenza;
int angolo;
int sensorValue1;
int sensorValue2;
int sensorLow = 1023;
int sensorHigh = 0;
int posizione;

void setup() {

  Serial.begin(9600);
  while(millis()<5000){
    motorino.attach(PINSERVO);
    sensorValue1 = analogRead(A0);
    sensorValue2 = analogRead(A1);

    if(sensorValue1 > sensorHigh)
    {
      sensorHigh = sensorValue1;
    }

    if(sensorValue1 < sensorLow)
    {
      sensorLow = sensorValue1;
    }

    if(sensorValue2 > sensorHigh)
    {
      sensorHigh = sensorValue2;
    }

    if(sensorValue2 < sensorLow)
    {
      sensorLow = sensorValue2;
    }
    
  }

}

void loop() {
  
  sensorValue1 = analogRead(A0);
  sensorValue2 = analogRead(A1);

  differenza = sensorValue1 - sensorValue2;

  //posizione = motorino.read();

  angolo = map(differenza, -100,100,0,179);
  Serial.println(angolo);

  motorino.write(angolo);
  delay(15);
}
