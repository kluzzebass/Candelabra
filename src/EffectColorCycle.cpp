
#include <EffectColorCycle.h>

void EffectColorCycle::init(Color *buffer, int bufferSize)
{
	Serial.println("EffectColorCycle::init");
	this->buffer = buffer;
	this->bufferSize = bufferSize;

	this->sequencePosition = 0;
	this->sequenceStep = random(1, 10);
}

void EffectColorCycle::update()
{
	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[map[reverse ? (LED_COUNT - 1 - i) : i]] = colorSequence(this->sequencePosition + (i * sequenceStep), false);
	}

	this->sequencePosition = (this->sequencePosition + sequenceStep) % sequenceLength(false);
}