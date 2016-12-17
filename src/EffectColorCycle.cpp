
#include <EffectColorCycle.h>

void EffectColorCycle::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = 50;

	sequencePosition = random(0, sequenceLength(false));
	sequenceStep = random(5, 16);
	sequenceSpeed = random(5, 16);
	reverse = random(0, 2);
}

bool EffectColorCycle::update()
{
	if (!timeForUpdate()) return false;

	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[map[reverse ? (LED_COUNT - 1 - i) : i]] = colorSequence(sequencePosition + (i * sequenceStep), false);
	}

	sequencePosition = (sequencePosition + sequenceSpeed) % sequenceLength(false);

	return true;
}