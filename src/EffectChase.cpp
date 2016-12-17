
#include <EffectChase.h>

void EffectChase::init(Color *buffer)
{
	this->buffer = buffer;
	lastTime = 0;
	effectDelay = random(30, 61);

	pixelPosition = 0;
	sequencePosition = random(0, sequenceLength(false));
	sequenceStep = random(5, 16);
	sequenceSpeed = random(5, 16);
	reverse = random(0, 2);
	tailLength = random(3, 8);
}

bool EffectChase::update()
{
	if (!timeForUpdate()) return false;

	uint8_t pos;
	uint8_t shift;

	for (uint8_t i = 0; i < LED_COUNT; i++) buffer[i].clear();

	Color c = colorSequence(sequencePosition, false);

	for (uint8_t i = 0; i < tailLength; i++)
	{
		shift = (tailLength - i - 1);
		Color n = Color(c.r >> shift, c.g >> shift, c.b >> shift);

		pos = (pixelPosition + i) % LED_COUNT; 
		if (reverse) pos = LED_COUNT - 1 - pos;

		buffer[map[pos]] = n;
	}

	pixelPosition = (pixelPosition + 1) % LED_COUNT;
	sequencePosition = (sequencePosition + sequenceSpeed) % sequenceLength(false); 

	return true;
}