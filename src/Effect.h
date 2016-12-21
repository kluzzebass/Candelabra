
#ifndef _Effect_h_
#define _Effect_h_

#include <Math.h>
#include <Adafruit_NeoPixel.h>
#include <Color.h>

#include <defs.h>

class Effect
{
public:
	Effect(const uint8_t (&map)[LED_COUNT]) : map(map) {}
	virtual void init(Color *buffer) = 0;
	virtual bool update() = 0;
	static void shimmerUpdate();
	static void initShimmer();

	Color *buffer = nullptr;

protected:
	const uint8_t (&map)[LED_COUNT];
	bool reverse = false;

	unsigned long lastTime = 0;
	uint16_t effectDelay = 100;

	static const uint16_t colorsPerSegment = 255;

	// Cyclic color sequencer with or without white
	static Color colorSequence(int, bool);
	static uint16_t sequenceLength(bool includeWhite);

	static Color shimmer(uint8_t led, int seqPos, bool includeWhite);

	static bool shimmerInitialized;
	static unsigned long lastShimmer;
	static float shimmerSpeed[LED_COUNT];
	static float shimmerAngle[LED_COUNT];

	bool timeForUpdate();
};

#endif // _Effect_h_