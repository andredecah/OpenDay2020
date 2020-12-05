#include <Stepper.h> //Libreria per motorino

Stepper motorino(2048, 11, 10, 9, 8); //Creo il motorino

int fotosensoreSX = A0; //fotoresistenza sinistra
int fotosensoreDX = A1; //fotoresistenza destra

int luminositaSX; //Il valore letto dalla fotoresistenza sinistra
int luminositaDX; //Il valore letto dalla fotoresistenza destra
 
void setup() {
  
  Serial.begin(9600);
  motorino.setSpeed(30); //Velocità usata dal motorino
  pinMode(fotosensoreSX, INPUT); //La fotoresistenza legge
  pinMode(fotosensoreDX, INPUT); //La fotoresistenza legge
  
}
 
void loop() {

  float gradi = 90; //Creo una variabile per rimappare i gradi a 90
  gradi = map(gradi, 0, 360, 0, 2048); //Li rimappo
  
  luminositaSX = analogRead(fotosensoreSX); //Lettura della luminosità della fotoresistenza di sinistra
  luminositaDX = analogRead(fotosensoreDX); //Lettura della luminosità della fotoresistenza di destra

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
  
} 

//Metodo sinistra
void Sinistra()
{
  //Rimetto i gradi anche nella funzione
  float gradi = 90;
  gradi = map(gradi, 0, 360, 0, 2048);
  //Giro verso sinistra di 90 gradi
  motorino.step(-gradi);
}


void Destra()
{
  //Rimetto i gradi anche nella funzione
  float gradi = 90;
  gradi = map(gradi, 0, 360, 0, 2048);
  //Giro verso destra di 90 gradi
  motorino.step(gradi);
}
