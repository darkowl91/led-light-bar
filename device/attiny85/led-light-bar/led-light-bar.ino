/*
    Smart LED Controller based on ATTINY85 Digispark USB
    Board Manager: https://raw.githubusercontent.com/ArminJo/DigistumpArduino/master/package_digistump_index.json

    PINS:
    * P0 - Photo-resistor input
    * P1 - LED output
    * P2 - Button input
*/

#include <Adafruit_NeoPixel.h>

#define BUTTON_PIN          2
#define LED_PIN             1
#define LED_COUNT           7
#define PHOTO_RESISTOR_PIN  0

Adafruit_NeoPixel led_bar = Adafruit_NeoPixel(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PHOTO_RESISTOR_PIN, INPUT);

  led_bar.begin();
}

void loop() {
}
