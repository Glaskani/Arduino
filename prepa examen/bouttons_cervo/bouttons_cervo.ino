#include <Servo.h> //import de la bibliothèque Servo
Servo accel; //création de l'objet Servo "accel"
int pinServo = 8; //pin de commande du servo
int pinBouton = 2; //pin de lecture du bouton poussoir
int pinBoutonD = 3;// pin de lecture deceleration
int cumul = 0; //variable d'appui
int angle = 0;

void setup() {
  pinMode(pinBouton, INPUT_PULLUP); //mode INPUT_PULLUP pour le poussoir
  pinMode(pinBoutonD, INPUT_PULLUP);//mode input_pullup
  accel.attach(pinServo); //liaison de l'objet Servo au pin de commande
  Serial.begin(9600);//pour lecture sur la console (Optionnel)
}
void loop() {
  boolean etatBouton = digitalRead(pinBouton); //lecture de l'état du bouton
  boolean etatBoutonD = digitalRead(pinBoutonD); //lecture de l'état du boutonD(eceleration)

  if (!etatBouton && cumul < 10000) // en mode INPUT_PULLUP on obtien 0 quand on appuie !
  { 
    cumul++; // on fait augmenter la valeur de la variable

  }
    if (!etatBoutonD && cumul > 0) // en mode INPUT_PULLUP on obtien 0 quand on appuie !
  { 
    cumul--; // on fait augmenter la valeur de la variable

  }

 /* else {
    cumul--; //on fait diminuer la valeur de la variable
    if (cumul < 0) //test si limite de diminution
      cumul = 0; //mise à la limite si dépassement
  }
  */
   angle = map(cumul, 0, 10000, 0, 179);
  accel.write(angle); //on place le servo à la position angle

}
