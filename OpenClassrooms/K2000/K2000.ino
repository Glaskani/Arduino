// declaration des leds
int pinLed[5]={2,3,4,5,6};

void setup() {
  for (int i=0;i<5;i++) {
    pinMode(pinLed[i],OUTPUT);
    digitalWrite(pinLed[i],LOW);
  }
}

void loop() {
  for (int i=0;i<5;i++) {// left to the right
    if (i != 5)
      digitalWrite(pinLed[i],1);
    if (i != 0)
      digitalWrite(pinLed[i-1],0);
    delay(100);
  }
  for (int i=4;i>=0;i--) {// right to the left
    if (i != -1)
      digitalWrite(pinLed[i],1);
    if (i != 6)
      digitalWrite(pinLed[i+1],0);
    delay(100);
  }
}
