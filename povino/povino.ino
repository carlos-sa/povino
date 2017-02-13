int led_infra = 2;
#include <Adafruit_NeoPixel.h>
#include "WS2812_Definitions.h"

#define PIN 4
#define LED_COUNT 8
// Create an instance of the Adafruit_NeoPixel class called "leds".
// That'll be what we refer to from here on...

#define delay_time 3

Adafruit_NeoPixel leds = Adafruit_NeoPixel(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  pinMode(led_infra, INPUT_PULLUP);
  leds.begin();  // Call this to start up the LED strip.
  clearLEDs();   // This function, defined below, turns all LEDs off...
  leds.show();   // ...but the LEDs don't actually update until you call this.
}

void loop() {
  while(digitalRead(led_infra)){
    leds.setPixelColor(7, BLACK);
    leds.setPixelColor(6, BLACK);
    leds.setPixelColor(5, BLACK);
    leds.setPixelColor(4, BLACK);
    leds.setPixelColor(3, BLACK);
    leds.setPixelColor(2, BLACK);
    leds.setPixelColor(1, BLACK);
    leds.setPixelColor(0, BLACK);
    leds.show();
  }
  for (int i=0; i<8; i++){
    drawCollum(i);
  }
}

// Sets all LEDs to off, but DOES NOT update the display;
// call leds.show() to actually turn them off after this.
void clearLEDs()
{
  for (int i=0; i<LED_COUNT; i++)
  {
    leds.setPixelColor(i, 0);
  }
}

void drawCollum(int number){
  leds.setPixelColor(7, BLACK);
  leds.setPixelColor(6, BLACK);
  leds.setPixelColor(5, BLACK);
  leds.setPixelColor(4, BLACK);
  leds.setPixelColor(3, BLACK);
  leds.setPixelColor(2, BLACK);
  leds.setPixelColor(1, BLACK);
  leds.setPixelColor(0, BLACK);
  leds.setPixelColor(number, YELLOW);
  leds.show();
  delay(1);
  leds.setPixelColor(7, BLACK);
  leds.setPixelColor(6, BLACK);
  leds.setPixelColor(5, BLACK);
  leds.setPixelColor(4, BLACK);
  leds.setPixelColor(3, BLACK);
  leds.setPixelColor(2, BLACK);
  leds.setPixelColor(1, BLACK);
  leds.setPixelColor(0, BLACK);
  leds.show();
  delayMicroseconds(500);
  }
