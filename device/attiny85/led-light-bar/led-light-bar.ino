/*
    Smart LED Controller based on ATTINY85 Digispark USB
    Board Manager: https://raw.githubusercontent.com/ArminJo/DigistumpArduino/master/package_digistump_index.json

    PINS:
    * P0 - Photo-resistor input
    * P1 - LED output
    * P2 - Button input
*/

#include <OneButton.h>
#include <FastLED.h>

#define BUTTON_PIN          2
#define LED_PIN             1
#define NUM_LEDS            7
#define PHOTO_RESISTOR_PIN  0
#define LED_TYPE            WS2812

OneButton button(BUTTON_PIN, false);
CRGB leds[NUM_LEDS];


void setup()
{
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
  pinMode(PHOTO_RESISTOR_PIN, INPUT);

  button.attachClick(buttonClick);
  button.attachDoubleClick(buttonDoubleClick);

  FastLED.addLeds<LED_TYPE, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(getBrightness());
}

void loop()
{
  button.tick();
}

int getBrightness()
{
  int resistor_value = analogRead(PHOTO_RESISTOR_PIN);
  return map(resistor_value, 0, 1023, 0, 255);
}

void buttonClick()
{
  FastLED.setBrightness(getBrightness());
  fill_rainbow(leds, NUM_LEDS, 0, 40);
  FastLED.show();
}

// Turn off the LED
void buttonDoubleClick()
{
  FastLED.clear(true);
}
