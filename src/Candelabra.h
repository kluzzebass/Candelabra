
#ifndef CANDELABRA_H
#define CANDELABRA_H

#include <Arduino.h>
#include <Debouncer.h>
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#include <avr/power.h>

#define BUTTON1_PIN 9
#define BUTTON2_PIN 10
#define STRIP_PIN 6
#define LED_COUNT 33
#define DEBOUNCE_DELAY 1000
#define BRIGHTNESS_LEVELS 9

const uint8_t brightnessLevels[BRIGHTNESS_LEVELS] PROGMEM = {
	255, 223, 191, 159, 127, 95, 63, 31, 0
};

const uint8_t seq1[LED_COUNT] PROGMEM = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32 
};

const uint8_t seq2[LED_COUNT] PROGMEM = {
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31
};

const uint8_t seq3[LED_COUNT] PROGMEM = {
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};

const uint8_t seq4[LED_COUNT] PROGMEM = {
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
	31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1
};

const uint8_t seq5[LED_COUNT] PROGMEM = {
	31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1,
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};


class Candelabra
{
public:
	Candelabra();

	void setup();
	void loop();

private:
	Debouncer btn1 = Debouncer();
	Debouncer btn2 = Debouncer();
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);
	uint8_t brightness = 0;

	void changeBrightness();


};


#endif // CANDELABRA_H