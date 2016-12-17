
#ifndef _Candelabrium_h_
#define _Candelabrium_h_

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>
#include <avr/power.h>
#include <LongPressButton.h>
#include <Effect.h>
#include <EffectOff.h>
#include <EffectColorCycle.h>
#include <EffectChase.h>
#include <EffectTwinkle.h>
#include <EffectTheaterChase.h>

#include <defs.h>

const uint8_t brightnessLevels[BRIGHTNESS_LEVELS] = {
	255, 223, 191, 159, 127, 95, 63, 31
};

const uint8_t map1[LED_COUNT] = {
	0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32 
};

const uint8_t map2[LED_COUNT] = {
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31
};

const uint8_t map3[LED_COUNT] = {
	1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31,
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};

const uint8_t map4[LED_COUNT] = {
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
	31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1
};

const uint8_t map5[LED_COUNT] = {
	31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1,
	0, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32
};

const uint8_t map6[LED_COUNT] = {
	16, 14, 18, 12, 20, 10, 22, 8, 24, 6, 26, 4, 28, 2, 30, 0, 32,
	1, 31, 3, 29, 5, 27, 7, 25, 9, 23, 11, 21, 13, 19, 15, 17
};

const uint8_t map7[LED_COUNT] = {
	0, 32, 1, 31, 2, 30, 3, 29, 4, 28, 5, 27, 6, 26, 7, 25, 8, 24,
	9, 23, 10, 22, 11, 21, 12, 20, 13, 19, 14, 18, 15, 17, 16
};


#ifdef GAMMA_CORRECTION
const uint8_t PROGMEM gamma[] = {
	  0,   1,   1,   1,   1,   1,   1,   1,   2,   2,   2,   2,   2,   2,   2,   2,
	  2,   3,   3,   3,   3,   3,   3,   3,   4,   4,   4,   4,   4,   4,   5,   5,
	  5,   5,   5,   6,   6,   6,   6,   6,   7,   7,   7,   7,   8,   8,   8,   8,
	  9,   9,   9,   9,  10,  10,  10,  11,  11,  11,  12,  12,  12,  13,  13,  13,
	 14,  14,  15,  15,  15,  16,  16,  17,  17,  17,  18,  18,  19,  19,  20,  20,
	 21,  21,  22,  22,  23,  23,  24,  24,  25,  25,  26,  26,  27,  27,  28,  29,
	 29,  30,  30,  31,  32,  32,  33,  34,  34,  35,  36,  36,  37,  38,  38,  39,
	 40,  41,  41,  42,  43,  44,  44,  45,  46,  47,  48,  48,  49,  50,  51,  52,
	 53,  54,  54,  55,  56,  57,  58,  59,  60,  61,  62,  63,  64,  65,  66,  67,
	 68,  69,  70,  71,  72,  73,  74,  75,  77,  78,  79,  80,  81,  82,  84,  85,
	 86,  87,  88,  90,  91,  92,  93,  95,  96,  97,  98, 100, 101, 102, 104, 105,
	107, 108, 109, 111, 112, 114, 115, 116, 118, 119, 121, 122, 124, 125, 127, 129,
	130, 132, 133, 135, 137, 138, 140, 141, 143, 145, 146, 148, 150, 152, 153, 155,
	157, 159, 160, 162, 164, 166, 168, 170, 171, 173, 175, 177, 179, 181, 183, 185,
	187, 189, 191, 193, 195, 197, 199, 201, 203, 205, 207, 209, 212, 214, 216, 218,
	220, 223, 225, 227, 229, 232, 234, 236, 238, 241, 243, 245, 248, 250, 253, 255
};
#endif

class Candelabrium
{
public:
	Candelabrium() {};

	void setup();
	void loop();

protected:
	LongPressButton button1 = LongPressButton(BUTTON1_PIN, DEBOUNCE_DELAY, HOLD_TIME);
	LongPressButton button2 = LongPressButton(BUTTON2_PIN, DEBOUNCE_DELAY, HOLD_TIME);
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);

	unsigned long lastTime = 0;

	uint8_t brightness = 0;

	bool on = true;

	bool cycling = true;

	uint8_t currentEffect = 0; 

	bool transitioning = false;
	unsigned long now = 0;
	unsigned long transitionStart = 0;

	uint8_t currentBuffer = 1;
	Color buffers[BUFFERS][LED_COUNT];

	Effect *off = new EffectOff(map1);

	Effect *effects[7] = {
		new EffectTheaterChase(map4),
		new EffectTwinkle(map1), // Doesn't actually use a map.
		new EffectChase(map4),
		new EffectChase(map6),
		new EffectColorCycle(map1),
		new EffectColorCycle(map6),
		new EffectColorCycle(map7)
	};

	uint8_t fxCount = sizeof(effects) / sizeof(effects[0]);

	Effect *priFx = nullptr;
	Effect *secFx = nullptr;

	void changeBrightness();
	void togglePower();
	void startTransition();
};


#endif // _Candelabrium_h_