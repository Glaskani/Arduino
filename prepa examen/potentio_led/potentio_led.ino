int pinPot=0; //position potentiometre sur pin analogique
int valPot = 0;// valeur du signale analogique
int led_allumee=0; //choisir la led à alumer
int ledJ=2; //position led
int ledR=3;
int ledB=4;
void setup() {
  Serial.begin(9600); //parler avec la console
  pinMode(ledJ,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(ledB,OUTPUT);
}

void loop() {
  valPot = analogRead(pinPot);// lecture de la valeur analogique du potentiometre
  led_allumee = map(valPot,0,1023,0,2); //assigner le mappage (de valpo qui est entre 0--1023) entre 0--2
  
switch(led_allumee){
  case 0:
  digitalWrite(ledJ,HIGH);
  digitalWrite(ledR,LOW);
  digitalWrite(ledB,LOW);
  break;
  case 1:
  digitalWrite(ledR,HIGH);
  digitalWrite(ledJ,LOW);
  digitalWrite(ledB,LOW);
  break;
  case 2:
  digitalWrite(ledB,HIGH);
  digitalWrite(ledJ,LOW);
  digitalWrite(ledR,LOW);
  break;
  
}
}
