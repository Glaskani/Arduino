#include <Stepper.h> // bibli stepper
int pinBouton = 2; //pin de lecture du bouton rotation +
int pinBoutonD = 3;// pin de lecture rotation-

int nombreDePas = 48 * 64; // nombre de pas
Stepper monMoteur(nombreDePas, 8, 10, 9, 11);

void setup()
{
  pinMode(pinBouton, INPUT_PULLUP); //mode INPUT_PULLUP pour le poussoir
  pinMode(pinBoutonD, INPUT_PULLUP);//mode input_pullup
  monMoteur.setSpeed(10);

}

void loop()
{
  boolean etatBouton = digitalRead(pinBouton); //lecture de l'état du bouton
  boolean etatBoutonD = digitalRead(pinBoutonD); //lecture de l'état du boutonD(eceleration)

  if (!etatBouton ) // en mode INPUT_PULLUP on obtien 0 quand on appuie !
  {
    monMoteur.step(100); 

  }
  if (!etatBoutonD ) // en mode INPUT_PULLUP on obtien 0 quand on appuie !
  {
    monMoteur.step(-100); 
  }


}
