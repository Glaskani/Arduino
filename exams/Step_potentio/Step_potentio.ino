#include <Stepper.h>

const int stepsPerRevolution = 48 * 64; // nombre de step

Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);// lier l'objet my stepper à la bibliotheque
void setup()
{
  myStepper.setSpeed(10); // vitesse moteur
}

void loop() 
{
  // read the sensor value:
  int sensorReading = analogRead(A0);// on lit la valeur sur le potentiometre
  int pos = map(sensorReading, 0, 1023, 0, 3); //mapper pour aller a gauche ou droite
  switch (pos)
  {
    case 0:
      myStepper.step(10); // faire + 10 pas
      break;
    case 1:
      myStepper.step(0);
      break;
    case 2:
      myStepper.step(-10); // faire - 10 pas
      break;
  }
}
