
#include <EffectChase.h>

void EffectChase::init(Color *buffer, int bufferSize)
{
	this->buffer = buffer;
	this->bufferSize = bufferSize;
	this->pixelPosition = 0;
	this->sequencePosition = random(0, sequenceLength(false));
	this->sequenceStep = random(5, 16);
	this->sequenceSpeed = random(5, 16);
	this->reverse = random(0, 2);
	this->tailLength = random(3, 8);
}

void EffectChase::update()
{
	uint8_t pos;
	uint8_t shift;

	for (uint8_t i = 0; i < LED_COUNT; i++) buffer[i].clear();

	Color c = colorSequence(sequencePosition, false);

	for (uint8_t i = 0; i < tailLength; i++)
	{
		shift = (tailLength - i);
		Color n = Color(c.r >> shift, c.g >> shift, c.b >> shift);

		pos = (pixelPosition + i) % LED_COUNT; 
		if (reverse) pos = LED_COUNT - 1 - pos;

		buffer[map[pos]] = n;
	}

	pixelPosition = (pixelPosition + 1) % LED_COUNT;
	sequencePosition = (sequencePosition + sequenceSpeed) % sequenceLength(false); 
}