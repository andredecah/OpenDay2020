#include <Servo.h> //Libreria per motorino

Servo motorino; //Il nome del servo è motorino

int fotosensoreSX = A0; //fotoresistenza sinistra
int fotosensoreDX = A1; //fotoresistenza destra

float luminositaSX; //Il valore letto dalla fotoresistenza sinistra
float luminositaDX; //Il valore letto dalla fotoresistenza destra
 
void setup() {
  
  Serial.begin(9600);
  motorino.attach(9); //Il Servo1 è collegato al pin digitale 9
  pinMode(fotosensoreSX, INPUT); //La fotoresistenza legge
  pinMode(fotosensoreDX, INPUT); //La fotoresistenza legge
  motorino.write(0);  //Imposto la posizione da cui parte il motorino
  
}
 
void loop() {

  delay(2000);
  luminositaSX = analogRead(fotosensoreSX); //Lettura della luminosità della fotoresistenza di sinistra
  Serial.print("LuminositaSX: ");
  Serial.println(luminositaSX);
  luminositaDX = analogRead(fotosensoreDX); //Lettura della luminosità della fotoresistenza di destra
  Serial.print("LuminositaDX: ");
  Serial.println(luminositaDX);

  //Se il fotosensore di sinistra rileva più luce di quella di destra
  if (luminositaSX > luminositaDX) 
  {
    //Il motorino gira verso sinistra
    Sinistra();
  }

  //Se il fotosensore di sinistra rileva più luce di quella di destra
  else if (luminositaDX > luminositaSX)
  {
    //Il motorino gira verso destra
    Destra();
  }

  //Se sono uguali
  else if (luminositaDX == luminositaSX)
  {
    //Torna in centro
    Uguale();
  }
  
} 

//Metodo sinistra
void Sinistra()
{
  int leggiSX;
  int spostaSX;
  leggiSX = motorino.read(); //Leggo la posizione in gradi del motorino
  spostaSX = 90 - leggiSX; //Calcolo di quanto spostarlo
  motorino.write(-spostaSX); //Lo sposto verso sinistra
}

//Metodo destra
void Destra()
{
  int leggiDX;
  int spostaDX;
  leggiDX = motorino.read(); //Leggo la posizione in gradi del motorino
  spostaDX = 90 - leggiDX; //Calcolo di quanto spostarlo
  motorino.write(spostaDX); //Lo sposto verso destra
} 

//Metodo uguale
void Uguale()
{
  motorino.write(0); //Torna al centro
}
