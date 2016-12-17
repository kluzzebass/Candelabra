
#include <EffectTheaterChase.h>

void EffectTheaterChase::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = random(50, 101);

	chasePosition = 0;
	sequencePosition = random(0, sequenceLength(false));
	sequenceSpeed = random(5, 16);
	reverse = random(0, 2);
	density = random(0, 2) ? 3 : 11;

}

bool EffectTheaterChase::update()
{
	if (!timeForUpdate()) return false;

	// Set all colors to black
	for (int i = 0; i < LED_COUNT; i++)
	{
		if ((i % density) == chasePosition)
			buffer[map[i]] = colorSequence(sequencePosition, false);
		else
			buffer[map[i]].clear();
	}

	chasePosition = (chasePosition + (reverse ? (density - 1) : 1)) % density;
	sequencePosition = (sequencePosition + sequenceSpeed) % sequenceLength(false);

	return true;
}