
#include <EffectColorCycle.h>

void EffectColorCycle::init(Color *buffer, int bufferSize)
{
	Serial.println("EffectColorCycle::init");
	this->buffer = buffer;
	this->bufferSize = bufferSize;

	this->sequencePosition = random(0, sequenceLength(false) - 1);
	this->sequenceStep = random(5, 15);
	this->sequenceSpeed = random(5, 15);
	this->reverse = random(0, 1);
}

void EffectColorCycle::update()
{
	for (int i = 0; i < LED_COUNT; i++)
	{
		buffer[map[reverse ? (LED_COUNT - 1 - i) : i]] = colorSequence(this->sequencePosition + (i * sequenceStep), false);
	}

	this->sequencePosition = (this->sequencePosition + sequenceSpeed) % sequenceLength(false);
}