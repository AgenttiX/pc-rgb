#include "FastLED.h"

#define START_PIN 1
#define NUM_PINS 10
#define LED_APA102 1
#define LED_WS2812 2

struct ledCommand {
  bool draw;
  unsigned char channel;
  unsigned char led;
  unsigned char r;
  unsigned char g;
  unsigned char b;
} ledCommand;

struct setupCommand {
  unsigned char channel;
  unsigned char led_type;
  unsigned char led_count;
} setupCommand;

CRGB* leds[NUM_PINS];

void setup() {
  Serial.begin(115200);
  bool setupReady = false;
  while (! setupReady) {
    const bool success = Serial.readBytes((char*)(&setupCommand), sizeof(setupCommand)) == sizeof(setupCommand);
    if (success) {
      leds[setupCommand.channel] = malloc(sizeof(CRGB)*setupCommand.led_count);
      if (setupCommand.led_type == LED_WS2812) {
        // Todo: implement a way to set the pins properly
        FastLED.addLeds<NEOPIXEL, START_PIN + setupCommand.channel>(leds[setupCommand.channel], setupCommand.led_count);
      }
    }
  }
}

void loop() {
  const bool success = Serial.readBytes((char*)(&ledCommand), sizeof(ledCommand)) == sizeof(ledCommand);
  if (success) {
    leds[ledCommand.channel][ledCommand.led] = CRGB(ledCommand.r, ledCommand.g, ledCommand.b);
    if (ledCommand.draw) {
      FastLED.show();
    }
  }
}
