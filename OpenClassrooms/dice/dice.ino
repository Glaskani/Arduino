// declaration of the led and button
int pinLed[5] = {2,3,4,5,6};
int pinButton = 7;

int show[5][5] = {0,0,1,0,0, //1
                  1,0,0,0,1, //2
                  1,0,1,0,1, //3
                  1,1,0,1,1, //4
                  1,1,1,1,1}; //5

void setup() {
  pinMode(pinButton,INPUT_PULLUP);
  for (int i=0;i<5;i++) {
    pinMode(pinLed[i],OUTPUT);
  }
  OffLed();
}

void loop() {
  boolean stateBouton = digitalRead(pinButton);
  if (stateBouton==LOW)
    OnLed();
  delay(200);
}

//chose some rand number and show it, repeat it 10 times
void OnLed() {
  int number[10];
  int del = 2000;
  for (int i=0;i < 10 ;i++) {
    number[i] = random(0, 4); // a number between 0 and 4 so 1 and 5
    for (int j=0;j < 5 ;j++) {
      digitalWrite(pinLed[j], show[number[i]][j]); // take the corect show
    }
    delay(del);
    del -= 300;
    OffLed();
  }
}

//Turn off all the led
void OffLed() {
  for (int i=0;i<5;i++) {
    digitalWrite(pinLed[i],LOW);
  }
}
