
#include <EffectColorCycle.h>

void EffectColorCycle::init(Color *buffer, int bufferSize)
{
	Serial.println("EffectColorCycle::init");
	this->buffer = buffer;
	this->bufferSize = bufferSize;
	this->lastTime = 0;
	this->effectDelay = 4;

	this->sequencePosition = random(0, sequenceLength(false));
	this->sequenceStep = random(5, 16);
	this->sequenceSpeed = random(5, 16);
	this->reverse = random(0, 2);
}

bool EffectColorCycle::update()
{
	if (!timeForUpdate()) return false;

	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[map[reverse ? (LED_COUNT - 1 - i) : i]] = colorSequence(this->sequencePosition + (i * sequenceStep), false);
	}

	this->sequencePosition = (this->sequencePosition + sequenceSpeed) % sequenceLength(false);

	return true;
}