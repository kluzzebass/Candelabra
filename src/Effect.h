
#ifndef _Effect_h_
#define _Effect_h_

#include <Adafruit_NeoPixel.h>
#include <Color.h>

#include <defs.h>

class Effect
{
public:
	Effect(const uint8_t (&map)[LED_COUNT]) : map(map) {}
	virtual void init(Color *buffer) = 0;
	virtual bool update() = 0;

	Color *buffer = nullptr;

protected:
	const uint8_t (&map)[LED_COUNT];
	bool reverse = false;

	unsigned long lastTime = 0;
	uint16_t effectDelay = 100;

	const uint16_t colorsPerSegment = 255;

	// Cyclic color sequencer with or without white
	Color colorSequence(int, bool);
	uint16_t sequenceLength(bool includeWhite);

	bool timeForUpdate();
};

#endif // _Effect_h_