
#ifndef _Effect_h_
#define _Effect_h_

#include <Adafruit_NeoPixel.h>
#include <Color.h>

#include <defs.h>

class Effect
{
public:
	Effect(const uint8_t (&map)[LED_COUNT], bool reverse) : map(map), reverse(reverse) {}
	virtual void init(Color *buffer, int bufferSize);
	virtual void update();


protected:
	const uint8_t (&map)[LED_COUNT];
	uint8_t bufferSize;
	Color *buffer = nullptr;
	bool reverse = false;

	const uint16_t colorsPerSegment = 255;

	// Cyclic color sequencer with or without white
	Color colorSequence(int, bool);
	uint16_t sequenceLength(bool includeWhite);
};

#endif // _Effect_h_