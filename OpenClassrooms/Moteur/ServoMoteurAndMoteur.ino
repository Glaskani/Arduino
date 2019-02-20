// Moteur
// ENA 1  2
//  0  *  * Arret
//  1  0  0 Pause
//  1  0  1 Horaire
//  1  1  0 AntiHoraire
//  1  1  1 Pause
// ENB 4  3
//  0  *  * Arret
//  1  0  0 Pause
//  1  0  1 Horaire
//  1  1  0 AntiHoraire
//  1  1  1 Pause

// ServoMoteur
// Orange Pin
// Red 5V
// Black GND

#include <Servo.h> // bibliothèque Servo
int pinServo = 1; // variable pour stocker le pin pour la commande
Servo leServo; // on définit un objet Servo nommé leServo

int pinMoteur1 = 2;
int pinMoteur2 = 3;

void setup() {
  //servo
  leServo.attach(pinServo); // on relie l'objet au pin de commande
  //moteur
  pinMode(pinMoteur1,OUTPUT);
  pinMode(pinMoteur2,OUTPUT);
}

void loop() {
  //servo moteur
  leServo.write(0); // on dit à l'objet de mettre le servo à 0°
  delay(1000);
  leServo.write(90); // position à 179, 180 est à éviter car cela forcerait le servo à dépasser ses limites
  delay(1000);
  //moteur
  digitalWrite(pinMoteur1,HIGH);
  digitalWrite(pinMoteur2,LOW);
}
