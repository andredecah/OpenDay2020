int analogInPin1 = A0;
int sensorValue1 = 0;
int analogInPin2 = A1;
int sensorValue2 = 0;
 
void setup() {
  Serial.begin(9600);
  pinMode(analogInPin1, INPUT);
  pinMode(analogInPin2, INPUT);
}
 
void loop() {
  sensorValue1 = analogRead(analogInPin1);  
  sensorValue2 = analogRead(analogInPin2);          
 
  Serial.print("sensor1 = " );
  Serial.println(sensorValue1);
  Serial.print("sensor2 = " );
  Serial.println(sensorValue2);
        
 
  delay(1000);
}
