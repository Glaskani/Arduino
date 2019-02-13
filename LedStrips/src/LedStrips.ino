#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

Adafruit_NeoPixel strip_a = Adafruit_NeoPixel(37, 6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip_b = Adafruit_NeoPixel(35, 7, NEO_GRB + NEO_KHZ800);

void setup() {
  //Strip
  strip_a.begin();
  strip_a.setBrightness(255);
  strip_a.show(); // Initialize all pixels to 'off'

  //Strip 2
  strip_b.begin();
  strip_b.setBrightness(255);
  strip_b.show(); // Initialize all pixels to 'off'
}

void loop() {
  uint16_t i;
  for(i=0; i< strip_a.numPixels()+5; i++) {
     strip_a.setPixelColor(i-5, 30, 30, 30);
     strip_a.setPixelColor(i, 255, 0, 0);
     strip_a.show();
     delay(120);
  }

  /*for(i=0; i< strip_b.numPixels()+5; i++) {
     strip_b.setPixelColor(i-5, 30, 30, 30);
     strip_b.setPixelColor(i, 255, 0, 0);
     strip_b.show();
     delay(120);
  }*/
  
  //colorWave(strip_a, 120, 5, strip_a.Color(30, 30, 30), strip_a.Color(255, 0, 0));
  //colorWave(strip_b, 120, 5, strip_b.Color(30, 30, 30), strip_b.Color(255, 0, 0));
  //allWhite(strip_a);
  //allWhite(strip_b);
  //allBlack(strip_a);
  //allBlack(strip_b);
}

void allBlack(Adafruit_NeoPixel strip) {
  uint16_t i;
  for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, 0, 0, 0);
      strip.show();
  }
}

void allWhite(Adafruit_NeoPixel strip) {
  uint16_t i;
  for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, 60, 60, 60);
      strip.show();
  }
}

void colorWave(Adafruit_NeoPixel strip, uint8_t wait, uint8_t lengthColor, uint32_t backColor, uint32_t waveColor) {
  uint16_t i;
  for(i=0; i< strip.numPixels()+lengthColor; i++) {
     strip.setPixelColor(i-lengthColor, backColor);
     strip.setPixelColor(i, waveColor);
     strip.show();
     delay(wait);
  }
}

void nightStar(Adafruit_NeoPixel strip, uint8_t wait, uint8_t maxAtTime, uint32_t backColor, uint32_t starColor) {
  uint16_t i, j, temp, temp2;
  for(i=0; i< maxAtTime; i++) {
    strip.setPixelColor(temp, 0, 0, 0);
    strip.setPixelColor(temp2, 0, 0, 0);
    temp = random(0,strip.numPixels()-1);
    temp2 = random(0,strip.numPixels()-1);
    strip.setPixelColor(temp, starColor);
    strip.setPixelColor(temp2, starColor);
    strip.show();
    delay(wait);
    strip.setPixelColor(temp, backColor);
    strip.setPixelColor(temp2, backColor);
    strip.show();
    delay(wait);
  }
}

void colorFade(Adafruit_NeoPixel strip, uint32_t obj_col, uint8_t n, uint8_t wait) {
  uint8_t obj_r, obj_g, obj_b;
  obj_b = obj_col & 0xFF; obj_g = (obj_col >> 8) & 0xFF; obj_r = (obj_col >> 16) & 0xFF;
  uint8_t curr_r, curr_g, curr_b;
  uint32_t curr_col = strip.getPixelColor(n); // get the current colour
  curr_b = curr_col & 0xFF; curr_g = (curr_col >> 8) & 0xFF; curr_r = (curr_col >> 16) & 0xFF;  // separate into RGB components

  while ((curr_r != obj_r) || (curr_g != obj_g) || (curr_b != obj_b)){  // while the curr color is not yet the target color
    if (curr_r < obj_r) curr_r++; else if (curr_r > obj_r) curr_r--;
    if (curr_g < obj_g) curr_g++; else if (curr_g > obj_g) curr_g--;
    if (curr_b < obj_b) curr_b++; else if (curr_b > obj_b) curr_b--;
    strip.setPixelColor(n, curr_r, curr_g, curr_b);
    strip.show();
    delay(wait);
  }
}
