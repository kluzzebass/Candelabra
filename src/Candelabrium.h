
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



class Candelabrium
{
public:
	Candelabrium() {};

	void setup();
	void loop();

private:
	LongPressButton button1 = LongPressButton(BUTTON1_PIN, DEBOUNCE_DELAY, HOLD_TIME);
	LongPressButton button2 = LongPressButton(BUTTON2_PIN, DEBOUNCE_DELAY, HOLD_TIME);
	Adafruit_NeoPixel strip = Adafruit_NeoPixel(LED_COUNT, STRIP_PIN, NEO_GRB + NEO_KHZ800);

	unsigned long lastTime = 0;

	uint8_t brightness = 6;
	uint8_t currentEffect = 1; 

	bool on = true;

	Color priBuf[LED_COUNT];
	Color secBuf[LED_COUNT];

	Effect *off = new EffectOff(map1);

	Effect *effects[6] = {
		new EffectColorCycle(map1),
		new EffectColorCycle(map2),
		new EffectColorCycle(map3),
		new EffectColorCycle(map4),
		new EffectColorCycle(map5),
		new EffectColorCycle(map6)
	};
	

	Effect *priFx = nullptr;
	Effect *secFx = nullptr;

	void changeBrightness();
	void togglePower();

};


#endif // _Candelabrium_h_